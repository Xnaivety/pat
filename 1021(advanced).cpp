#include<iostream>
#include<vector>
#include<set>
using namespace std;

//set本身就有去重功能和排序功能


vector<int>v[10001];
vector<int>farthest_point;
int maxdis = 0;
int visited[10001] = {0};
set<int>final_ans;

void dfs(int cur){
	if(visited[cur]){
		return;//及时止损
	}
	visited[cur] = 1;
	for(int m:v[cur]){
		dfs(m);
	}
}

void dfs2(int cur,int depth){
	if(visited[cur])return;
	visited[cur] = 1;
	if(depth>maxdis) {
		maxdis = depth;
		farthest_point.clear();
		farthest_point.emplace_back(cur);
	}
	else if(depth == maxdis){
		farthest_point.emplace_back(cur);
	}
	for(int i:v[cur]) {
		dfs2(i,depth+1);
	}
}

int main(){
	int N,i,j,k;
	cin>>N;
	for(i = 0;i<N;i++){
		cin>>j>>k;
		v[j].emplace_back(k);
		v[k].emplace_back(j);
	}
	int count = 0;
	for(i = 1;i<=N;i++){
		if(!visited[i]){
			count++;
			dfs(i);
		}
	}
	if(count>1){
		cout<<"Error: "<<count<<" components";
		//不是树
	}
	else{
		//是树
		for(i = 1;i<N;i++){
			visited[i] = 0;
		}
		dfs2(1,0);//第一次dfs2
		for(int each:farthest_point)final_ans.insert(each);
		farthest_point.clear();
		maxdis = 0;
		for(i = 0;i<10001;i++)visited[i] = 0;
		dfs2(*final_ans.begin(),0);//第二次dfs2
		for(int each:farthest_point){
			final_ans.insert(each);
		}
		for(int each:final_ans){
			cout<<each<<'\n';
		}
	}
	return 0;
}