#include <iostream>
#include <fstream>
using namespace std;

/*se da o suprafata de dimensiune maxima  n x m. O minge pleaca din punctul cel mai inalt si trbuie sa ajunga in punctul cel mai jos.
sa se afiseze toate solutiile. Metoda de deplasare este dupa 8 puncte cardinale.*/

int n, m, x, y, a[100][100], sol[100][100];
int dx[8] = { -1,1,0,0,-1,1,1,-1 }, dy[8] = { 0,0,-1,1,1,1,-1,-1 };

ifstream read("in.txt");


void citire() {

	read >> n >> m >> x >> y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			read >> a[i][j];
		}
	}
	a[x][y] = 1;
}

void afisare() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

void solutie() {

	static int w = 1;

	cout << "Solutia nr. " << w << ": \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}

	w++;
	cout << "\n\n";

}

bool isOk(int i,int j, int imax, int jmax) {

	if (imax<0 || imax>n - 1) {
		return 0;
	}
	if (jmax<0 || jmax>m - 1) {
		return 0;
	}
	if (imax < i ) {
		return 0;
	}
	if (imax == i && jmax != j) {
		return 0;
	}
	if (a[imax][jmax]!=0) {
		return 0;
	}
	return true;
}

bool sfarsit(int x) {

	if (x == n - 1) {
		return true;
	}
	return false;
}

void back(int i, int j, int pas) {

	int imax, jmax, k;

	if (sfarsit(i) == true) {
		solutie();
		return;
	}

	for (k = 0; k < 8; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOk(i,j, imax, jmax) == true) {
			a[imax][jmax] = pas;
			back(imax, jmax, pas + 1);
			a[imax][jmax] = 0;
		}
	}

}

void functie() {

	citire();
	back(x, y, 2);

}

















