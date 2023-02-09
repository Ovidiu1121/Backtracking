#include <iostream>
#include <fstream>
using namespace std;


/*Se consideră o tablă de joc de formă dreptunghiulară, împărţită în n linii şi m coloane. Se obţin astfel n*m zone şi se cunoaște înălțimea
fiecărei zone. La o poziție cunoscută – linia istart, coloana jstart se află o bilă care se poate deplasa pe o poziție vecină 
(sus, jos, stânga, dreapta) doar dacă înălțimea poziției vecine este strict mai mică decât înălțimea poziției curente.
Determinați numărul maxim de zone prin care poate să treacă bila pentru a ajunge pe una dintre marginile tablei de joc.*/


int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int n, m, x, y, a[100][100], maxim = 0, nrPasi = 0,sol[100][100];

ifstream read("in.txt");

void citire() {

	read >> n >> m >> x >> y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			read >> a[i][j];
		}
	}
}

bool isOk(int i, int j,int imax, int jmax) {

	if (imax < 0 || imax>n - 1) {
		return false;
	}

	if (jmax<0 || jmax>m - 1) {
		return false;
	}

	if (a[imax][jmax] >= a[i][j]) {
		return false;
	}
	if (a[imax][jmax] == 0) {
		return false;
	}
	return true;
}

void back(int i, int j) {

	int imax, jmax, k;

	if (i == n || j == m || i == 0 || j == 0) {
		if (nrPasi > maxim) {
			maxim = nrPasi;
		}
		return;
	}

	for (k = 0; k < 4; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (isOk(i,j,imax, jmax) == true) {
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
	back(x, y);
	cout << maxim;
}






















