#include <iostream>

using namespace std;


int s[100], n = 4, m = 3, t = 1;

void tipar() {
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << s[i] << " ";
	}

}

int valid(int k) {
 /*
	if (k == 0 && s[k] == t) {
		return 0;
	}*/

	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {

	if (k == m - 1) {
		return 1;
	}
	else {
		return 0;
	}

}

void back(int k) {

	int val;

	for (val = 1; val <= n; val++) {
		s[k] = val;
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







