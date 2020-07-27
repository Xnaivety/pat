#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>

int main(void){
	string A;
	char Da;
	string B;
	char Db;
	string Asum;
	string Bsum; 
	long Pa = 0;
	long Pb = 0;
	cin>>A>>Da>>B>>Db;
	for(int i = 0;i<(int)A.length();i++){
		if(A[i] == Da){
			Asum += Da;
		}
	} 
	for(int i = 0;i<(int)B.length();i++){
		if(B[i] == Db){
			Bsum += Db;
		}
	}
	long sum;
	Pa = atoi(Asum.c_str());
	Pb = atoi(Bsum.c_str());
	sum = Pb+Pa;
	cout<<sum;
	return 0;
}

