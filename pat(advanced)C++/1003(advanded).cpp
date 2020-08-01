#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c1, c2;//n为城市的数量，m为路径数量，c1是出发地，c2是目的地
int e[510][510], weight[510], dis[510], num[510], w[510];//e为邻接矩阵，记录任意两个城市之间的距离，weight数组是每个城市搜救队伍的数量，dis数组为出发点到该点的最短距离，num数组为出发点到该点最短路径的条数，w数组为出发点到该点最短路径下的最多救援队个数
bool visit[510];//该数组未经过初始化？？？可能是默认true//vist数组表示是否被选入最短路径
const int inf = 99999999;
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);//遍历赋值第一行数据
    for(int i = 0; i < n; i++)//遍历并赋值第二行数据
        scanf("%d", &weight[i]);
    fill(e[0], e[0] + 510 * 510, inf);//将数组e的510*510个单元格全部啊赋值成inf
    fill(dis, dis + 510, inf);//将距离数组全部赋值为无穷
    int a, b, c;//a,b为城市，c为a，b两个城市之间的距离
    for(int i = 0; i < m; i++) {遍历赋值给数组e
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;//因为是无向图，因此邻接矩阵关于斜对角对称
    }
    dis[c1] = 0;//将出发地的距离赋值为0
    w[c1] = weight[c1];//出发点并入最短路径，并将救援队数量加入总和
    num[c1] = 1;//初始路径数量为1
    for(int i = 0; i < n; i++) {//该for循环选出未被并入最短路径的结点
        int u = -1,   = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];//
            }
        }
        if(u == -1) break;//判断是否有新结点并入最短路径，如果没有则退出循环，打印结果
        for(int v = 0; v < n; v++) {//遍历未被并入最短路径的结点，刷新各个数值
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {//距离更短的情况下，刷新距离以及救援队数量
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if(dis[u] + e[u][v] == dis[v]) {//距离长短一样的情况下，比较救援队数量，如果更少就刷新
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}