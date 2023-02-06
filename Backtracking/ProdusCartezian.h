#include <iostream>

using namespace std;


unsigned s[2], n, m;
unsigned P[100], I[100], T;

void tipar() {

	cout << endl;
	for (int i = 0; i < 2; i++) {
		cout << s[i] << " ";
	}

}

int valid(int k) {
	//produsul cartezian nu are functie de validare
	return 1;

}

int solutie(int k) {

	if (k == 1) {
		return 1;
	}
	else {
		return 0;
	}

}

void back(int k) {

	unsigned j, n_m;

	//salvam n_m numarul de solutii din multime P sau I in functie de valoare lui k

	(k == 0 ? n_m = n : n_m = m);

	for (int j = 0; j < n_m; j++) {
		(k == 0 ? s[k] = P[j] : s[k] = I[j]);

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

void Main() {

	unsigned i;

	cout << "n=";
	cin >> n;
	for (i = 0; i < n; i++) {
		P[i] = i * 2;
	}

	cout << "m=";
	cin >> m;
	for (i = 1; i < m * 2; i++) {
		I[i / 2] = i;
	}

	cout << "T=";
	cin >> T;

	cout << "P=";
	for (i = 0; i < n; i++) {
		cout << P[i]<<" ";
	}

	cout << endl << "I=";
	for (i = 0; i < m; i++) {
		cout << I[i]<<" ";
	}
	cout << endl;

	back(0);

}
















