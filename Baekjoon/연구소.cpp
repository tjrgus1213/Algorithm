#include<iostream>
#include<stack>

using namespace std;

int N, M;
int ary[64];
int plusx[4] = { -1, 1, 0, 0 };
int plusy[4] = { 0, 0, -1, 1 };
stack<int> virus_pos;

int check(stack<int> pos);

int main()
{
	cin >> N >> M;
	int max = 0;
	int i, j, k;
	for (i = 0; i < N * M; i++) {
		cin >> ary[i];
		if (ary[i] == 2)
			virus_pos.push(i);
	}

	int temp;
	for (i = 0; i < N * M; i++) {
		if (ary[i] != 0)
			continue;
		ary[i] = 1;
		for (j = i + 1; j < N * M; j++) {
			if (ary[j] != 0)
				continue;
			ary[j] = 1;
			for (k = j + 1; k < N * M; k++) {
				if (ary[k] != 0)
					continue;
				ary[k] = 1;
				temp = check(virus_pos);
				if (max < temp)
					max = temp;
				ary[k] = 0;
			}
			ary[j] = 0;
		}
		ary[i] = 0;
	}

	cout << max << endl;
	system("pause");
	return 0;
}


int check(stack<int> pos) {
	int i;
	int x, tx;
	while (!pos.empty()) {
		x = pos.top();
		pos.pop();

		for (i = 0; i < 4; i++) {
			tx = x + (plusx[i] * M) + plusy[i];
			if (plusx[i] == 0 && x / M != tx / M)
				continue;
			if (tx < 0 || tx >= N*M)
				continue;

			if (ary[tx] == 0) {
				ary[tx] = 3;
				pos.push(tx);
			}
		}
	}

	x = 0;
	for (i = 0; i < N * M; i++) {
		if (ary[i] == 0)
			x++;
		else if (ary[i] == 3)
			ary[i] = 0;
	}

	return x;
}