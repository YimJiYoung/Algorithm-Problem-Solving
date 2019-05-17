#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

vector <pair<int, int>> path;

int MoveTower(int from, int to, int n) { //from에서 to로 n층의 하노이 탑을 이동한 횟수
	int res=0; // 이동 횟수
	int empty; // from도 to도 아닌 ..

	if (n == 1) { //base case
		path.push_back(make_pair(from, to));
		return 1;
	}
	
	for (int i = 1; i <= 3; i++)
		if (i != from && i != to)
			empty = i;

	res += MoveTower(from, empty, n - 1); // n-1층의 탑을 empty로 이동
	res++; // n 원반 to로 이동
	path.push_back(make_pair(from, to));
	res += MoveTower(empty, to, n - 1); // n-1층의 탑 n 원반 위로 이동

	return res;
}

int main() {

	int n;
	cin >> n;
	cout << MoveTower(1, 3, n)<<'\n';
	for (int i = 0; i < path.size(); i++)
		cout << path[i].first << ' ' << path[i].second << '\n';
	return 0;
}