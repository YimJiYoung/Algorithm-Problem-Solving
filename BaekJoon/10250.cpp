#include <iostream>
using namespace std;

int main()
{
	int T, H, W, N;
	int floor; // 층 수
	int num; // 엘리베이터에서부터 세었을 때의 번호
	int ans; // 답(방 번호)
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> H >> W >> N;
		num = N / H + 1; 
		floor = N % H ;
		if (floor == 0) // H로 나누어떨어질 땐 H층에 위치
		{
			floor = H;
			num--;
		}
		ans = floor * 100 + num; // YYXX로 표시
		cout << ans << endl;
	}
	return 0;
}