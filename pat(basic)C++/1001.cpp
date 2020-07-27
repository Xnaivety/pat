#include<iostream>
using namespace std;
#include<stdio.h>
int main(void)
{
	int index = 0;
	int a;
	scanf("%d",&a);
	while(a != 1){
		if(a%2==0){
			a = a/2;
		}
		else{
		a = (3*a+1)/2;
		}
		index += 1;
	}
	printf("%d", index);
	return 0;
}