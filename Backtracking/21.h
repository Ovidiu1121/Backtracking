#include <iostream>
#include <fstream>
using namespace std;


/*Pentru a-i duce cadoul dorit lui Dorel, Moș Crăciun trebuie să străbată un labirint cu capcane reprezentat de o matrice cu n linii și n 
coloane. Fiecare celula a labirintului este marcată cu valoarea 1 dacă este capcană sau cu 0 dacă este poziție liberă. Inițial, Moș Crăciun
se află în celula de coordonate (1, 1), iar Dorel în celula de cordonate (n,n).
Moș Crăciun se poate deplasa doar pe valori vecine pe diagonale. Dacă se află în poziția (i,j), atunci el poate merge în pozițiile (i-1,j-1),
(i-1,j+1), (i+1,j+1) și (i+1,j-1). Moș crăciun dorește să știe numărul total de drumuri pe care le poate urma prin labirint până la poziția
în care se află Dorel, astfel încât să nu treacă prin capcane și să nu treacă de mai multe ori prin aceeași pozitie. De asemenea, 
Moș Crăciun vrea să îl facă pe Dorel să îl aștepte cât mai mult și ar vrea să știe lungimea celui mai lung drum. Dacă îl ajutați să 
calculeze aceste numere, atunci Moș Crăciun promite că va trece și pe la voi..*/


int dx[] = { -1,-1,1,1 }, dy[] = { -1,1,-1,1 };
int n, m, xi, yi, xf, yf, a[100][100], sol[100][100], modalitati = 0, maxim = 0, nrPasi = 1;

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

	if (imax < 0 || imax>n - 1) {
		return false;
	}

	if (jmax<0 || jmax>m - 1) {
		return false;
	}

	if (a[imax][jmax]) {
		return false;
	}
	return true;
}

void back(int i, int j) {

	int imax, jmax, k;

	if (i == xf && j == yf) {
		modalitati++;
		if (nrPasi > maxim) {
			maxim = nrPasi;
		}
		return;
	}

	for (k = 0; k < 4; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOk(imax, jmax) == true) {
			nrPasi++;
			sol[i][j] = a[i][j];
			a[i][j] = 1;
			back(imax, jmax);
			nrPasi--;
			a[i][j] = 0;
		}
	}

}

void functie() {

	citire();
	back(xi, yi);
	cout << modalitati << endl;
	cout << maxim;

}



















