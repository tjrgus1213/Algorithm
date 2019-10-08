#include<iostream>

using namespace std;

int N;
int number[10];
char cal[9];
int tmax = -2100000000;

void func(int pos, int sum);
int calculation(int a, int b, char c);

int main()
{
	int i;
	cin >> N;
	N /= 2;
	for (i = 0; i < N; i++) {
		cin >> number[i];
		cin >> cal[i];
	}
	cin >> number[i];

	func(0, 0);
	cout << tmax << endl;
	return 0;
}

void func(int pos, int sum) {
	if (pos > N) {
		if (tmax < sum)
			tmax = sum;
		return;
	}
	if (pos == 0) {
		func(pos + 1, number[0]);
		func(pos + 2, calculation(number[0], number[1], cal[0]));
	}
	else {
		func(pos + 1, calculation(sum, number[pos], cal[pos - 1]));
		if (pos <= N - 1) {
			func(pos + 2, calculation(sum, calculation(number[pos], number[pos + 1], cal[pos]), cal[pos - 1]));
		}
	}
}


int calculation(int a, int b, char c) {
	switch (c) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
	return 0;
}