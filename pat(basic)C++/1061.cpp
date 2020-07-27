#include<iostream>
using namespace std;
int main(){
	int stu_count2;
	int question_count2;
	cin>>stu_count2>>question_count2;
	const int stu_count = stu_count2;
	const int question_count = question_count2;
	int question_mark[question_count] = {0};
	int question_count1 = question_count;
	int index = 0;
	int question_answer[question_count];
	int varieties = 0;
	while(question_count1--){
		cin>>question_mark[index];
		index++;
	}
	question_count1 = question_count;
	while(question_count1--){
		cin>>question_answer[varieties];
		varieties++;
	}
	for(int i = 0;i<stu_count;i++){
		int stu_mark = 0;
		for(int j = 0;j<question_count;j++){
			int question;
			cin>>question;
			if(question==question_answer[j]){
				stu_mark += question_mark[j];
			}
		}
		cout<<stu_mark<<endl;
	}
}