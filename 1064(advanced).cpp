#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int> v;
vector<int> b;
int c[1001];
int N;
void inordertraversal(int k){
	if(k>N)return;
	inordertraversal(2*k);
	v.emplace_back(k);
	inordertraversal(2*k+1);

}



int main(){
	cin>>N;
	int count = N;
	int index;
	inordertraversal(1);
	while(N--){
		cin>>index;
		b.emplace_back(index);
	}
	sort(b.begin(),b.end());
	for(int i = 0;i<count;i++){
		c[v[i]] = b[i];
	}
	for(int k = 1;k<=count;k++){
		if(k==1){
			cout<<c[k];
		}
		else if(k!=1){
			cout<<' '<<c[k];
		}
	}
	return 0;
}