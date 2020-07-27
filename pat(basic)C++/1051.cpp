#include<iostream>
using namespace std;
#include<cmath>
#include<iomanip>
int main(){
    double R1;
    double P1;
    double R2;
    double P2;
    double shibu1;
    double xubu1;
    double shibu2;
    double xubu2;
    double shibu;
    double xubu;
    cin>>R1>>P1>>R2>>P2;
    shibu1 = R1*cos(P1);
    xubu1 = R1*sin(P1);
    shibu2 = R2*cos(P2);
    xubu2 = R2*sin(P2);
    shibu = shibu1*shibu2-xubu1*xubu2;
    xubu = shibu1*xubu2+shibu2*xubu1;
    if(abs(shibu)<0.005){
        shibu = 0;
    }
    if(abs(xubu)<0.005){
        xubu = 0;
    }
    if(xubu<0){
        cout<<fixed<<setprecision(2)<<shibu<<xubu<<'i';
    }
    else{
        cout<<fixed<<setprecision(2)<<shibu<<'+'<<xubu<<'i';
    }
    return 0;
}