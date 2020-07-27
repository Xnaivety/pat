#include<iostream>
#include <string>
using namespace std;
void waiguan(string &waiguan);
int main(){
    string waiguan1;
    int n;
    cin>>waiguan1>>n;
    n = n-1;
    while(n--){
        waiguan(waiguan1);
    }
    cout<<waiguan1;
    return 0;
}
void waiguan(string &waiguan1){
    int count = 0;
    char fix = waiguan1[0];
    string waiguanxin;
    waiguanxin += waiguan1[0];
    for(int j = 0;j<(int)waiguan1.length();j++){
        if(fix == waiguan1[j]){
            count++;
        }
        else{
            waiguanxin += to_string(count);
            waiguanxin += waiguan1[j];
            fix = waiguan1[j];
            count = 1;
        }
    }
    waiguanxin += to_string(count);
    waiguan1 = waiguanxin;
    // cout<<waiguan1<<endl;
}