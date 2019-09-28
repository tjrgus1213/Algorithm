#include<iostream>

using namespace std;

int plusx[4] = { 0, 0, -1, 1 };
int plusy[4] = { 1, -1, 0, 0 };
int atom[1000][3];
int work[1000];
float ptime[1000];
int num;
int total_work;

float function(int i, float t);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		total_work = 0;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> atom[i][0] >> atom[i][1] >> atom[i][2];
			cin >> work[i];
			ptime[i] = 0;
		}

		for (int i = 0; i < num; i++) {
			function(i, 10000);
		}

		cout << "#" << test_case << " ";
		cout << total_work << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

float function(int i, float t) {
	float temp;
	float min = 10000;
	int min_pos = -1;

	if (ptime[i] > 0)
		return ptime[i];

	if (atom[i][2] <= 1) {
		for (int j = 0; j < num; j++) {
			if (i == j)
				continue;

			if (atom[j][2] <= 1) {
				if (atom[i][0] == atom[j][0] && atom[i][2] != atom[j][2]) {
					temp = atom[i][1] > atom[j][1] ? (atom[i][1] - atom[j][1]) * plusy[atom[j][2]] : (atom[j][1] - atom[i][1]) * plusy[atom[i][2]];
					temp /= 2;
					if (temp >= t)
						continue;
					if (temp < 0)
						continue;
					if (temp == ptime[j] || temp == function(j, temp)) {
						if (min > temp) {
							min = temp;
							min_pos = j;
						}
					}
				}
				else
					continue;
			}
			else {
				temp = (atom[i][0] - atom[j][0]) * plusx[atom[j][2]];
				int movey = (atom[j][1] - atom[i][1]) * plusy[atom[i][2]];
				if (temp == movey && temp > 0) {
					if (temp >= t)
						continue;
					if (temp == ptime[j] || temp == function(j, temp)) {
						if (min > temp) {
							min = temp;
							min_pos = j;
						}
					}
				}
			}
		}
	}
	else {
		for (int j = 0; j < num; j++) {
			if (i == j)
				continue;

			if (atom[j][2] > 1) {
				if (atom[i][1] == atom[j][1] && atom[i][2] != atom[j][2]) {
					temp = atom[i][0] > atom[j][0] ? (atom[i][0] - atom[j][0]) * plusx[atom[j][2]] : (atom[j][0] - atom[i][0]) * plusx[atom[i][2]];
					temp /= 2;
					if (temp >= t)
						continue;
					if (temp < 0)
						continue;
					if (temp == ptime[j] || temp == function(j, temp)) {
						if (min > temp) {
							min = temp;
							min_pos = j;
						}
					}
				}
				else
					continue;
			}
			else {
				temp = (atom[j][0] - atom[i][0]) * plusx[atom[i][2]];
				int movey = (atom[i][1] - atom[j][1]) * plusy[atom[j][2]];
				if (temp == movey && temp > 0) {
					if (temp >= t)
						continue;
					if (temp == ptime[j] || temp == function(j, temp)) {
						if (min > temp) {
							min = temp;
							min_pos = j;
						}
					}
				}
			}
		}
	}

	if (min_pos != -1) {
		total_work += work[i];
		total_work += work[min_pos];
		work[i] = 0;
		work[min_pos] = 0;
		ptime[i] = min;
		ptime[min_pos] = min;

		return min;
	}

	return t;
}