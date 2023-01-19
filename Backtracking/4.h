#include <iostream>

using namespace std;

/*Se dau numerele naturale n si k. Sa se genereze in ordine lexicografică toate permutările mulțimii {1,2,...,n}
cu proprietatea că diferența în modul dintre oricare două numere alăturate din permutare este de cel mult k.*/


int s[100], n = 4, d = 2;

void tipar() {

	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}

}

int valid(int k) {

	for (int i = 0; i < k; i++) {
		if (abs(s[i] - s[i + 1]) > d) {
			return 0;
		}
	}

	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {

	if (k == n - 1) {
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












