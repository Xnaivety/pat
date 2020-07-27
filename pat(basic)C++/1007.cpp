#include<iostream>
using namespace std;
#include<cmath>
int IsPrime(int Prime);
int main(){
	int count;
	cin>>count;
	int primepair = 0;
	for(int j = 2;j<=count-2;j++){
		if(IsPrime(j)*IsPrime(j+2)==1){
			primepair++;
		}
	}
	cout<<primepair;
	return 0;
}
int IsPrime(int Prime){
    if(Prime==1){
    	return 0;
    }
    if(Prime==2||Prime==3){
        return 1;
    }
    else{
        for(int i = 2;i<=(int)sqrt(Prime);i++){
            if(Prime%i==0){
                return 0;
            }
        }
        return 1;
    }
}