#include <iostream>
#include <fstream>
using namespace std;

//problema labirintului

int x, y, a[100][100], n, m, sol[20][20];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

ifstream f("in.txt");

void citire() {

	int i, j;

	f >> n >> m;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
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
			cout << sol[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;

}

void rec(int i, int j, int pas) {

	int jmax, imax, k;

	for (k = 0; k < 4; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (a[imax][jmax] == 1 && sol[imax][jmax] == 0) {
			sol[imax][jmax] = pas;
			if (imax == 0 || imax == n - 1 || jmax == 0 || jmax == n - 1) {
				afisare();
			}
			rec(imax, jmax, pas + 1);
			sol[imax][jmax] = 0;
		}
	}

}

void Main() {

	citire();
	sol[x][y] = 1;	
	rec(x, y, 2);

}
























