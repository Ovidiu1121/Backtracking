#include <iostream>
#include <fstream>
using namespace std;

/*se citeste de la tastatura o matrice reprezentand o tabla de sah si coordonatele unui punct in interirul tablei de sah. Punctul citit este
reprezentat de un cal. Care sunt toate punctele pe care acest cal le poate atinge in matrice, pe tabla de sah?*/

int n, m,x,y, a[100][100];
int dx[8] = { -2, -1, 1, 2,  2,  1, -1, -2 }, dy[8] = { 1,  2, 2, 1, -1, -2, -2, -1 };

ifstream read("in.txt");

void citire() {

	read >> n >> m >> x >> y;
	a[x][y] = 1;
	for (int i = 0; i < 0; i++) {
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
	cout << "\n";
}

bool isOk(int i, int j) {

	if (i<0 || i>n - 1) {
		return false;
	}
	if (j<0 || j>m - 1) {
		return false;
	}
	if (a[i][j] != 0) {
		return false;
	}
	return true;
}

bool isFull() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void back(int i, int j, int pas) {

	int imax, jmax, k;

	if (isFull() == true) {
		afisare();
		return;
	}

	for (k = 0; k < 8; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOk(imax, jmax) == true) {
			a[imax][jmax] = pas;
			back(imax, jmax, pas + 1);
		}
	}

}

void functie() {

	citire();
	afisare();
	back(x, y, 2);


}

















