#include<iostream>

using namespace std;

struct node {
	int x, y;
	int road;
	int h;
	bool is;
};

int N, K;
int ary[8][8];
int check[8][8];
int plusx[4] = { -1, 1, 0, 0 };
int plusy[4] = { 0, 0, -1, 1 };

int function(node top);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	int i, j;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		int max = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				cin >> ary[i][j];
				check[i][j] = 0;
				if (max < ary[i][j])
					max = ary[i][j];
			}
		}

		node input;
		int max_road = 0, temp;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (max == ary[i][j]) {
					input.x = i;
					input.y = j;
					input.road = 1;
					input.h = ary[i][j];
					input.is = true;
					temp = function(input);
					if (max_road < temp)
						max_road = temp;
				}
			}
		}
		cout << "#" << test_case << " ";
		cout << max_road << endl;
	}
	system("pause");
	return 0;
}

int function(node temp) {
	node top;
	int tempi, tempj;
	int max = 0;
	int f = 0;

	check[temp.x][temp.y] = 1;
	for (int k = 0; k < 4; k++) {
		top = temp;
		tempi = temp.x + plusx[k];
		tempj = temp.y + plusy[k];
		if (tempi < 0 || tempi >= N || tempj < 0 || tempj >= N)
			continue;

		if (ary[tempi][tempj] < top.h) {
			top.x = tempi;	top.y = tempj;
			top.road++;
			top.h = ary[tempi][tempj];
			f = function(top);
		}
		else if (top.is && ary[tempi][tempj] - top.h < K && check[tempi][tempj] == 0) {
			top.is = false;
			top.x = tempi;	top.y = tempj;
			top.road++;
			top.h--;
			f = function(top);
		}
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << check[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			if (max < top.road)
				max = top.road;
		}
		if (max < f)
			max = f;
	}
	check[temp.x][temp.y] = 0;
	return max;
}
