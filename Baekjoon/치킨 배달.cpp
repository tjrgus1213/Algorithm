#include<iostream>
#include<vector>

using namespace std;

int N, M, tmin = 100000000;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

void func(int chi[][2], int pos, int cnt);

int main()
{
	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 1)
				home.push_back(make_pair(i, j));
			else if (temp == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	int chi[20][2];
	func(chi, 0, 0);
	cout << tmin << endl;
	return 0;
}

void func(int chi[][2], int pos, int cnt) {
	if (cnt == M) {
		int tm, dis, total = 0;
		for (int i = 0; i < home.size(); i++) {
			tm = 1000;
			for (int j = 0; j < cnt; j++) {
				dis = abs(home[i].first - chi[j][0]) + abs(home[i].second - chi[j][1]);
				if (tm > dis)
					tm = dis;
			}
			total += tm;
		}
		if (tmin > total)
			tmin = total;
		return;
	}
	for (int i = pos; i < chicken.size(); i++) {
		chi[cnt][0] = chicken[i].first;
		chi[cnt][1] = chicken[i].second;
		func(chi, i + 1, cnt + 1);
	}
}