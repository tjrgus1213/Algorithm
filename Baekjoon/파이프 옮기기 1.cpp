#include<iostream>

using namespace std;

int N;
int map[16][16];

int find_way(pair<int, int> p, int dir);

int main()
{
	pair<int, int> pos = make_pair(0 ,1);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	cout << find_way(pos, 0) << endl;
	return 0;
}

int find_way(pair<int, int> p, int dir) {
	if (p.first == N - 1 && p.second == N - 1)
		return 1;

	int cnt = 0;
	switch (dir) {
	case 0: // 가로
		if (p.second + 1 < N && map[p.first][p.second + 1] == 0)
			cnt += find_way(make_pair(p.first, p.second + 1), 0);
		if (p.first + 1 < N && p.second + 1 < N)
			if (map[p.first][p.second + 1] == 0 && map[p.first + 1][p.second] == 0 && map[p.first + 1][p.second + 1] == 0)
				cnt += find_way(make_pair(p.first + 1, p.second + 1), 1);
		return cnt;
	case 1: // 대각선
		if (p.second + 1 < N && map[p.first][p.second + 1] == 0)
			cnt += find_way(make_pair(p.first, p.second + 1), 0);
		if (p.first + 1 < N && p.second + 1 < N)
			if (map[p.first][p.second + 1] == 0 && map[p.first + 1][p.second] == 0 && map[p.first + 1][p.second + 1] == 0)
				cnt += find_way(make_pair(p.first + 1, p.second + 1), 1);
		if (p.first + 1 < N && map[p.first + 1][p.second] == 0)
			cnt += find_way(make_pair(p.first + 1, p.second), 2);
		return cnt;
	case 2: // 세로
		if (p.first + 1 < N && p.second + 1 < N)
			if (map[p.first][p.second + 1] == 0 && map[p.first + 1][p.second] == 0 && map[p.first + 1][p.second + 1] == 0)
				cnt += find_way(make_pair(p.first + 1, p.second + 1), 1);
		if (p.first + 1 < N && map[p.first + 1][p.second] == 0)
			cnt += find_way(make_pair(p.first + 1, p.second), 2);
		return cnt;
	}

	return 0;
}