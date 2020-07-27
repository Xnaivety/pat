#include<iostream>
using namespace std;
int main(){
    int number;
    cin>>number;
    int numbers = number;
    int sequence[10001] = {0};
    int sum[10001] = {0};
    int best_answer[10001];
    int cursor = 1;

    int bestsum[10001];
    int bestonesum = -999999;
    int j = -1;
    sum[0] = 0;
    for(int k = 0;k<=10000;k++){
        bestsum[k] = -999999;
        best_answer[k] = -1;
    }
    while(number--){
        // scanf("%d ",&sequence[cursor]);
        cin>>sequence[cursor];
        if(cursor == 1){
            sum[1] = sequence[1];
        }
        else{
            sum[cursor] = sum[cursor-1]+sequence[cursor];
        }
        cursor++;
    }
    for(int i = 1;i<=numbers;i++){
        int min = 999999;
        for(int j = 0;j<i;j++){
            if(sum[j]<min){
                min = sum[j];
                best_answer[i] = j;
                bestsum[i] = sum[i]-min;
            }
        }
    }
    int k;
    int o = -1;
    for(k = 1;k<=numbers;k++){
        if(bestonesum<bestsum[k]){
            bestonesum = bestsum[k];
            j = best_answer[k];
            o = k;
        }
    }
    if(bestonesum<0){
        cout<<0<<' '<<sequence[1]<<' '<<sequence[numbers];
    }
    else{
        cout<<bestonesum<<' '<<sequence[j+1]<<' '<<sequence[o];
    }
}