#include<iostream>
using namespace std;
#include<algorithm>

struct student{
    string id;
    string name;
    int grade{};
};
int  cursor = 0;

student students[100000];
bool comp1(const student& x,student y){
    return x.id<y.id;
}

bool comp2(const student& x,student y){
    return x.name<y.name;
}

bool comp3(const student& x,student y){
    return x.grade<y.grade;
}



int main(){
    int N;
    int C;
    cin>>N;
    cin>>C;

    while(N--){
        cin>>students[cursor].id;
        cin>>students[cursor].name;
        cin>>students[cursor].grade;
        cursor++;
    }
    if(C==1)sort(students,students+cursor,comp1);
    else if(C==2){
    	sort(students,students+cursor,comp1);
    	sort(students,students+cursor,comp2);
    }
    else if(C==3){
    	sort(students,students+cursor,comp1);
    	sort(students,students+cursor,comp3);
    }
    for(int i = 0;i<cursor;i++){
        cout<<students[i].id<<' '<<students[i].name<<' '<<students[i].grade<<endl;
    }
    return 0;
}