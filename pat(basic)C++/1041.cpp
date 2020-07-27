#include<iostream>
using namespace std;
struct zhun_kao_zheng;
int main(){
    int count;
    cin >> count;
    const int b = count;
    struct zhun_kao_zheng{
        string zhun_kao_zheng_hao[1000];
        int shi_ji_zuo_wei_hao[1000];
        int kao_shi_zuo_wei_hao[1000];
    };
    struct zhun_kao_zheng student;
    for(int k = 0;k<1000;k++){
        student.zhun_kao_zheng_hao[k] = "";
        student.shi_ji_zuo_wei_hao[k] = -1;
        student.kao_shi_zuo_wei_hao[k] = -1;
    }
    int index = 0;
    while (count--){
        cin >> student.zhun_kao_zheng_hao[index];
        cin >> student.shi_ji_zuo_wei_hao[index];
        cin >> student.kao_shi_zuo_wei_hao[index];
        index++;
    }
    int search_count;
    cin >> search_count;
    while (search_count--){
        int search_shi_ji;
        cin >> search_shi_ji;
        for (int j = 0;j < b;j++){
            if (student.shi_ji_zuo_wei_hao[j] == search_shi_ji){
                cout << student.zhun_kao_zheng_hao[j] << ' ' << student.kao_shi_zuo_wei_hao[j]<<endl;
                break;
            }
        }
    }
    return 0;
}