#include <iostream>

using namespace std;
#include <math.h>


/*Se dă numărul natural n. Determinati o modalitate de așezare a numerelor din mulțimea 1,2,…,n pe un cerc astfel 
încât suma a oricare două nume învecinate să fie pătrat perfect.
29 7 18 31 5 11 25 24 12 13 3 6 30 19 17 32 4 21 28 8 1 15 10 26 23 2 14 22 27 9 16 20*/

int s[100], n = 32;

void tipar() {

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}

}

bool patratPerfect(int n) {

	if ((int)sqrt(n) == sqrt(n)) {
		return 1;
	}
	return 0;
}

int sumaPatratPerfect(int a, int b) {

	if (patratPerfect(a + b)) {
		return 1;
	}
	return 0;
}

bool invecinatePP(int v[], int d) {

	for (int i = 1; i <= d-2; i++) {
		
		if (sumaPatratPerfect(v[i - 1], v[i]) == 0 || sumaPatratPerfect(v[i], v[i + 1]) == 0) {
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
	return   1;
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
				if (invecinatePP(s, n)) {
					tipar();
				}
			}
			else {
				back(k + 1);
			}
		}
	}

}










