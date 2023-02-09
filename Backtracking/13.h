#include <iostream>
#include <fstream>
using namespace std;


/*se citeste de la tastatura o matrice reprezentand o tabla de sah si coordonatele a doua puncte din interiorul tablei de sah. punctele 
reprezentate sunt doua ture. cele doua ture sunt din echipe adverse. care este cel mai mic numar de pasi pe care trbuie sa il faca
tura din echipa negra ca sa ia tura din echipa neagra. tura din echipa alba nu face nici o alta miscare intre timp*/

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int nrPasi=0,n, m, xi, yi, xf, yf, a[100][100],minim=INT_MAX;

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

}

bool isOk(int imax, int jmax) {

	if (imax<0 || imax>n - 1) {
		return 0;
	}
	if (jmax<0 || jmax>n - 1) {
		return 0;
	}
	if (a[imax][jmax]) {
		return 0;
	}
	return 1;
}

void back(int i, int j, int pas) {

	int imax, jmax, k;

	if (i == xf && j == yf) {
		if (nrPasi < minim) {
			minim = nrPasi;
		}
		return;
	}

	for (k = 0; k < 4; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOk(imax, jmax) == true) {
			nrPasi++;
			a[imax][jmax] = pas;
			back(imax, jmax, pas + 1);
			nrPasi--;
			a[imax][jmax] = 0;
		}
	}

}

void functie() {

	citire();
	back(xi, yi, 2);
	cout << minim;

}
















