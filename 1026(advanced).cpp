#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;
//迎客
struct player {
    int arriving_time = 0;
    int vip = 0;
    int leaving_time = 0;
    int waiting_time = 0;
    int playing_time = 0;
};
vector<int> has_serve;
struct table {
    int count = 0;
    int vip_flag = 0;
    int servingend_time = 0;
    int isserve = 0;
};
player players[10000];
table tables[101];

bool comp(player x, player y) {
    return x.arriving_time < y.arriving_time;
}

void second_to_time(int seconds) {
    int hh;
    int mm;
    int ss;
    hh = seconds / 3600;
    mm = (seconds - hh * 3600) / 60;
    ss = seconds - 3600 * hh - 60 * mm;
    printf("%02d:%02d:%02d", hh, mm, ss);
}

int main() {
    int number_people = 0;
    cin >> number_people;
    int number_alltable;
    int number_viptable;
    int hour;
    int minute;
    int second;
    int play_time;
    int vip_tag;
    int index;
    queue<int> q1, q2;

    for (int i = 0; i < number_people; i++) {
        cin >> hour;
        getchar();
        cin >> minute;
        getchar();
        cin >> second;
        players[i].arriving_time = 3600 * hour + 60 * minute + second;
        getchar();
        cin >> play_time;
        if (play_time >= 120) {
            play_time = 120;
        }
        players[i].playing_time = play_time * 60;
        getchar();
        cin >> vip_tag;
        players[i].vip = vip_tag;
    }
    cin >> number_alltable;
    cin >> number_viptable;
    while (number_viptable--) {
        cin >> index;
        tables[index].vip_flag = 1;
    }
    sort(players, players + number_people, comp);
    int cursor = 0;
    for (int time = 28800; time < 75600; time++) {
        for (int i = 1; i <= number_alltable; i++) {
            if (tables[i].isserve == 1) {
                if (tables[i].servingend_time == time) {
                    tables[i].isserve = 0;
                }
            }
        }
        if (cursor < number_people && players[cursor].arriving_time == time) {
            q1.push(cursor);
            if (players[cursor].vip == 1) {
                q2.push(cursor);
            }
            cursor++;
        }
        while (!q2.empty() && players[q2.front()].playing_time == 0) {
            q2.pop();
        }
        for (int i = 1; i <= number_alltable; i++) {
            if (tables[i].isserve == 0 && tables[i].vip_flag == 1) {
                if (!q2.empty()) {
                    players[q2.front()].waiting_time = time - players[q2.front()].arriving_time;
                    players[q2.front()].leaving_time = time + players[q2.front()].playing_time;
                    players[q2.front()].playing_time = 0;
                    tables[i].isserve = 1;
                    tables[i].servingend_time = players[q2.front()].leaving_time;
                    tables[i].count++;
                    has_serve.emplace_back(q2.front());
                    q2.pop();
                }
            }
        }
        while (!q1.empty() && players[q1.front()].playing_time == 0) {
            q1.pop();
        }
        for (int i = 1; i <= number_alltable; i++) {
            if (tables[i].isserve == 0) {
                if (!q1.empty()) {
                    players[q1.front()].waiting_time = time - players[q1.front()].arriving_time;
                    players[q1.front()].leaving_time = time + players[q1.front()].playing_time;
                    players[q1.front()].playing_time = 0;
                    tables[i].isserve = 1;
                    tables[i].servingend_time = players[q1.front()].leaving_time;
                    tables[i].count++;
                    has_serve.emplace_back(q1.front());
                    q1.pop();
                }
            }
        }
    }
    for (int each:has_serve) {
        second_to_time(players[each].arriving_time);
        cout << ' ';
        second_to_time(players[each].arriving_time + players[each].waiting_time);
        cout << ' ';
        double m = players[each].waiting_time / 60.0 + 0.5;
        cout << (int)m << endl;
    }
    for (int i = 1; i <= number_alltable; i++) {
        if (i != 1) {
            cout << ' ';
        }
        cout << tables[i].count;
    }
    return 0;
}
