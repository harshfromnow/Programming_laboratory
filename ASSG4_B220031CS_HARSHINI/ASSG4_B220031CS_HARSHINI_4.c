#include <stdio.h>

void sort(int arr[],int n,int lim) {
    int swaps = 0, rounds = 1;
    for (int i=0;i<n;i++) {
        int selected=arr[i];
        int pos=i;
        for (int j=i+1;j<n;j++) {
            if (rounds%2!=0) {
                if (selected>arr[j]) {
                    selected=arr[j];
                    pos=j;
                }
            } else {
                if (selected<arr[j]) {
                    selected=arr[j];
                    pos=j;
                }
            }
        }
        if (pos!=i) {
            int temp=arr[i];
            arr[i]=selected;
            arr[pos]=temp;
            swaps++;
        }
        rounds++;
        if (swaps>=lim) {
            break;
        }
    }
}

int main() {
    int num,target;
    scanf("%d",&num);
    int pages[num];
    for (int i=0;i<num;i++) {
        scanf("%d",&pages[i]);
    }
    scanf("%d", &target);
    sort(pages,num,target);
    for (int i=0;i<num-1;i++) {
        printf("%d ",pages[i]);
    }
    printf("%d\n", pages[num - 1]);
    return 1;
}
