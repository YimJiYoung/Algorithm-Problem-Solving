#include <iostream>
using namespace std;

int apt[15][15]; // 아파트 각 호에 거주하는 사람들의 수 

int GetNumberOfPeople(int k, int n) {

	int res = 0;

	if (apt[k][n] != 0) // 이미 계산된 값이 있을 때
		return apt[k][n];

	for (int i = 1; i <= n; i++) { // 아래층(k-1) 1~n호까지 사람들의 수 합 
		if (apt[k - 1][i] != 0) // 이미 계산된 값이 있을 때
			res += apt[k - 1][i];
		else {
			res+=GetNumberOfPeople(k - 1, i);
		}
	}
	apt[k][n] = res;

	return res;
}

int main() {

	int T, k, n;

	for (int i = 0; i < 15; i++) // 0층의 i호에는 i명이 산다
		apt[0][i] = i;

	for (int i = 1; i < 15; i++)
		for (int j = 0; j < 15; j++)
			apt[i][j] = 0; // 0으로 초기화
	
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> k >> n;
		cout<<GetNumberOfPeople(k, n)<<endl;
	}
	
	return 0;
}