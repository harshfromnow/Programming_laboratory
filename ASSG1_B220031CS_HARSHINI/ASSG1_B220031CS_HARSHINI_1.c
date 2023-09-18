#include <stdio.h>
#include <ctype.h>
void main(){
	char str[100];
	fgets(str,sizeof(str),stdin);
	char x;
	int count=0;
	scanf("%c",&x);
	for(int i=0;i<sizeof(str);i++){
		if (toupper(x)==str[i] || tolower(x)==str[i])
			count=count+1;}
	printf("%d",count);}
