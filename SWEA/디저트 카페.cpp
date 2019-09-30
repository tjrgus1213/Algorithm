#include<iostream>
#include<set>

using namespace std;

int N;
int ary[20][20];
int find_way(int x, int y);
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	int i, j;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				cin >> ary[i][j];

		int max = -1;
		int temp;
		for (i = 0; i < N - 2; i++) {
			for (j = 1; j < N - 1; j++) {
				temp = find_way(i, j);
				max = max < temp ? temp : max;
			}
		}
		cout << "#" << test_case << " ";
		cout << max << endl;
	}
	return 0;
}

int find_way(int x, int y) {
	int i, j, a;
	int tx, ty;
	int temp;
	int food = 0;
	set<int> check;
	pair<set<int>::iterator, bool> is;
	i = 1;	j = 1;
	while (true) {
		tx = x;
		ty = y;
		temp = 0;
		check.clear();
		if (i + j + x < N && y + j < N && y - i >= 0) {
			for (a = 1; a <= i; a++) {
				tx += 1;	ty -= 1;
				is = check.insert(ary[tx][ty]);
				if (is.second)
					temp++;
				else
					goto jump;
			}
			for (a = 1; a <= j; a++) {
				tx += 1;	ty += 1;
				is = check.insert(ary[tx][ty]);
				if (is.second)
					temp++;
				else
					goto jump;
			}
			for (a = 1; a <= i; a++) {
				tx -= 1;	ty += 1;
				is = check.insert(ary[tx][ty]);
				if (is.second)
					temp++;
				else
					goto jump;
			}
			for (a = 1; a <= j; a++) {
				tx -= 1;	ty -= 1;
				is = check.insert(ary[tx][ty]);
				if (is.second)
					temp++;
				else
					goto jump;
			}
			if (food < temp)
				food = temp;
		jump:
			j++;
		}
		else {
			if (j == 1)
				break;
			i++;
			j = 1;
		}
	}
	if (food == 0)
		return -1;
	return food;
}