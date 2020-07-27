#include<iostream>
using namespace std;
#include<cctype>
#include<map>
map<char,string> weekname;
map<char,string> hour;
int main(){
	string a;
	string b;
	string c;
	string d;
	char a1 = '\0';
	char b1 = '\0';
	int c1 = -1;
	string day;
	string hh;
	int o = -1;
	int p = -1;
	cin>>a>>b>>c>>d;
	for(int i = 0;i<(int)a.length();i++){
		for(int j = 0;j<(int)b.length();j++){
			if(b[j] == a[i]&&isupper(b[j])){
                a1 = a[i];
                o = i+1;
                p = j+1;
                goto next_cycle;
			}
		}
	}
	next_cycle:
    for(int ii = o;ii<(int)a.length();ii++){
        for(int jj = p;jj<(int)b.length();jj++){
            if(a[ii]==b[jj]&&(isupper(a[ii])||isdigit(a[ii]))){
                b1 = a[ii];
                goto next1_cycle;
            }
        }
    }
    next1_cycle:
	for(char k : c){
		for(int l = 0;l<(int)d.length();l++){
			if(k == d[l]){
				c1 = l;
				goto next2_cycle;
			}
		}
	}
	next2_cycle:
	weekname['A'] = "MON";
	weekname['B'] = "TUE";
	weekname['C'] = "WED";
	weekname['D'] = "THU";
	weekname['E'] = "FRI";
	weekname['F'] = "SAT";
	weekname['A'] = "SUN";
	day = weekname[a1];
	hour['0']  = "0";
	hour['1']  = "1";
	hour['2']  = "2";
	hour['3']  = "3";
	hour['4']  = "4";
	hour['5']  = "5";
	hour['6']  = "6";
	hour['7']  = "7";
	hour['8']  = "8";
	hour['9']  = "9";
	hour['A']  = "10";
	hour['B']  = "11";
	hour['C']  = "12";
	hour['D']  = "13";
	hour['E']  = "14";
	hour['F']  = "15";
	hour['G']  = "16";
	hour['H']  = "17";
	hour['I']  = "18";
	hour['J']  = "19";
	hour['K']  = "20";
	hour['L']  = "21";
	hour['M']  = "22";
	hour['N']  = "23";
	hh = hour[b1];
	cout<<day<<' ';
	cout.width(2);
	cout.fill('0');
	cout<<hh<<':';
    cout.width(2);
    cout.fill('0');
	cout<<c1;
}