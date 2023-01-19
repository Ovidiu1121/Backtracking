#include <iostream>

using namespace std;

//Se citesc două numere a și b. Să se afișeze, în ordine lexicografică, permutările mulțimii {a, a + 1, ..., b}.


int s[100],a=4,b=6;

void tipar() {
	cout << endl;
	for (int i = 0; i <= b-a; i++) {
		cout << s[i] << " ";
	}

}

int valid(int k) {

	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {

	if (k == (b-a)) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {

	for (int i = a; i <= b; i++) {
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




























