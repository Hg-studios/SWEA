#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void sheep(int n) {
	int check = 0;
	int kn = 0;

	while (1) {
		kn += n;
		int tmp = kn;

		while (tmp > 0) {
			check |= 1 << (tmp % 10);
			tmp /= 10;
		}

		if (check == (1 << 10) - 1) {
			cout << kn;
			break;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		int n; cin >> n; 
		cout << "#" << i << " ";
		sheep(n);
		cout << '\n';
	}

	return 0;
}