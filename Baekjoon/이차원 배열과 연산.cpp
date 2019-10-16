#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int R, C, K;
	int ary[101][101] = { 0, };
	int numlist[101][101];
	int numcnt[101], listsize[101];
	cin >> R >> C >> K;

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> ary[i][j];

	int time = 0;
	int nr = 3, nc = 3, tr, tc;
	while (ary[R][C] != K) {
		if (nr >= nc) {
			tc = 0;
			for (int r = 1; r <= nr; r++) {
				memset(numcnt, 0, sizeof(numcnt));
				memset(listsize, 0, sizeof(listsize));
				for (int c = 1; c <= nc; c++) {
					numcnt[ary[r][c]]++;
				}
				int temp = nc, i = 1, j;
				while (temp > 0 && i <= 100) {
					if (numcnt[i] == 0) {
						i++;
						continue;
					}
					j = 0;
					while (listsize[numcnt[i]] > j && numlist[numcnt[i]][j] < i)
						j++;
					for (int x = listsize[numcnt[i]] - 1; x >= j; x--)
						numlist[numcnt[i]][x + 1] = numlist[numcnt[i]][x];
					numlist[numcnt[i]][j] = i;
					listsize[numcnt[i]]++;
					temp -= numcnt[i];
					i++;
				}

				temp = 0;
				for (i = 1; i <= 100; i++) {
					if (listsize[i] == 0)
						continue;
					for (j = 0; j < listsize[i]; j++) {
						temp++;
						ary[r][temp] = numlist[i][j];
						temp++;
						ary[r][temp] = i;
					}
				}
				if (tc < temp)
					tc = temp;
				while (++temp <= nc) {
					ary[r][temp] = 0;
				}
				
			}
			nc = tc;
		}
		else {
			tr = 0;
			for (int c = 1; c <= nc; c++) {
				memset(numcnt, 0, sizeof(numcnt));
				memset(listsize, 0, sizeof(listsize));
				for (int r = 1; r <= nr; r++) {
					numcnt[ary[r][c]]++;
				}
				int temp = nr, i = 1, j;
				while (temp > 0 && i <= 100) {
					if (numcnt[i] == 0) {
						i++;
						continue;
					}
					j = 0;
					while (listsize[numcnt[i]] > j && numlist[numcnt[i]][j] < i)
						j++;
					for (int x = listsize[numcnt[i]] - 1; x >= j; x--)
						numlist[numcnt[i]][x + 1] = numlist[numcnt[i]][x];
					numlist[numcnt[i]][j] = i;
					listsize[numcnt[i]]++;
					temp -= numcnt[i];
					i++;
				}

				temp = 0;
				for (i = 1; i <= 100; i++) {
					if (listsize[i] == 0)
						continue;
					for (j = 0; j < listsize[i]; j++) {
						temp++;
						ary[temp][c] = numlist[i][j];
						temp++;
						ary[temp][c] = i;
					}
				}
				if (tr < temp)
					tr = temp;
				while (++temp <= nr) {
					ary[temp][c] = 0;
				}

			}
			nr = tr;
		}
		time++;
		if (time == 101) {
			time = -1;
			break;
		}
	}
	cout << time << endl;
	return 0;
}