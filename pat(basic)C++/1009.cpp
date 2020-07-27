#include<iostream>
using namespace std;
int main(){
	string a[80];
	int count = 0;
	while(cin>>a[count]){
		count++;
		if(cin.get()=='\n'){
			break;
		}
	}
	for(int i = count;i>0;i--){
		cout<<a[i-1];
		if(i!=1){
			cout<<' ';
		}
	}
	return 0;
}