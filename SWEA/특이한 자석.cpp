#include<iostream>
#include<math.h>

using namespace std;

int gear[4][8];

void function(int p, int dir, int* pos, int* isturn);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int K;
		int point = 0;
		int pos[4] = { 0, 0, 0, 0 };
		int turn[20][2];
		cin >> K;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 8; j++)
				cin >> gear[i][j];
		for (int i = 0; i < K; i++) {
			cin >> turn[i][0] >> turn[i][1];
			turn[i][0]--;
		}


		for (int i = 0; i < K; i++) {
			int isturn[4] = { 0 , };
			function(turn[i][0], turn[i][1], pos, isturn);
		}

		for (int j = 0; j < 4; j++) {
			if (gear[j][pos[j]] == 1)
				point += (int)pow(2, j);
		}

		cout << "#" << test_case << " ";
		cout << point << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void function(int p, int dir, int* pos, int* isturn) {
	if (isturn[p] == 1)
		return;
	isturn[p] = 1;
	int pre_right;
	int next_left;
	int now_right = pos[p] + 2 >= 8 ? pos[p] - 6 : pos[p] + 2;
	int now_left = pos[p] - 2 < 0 ? pos[p] + 6 : pos[p] - 2;
	if (p > 0) {
		pre_right = pos[p - 1] + 2 >= 8 ? pos[p - 1] - 6 : pos[p - 1] + 2;
		if (gear[p - 1][pre_right] != gear[p][now_left])
			function(p - 1, dir*-1, pos, isturn);
	}
	if (p < 3) {
		next_left = pos[p + 1] - 2 < 0 ? pos[p + 1] + 6 : pos[p + 1] - 2;
		if (gear[p + 1][next_left] != gear[p][now_right])
			function(p + 1, dir*-1, pos, isturn);
	}
	pos[p] += dir*-1;
	if (pos[p] >= 8)
		pos[p] -= 8;
	else if (pos[p] < 0)
		pos[p] += 8;
	return;
}