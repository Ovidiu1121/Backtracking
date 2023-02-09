#include <iostream>
#include <fstream>
using namespace std;


/*Se considerã o tablã de ºah cu n linii ºi m coloane. La o poziþie datã se aflã un cal de ºah, acesta putându-se deplasa pe tablã în modul
specific acestei piese de ºah (în L).
Sã se determine o modalitate de parcurgere integralã a tablei de cãtre calul dat, astfel încât acesta sã nu treacã de douã ori prin aceeaºi
poziþie.*/

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























