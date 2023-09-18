#include <stdio.h>
#include <string.h>

void main(){
	char str[1000];
	scanf("%s",str);
	char maxstr='\0';
	int n,max=1,sum=0;
	n=(int)strlen(str);
	for (int k=1;k<=n;k++){
		sum+=k;}
	char fancystr[sum];
	int ind=0;
	for (int j=0;j<n;j++){
		for (int i=0;i<=j;i++){
			fancystr[ind]=str[j];
			ind++;}}
	char ch;
	for (int i=0;i<n;i++){
		ch=str[i];
		int freq=0;
		for (int j=0;j<sum;j++){
			if (fancystr[j]==ch){
				freq+=1;
				}}
		if (freq>max){
			max=freq;
			maxstr=ch;}}
	printf("%c",maxstr);}
