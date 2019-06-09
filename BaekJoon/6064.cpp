#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int T,M,N,x,y;
	cin >> T;
	for (int t = 0; t < T; t++ ) {
		cin >> M >> N >> x >> y;
		int i = 1;
		int gap;
		if (M > N) { // 더 큰 수를 기준으로 
			gap = M; i = x;
		}
		else {
			gap = N; i = y;
		}
		while (i <= lcm(M, N)) { // 마지막= M과 N의 최소공배수 
			int tx = i % M == 0 ? M : i % M;
			int ty = i % N == 0 ? N : i % N;
			if (tx == x && ty == y) 
				break;
			i += gap;
		}
		if (i > lcm(M, N)) // 범위 내에서 못찾았으면 ..
			i = -1;
		cout << i << '\n';
	}
}