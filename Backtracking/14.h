#include <iostream>
#include <fstream>
using namespace std;


/*Se dă o tablă dreptunghiulară formată din n linii și m coloane, definind n*m zone, unele dintre ele fiind libere, altele conținând
obstacole. În zona aflată la poziția is, js se află un șoarece care se poate deplasa pe tablă trecând din zona curentă în zona învecinată
cu aceasta pe linie sau pe coloană. Scopul sau este să ajungă la o bucată de brânză aflată în zona de la poziția ib, jb, fără a părăsi
tabla, fără a trece prin zone care conțin obstacole și fără a trece de două ori prin aceeași zonă.
Determinați câte modalități prin care șoarecele poate ajunge de la poziția inițială la cea a bucății de brânză există.*/


int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int modalitati = 0, n, m, xi, yi, xf, yf, a[100][100];

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

	for (int i = 0; i<n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

bool isOk(int imax, int jmax) {

	if (imax < 0 || imax>n - 1) {
		return false;
	}

	if (jmax<0 || jmax>m - 1) {
		return false;
	}

	if (a[imax][jmax]==1) {
		return false;
	}
	return true;
}

void back(int i, int j) {

	int imax, jmax, k;

	if (i == xf && j == yf) {
		modalitati++;
		return;
	}

	for (k = 0; k < 4; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOk(imax, jmax) == true) {
			a[imax][jmax] = 1;
			back(imax, jmax);
			a[imax][jmax] = 0;
		}
	}

}

void functie() {

	citire();
	back(xi, yi);
	cout << modalitati;

}
















