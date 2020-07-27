#include<iostream>
using namespace std;
int main(){
    int T_chouma;
    int K_count;
    cin>>T_chouma>>K_count;
    while(K_count--){
        int n1;
        int b;
        int t;
        int n2;
        cin>>n1>>b>>t>>n2;
        if(b == 0){
            b = -1;
        }
        if(T_chouma>=t){
            if(((n1-n2)*b)<0){
                T_chouma += t;
                cout<<"Win "<<t<<"!  Total = "<<T_chouma<<'.'<<endl;
            }
            else{
                T_chouma -=t;
                cout<<"Lose "<<t<<".  Total = "<<T_chouma<<'.'<<endl;
                if(T_chouma==0){
                    cout<<"Game Over.";
                    break;
                }
            }
        }
        else{
            cout<<"Not enough tokens.  Total = "<<T_chouma<<'.'<<endl;
        }
    }
    return 0;
}