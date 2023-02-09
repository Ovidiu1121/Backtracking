#include <iostream>
#include <fstream>
using namespace std;

/*se da o fotografie alb negru codificata printr o matrice binara. Fotografia poate avea unul sau mai multe obiecte in poza. Un obiect este
format din elemente cu valoarea 1 care se invecineaza. Se citeste un punct de la tastatura in matricea 2D. Punctul citit are obligatia de a
fi in interiorul unui obiect. Sa se determine numarul de puncte de pe frontiera obiectului din care face parte punctul citit in planl XoY */

int dx[8] = { -1,1,0,0,-1,1,1,-1 }, dy[8] = { 0,0,-1,1,1,1,-1,-1 };
int x, y, a[100][100], n, m, ct = 0;

ifstream f("in.txt");

void citire() {

	f >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f >> a[i][j];
		}
	}
	do {
		cin >> x >> y;
	} while (a[x][y] == 0);

}

void afisare() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

bool isOK(int i, int j) {

	if (i<0 || i>n - 1) {
		return false;
	}
	if (j<0 || j>m - 1) {
		return false;
	}
	if (a[i][j] == 0) {
		return false;
	}
	return true;
}

void back(int i, int j) {

	int imax, jmax, k = 0;
	
	for (k = 0; k < 8; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOK(imax, jmax) == true) {
			ct++;
			a[imax][jmax] = 0;
		}
	}

}

void functie() {

	citire();
	afisare();
	back(x, y);
	cout << ct;
}













