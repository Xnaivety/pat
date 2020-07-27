#include <iostream>
using namespace std;
int main() {
    float c[1001] = {0};//根据指数建立数组，数组内容为相应的系数
    int m, n, t;//m，n分别为两列的系数个数，t为指数变量
    float num;//num为系数变量
    
    //两次循环读入指数和系数
    scanf("%d", &m);//读入项数个数
    for (int i = 0; i < m; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    scanf("%d", &n);//读入项数个数
    for (int i = 0; i < n; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }

    int cnt = 0;//cnt为总项数
    for (int i = 0; i < 1001; i++) {  //计算出非零项项数的个数
        if (c[i] != 0) cnt++;
    }

    printf("%d", cnt);//输出求和之后的项数个数

    for (int i = 1000; i >= 0; i--) {//降幂输出多项式的指数和系数
        if (c[i] != 0.0)
            printf(" %d %.1f", i, c[i]);
    }

    return 0;
}