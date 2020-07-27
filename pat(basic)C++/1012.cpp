#include<iostream>
using namespace std;
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>
int main(){
	int count;
	cin>>count;
	int sum1 = 0;
	int sum2 = 0;
	int count3 = 0;
	int sum4 = 0;
	int max5 = 0;
	int judge = 0;
	int count4 = 0;
	int flag2 = 0;
	while(count--){
		int index;
		cin>>index;
		switch(index%5){
			case(0):
				if(index%10==0){
					sum1 +=index;
				}
				break;
			case(1):
				flag2 = 1;
				if(judge==0){
					sum2 += index;
					judge = 1;
				}
				else if(judge==1){
					sum2 -= index;
					judge = 0;
				}
				break;
			case(2):
				count3++;
				break;
			case(3):
				count4++;
				sum4 += index;
				break;
			case(4):
				if(max5<index){
					max5 = index;
				}
				break;
		}
	}
	if(sum1==0){
		cout<<'N'<<' ';
	}
	else {
		cout<<sum1<<' ';
	}
	if(flag2==0){
		cout<<'N'<<' ';
	}
	else {
		cout<<sum2<<' ';
	}
	if(count3==0){
		cout<<'N'<<' ';
	}
	else {
		cout<<count3<<' ';
	}
	if(count4==0){
		cout<<'N'<<' ';
	}
	else {
		cout<<fixed<<setprecision(1)<<(double)sum4/count4<<' ';
	}
	if(max5==0){
		cout<<'N';
	}
	else {
		cout<<max5;
	}
}


