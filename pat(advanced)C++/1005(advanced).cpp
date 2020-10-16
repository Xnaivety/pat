#include<iostream>

using namespace std;
string convert[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {

    int index;
    int sum = 0;
    index = getchar();
    while (index != '\n') {
        sum += index - '0';
        index = getchar();
    };
    string output = to_string(sum);
    for (int i = 0; i < (int) output.length(); i++) {
        if (i != 0) {
            cout << ' ';
        }
        cout << convert[output[i] - '0'];
    }
    return 0;
}