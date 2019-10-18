#include<iostream>

using namespace std;

int ary[11][11] = { 0, };
int mindep = 26;
int paper[6] = { 5, 5, 5, 5, 5, 5 };
void solve(int dep);
int main()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> ary[i][j];

	solve(0);
	if (mindep == 26)
		mindep = -1;
	cout << mindep << endl;
	return 0;
}

void solve(int dep) {
	if (dep == mindep)
		return;

	int r, c, maxsize = 5;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (ary[i][j] == 1) {
				r = i;
				c = j;
				for (int t = 2; t <= 5; t++)
					for (int a = 0; a < t; a++)
						for (int b = 0; b < t; b++)
							if (ary[r + a][c + b] == 0) {
								maxsize = t - 1;
								goto here;
							}
				goto here;
			}
		}
		if (i == 9) {
			if (mindep > dep)
				mindep = dep;
			return;
		}
	}
here:

	for (int i = maxsize; i >= 1; i--) {
		if (paper[i] == 0)
			continue;
		paper[i]--;
		for (int a = 0; a < i; a++)
			for (int b = 0; b < i; b++)
				ary[r + a][c + b] = 0;

		solve(dep + 1);
		paper[i]++;
		for (int a = 0; a < i; a++)
			for (int b = 0; b < i; b++)
				ary[r + a][c + b] = 1;
	}
}