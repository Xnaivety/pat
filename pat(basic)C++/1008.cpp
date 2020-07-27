#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>index;
    int count;
    int move;
    cin>>count;
    int count1 = count;
    cin>>move;
    while(count--){
        int i;
        cin>>i;
        index.push_back(i);
    }
    while(move--){
        int j;
        j = index[count1-1];
        index.erase(index.begin()+(count1-1));
        index.insert(index.begin(),j);
    }
    for(auto it = index.begin();it!=index.end();it++){
        if(it!=index.begin()){
            cout<<' ';
        }
        cout<<(*it);
    }
}