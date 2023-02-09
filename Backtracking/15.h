#include <iostream>
#include <fstream>
using namespace std;



/*Se dă o tablă dreptunghiulară formată din n linii și m coloane, definind n*m zone, unele dintre ele fiind libere, altele conținând 
obstacole. Într-o zonă precizată se află un șoarece care se poate deplasa pe tablă trecând din zona curentă în zona învecinată cu aceasta
pe linie sau pe coloană. Scopul sau este să ajungă la o bucată de brânză aflată într-o zonă de asemenea precizată, fără a părăsi tabla, 
fără a trece prin zone care conțin obstacole și fără a trece de două ori prin aceeași zonă. Determinați o modalitate prin care șoarecele
poate să ajungă la bucata de brânză.*/

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
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

void afisare() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n";
}

bool isOk(int imax, int jmax) {

	if (imax < 0 || imax>n - 1) {
		return false;
	}

	if (jmax<0 || jmax>m - 1) {
		return false;
	}

	if (a[imax][jmax]!=0) {
		return false;
	}
	return true;
}

void back(int i, int j, int pas) {

	int imax, jmax, k;
	
	if (i == xf && j == yf && ct == 0) {
		ct++;
		afisare();
		return;
	}

	for (k = 0; k < 4; k++) {
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


















