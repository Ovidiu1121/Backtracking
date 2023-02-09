#include <iostream>
#include <fstream>
using namespace std;


/*Se dă o tablă de șah formată din n linii și m coloane, definind n*m zone, unele dintre ele fiind libere, altele conținând obstacole. În 
zona de coordonate 1 1 se află un cal care se poate deplasa pe tablă în L, ca la șah, fără a părăsi tabla, fără a trece prin zone care
conțin obstacole și fără a trece de două ori prin aceeași zonă. Determinați o modalitate prin care calul poate ajunge în zona de coordonate
n m – unde se află o căpiță de fân.*/

int dx[8] = { -2, -1, 1, 2,  2,  1, -1, -2 }, dy[8] = { 1,  2, 2, 1, -1, -2, -2, -1 };
int n, m, xi, yi, xf, yf, a[100][100], sol[100][100], ct = 0;

ifstream read("in.txt");

void citire() {

	read >> n >> m >> xi >> yi >> xf >> yf;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			read >> a[i][j];
		}
	}
	sol[xi][yi] = 1;
}

void afisare(int v[100][100]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
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

	if (a[imax][jmax] != 0) {
		return false;
	}
	return true;
}

void back(int i, int j, int pas) {

	int imax, jmax, k;

	if (i == xf && j == yf && ct == 0) {
		ct++;
		afisare(sol);
		return;
	}

	for (k = 0; k < 8; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOk(imax, jmax) == true) {
			sol[imax][jmax] = pas;
			a[imax][jmax] = 1;
			back(imax, jmax, pas + 1);
			a[imax][jmax] = 0;
		}
	}

}

void functie() {

	citire();
	back(xi, yi, 2);

}




















