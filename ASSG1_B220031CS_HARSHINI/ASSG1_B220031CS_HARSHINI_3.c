#include <stdio.h>

int factorial(int n){
	int fact=1;
	for (int i=1; i<=n ; i++){
		fact=fact*i;}
	return fact;}

double power(double a,int b){
	double p=1.0;
	for(int i=1;i<=b;i++){
		p=p*a;}
	return p;}
		
void main(){
	int n;
	double x,y;
	scanf("%lf",&x);
	scanf("%d",&n);
	y=x*(3.1415/180);
	double sum=0;
	int num1=1;
	for(int i=1;i<=n;i=i+2){
		sum+=num1*power(y,i)/factorial(i);
		num1*=-1;}
		printf("%.4f",sum);
		}
