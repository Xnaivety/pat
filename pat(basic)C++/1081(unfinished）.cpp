#include<iostream>
#include<cctype>
using namespace std;
int main(){
    int count;
    cin>>count;
    while(count--){
        string password;
        cin>>password;
        int fei_fa = 0;
        int digit = 0;
        int alpha = 0;
        int dot = 0;
        for(int i = 0;i<(int)password.length();i++){
            if(isdigit(password[i])){
                digit++;
            }
            else if(isalpha(password[i])){
                alpha++;
            }
            else if(password[i]=='.'){ 
            	dot++;
            }
            else{
                fei_fa++;
            }
        }
        if(password.length()<6){
        	cout<<"Your password is tai duan le."<<endl;
        }
        else if(fei_fa!=0){
        	cout<<"Your password is tai luan le."<<endl;
        }
        else if (digit==0&&alpha){
        	cout<<"Your password needs shu zi."<<endl;
        }
        else if(alpha==0&&digit){
        	cout<<"Your password needs zi mu."<<endl;
        }
        else{
        	cout<<"Your password is wan mei."<<endl;
        }   
    }
    return 0;
}

            


