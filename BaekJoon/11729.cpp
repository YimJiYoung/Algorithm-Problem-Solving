#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

vector <pair<int, int>> path;

int MoveTower(int from, int to, int n) { //from���� to�� n���� �ϳ��� ž�� �̵��� Ƚ��
	int res=0; // �̵� Ƚ��
	int empty; // from�� to�� �ƴ� ..

	if (n == 1) { //base case
		path.push_back(make_pair(from, to));
		return 1;
	}
	
	for (int i = 1; i <= 3; i++)
		if (i != from && i != to)
			empty = i;

	res += MoveTower(from, empty, n - 1); // n-1���� ž�� empty�� �̵�
	res++; // n ���� to�� �̵�
	path.push_back(make_pair(from, to));
	res += MoveTower(empty, to, n - 1); // n-1���� ž n ���� ���� �̵�

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