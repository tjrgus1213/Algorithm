#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(vector<vector<string>> relation);
int combi(int a, int b);
void func(int* comp, int pos, int tuple_size, int n);

int main() {
	
	return 0;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int tuple_size = relation[0].size();
	int comp[9] = { 0, 0, 1, 2, 3, 4, 5, 6, 7 };
	int num[9];
	vector<vector<int>> check;
	vector<int> temp_check;

	for (int i = 1; i < tuple_size; i++) {
		num[i] = combi(tuple_size, i);
	}

	for (int a = 1; a < tuple_size; a++) {
		for (int b = 0; b < num[a]; b++) {
			bool is = true;

			for(int y = 0; y < check.size(); y++){
				int temp_cnt = 0;
				for (int k = 1; k <= a; k++) {
					for (int ty = 0; ty < check[y].size(); ty++) {
						if (check[y][ty] == comp[k])
							temp_cnt++;
					}
				}
				if (temp_cnt == check[y].size()) {
					is = false;
					func(comp, a, tuple_size, a);
					break;
				}
			}
			if (!is)
				continue;

			for (int i = 0; i < relation.size(); i++) {
				for (int j = i + 1; j < relation.size(); j++) {
					int cnt = 0;
					for (int k = 1; k <= a; k++) {
						//cout << relation[i][comp[k]] << " " << relation[j][comp[k]] << endl;
						if (relation[i][comp[k]] == relation[j][comp[k]]) {
							cnt++;
							//cout << "same : " << relation[i][comp[k]] << " " << relation[j][comp[k]] << endl;
						}
						if (cnt == a)
							is = false;
					}
					if (!is)
						break;
				}
				if (!is)
					break;
			}

			if (is) {
				answer++;
				for (int k = 1; k <= a; k++) {
					//cout << comp[k] << " ";
					temp_check.push_back(comp[k]);
				}
				//cout << endl;
			}

			func(comp, a, tuple_size, a);
			if (temp_check.size() > 0) {
				check.push_back(temp_check);
				temp_check.clear();
			}
		}
	}
	
	if (answer == 0) {
		if (relation.size() == 1)
			answer = tuple_size;
		else
			answer = 1;
	}
		
	//cout << answer << endl;
	return answer;
}

int combi(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) {
		res *= (a - i);
	}
	for (int i = 2; i <= b; i++) {
		res /= i;
	}

	return res;
}

void func(int* comp, int pos, int tuple_size, int n) {
	if (pos == 1 && comp[pos] == tuple_size - n) {
		comp[pos] = 0;
		return;
	}
		
	if (comp[pos] + 1 == tuple_size - n + pos) {
		func(comp, pos - 1, tuple_size, n);
		comp[pos] = comp[pos - 1] + 1;
	}
	else
		comp[pos]++;

	return;
}