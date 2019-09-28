#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int function(int per, int st, vector<vector<int>> ary);
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	int stair[2][2];
	int stairtime[2];
	int person[10][2];
	int numOfperson;
	int timeTostair[10][2];

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int i, j;
		int temp = 0;
		int input;
		numOfperson = 0;
		cin >> N;

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				cin >> input;
				if (input == 1) {
					person[numOfperson][0] = i;
					person[numOfperson][1] = j;
					numOfperson++;
				}
				else if (input > 1) {
					stair[temp][0] = i;
					stair[temp][1] = j;
					stairtime[temp] = input;
					temp++;
				}
			}
		}
		for (i = 0; i < numOfperson; i++) {
			timeTostair[i][0] = abs(person[i][0] - stair[0][0]) + abs(person[i][1] - stair[0][1]);
			timeTostair[i][1] = abs(person[i][0] - stair[1][0]) + abs(person[i][1] - stair[1][1]);
		}

		int rest;
		int time;
		int pos;
		int waittime;;
		int min = 1000;
		int temp_max = 0;
		int k;

		for (i = 0; i < (2 << numOfperson); i++) {
			rest = numOfperson;
			time = 1;
			temp_max = 0;
			vector<vector<int>> perOfstair(2, vector<int>(200, 0));
			while (rest > 0) {
				for (j = 0; j < numOfperson; j++) {
					pos = (i >> j) & 1;
					if (timeTostair[j][pos] == time) {
						waittime = time;
						while (perOfstair[pos][waittime] >= 3)
							waittime++;
						for (k = waittime; k < waittime + stairtime[pos]; k++)
							perOfstair[pos][k]++;
						rest--;
						if (temp_max < k)
							temp_max = k;
					}
				}
				time++;
			}
			if (min > temp_max)
				min = temp_max;
		}

		cout << "#" << test_case << " ";
		cout << min + 1 << endl;
	}
	return 0;
}
