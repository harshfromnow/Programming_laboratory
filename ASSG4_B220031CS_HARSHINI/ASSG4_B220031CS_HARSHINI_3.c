#include <stdio.h>
#include <string.h>

void swap(char str[],int i, int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;}

int partition(char str[],int p,int r){
	char pivot=str[r];
	int i =p-1;
	for (int j=p;j<r;j++){
		if(str[j]>pivot){
			i++;
			swap(str,i,j);
			}}
	swap(str,i+1,r);
	return (i+1);}
		
void quicksort(char str[],int p,int r){
	if (p<r){
		int q=partition(str,p,r);
		quicksort(str,p,q-1);
		quicksort(str,q+1,r);}
}
		
int main(){
	int n;
	scanf("%d",&n);
	char str[n+1];
	char a;
	int index=0;
	for (int i=0;i<2*n;i++){
		scanf("%c",&a);
		if (a!=' ' && a!='\t' && a!='\n'){
			str[index++]=a;}}
	quicksort(str,0,strlen(str));
	for (int i=0;i<n-1;i++){
		if (str[i]>=65 && str[i]<=90 || str[i]>=97 && str[i]<=122){
			printf("%c ",str[i]);}
		}
	printf("%c",str[n-1]);
	return 1;
}
