#include <iostream>
#include <fstream>
using namespace std;

/*Pentru a evada din Matrix, Neo trebuie să străbată un labirint reprezentat de o matrice cu n linii și m coloane. Fiecare celulă a
labirintului este marcată cu o cifră în baza 10 cu semnificația că Neo trebuie să treacă prin acea poziție de atâtea ori cât este valoarea
cifrei din acea poziție. Practic, Neo poate merge doar pe poziții care au valori nenule. Inițial, Neo se află în celula de coordonate (x, y),
cunoscută. Neo se poate deplasa doar pe valori vecine pe linie și pe coloană. Dacă se află în poziția (i,j), atunci el poate merge în
pozițiile (i-1,j), (i+1,j), (i,j+1) și (i,j-1). Neo vrea să știe numărul total de moduri în care poate parcurge labirintul. Dacă îl ajutați 
să calculeze acest număr, atunci Neo va insista pe lângă Moș Crăciun să vă aducă bomboane roșii și albastre.*/

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int n, m, xi, yi, xf, yf, a[100][100], sol[100][100], modalitati = 0;

ifstream read("in.txt");

void citire() {

	read >> n >> m >> xi >> yi >> xf >> yf;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			read >> a[i][j];
		}
	}
}

void afisare() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n";
}

bool isOk(int imax, int jmax) {

	if (a[imax][jmax] == 0) {
		return false;
	}
	return true;
}

bool sfarsit() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

void back(int i, int j) {

	int imax, jmax, k;

	if (sfarsit() == true) {
		modalitati++;
		return;
	}

	for (k = 0; k < 4; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOk(imax, jmax) == true) {
			if (a[i][j] > 1) {
				sol[i][j] = a[i][j];
				a[i][j]--;
				back(imax, jmax);
				a[i][j]++;;
			}
		}
	}

}

void functie() {

	citire();
	back(xi, yi);
	cout << modalitati << endl;

}

























