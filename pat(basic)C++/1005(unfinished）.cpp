#include<iostream>
using namespace std;
int main() {
    int count1;
    cin >> count1;
    const int count = count1;
    int index[count];
    int j = 0;
    int Callatz[1000] = {0};
    while (count1--) {
        cin >> index[j];
        j++;
    }
    for (int i = 0; i < count; i++) {
        if (index[i] != 0) {
            int a = index[i];
            int b = 0;
            Callatz[b] = a;
            while (a != 1) {
                if (a % 2 == 0) {
                    a = a / 2;
                } else {
                    a = (3 * a + 1) / 2;
                }
                b++;
                Callatz[b] = a;
            }
            for (j = 1; j < b; j++) {
                for (int k = 0; k < count; k++) {
                    if(k == index[i]) continue;
                    if (Callatz[j] == index[k]) {
                        index[k] = 0;
                    }
                }
            }
        }
    }
    for(int m = 0;m<count;m++){
        if(index[m]!=0){
            if(m!=0){
                cout<<' ';
            }
            cout<<index[m];
        }
    }
    return 0;
}