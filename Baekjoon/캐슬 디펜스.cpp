#include<iostream>
#include<vector>

using namespace std;

struct enemy {
	int r, c;
	enemy(int a, int b) : r(a), c(b) {};
};

int N, M, D;
vector<enemy> elist;
vector<enemy> templist;

int main()
{
	cin >> N >> M >> D;
	int temp;
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			if (temp == 1)
				elist.push_back(enemy(i, j));
		}
	}

	int d1, d2, d3;
	int l1, l2, l3, templ;
	bool is;
	int maxcnt = 0, tcnt;
	for (int a = 0; a < M - 2; a++) {
		for (int b = a + 1; b < M - 1; b++) {
			for (int c = b + 1; c < M; c++) {
				tcnt = 0;
				templist.assign(elist.begin(), elist.end());
				while (true) {
					is = true;
					d1 = -1;	d2 = -1;	d3 = -1;
					l1 = 100;	l2 = 100;	l3 = 100;
					for (int i = 0; i < templist.size(); i++) {
						if (templist[i].r == N)
							continue;
						is = false;
						templ = (N - templist[i].r) + abs(a - templist[i].c);
						if (templ <= D && (templ < l1 || (templ == l1 && templist[d1].c > templist[i].c))) {
							d1 = i;
							l1 = templ;
						}
						
						templ = (N - templist[i].r) + abs(b - templist[i].c);
						if (templ <= D && (templ < l2 || (templ == l2 && templist[d2].c > templist[i].c))) {
							d2 = i;
							l2 = templ;
						}

						templ = (N - templist[i].r) + abs(c - templist[i].c);
						if (templ <= D && (templ < l3 || (templ == l3 && templist[d3].c > templist[i].c))) {
							d3 = i;
							l3 = templ;
						}
						templist[i].r++;
					}
					if (is)
						break;
					if (d1 != -1) {
						templist[d1].r = N;
						tcnt++;
					}
					if (d2 != -1 && d2 != d1) {
						templist[d2].r = N;
						tcnt++;
					}
					if (d3 != -1 && d3 != d2 && d3 != d1) {
						templist[d3].r = N;
						tcnt++;
					}
				}
				if (maxcnt < tcnt)
					maxcnt = tcnt;

			}
		}
	}
	cout << maxcnt << endl;
	return 0;
}