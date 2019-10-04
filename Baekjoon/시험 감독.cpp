#include<iostream>
using namespace std;

int stu[1000000];

int main()
{
	ios::sync_with_stdio(false);
	int N, B, C;
	long long cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> stu[i];
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		if (stu[i] <= 0)
			continue;

		cnt++;
		stu[i] -= B;
		if (stu[i] > 0) {
			cnt += stu[i] / C;
			if (stu[i] % C != 0)
				cnt++;
		}
	}

	cout << cnt << endl;
	system("pause");
	return 0;
}