#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//cin换成sacnf可以节省内存


vector<long long int> a;
int main(){
	string line1;
	string line2;
	getline(cin,line1);
	getline(cin,line2);
	string index1;
	for(int j = 0;j<2;j++){
		for(int i = 0;i<(int)line1.length();i++){
			if(line1[i]!=' '){
				a.emplace_back(stoll(index1));
				index1 = "";
			}
			else if(line1[i] == '\n'){
				a.emplace_back(stoll(index1));
				break;
			} 
			else{ 
				index1 += line1[i];
			}
		}
	}
	sort(a.begin(),a.end());
	cout<<a[(int)((a.size()-1)/2)];
}