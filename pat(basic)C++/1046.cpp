#include <iostream>

using namespace std;
int main(void) {
	int round;
	cin >> round;
	int jiahan, jiahua, yihan, yihua = 0;
	int jiaying =0 ,yiying = 0;
	int sum;
	for (int index = 0; index < round; index++) {
		cin >> jiahan >> jiahua >> yihan >> yihua;
		sum = jiahan + yihan;
		if (sum == jiahua&& sum!=yihua) {
			jiaying++;
		}
		if (sum != jiahua && sum == yihua) {
			yiying++;
		}
	}
	cout << yiying << ' ' << jiaying;
}
