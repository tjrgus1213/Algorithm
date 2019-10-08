#include<iostream>

using namespace std;

int N;
int number[11];
int cal[4];
int tmax = -200000000, tmin = 200000000;

void func(int num, int dep);

int main()
{
	int i;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> number[i];
	for (i = 0; i < 4; i++)
		cin >> cal[i];

	func(number[0], 1);

	cout << tmax << endl;
	cout << tmin << endl;
	system("pause");
	return 0;
}

void func(int num, int dep) {
	if (dep == N) {
		if (tmax < num)
			tmax = num;
		if (tmin > num)
			tmin = num;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cal[i] == 0)
			continue;

		switch (i) {
		case 0:
			cal[i]--;
			func(num + number[dep], dep + 1);
			cal[i]++;
			break;

		case 1:
			cal[i]--;
			func(num - number[dep], dep + 1);
			cal[i]++;
			break;

		case 2:
			cal[i]--;
			func(num * number[dep], dep + 1);
			cal[i]++;
			break;

		case 3:
			cal[i]--;
			func(num / number[dep], dep + 1);
			cal[i]++;
			break;
		}
	}
}