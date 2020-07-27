#include<iostream>
using namespace std;
int main(){
    int count;
    cin>>count;
    string index;
    while(count--){
        cin>>index;
        int topA = 0;
        int middleA = 0;
        int bottomA = 0;
        int flag = 0;
        int other = 0;
        for(int j= 0;j<(int)index.length();j++){
            if(index[j]=='A'){
                if(flag==0){
                    topA += 1;
                }
                else if(flag==1){
                    middleA += 1;
                }
                else if(flag ==2){
                    bottomA += 1;
                }
            }
            else if(index[j]=='P'){
                flag = 1;
            }
            else if(index[j]=='T'){
                flag = 2;
            }
            else{
                other += 1;
            }
        }
        if(topA*middleA==bottomA&&other==0&&middleA!=0&&flag==2){
            cout<<"YES"<<endl;
        }
        else if(topA*middleA!=bottomA||other!=0||middleA==0||flag!=2){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}