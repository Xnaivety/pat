#include<iostream>
using namespace std;
int main(){
    int count = 0;
    cin>>count;
    int flag = 0;
    string input = "";
    string qualify = "10X98765432";
    string output = "";
    int z = 0;
    int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    while(count){
        int sum = 0;
        cin>>input;
        for(int i = 0;i<17;i++){
            sum += weight[i]*(input[i]-'0');
        }
        z = sum%11;
        if(qualify[z]!=input[17]){
            flag++;
            if(flag!=1){
                cout<<endl;
            }
            cout<<input;
        }
        count--;
    }
    if(flag==0){
        cout<<"All passed";
    }
    return 0;
}