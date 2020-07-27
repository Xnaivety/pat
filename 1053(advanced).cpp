#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
long long int weights[100] = {0};//结点和其权重的对应关系
vector<int>path;
vector<int>node[100];
vector<int>final_path[100];
int none_leaf_nodes[100] = {0};//结点无效为0
int nodes;
int number_none_leaf_nodes;
int number_final_path = 0;
long long int weight;

bool comp(int a,int b){
    return weights[a]>weights[b];
}

void dfs(int curnode,long long int curweight){
    curweight += weights[curnode];
    if(curweight>weight){
        return;//及时止损；
    }
    else{
        path.emplace_back(curnode);
    }
    if(none_leaf_nodes[curnode]==2){
        for(int each:node[curnode]){
            dfs(each,curweight);
        }
    }
    if(curweight==weight&&none_leaf_nodes[curnode]==1){
        final_path[number_final_path] = path;
        number_final_path += 1;
    }
    path.pop_back();
    curweight-=weights[nodes];
}


int main(){

    cin>>nodes>>number_none_leaf_nodes>>weight;
    for(int i = 0;i<nodes;i++){
        none_leaf_nodes[i] = 1;//结点有效为1
        cin>>weights[i];
    }
    for(int i = 0;i<number_none_leaf_nodes;i++){
        cin>>nodes;
        none_leaf_nodes[nodes] = 2;//非叶子结点为2
        int number = 0;
        cin>>number;
        for(int j = 0;j<number;j++){
            int leaves = 0;
            cin>>leaves;
            node[nodes].emplace_back(leaves);
        }
        sort(node[nodes].begin(),node[nodes].end(),comp);
    }
    dfs(0,0);

    for(int j = 0;j<number_final_path;j++){
        int o = 0;
        for(int each:final_path[j]){
            if(o!=0){
                cout<<' '<<weights[each];
            }
            else{
                cout<<weights[each];
                o = 1;
            }
        }
        if(j!=number_final_path-1){
            cout<<endl;
        }
    }
    return 0;
}