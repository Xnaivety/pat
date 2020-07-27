//该题采用深度优先遍历算法求解，github上的代码采用dijkstra算法

#include<iostream>
#include<vector>
using namespace std;
int Cmax,N,Sp,M;//Cmax每个站的最大车数，N是站数，Sp问题站，M路数
int bike[500];//500个车站
int dis[501][501];
int mindis_to[501];
int final_dis=99999999;
int final_send;
int final_take;
vector<int> v[501];
vector<int> path;
vector<int>final_ans;

void dfs(int curstation,int curdis,int cursend,int curtake){
//curdis为当前移动的距离，curstation为当前所在的车站，sursend当前需要发送的车的数量，curtake为当前需要带回去的自行车的数量
	if(curdis>mindis_to[curstation])return;//及时止损
	path.emplace_back(curstation);
	if(curstation==Sp){//如果到达了问题站
		if((curdis<final_dis)||(curdis==final_dis&&cursend<final_send)||(curdis==final_dis&&cursend==final_send&&curtake<final_take)){
			final_ans = path;
			final_dis = curdis;
			final_send = cursend;
			final_take = curtake;
		}
	}
	else{
		if(curdis<mindis_to[curstation]){//如果目前这个路径为最短路径则刷新最短路径
			mindis_to[curstation]=curdis;
		}
		for(int i:v[curstation]){
			if(curtake+bike[i]<Cmax/2){
				dfs(i,curdis+dis[curstation][i],cursend+Cmax/2-curtake-bike[i],0);
			}
			else{
				dfs(i,curdis+dis[curstation][i],cursend,curtake+bike[i]-Cmax/2);
			}
		}
	}
	path.pop_back();
}
int main(){
	int i,j,k;
	cin>>Cmax>>N>>Sp>>M;
	for(i = 1;i<=N;i++){//循环输入每个车站的数量
		cin>>bike[i];
	}
	while(M--){
		cin>>i>>j>>k;
		v[i].emplace_back(j);
		v[j].emplace_back(i);
		dis[i][j]=dis[j][i]=k;
	}
	for(i = 0;i<=N;i++)mindis_to[i]=9999999;
	dfs(0,0,0,0);
	cout<<final_send<<' ';
	cout<<final_ans[0];
	for(i = 1;i<(int)final_ans.size();i++){
		cout<<"->"<<final_ans[i];
	}
	cout<<' '<<final_take;
}





