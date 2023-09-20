#include <stdio.h>
#define maxbuckets 1000
#define maxelements 1000

void insertionSort(float arr[], int n) {
    for (int i=1;i<n;i++) {
        float key=arr[i];
        int j= i-1;
        while (j>=0 && arr[j] > key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bucketsort(float arr[], int n) {
    float max=arr[0];
    float min=arr[0];
    for (int i=0;i<n;i++) {
        if (arr[i]>max) {
            max=arr[i];
        }
        if (arr[i]<min) {
            min=arr[i];
        }
    }
    float range=(max-min)/maxbuckets;
    float buckets[maxbuckets][maxelements]={0};
    int bucketsize[maxbuckets]={0};
    for (int i=0;i<n;i++) {
        int bucketindex=(int)((arr[i]-min)/range*maxbuckets);
        if (bucketindex>=maxbuckets){
            bucketindex=maxbuckets-1;
        }
        if (bucketsize[bucketindex]<maxelements){
            buckets[bucketindex][bucketsize[bucketindex]++]=arr[i];
        }
    }
    for (int i= 0;i< maxbuckets;i++) {
        if (bucketsize[i]>0){
            insertionSort(buckets[i],bucketsize[i]);
        }
    }
    int index=0;
    for (int i=0;i<maxbuckets;i++) {
        for (int j=0;j<bucketsize[i];j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i=0;i<n;i++) {
        scanf("%f",&arr[i]);
    }
    bucketsort(arr,n);
    for (int i=0;i<n-1;i++) {
        printf("%.2f ",arr[i]);
    }
    printf("%.2f",arr[n-1]);
    return 1;
}

