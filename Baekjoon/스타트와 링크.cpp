#include<iostream>

using namespace std;

int N, tmin = 2000000000;
int ary[20][20];
int team1[10], team2[10];

void make_team(int pre, int cnt);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ary[i][j];

	team1[0] = 0;
	make_team(1, 1);
	cout << tmin << endl;
	system("pause");
	return 0;
}

void make_team(int pre, int cnt) {
	if (cnt == N / 2) {
		int temp = 1, temp2 = 0;
		for (int i = 1; i < N; i++) {
			if (temp != N/2 && team1[temp] == i) {
				temp++;
			}
			else {
				team2[temp2] = i;
				temp2++;
			}
		}
		temp = 0;
		temp2 = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = i; j < N / 2; j++) {
				temp += ary[team1[i]][team1[j]];
				temp += ary[team1[j]][team1[i]];
				temp2 += ary[team2[i]][team2[j]];
				temp2 += ary[team2[j]][team2[i]];
			}
		}
		temp = abs(temp - temp2);
		if (tmin > temp)
			tmin = temp;
			
	}

	for (int i = pre; i < N; i++) {
		team1[cnt] = i;
		make_team(i + 1, cnt + 1);
	}
}