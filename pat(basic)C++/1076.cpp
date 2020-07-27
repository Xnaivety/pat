#include<iostream>
#include<stdio.h>
using namespace std;
int main(void){
	int number;
	cin>>number;
	int geshu = 4*number;
	string index;
	string da_an;
	while(geshu > 0){
		cin>>index;
		if(index[2]=='T'){
			da_an += index[0]-16;
		}
		geshu--;
	}
	cout<<da_an;
	return 0;


}
