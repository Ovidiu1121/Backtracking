#include <iostream>
#include <fstream>
using namespace std;


/*Se consider� o tabl� de �ah cu n linii �i m coloane. La o pozi�ie dat� se afl� un cal de �ah, acesta put�ndu-se deplasa pe tabl� �n modul
specific acestei piese de �ah (�n L).
S� se determine o modalitate de parcurgere integral� a tablei de c�tre calul dat, astfel �nc�t acesta s� nu treac� de dou� ori prin aceea�i
pozi�ie.*/

ifstream read("in.txt");

int n, m, a[105][105], xi, yi;
int dx[8] = { -2, -1, 1, 2,  2,  1, -1, -2 }, dy[8] = { 1,  2, 2, 1, -1, -2, -2, -1 }, o = 0;

void citire() {

    read >> n >> m >> xi >> yi;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            read >> a[i][j];
        }
    }
    a[xi][yi] = 1;
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

bool isFull()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0) {
                return false;
            }
    return true;
}

bool isOK(int i, int j)
{
    if (i > n - 1 || i < 0) {
        return false;
    }
    if (j > n - 1 || j < 0) {
        return false;
    }
    if (a[i][j]) {
        return false;
    }

    return true;
}

void back(int x, int y, int pas)
{

    if (isFull()&&o==0)
    {
        o++;
        afisare();
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int imax = x + dx[i];
        int jmax = y + dy[i];   
        if (isOK(imax, jmax))
        {
            a[imax][jmax] = pas;
            back(imax, jmax, pas + 1);
            a[imax][jmax] = 0;
        }
    }
}

void functie()
{
    citire();
    back(xi, yi,2);



}























