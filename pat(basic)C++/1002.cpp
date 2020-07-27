#include<iostream>
using namespace std;
int main (){
	string du_yin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	int sum = 0;
	char p = cin.get();
	while(p!='\n'){
		sum += p-48;
		p = cin.get();
	}
	string number_pinyin = to_string(sum);
	for(int index = 0;number_pinyin[index];index++){
		cout<<du_yin[number_pinyin[index]-48];
		if(number_pinyin[index+1])
			cout<<' ';
	}
	return 0;
}
