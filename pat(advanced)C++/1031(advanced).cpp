#include<iostream>
using namespace std;
int main(){
    string a;
    cin>>a;
    int string_length = a.length();
    int j = (string_length+2)%3;
    int m;
    if(j==0){
        m = (string_length+2)/3;
        for(int i = 1;i<=m-1;i++){
            for(int k = 1;k<=m;k++){
                if(k==1){
                    cout<<a[i-1];
                }
                else if(k == m){
                    cout<<a[(int)a.length()-i]<<endl;
               }
                else{
                    cout<<' ';
                }
            }
        }
        for(int i = m;i<=2*m-1;i++){
            cout<<a[i-1];
        }
    }
    else if(j==1){
        m = (string_length+2)/3;
        for(int i = 1;i<=m-1;i++){
            for(int k = 1;k<=m+1;k++){
                if(k==1){
                    cout<<a[i-1];
                }
                else if(k == m+1){
                    cout<<a[(int)a.length()-i]<<endl;
                }
                else{
                    cout<<' ';
                }
            }
        }
        for(int i = m;i<=2*m;i++){
            cout<<a[i-1];
        }
    }
    else if(j==2){
        m = (string_length+2)/3;
        for(int i = 1;i<=m-1;i++){
            for(int k = 1;k<=m+2;k++){
                if(k==1){
                    cout<<a[i-1];
                }
                else if(k == m+2){
                    cout<<a[(int)a.length()-i]<<endl;
                }
                else{
                    cout<<' ';
                }
            }
        }
        for(int i = m;i<=2*m+1;i++){
            cout<<a[i-1];
        }
    }
}
