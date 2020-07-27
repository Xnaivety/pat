#include<iostream>
using namespace std;
#include<unordered_map>
unordered_map<int,int>digit[3];



int main(){
	string number;
	string number1;
	int j;
	int jinwei = 0;
	cin>>number;
	for(int i = 0;i<10;i++){
		digit[1][i] = 0;
		digit[2][i] = 0;
	}
	for(int i = 0;i<(int)number.size();i++){
		digit[1][number[i]-'0']++;
		digit[2][number[i]-'0']++;
	}
	for(int i = (int)number.size()-1;i>=0;i--){
		digit[2][number[i]-'0']--;
		j = (number[i]-'0')*2;
		j+=jinwei;
		if(j>=10){
			digit[2][j-10]++;
			number1 += '0'+j-10;
			jinwei = 1;
		}
		else{
			digit[2][j]++;
			number1 += '0'+j;
			jinwei = 0;
		}
	}
	int k;
	for(k = 0;k<10;k++){
		if(digit[1][k]!=digit[2][k]){
			break;
		}
	}
	if(k==10){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
		if(number[0]>='5'){
			cout<<'1';
		}
	}
	for(int i = (int)number.size()-1;i>=0;i--){
			cout<<number1[i];
		}
	return 0;
}