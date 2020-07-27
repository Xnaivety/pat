#include<iostream>
#include<vector>
using namespace std;
//164
//十六进制
//10 4

vector<int> digit;
int main(){
	int N;
	int b;
	cin>>N>>b;
	while(N!=0){
		digit.emplace_back(N%b);
		N/=b;
	}
	int i = 0;
	for(i = 0;i<(int)digit.size();i++){
		if(digit[i]!=digit[digit.size()-1-i]){
			cout<<"NO"<<endl;
			break;
		}
	}
	if(i==(int)digit.size()){
		cout<<"YES"<<endl;

	}
	for(int j = (int)digit.size()-1;j>=0;j--){
		cout<<digit[j];
		if(j!=0){
			cout<<' ';
		}
	}
}