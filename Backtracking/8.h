#include <iostream>
#include <fstream>
using namespace std;

/*se citeste de la tastatura o matrice reprezentand o tabla de sah si doua puncte de coordonate XoY care reprezinta pozitia
unui cal si a reginei adversarului. afisati toate drumurile care le poate parcurge calul a.i. sa poata ajunge la pozitia reginei.
Care este numarul de pasi pentru cel mai scurt astfel de drum? */

int a[100][100], sol[100][100], n, m, xi, yi, xf, yf, nrPasi=INT_MAX;
int dx[8] = { -2, -1, 1, 2,  2,  1, -1, -2 }, dy[8] = { 1,  2, 2, 1, -1, -2, -2, -1 };

ifstream read("in.txt");

void citire()
{
	read >> n >> m >> xi >> yi >> xf >> yf;

	sol[xi][yi] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
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

bool sfarsit(int i, int j) {

	if (i == xf && j == yf) {
		return true;
	}
	return false;
}

void solutie() {

	static int k = 1;

	cout << "Solutia nr. " << k << ": \n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	k++;
	cout << "\n\n";
}

bool isOK(int i, int j) {

	if (i<0 || i>n - 1) {
		return false;
	}
	if (j<0 || j>m - 1) {
		return false;
	}
	if (a[i][j]) {
		return false;
	}

	return true;
}

void back(int x, int y, int pas) {

	if (sfarsit(x, y) == true) {
		if (pas < nrPasi) {
			nrPasi = pas;
		}
		solutie();
		return;
	}

	int imax, jmax;

	for (int i = 0; i < 8; i++) {
		imax = x + dx[i];
		jmax = y + dy[i];
		if (isOK(imax, jmax) == true) {
			a[imax][jmax] = pas;
			sol[imax][jmax] = pas;
			back(imax, jmax, pas + 1);
			a[imax][jmax] = 0;
		}
	}

}

void functie() {

	citire();
	back(xi, yi, 2);
	cout << "Nr de pasi minim: " << nrPasi;
}

















