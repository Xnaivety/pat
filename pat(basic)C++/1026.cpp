#include<iostream>
using namespace std;

int main(){
    long start,end;
    cin>>start>>end;
    long lasting = (int)((end-start)/100);
    if(((end-start)%100) >=50){
        lasting += 1;
    }
    long ss;
    long mm;
    long hh;
    hh = lasting/3600;
    mm = (lasting-lasting/3600*3600)/60;
    ss = lasting - (hh*3600+mm*60);
    cout.setf(ios::right);
    cout.width(2);
    cout.fill('0');
    cout<<hh<<':';
    cout.setf(ios::right);
    cout.width(2);
    cout.fill('0');
    cout<<mm<<':';
	cout.setf(ios::right);
    cout.width(2);
    cout.fill('0');
    cout<<ss;
    return 0;
}
