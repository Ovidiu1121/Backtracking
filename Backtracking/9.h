#include <iostream>
#include <fstream>
using namespace std;


/*se citeste de la tastatura o matrice reprezentand un labirint si doua puncte in planul 2D. Punctele reprezinta pozitia unui soarece si a 
unei pisici. Matricea este una binara unde elementul 1 reprezinta perete iar elementul 0 reprezinta drum. Care este cel mai scurt drum
pe care trebuie sa il parcurga pisica pentru a prinde soarecele? se presupune ca exista cel putin un astfel de drum */

int a[100][100], n, m, xi, yi, xf, yf, nrPasi = 0;
int dx[8] = { -1,1,0,0,-1,1,1,-1 }, dy[8] = { 0,0,-1,1,1,1,-1,-1 };

ifstream read("in.txt");

void citire() {

	read >> n >> m >> xi >> yi >> xf >> yf;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			read >> a[i][j];
		}
	}

}

void afisare(int v[100][100]) {

	static int k = 1;

	cout << "Solutia nr. " << k << ": \n\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
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
	if (a[i][j] != 0) {
		return false;
	}
	return true;
}

void solutie()
{
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

bool sfarsit(int x, int y) {

	if (x == xf && y == yf) {
		return true;
	}
	return false;
}

void back(int x, int y, int pas) {
	
	int v[100],d=0, k, imax, jmax;
	int static r = 2;

	if (sfarsit(x, y) == true) {
		v[d] = nrPasi;
		d++;
		solutie();
		return;
	}
	nrPasi = 0;
	for (k = 0; k < 8; k++) {
		 imax = x + dx[k];
		 jmax = y + dy[k];
		 if (isOK(imax, jmax) == true) {
			 nrPasi++;
			 a[imax][jmax] = r++;
			 back(imax, jmax, pas + 1);
			 a[imax][jmax] = 0;
			 r--;
		 }
	}

}

void functie() {

	citire();
	back(xi, yi, 2);

}















