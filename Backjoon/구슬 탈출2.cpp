#include<iostream>
#include<map>

using namespace std;

int N, M;
char ary[10][10];
int check[10][10][10][10];
int function(pair<int, int> r, pair<int, int> b, int cnt);
int main()
{
	pair<int, int> red, blue;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ary[i][j];
			if (ary[i][j] == 'R') {
				red.first = i;
				red.second = j;
			}
			else if (ary[i][j] == 'B') {
				blue.first = i;
				blue.second = j;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				for (int x = 0; x < 10; x++)
					check[i][j][k][x] = 10000;

	int temp = function(red, blue, 0);
	if (temp >= 10)
		temp = -1;
	cout << temp << endl;
	system("pause");
	return 0;
}

int function(pair<int, int> r, pair<int, int> b, int cnt) {
	int i, j;
	bool rin, bin;
	int min = 10000;
	int temp;
	cnt++;
	check[r.first][r.second][b.first][b.second] = cnt;
	//up
	rin = false;	bin = false;
	for (i = r.first; i >= 0; i--) {
		if (ary[i][r.second] == '#') {
			i++;
			break;
		}
		else if (ary[i][r.second] == 'O') {
			rin = true;
			break;
		}
	}
	for (j = b.first; j >= 0; j--) {
		if (ary[j][b.second] == '#') {
			j++;
			break;
		}
		else if (ary[j][b.second] == 'O') {
			bin = true;
			break;
		}
	}
	if (rin && !bin)
		return cnt;
	if (i == j && r.second == b.second) {
		if (r.first > b.first)
			i++;
		else
			j++;
	}
	if (!bin && check[i][r.second][j][b.second] > cnt) {
		temp = function(make_pair(i, r.second), make_pair(j, b.second), cnt);
		if (min > temp)
			min = temp;
	}

	//down
	rin = false;	bin = false;
	for (i = r.first; i < N; i++) {
		if (ary[i][r.second] == '#') {
			i--;
			break;
		}
		else if (ary[i][r.second] == 'O') {
			rin = true;
			break;
		}
	}
	for (j = b.first; j < N; j++) {
		if (ary[j][b.second] == '#') {
			j--;
			break;
		}
		else if (ary[j][b.second] == 'O') {
			bin = true;
			break;
		}
	}
	if (rin && !bin)
		return cnt;
	if (i == j && r.second == b.second) {
		if (r.first > b.first)
			j--;
		else
			i--;
	}
	if (!bin && check[i][r.second][j][b.second] > cnt) {
		temp = function(make_pair(i, r.second), make_pair(j, b.second), cnt);
		if (min > temp)
			min = temp;
	}

	//left
	rin = false;	bin = false;
	for (i = r.second; i >= 0; i--) {
		if (ary[r.first][i] == '#') {
			i++;
			break;
		}
		else if (ary[r.first][i] == 'O') {
			rin = true;
			break;
		}
	}
	for (j = b.second; j >= 0; j--) {
		if (ary[b.first][j] == '#') {
			j++;
			break;
		}
		else if (ary[b.first][j] == 'O') {
			bin = true;
			break;
		}
	}
	if (rin && !bin)
		return cnt;
	if (i == j && r.first == b.first) {
		if (r.second > b.second)
			i++;
		else
			j++;
	}
	if (!bin && check[r.first][i][b.first][j] > cnt) {
		temp = function(make_pair(r.first, i), make_pair(b.first, j), cnt);
		if (min > temp)
			min = temp;
	}

	//right
	rin = false;	bin = false;
	for (i = r.second; i < M; i++) {
		if (ary[r.first][i] == '#') {
			i--;
			break;
		}
		else if (ary[r.first][i] == 'O') {
			rin = true;
			break;
		}
	}
	for (j = b.second; j < M; j++) {
		if (ary[b.first][j] == '#') {
			j--;
			break;
		}
		else if (ary[b.first][j] == 'O') {
			bin = true;
			break;
		}
	}
	if (rin && !bin)
		return cnt;
	if (i == j && r.first == b.first) {
		if (r.second > b.second)
			j--;
		else
			i--;
	}
	if (!bin && check[r.first][i][b.first][j] > cnt) {
		temp = function(make_pair(r.first, i), make_pair(b.first, j), cnt);
		if (min > temp)
			min = temp;
	}

	return min;
}