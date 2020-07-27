#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	char input_index;
	int P_count = 0;
	int A_count = 0;
	int T_count = 0;
	int e_count = 0;
	int s_count = 0;
	int t_count = 0;
	input_index = cin.get();
	while(input_index != '\n'){
		if(input_index == 'P'){
			P_count++;
		}
		else if(input_index == 'A'){
			A_count++;
		}
		else if(input_index == 'T'){
			T_count++;
		}
		else if(input_index == 'e'){
			e_count++;
		}
		else if(input_index == 's'){
			s_count++;
		}
		else if(input_index == 't'){
			t_count++;
		}
		input_index = cin.get();
	}
	while(P_count != 0||A_count != 0||T_count != 0||e_count != 0||s_count!= 0||t_count != 0){
		if(P_count>0){
			cout<<'P';
			P_count--;
		}
		if(A_count>0){
			cout<<'A';
			A_count--;
		}
		if(T_count>0){
			cout<<'T';
			T_count--;
		}
		if(e_count>0){
			cout<<'e';
			e_count--;
		}
		if(s_count>0){
			cout<<'s';
			s_count--;
		}
		if(t_count>0){
			cout<<'t';
			t_count--;
		}
	}
	return 0;
}
