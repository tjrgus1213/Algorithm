#include <string>
#include <vector>

using namespace std;

struct ttime {
	int hour, min;
	float sec;
};

int stringToint(string s);
float stringToSec(string s);
float stringToDuration(string s);
bool compareTime(ttime &a, ttime  &b);

int solution(vector<string> lines) {
	int answer = 1;
	ttime ary[2001][2];
	ttime temp;
	float dur;
	for (int i = 0; i < lines.size(); i++) {
		temp.hour = stringToint(lines[i].substr(11, 2)); // hour
		temp.min = stringToint(lines[i].substr(14, 2)); // min
		temp.sec = stringToSec(lines[i].substr(17, 6)); // sec
		dur = stringToDuration(lines[i].substr(24)); // duration

		ary[i][1] = temp;
		temp.sec -= dur - 0.001;
		if (temp.sec < 0) {
			temp.sec += 60;
			temp.min--;
			if (temp.min < 0) {
				temp.min += 60;
				temp.hour--;
			}
		}
		ary[i][0] = temp;
	}

	ttime end;
	int cnt;
	for (int i = 0; i < lines.size(); i++) {
		end = ary[i][1];
		end.sec += 0.999;
		if (end.sec >= 60) {
			end.sec -= 60;
			end.min++;
			if (end.min >= 60) {
				end.min -= 60;
				end.hour++;
			}
		}
		cnt = 1;
		for (int j = i + 1; j < lines.size(); j++) {
			if (compareTime(ary[i][1], ary[j][0]) && compareTime(ary[j][0], end))
				cnt++;
			else if (compareTime(ary[i][1], ary[j][1]) && compareTime(ary[j][1], end))
				cnt++;
			else if (compareTime(ary[j][0], ary[i][1]) && compareTime(end, ary[j][1]))
				cnt++;
		}
		if (answer < cnt)
			answer = cnt;
	}
	return answer;
}

int stringToint(string s) {
	return ((s[0] - '0') * 10) + (s[1] - '0');
}
float stringToSec(string s) {
	float sec = 0;
	sec += ((s[0] - '0') * 10) + (s[1] - '0');
	sec += ((float)(s[3] - '0') / 10) + ((float)(s[4] - '0') / 100) + ((float)(s[5] - '0') / 1000);
	return sec;
}
float stringToDuration(string s) {
	int i = 0;
	float dur = 0, div = 1;
	while (s[i] != 's') {
		if (s[i] != '.') {
			dur += ((float)(s[i] - '0')) / div;
			div *= 10;
		}
		i++;
	}
	return dur;
}
bool compareTime(ttime &a, ttime &b) {
	if (a.hour < b.hour)
		return true;
	else if (a.hour > b.hour)
		return false;
	if (a.min < b.min)
		return true;
	else if (a.min > b.min)
		return false;
	if (a.sec <= b.sec)
		return true;
	else
		return false;
}