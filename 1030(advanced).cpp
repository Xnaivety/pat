#include<iostream>
#include<vector>
using namespace std;
vector<int>v[500];
int distances[500][500];
int cost[500][500];
int number_city;
int number_roads;
int startcity;
int endcity;
int city1;
int city2;
int lengths;
int costs;
int final_cost;
int final_distance;
vector<int>path;
vector<int>final_path;
int mindis[500];

void dfs(int curcity,int curdistance,int curcost){
    if(mindis[curcity]<curdistance){
        return;
    }
    path.emplace_back(curcity);
    if(curcity == endcity){
        if(curdistance<mindis[curcity]||(curdistance==mindis[curcity]&&curcost<final_cost)){
            mindis[curcity] = curdistance;
            final_cost = curcost;
            final_path = path;
            final_distance = curdistance;
        }
    }
    else{
        if(curdistance<=mindis[curcity]){
            mindis[curcity] = curdistance;
            for(int each:v[curcity]){
                dfs(each,curdistance+distances[curcity][each],curcost+cost[curcity][each]);
            }
        }
    }
    path.pop_back();
}

using namespace std;
int main(){
    for(int & mindi : mindis){
        mindi = 999999;
    }
    cin>>number_city>>number_roads>>startcity>>endcity;
    while(number_roads--){
        cin>>city1>>city2>>lengths>>costs;
        v[city1].emplace_back(city2);
        v[city2].emplace_back(city1);
        distances[city1][city2] = distances[city2][city1] = lengths;
        cost[city1][city2] = cost[city2][city1] = costs;
    }

    //数据录入完成；
    dfs(startcity,0,0);

    for(int each:final_path){
        cout<<each<<' ';
    }
    cout<<final_distance<<' '<<final_cost;
    return 0;
}