#include <iostream>

using namespace std;


/*Se citeşte un număr natural nenul n, apoi n numere naturale distincte. Să se afişeze, în ordine lexicografică, 
șirurile din cele n valori cu proprietatea că oricare două valori învecinate sunt prime între ele.*/

int s[100], v[4] = { 8, 6, 7, 9 }, n = 4;

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}

}

int cmmdc(int a, int b) {

	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;
}

bool primeIntreEle(int a, int b) {

	if (cmmdc(a, b) == 1) {
		return true;
	}
	return false;
}

int valid(int k) {

	for (int i = 0; i < k; i++) {
		if (primeIntreEle(s[i], s[i + 1]) == 0) {
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

	for (int i = 0; i < n; i++) {
		s[k] = v[i];
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

































