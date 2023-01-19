#include <iostream>

using namespace std;

/*Se cite�te un num�r natural nenul n �i o permutare a mul�imii M={1,2,..,n}. S� se afi�eze, �n ordine lexicografic�,
toate permut�rile mul�imii M care nu con�in elemente al�turate care au fost al�turate �i �n permutarea dat�(2,3,1,4).
1 2 4 3
3 4 2 1 */

int s[100], v[4] = {2,3,1,4}, n = 4;

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}

}

int pozitieNr(int v[],int d, int n) {

	for (int i = 0; i < d; i++) {
		if (v[i] == n) {
			return i;
		}
	}
	return -1;
}

bool numereAlaturate(int x[], int f[]) {

	for (int i = 1; i < n; i++) {
		
		int poz = pozitieNr(x, n, f[i]);

		bool c1 = f[i - 1] == x[poz - 1] || f[i - 1] == x[poz+1];
		bool c2 = f[i + 1] == x[poz-1] || f[i + 1] == x[poz + 1];
		
		if (c1 == 1 || c2 == 1) {
			return 0;
		}

	}
	return 1;
}

int valid(int k) {

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
				if (numereAlaturate(v,s)) {
					tipar();
				}
			}
			else {
				back(k + 1);
			}
		}
	}

}




















