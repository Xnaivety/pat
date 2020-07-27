
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main(){
	string n;
	int count = 0;
	for(int j = 0;j<10;j++){
		cin>>count;
		while(count){
			n += '0'+ j;
			count--;
		}
	}
	int index = 0;
	while(n[index] == '0'){
		index++;
	}
	swap(n[index],n[0]);
	cout<<n;
}
