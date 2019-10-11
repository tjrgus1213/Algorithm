#include<iostream>

using namespace std;

int N, M, H;
int ladder[11][31] = { 0, };
int tmin = 5;

void make_ladder(int r, int c, int cnt);
bool check_ladder();

int main()
{
	cin >> N >> M >> H;

	int pos, h;
	for (int i = 0; i < M; i++) {
		cin >> h >> pos;
		ladder[pos][h] = 1;
	}

	if (check_ladder())
		tmin = 0;
	else {
		make_ladder(1, 1, 1);
		if (tmin == 5)
			tmin = -1;
	}

	cout << tmin << endl;
	return 0;
}

void make_ladder(int r, int c, int cnt) {
	if (cnt == 4)
		return;

	int i, j;
	for (i = r; i < N; i++) {
		if (i == r)
			j = c;
		else
			j = 1;

		for (; j <= H; j++) {
			if (ladder[i][j] == 0) {
				if (ladder[i - 1][j] == 1 || ladder[i + 1][j] == 1)
					continue;

				ladder[i][j] = 1;
				if (check_ladder()) {
					if (tmin > cnt)
						tmin = cnt;
				}
				else if(cnt < 3) {
					if (j != H)
						make_ladder(i, j + 1, cnt + 1);
					else
						make_ladder(i + 1, 1, cnt + 1);
				}
				ladder[i][j] = 0;
			}
		}
	}
}

bool check_ladder() {
	int pos;
	for (int i = 1; i <= N; i++) {
		pos = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[pos][j] == 1)
				pos++;
			else if (ladder[pos - 1][j] == 1) 
				pos--;
		}

		if (i != pos)
			return false;
	}
	return true;
}