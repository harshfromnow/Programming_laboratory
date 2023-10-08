#include <stdio.h>

void MAXHEAPIFY(int A[],int n, int i){
	int max=i;
	int left=2*i+1; //left(i)
	int right=2*i+2; //right(i)
	if (left <n && A[left]>A[max]){
		max=left;}
	if (right <n && A[right] > A[max]){
		max=right;}
	if (max!=i){ //if the largest element is not the root
	//swapping the elements
		int temp=A[i]; 
		A[i]=A[max];
		A[max]=temp;
		MAXHEAPIFY(A,n,max);}
	}
	
void BUILDMAXHEAP(int A[], int n){
	for (int i= n/2-1;i>=0;i--){
		MAXHEAPIFY(A,n,i);
	}
}

void HEAPSORT(int A[], int n){
	for (int i=n-1;i>0;i--){
		int temp=A[0];
		A[0]=A[i];
		A[i]=temp;
		MAXHEAPIFY(A,i,0);}
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++){
		scanf("%d",&arr[i]);}
	HEAPSORT(arr,n);
	for (int i=0;i<n-1;i++){
		printf("%d ",arr[i]);}
	printf("%d",arr[n-1]);
	return 1;
}

	
