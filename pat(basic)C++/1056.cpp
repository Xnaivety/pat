#include<iostream>
using namespace std;
int main(){
	int count;
	cin>>count;
	int p = count;
	int index = 0;
	int array[9] = {};
	while(count--){
		cin>>array[index];
		index++;
	}
//	for(int m = 0;m<p;m++){
//		cout<<array[m];
//	}
	int sum = 0;
	for(int j = 0;j<p;j++){
		for(int k = 0;k<p;k++){
			if(k==j){
				continue;
			}
			sum += array[j]*10+array[k];
		}
	}
	cout<<sum;
	return 0;
}