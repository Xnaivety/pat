#include<iostream>
using namespace std;
#include<vector>
#include<queue>
vector<int>nodes[100];
queue<int>q[100];
int visit[100] = {0};
int level = 1;
int every_level_none_leaf[100] = {0};
void dfs(){
    while(!q[level].empty()){
        int node;
        node = q[level].front();
        q[level].pop();
        visit[node] = 1;
        if(!nodes[node].empty()){
            level++;
            for(int each:nodes[node]){
                q[level].push(each);
            }
            level--;
        }
        else{
            every_level_none_leaf[level]++;
        }
    }
    level++;
    if(!q[level].empty()){
        dfs();
    }
}

int main(){
    int number_of_nodes;
    int number_of_nonleaf_nodes;
    cin>>number_of_nodes>>number_of_nonleaf_nodes;
    for(int i = 0;i<number_of_nonleaf_nodes;i++){
        int rootnode;
        cin>>rootnode;
        int number_of_leaf_for_this_rootnode;
        cin>>number_of_leaf_for_this_rootnode;
        for(int j = 0;j<number_of_leaf_for_this_rootnode;j++){
            int leaf_for_this_rootnode;
            cin>>leaf_for_this_rootnode;
            nodes[rootnode].emplace_back(leaf_for_this_rootnode);
        }
    }
    //数据录入完成；
    q[1].push(1);
    dfs();
    for(int j = 1;j<=level-1;j++){
        if(j!=1){
            cout<<' ';
        }
        cout<<every_level_none_leaf[j];
    }
    return 0;
}