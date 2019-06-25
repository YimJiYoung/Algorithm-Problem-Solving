#include <iostream>
#include <utility>
using namespace std;

char yard[250][250];
bool visited[250][250];
int R, C;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

pair<int, int> dfs(int y, int x) {
	pair<int, int> p = make_pair(0, 0);
	pair<int, int> tmp;
	if (yard[y][x] == 'o')
		p.first++;
	else if (yard[y][x] == 'v')
		p.second++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		//¹üÀ§
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;
		//
		if (visited[ny][nx] || yard[ny][nx] == '#')
			continue;
		visited[ny][nx] = true;
		tmp=dfs(ny, nx);
		p.first += tmp.first;
		p.second += tmp.second;
	}
	return p;
}

pair<int, int> solution() {
	pair<int, int> ans;
	pair<int, int> tmp;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (!visited[i][j]&& yard[i][j] != '#')
			{
				visited[i][j] = true;
				tmp = dfs(i, j);
				if (tmp.first > tmp.second)//¾çÀÇ ¼ö°¡ ´õ ¸¹À¸¸é
					tmp.second = 0;
				else
					tmp.first = 0;
				ans.first += tmp.first;
				ans.second += tmp.second;
			}
		}
	return ans;
}

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> yard[i][j];
	pair<int, int> ans = solution();
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
