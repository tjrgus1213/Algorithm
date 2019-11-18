#include <iostream>
#include <set>

using namespace std;

void find_way(int num, int x, int y, int cnt);

set<int> s;
int ary[4][4];
int px[4] = { 0, 0, -1, 1 };
int py[4] = { -1, 1, 0, 0 };

int main() {
	int test_case;
	cin >> test_case;

	for (int T = 1; T <= test_case; T++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> ary[i][j];

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				find_way(0, i, j, 0);

		cout << "#" << T << " ";
		cout << s.size() << endl;
		s.clear();
	}
	return 0;
}

void find_way(int num, int x, int y, int cnt) {
	num = num * 10 + ary[x][y];
	cnt++;
	if (cnt == 7) {
		s.insert(num);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (x + px[i] < 0 || x + px[i] > 3 || y + py[i] < 0 || y + py[i] > 3)
				continue;

			find_way(num, x + px[i], y + py[i], cnt);
		}
	}
}