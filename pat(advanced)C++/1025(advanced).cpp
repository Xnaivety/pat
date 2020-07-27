#include<iostream>
#include<algorithm>
using namespace std;
struct testee{
    string id;
    int score,final_rank,location_number,local_rank;
};

bool comp(testee x,testee y){
        return x.score>y.score;
}

bool comp2(testee x,testee y){

    if(x.score!=y.score){
        return x.score>y.score;
    }
    else{
        return x.id<y.id;
    }
}




testee t[30000];
int main(){
    int N,K,i,j;//N为地区个数；K为该地区人数
    cin>>N;
    for(i = 1,j = 0;i<=N;i++){
        cin>>K;
        int start = j;
        while(K--){
            cin>>t[j].id>>t[j].score;
            t[j].location_number = i;
            j++;
        }
        sort(t+start,t+j,comp);
        for(int k = start;k<j;k++){
            if(k ==start||t[k].score!=t[k-1].score){
                t[k].local_rank = k-start+1;
            }
            else{
                t[k].local_rank = t[k-1].local_rank;
            }
        }
    }
    sort(t,t+j,comp2);
    for(int k = 0;k<j;k++){
        if(k == 0||t[k].score!=t[k-1].score){
            t[k].final_rank = k+1;
        }
        else{
            t[k].final_rank = t[k-1].final_rank;
        }
    }
    cout<<j<<endl;
    for(int k = 0;k<j;k++){
        cout<<t[k].id<<' '<<t[k].final_rank<<' '<<t[k].location_number<<' '<<t[k].local_rank<<endl;
    }
    return 0;
}