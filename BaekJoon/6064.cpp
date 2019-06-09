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
		if (M > N) { // �� ū ���� �������� 
			gap = M; i = x;
		}
		else {
			gap = N; i = y;
		}
		while (i <= lcm(M, N)) { // ������= M�� N�� �ּҰ���� 
			int tx = i % M == 0 ? M : i % M;
			int ty = i % N == 0 ? N : i % N;
			if (tx == x && ty == y) 
				break;
			i += gap;
		}
		if (i > lcm(M, N)) // ���� ������ ��ã������ ..
			i = -1;
		cout << i << '\n';
	}
}