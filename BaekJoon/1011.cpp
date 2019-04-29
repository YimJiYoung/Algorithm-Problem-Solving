#include <iostream>
using namespace std;

int main()
{
	long T, x, y;
	long len; // 목적지까지의 거리
	long k; // 전의 이동 거리
	long cnt; // 이동 횟수
	long tmp; // 이동 가능 거리
	cin >> T;
	for (int t = 0; t < T; t++) {
		cnt = 0;
		cin >> x >> y;
		len = y - x;

		if (len <=2)
			cnt = len;
		else {
			len--; // 맨 처음 1만큼 이동
			k = 1;
			cnt++;

			while (len > 1) {
				for (int i = 1; i >= -1; i--) { // k+1, K, K-1 만큼 이동 가능
					tmp = k + i;
					if (len >= (tmp*(tmp + 1)) / 2) // tmp 만큼 이동하려면 최소 1+2+..+tmp 만큼의 거리가 남아있어야 함
					{
						k = tmp;
						len -= tmp;
						cnt++;
						break;
					}
				}
			}
			cnt++;
		}
		cout << cnt<<endl;
	}

	return 0;
}