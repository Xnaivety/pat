#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(void){
	int geshu;
	cin>>geshu;
	long A;
	long B;
	long C;
	int index = 1;
	string a = "";
	while(geshu){
		cin>>A>>B>>C;
		if(A+B>C){
			a += "Case #";
			a += index+48;
			a += ": true";
		}
		else{
			a += "Case #";
			a += index+48;
			a += ": false";
		}
		geshu--;
		if(geshu!=0){
			a += '\n';
		}
		index++;
	}
	cout<<a;
	return 0;

}