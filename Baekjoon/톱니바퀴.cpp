#include<iostream>
#include<math.h>

using namespace std;

int gear[4][8];
void func(int pos, int dir, int lr);
int main()
{
	int K, temp;

	for (int i = 0; i < 4; i++) {
		cin >> temp;
		for (int j = 7; j >= 0; j--) {
			gear[i][j] = temp % 10;
			temp /= 10;
		}
	}

	cin >> K;
	int pos, dir;
	for (int i = 0; i < K; i++) {
		cin >> pos >> dir;
		func(pos - 1, dir, 0);
	}
	int sum = 0;
	for (int i = 0; i < 4; i++)
		if (gear[i][0] == 1)
			sum += (int)pow(2, i);

	cout << sum << endl;
	return 0;
}

void func(int pos, int dir, int lr) {
	if (pos < 3 && lr != -1) {
		if (gear[pos][2] != gear[pos + 1][6])
			func(pos + 1, dir * -1, 1);
	}
	if (pos > 0 && lr != 1) {
		if (gear[pos][6] != gear[pos - 1][2])
			func(pos - 1, dir * -1, -1);
	}

	int temp;
	if (dir == 1) {
		temp = gear[pos][7];
		for (int i = 7; i > 0; i--) {
			gear[pos][i] = gear[pos][i - 1];
		}
		gear[pos][0] = temp;
	}
	else {
		temp = gear[pos][0];
		for (int i = 0; i < 7; i++) {
			gear[pos][i] = gear[pos][i + 1];
		}
		gear[pos][7] = temp;
	}
}