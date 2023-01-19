#include <iostream>

using namespace std;


int s[100], n=3;

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
}

int valid(int k) {

	/*if (k == 0 && s[k] % 2 == 0) {
		return 0;
	}
	if (k == n - 1 && s[k] % 2 == 1) {
		return 0;
	}*/
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {

	if (k == (n - 1)) {
		return 1;
	}
	else {
		return 0;
	}

}

void back(int k) {

	for (int i = 1; i <= n; i++) {
		s[k] = i;
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}

}





















