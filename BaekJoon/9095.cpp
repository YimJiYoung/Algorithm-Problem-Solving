#include <iostream>
#include <string>
using namespace std;

int mem[11];

int main()
{
	int T, n;
	cin >> T;
	//mem√ ±‚»≠
	mem[0] = 1;
	mem[1] = 1;
	mem[2] = 2;
	for (int i = 3; i < 11; i++)
		mem[i] = mem[i - 1]+ mem[i - 2]+ mem[i - 3];

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << mem[n] << '\n';
	}
	
	return 0;
}