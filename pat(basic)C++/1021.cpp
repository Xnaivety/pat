#include<iostream>
#include<stdio.h>
using namespace std;
int main(void){
	char a = cin.get();
	int zero = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;
	while(a!='\n'){
		if(a =='0'){
			zero++;
		}
		else if(a =='1'){
			one++;
		}
		else if(a =='2'){
			two++;
		}
		else if(a =='3'){
			three++;
		}
		else if(a =='4'){
			four++;
		}
		else if(a =='5'){
			five++;
		}
		else if(a =='6'){
			six++;
		}
		else if(a =='7'){
			seven++;
		}
		else if(a =='8'){
			eight++;
		}
		else if(a =='9'){
			nine++;
		}
		a = cin.get();
	}
	if(zero)cout<<"0:"<<zero<<endl;
	if(one)cout<<"1:"<<one<<endl;
	if(two)cout<<"2:"<<two<<endl;
	if(three)cout<<"3:"<<three<<endl;
	if(four)cout<<"4:"<<four<<endl;
	if(five)cout<<"5:"<<five<<endl;
	if(six)cout<<"6:"<<six<<endl;
	if(seven)cout<<"7:"<<seven<<endl;
	if(eight)cout<<"8:"<<eight<<endl;
	if(nine)cout<<"9:"<<nine<<endl;

}
