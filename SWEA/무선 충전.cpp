#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int plusx[5] = { 0, 0, 1, 0, -1 };
int plusy[5] = { 0, -1, 0, 1, 0 };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int M, A, total_charge = 0;
		pair<int, int> posA = make_pair(1, 1);
		pair<int, int> posB = make_pair(10, 10);
		vector<int> personA, personB;
		vector<int> AP_power;
		map<pair<int, int>, vector<int>> pos;
		cin >> M >> A;
		int temp_move;
		for (int i = 0; i < M; i++) {
			cin >> temp_move;
			personA.push_back(temp_move);
		}
		for (int i = 0; i < M; i++) {
			cin >> temp_move;
			personB.push_back(temp_move);
		}

		int BCx, BCy, range, power;
		for (int i = 0; i < A; i++) {
			cin >> BCx >> BCy >> range >> power;
			AP_power.push_back(power);

			for (int j = -range; j <= range; j++)
				for (int k = -range; k <= range; k++)
					if (abs(j) + abs(k) <= range)
						if (1 <= BCx + j && BCx + j <= 10)
							if (1 <= BCy + k && BCy + k <= 10)
								pos[make_pair(BCx + j, BCy + k)].push_back(i);

		}

		for (int i = 0; i <= M; i++) {
			int use = -1;
			int max = 0;
			int charge;
			if (pos[posA].size() > 0 && pos[posB].size() > 0) {
				for (int j = 0; j < pos[posA].size(); j++) {
					charge = 0;
					use = pos[posA][j];
					for (int k = 0; k < pos[posB].size(); k++) {
						charge = AP_power[pos[posA][j]];
						if (pos[posB][k] != use) {
							charge += AP_power[pos[posB][k]];
						}
						if (max < charge)
							max = charge;
					}
				}
			}
			else if (pos[posA].size() == 0 && pos[posB].size() > 0) {
				for (int j = 0; j < pos[posB].size(); j++) {
					if (max < AP_power[pos[posB][j]])
						max = AP_power[pos[posB][j]];
				}
			}
			else if (pos[posB].size() == 0 && pos[posA].size() > 0) {
				for (int j = 0; j < pos[posA].size(); j++) {
					if (max < AP_power[pos[posA][j]])
						max = AP_power[pos[posA][j]];
				}
			}

			if (i != M) {
				posA.first += plusx[personA[i]];
				posA.second += plusy[personA[i]];
				posB.first += plusx[personB[i]];
				posB.second += plusy[personB[i]];
			}
			total_charge += max;
		}
		cout << "#" << test_case << " ";
		cout << total_charge << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}