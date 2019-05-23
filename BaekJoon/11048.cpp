#include <stdio.h>
#include <iostream>
using namespace std;

int map[1000][1000];
int cache[1000][1000];
int n, m;

int max(int a, int b, int c) {
	int max = (a < b) ? b : a;
	return ((max < c) ? c : max);
}

int MaxCandy(int y, int x) { // (y,x)에서 (n,m)으로 이동할 때 최대 사탕 수
	if (y> n - 1 || x> m - 1) // 범위 아웃
		return -1000000;
	if (y == n - 1 && x == m - 1) // 마지막 칸에 도달
		return map[n - 1][m - 1];

	int& ret = cache[y][x];
	if (ret != -1)return ret;
	int candy = map[y][x];
	return ret = max(MaxCandy(y + 1, x), MaxCandy(y, x + 1), MaxCandy(y + 1, x + 1)) + candy;
}

int main()
{
	int tmp;
	scanf_s("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}
	memset(cache, -1, sizeof(cache));
	int ans = MaxCandy(0, 0);
	printf("%d", ans);
	while (1) {}
	return 0;
}