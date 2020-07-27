#include<iostream>
using namespace std;
void top_and_bottom(int length,char index)
void middle(int length,char index)
int main(){
	int length;
	char index;
	cin>>length>>index;
	top_and_bottom(length,index);
	middle(length,index);
	top_and_bottom(length,index);
	return 0;
}
void top_and_bottom(int length,char index){
	for(int i = 0;i<length;i++){
		cout<<index;
	}
	cout<<endl;
	return;
}
void middle(int length,char index){
	int Hangshu;
	if(length%2!=0){
		Hangshu = (length/2)-1;
	}
	else{
		Hangshu = length/2-2;
	}
	for(int j = 0;j<Hangshu;j++){
		cout<<index;
		for(int k = 0;k<length-2;k++){
			cout<<' ';
		}
		cout<<index;
	}
}