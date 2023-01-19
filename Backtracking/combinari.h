#include <iostream>

using namespace std;

int s[100], n = 7, m = 3;


bool pp(int s) {

	if ((int)sqrt(s) == sqrt(s)) {
		return true;
	}
	else {
		return false;
	}

}

void tipar() {

	cout << endl;

	for (int i = 0; i < m; i++) {
		cout << s[i] << " ";
	}

}

int valid(int k) {

	if (k == 0 && pp(s[k]) == false) {
		return 0;
	}

	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
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


















