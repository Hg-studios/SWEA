#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool solve() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		if (!(m&(1<<i))) { //m의 i번째 비트가 1인지 아닌지 확인(0번째부터)
			return 0;
		}	
	}
	return 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "#" << i << " ";
		if (solve()) cout << "ON";
		else cout << "OFF";
		cout << '\n';
	}

	return 0;
}