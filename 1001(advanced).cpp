#include<iostream>
using namespace std;
#include<cmath>
int main(){
	long long int a;
	long long int b;
	cin>>a>>b;
	long long int sum;
	sum = a+b;
	if(abs(sum)<1000){
		cout<<sum;
	}
	else if(abs(sum)<1000000){
		string out = to_string(sum);
		int a = out.length();
		string output;
		for(int j = 0;j<(int)out.length();j++){
			if(j!=a-3){
				output += out[j];
			}
			else if(j==a-3){
				output += ',';
				output += out[j];
			}
		}
		cout<<output;
	}
	else if(abs(sum)<1000000000){
		string out = to_string(sum);
		int a = out.length();
		string output;
		for(int j = 0;j<(int)out.length();j++){
			if((j!=a-3)&&(j!=a-6)){
				output += out[j];
			}
			else if(j==a-6||j==a-3){
				output += ',';
				output += out[j];
			}
		}
		cout<<output;
	}
	return 0;
}