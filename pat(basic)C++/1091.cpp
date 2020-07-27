#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int zi_shou_shu(int index,int *flag);
int main(){
	int count;
	int flag = 0;
	cin>>count;
	int push = 0;
	while(count){
        cin>>push;
	    zi_shou_shu(push,&flag);
	    flag++;
	    count--;
	}
	return 0;
}
int zi_shou_shu(int index, int *flag){
	int pingfang = (int)pow(index*1.0,2.0);
	for(int j = 1;j<=10;j++){
		string num = to_string(j*pingfang);
		int position = num.rfind(to_string(index));
		if(to_string(index).length()==num.length()-position) {
            if ((*flag) != 0) {
                cout << endl;
            }
            cout << j <<' '<< num;
            return 1;
        }
	}
    if ((*flag) != 0) {
        cout << endl;
    }
    cout<<"No";
    return 0;
}