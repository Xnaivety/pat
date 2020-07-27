#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
int main(void)
{
	
	int a[1000] = {};
	int team_quantity;
	cin>>team_quantity;
	int team_number;
	int member_number;
	int member_mark;
	while(team_quantity--){
		scanf("%d-%d %d", &team_number,&member_number,&member_mark);
		a[team_number-1] += member_mark;
	}
	int maxscore = a[0];
	int maxteamnumber = 1;
	for(int i = 0;i<1000;i++){
		if(a[i]>maxscore){
			maxscore = a[i];
			maxteamnumber = i+1;
		} 
	}
	cout<<maxteamnumber<<' '<<maxscore;
	return 0;
}
	