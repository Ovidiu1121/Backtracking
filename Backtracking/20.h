#include <iostream>
#include <fstream>
using namespace std;


/*Harta unui munte este reprezentată printr-o matrice cu n linii și m coloane în care fiecare element reprezintă înălțimea zonei respective.
Un alpinist pleacă de la coordonatele (1,1) și dorește să ajungă la coordonatele (n,m). Deplasarea se face pe aceeași linie sau coloană; 
alpinistul poate să treacă din zona curentă în zona învecinată numai dacă înălțimea zonei curente este mai mică sau egală cu cea a zonei 
învecinate. Determinați lungimea minimă a unui traseu al alpinistului.*/


int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int n, m, xi, yi, xf, yf, a[100][100], minim = INT_MAX, nrPasi = 1, sol[100][100];

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

bool isOk(int i, int j, int imax, int jmax) {

	if (imax < 0 || imax>n - 1) {
		return false;
	}

	if (jmax<0 || jmax>m - 1) {
		return false;
	}

	if (a[imax][jmax] < a[i][j]) {
		return false;
	}
	return true;
}

void back(int i, int j) {

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
		if (isOk(i, j, imax, jmax) == true) {
			nrPasi++;
			sol[i][j] = a[i][j];
			a[i][j] = 0;
			back(imax, jmax);
			a[i][j] = sol[i][j];
			nrPasi--;
		}
	}

}

void functie() {

	citire();
	back(xi, yi);
	cout << minim;
}




















