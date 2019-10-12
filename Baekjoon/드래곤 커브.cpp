#include<iostream>
#include<vector>

using namespace std;

int map[101][101] = { 0, };
int plusx[4] = { 1, 0, -1, 0 };
int plusy[4] = { 0, -1, 0, 1 };

void make_curve(int r, int c, int dir, int gen);

int main()
{
	int N;

	cin >> N;
	int r, c, dir, gen;
	for (int i = 0; i < N; i++) {
		cin >> c >> r >> dir >> gen;
		make_curve(r, c, dir, gen);
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++) 
		for (int j = 0; j < 100; j++) 
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1 && map[i + 1][j] == 1) 
				cnt++;
	
	cout << cnt << endl;
	return 0;
}

void make_curve(int r, int c, int dir, int gen) {
	vector<int> temp;
	temp.push_back(dir);
	int size, d;
	for (int g = 1; g <= gen; g++) {
		size = temp.size();
		for (int i = size - 1; i >= 0; i--) {
			d = temp[i];
			d = (d + 1) % 4;
			temp.push_back(d);
		}
	}

	map[r][c] = 1;
	for (int i = 0; i < temp.size(); i++) {
		r += plusy[temp[i]];
		c += plusx[temp[i]];
		map[r][c] = 1;
	}
}