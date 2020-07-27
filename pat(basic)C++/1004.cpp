#include<iostream>
using namespace std;
struct student
{
	string name;
	string stu_number;
	int mark;
};
int main(void)
{
	int number;
	cin>>number;
	student max{" "," ",0};
	student min{" "," ",100};
	student t;
	for(int index = 0;index<number;index++){
		cin>>t.name>>t.stu_number>>t.mark;
		max = t.mark>max.mark?t:max;
		min = t.mark<min.mark?t:min;
	}
	cout<<max.name<<' '<<max.stu_number<<endl;
	cout<<min.name<<' '<<min.stu_number;
	return 0;
}