#include<iostream>
using namespace std;
int main(void)
{
	int input_number;
	cin>>input_number;
	string output;
	int baiwei = input_number/100;
	while(baiwei != 0){
		output += 'B';
		baiwei--;
	}
	int shiwei = (input_number%100)/10;
	while(shiwei != 0){
		output += 'S';
		shiwei--;
	}
	int gewei = (input_number%100)%10;
	int i = 1;
	while(gewei){
		output += to_string(i);
		gewei--;
		i++;
	}
	cout<<output;	
	return 0;
}

