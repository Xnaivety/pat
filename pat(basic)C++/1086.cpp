#include<iostream>
using namespace std;
#include<algorithm>
int main(void){
	int a;
	int b;
	cin>>a>>b;
	int c = a*b;
	string d;
	d = to_string(c);
	reverse(d.begin(),d.end());
	
	cout<<atoi(d.c_str());
	return 0;
}