#include<iostream>

using namespace std;


int distances[500][500];
int number_of_city;
int number_of_roads;
int startcity;
int endcity;
int visit[500] = {0};
int mindis[500] = {0};
int number_of_rescue_teams[500];
int rescuenumber[500];
int number_count[500] = {0};

void dijkstra(int indexcity) {
    while (indexcity != endcity) {
        for (int i = 0; i < number_of_city; i++) {
            if (visit[i] == 0 && distances[indexcity][i] != 999999) {
                if (mindis[i] > mindis[indexcity] + distances[i][indexcity]) {
                    number_count[i] = number_count[indexcity];
                    mindis[i] = mindis[indexcity] + distances[i][indexcity];
                    rescuenumber[i] = rescuenumber[indexcity] + number_of_rescue_teams[i];
                } else if (mindis[i] == mindis[indexcity] + distances[i][indexcity]) {
                    number_count[i] += number_count[indexcity];
                    if (rescuenumber[i] < rescuenumber[indexcity] + number_of_rescue_teams[i]) {
                        rescuenumber[i] = rescuenumber[indexcity] + number_of_rescue_teams[i];
                    }
                }
            }
        }
        int mincity = 500;
        int mindiss = 999999;
        for (int j = 0; j < number_of_city; j++) {
            if (visit[j] == 0 && mindis[j] < mindiss) {
                mincity = j;
                mindiss = mindis[j];
            }
        }
        visit[mincity] = 1;
        indexcity = mincity;
    }
}


int main() {
    cin >> number_of_city >> number_of_roads >> startcity >> endcity;
    for (int i = 0; i < number_of_city; i++) {
        cin >> number_of_rescue_teams[i];
    }
    for (int j = 0; j < number_of_city; j++) {
        for (int i = 0; i < number_of_city; i++) {
            distances[j][i] = 999999;
        }
    }


    for (int i = 0; i < number_of_roads; i++) {
        int city1;
        int city2;
        int index_distance;
        cin >> city1 >> city2 >> index_distance;
        distances[city1][city2] = distances[city2][city1] = index_distance;
    }

    for (int i = 0; i < number_of_city; i++) {
        mindis[i] = 999999;
    }

    visit[startcity] = 1;
    mindis[startcity] = 0;
    rescuenumber[startcity] = number_of_rescue_teams[startcity];
    number_count[startcity] = 1;
    dijkstra(startcity);
    cout << number_count[endcity] << ' ' << rescuenumber[endcity];
}