#include<iostream>
using namespace std;

string stepone(string a){
    string b;
    string c;
    string d;
    int j;
    int jinwei = 0;
    for(int i = a.length()-1;i>=0;i--){
        b += a[i];
    }
    for(int i = a.length()-1;i>=0;i--){
        j = (a[i]-'0')+(b[i]-'0')+jinwei;
        if(j>= 10){
            c +=  j-10+'0';
            jinwei = 1;
        }
        else{
            c += j+'0';
            jinwei = 0;
        }
    }
    if(jinwei == 1){
        c += '1';
    }
    for(int i = c.length()-1;i>=0;i--){
        d += c[i];
    }
    return d;
}


int palindromic(string c){
    for(int i = 0;i< c.length();i++) {
        if(c[i]!=c[c.length()-1-i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    string index;
    int step;
    int m = 0;
    cin>>index>>step;
    do{
        if(palindromic(index)==1){
            break;
        }
        else{
            index = stepone(index);
            m++;
        }
    }
    while(m<step);
    cout<<index<<endl;
    cout<<m;
    return 0;
}