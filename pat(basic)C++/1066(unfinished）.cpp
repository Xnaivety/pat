#include<iostream>
using namespace std;
#include<iomanip>
int main(){
	int M;
	int N;
	cin>>M>>N;
	int A;
	int B;
	cin>>A>>B;
	int replace;
	cin>>replace;
	int count = M*N;
	int flag = 0;
	while(count--){
		int a;
		cin>>a;
		if(a>=A&&a<=B){
			a = replace;
		}
		flag++;
		cout.width(3);
		cout.fill('0');
		cout<<a;
		if(flag%N==0){
			cout<<endl;
		}
		else{
			cout<<' ';
		}
	}
	return 0;
}
