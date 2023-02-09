#include <iostream>
#include <fstream>
using namespace std;

/*pe un teren de dimensiune dreptunghiulara, cu denivelari, se aflsa un sportiv care doreste sa se antreneze pentruun concurs de
alpinism. Cunoscand altitudinea fiecarei portiuni de teren, pozitia initiala si pozitia finala, sa se determine un traseu pentru
care suma diferentelor de altitudine  intre pozitii consecutive sa fie maxima, alpinistul nu are voie sa coboare*/

int dx[8] = { -1,1,0,0,-1,1,1,-1 }, dy[8] = { 0,0,-1,1,1,1,-1,-1 };  
int xi, yi, xf, yf, a[10][20], n, m, sol[10][20];

ifstream read("in.txt");

void citire()
{
    read >> n >> m >> xi >> yi >> xf >> yf;

    sol[xi][yi] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            read >> a[i][j];
        }
    }
}

void afisare(int a[20][20])
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

bool isOK(int i,int j, int imax, int jmax) {

    if (imax < i) {
        return false;
    }
    if (imax > n || imax < 1) {
        return false;
    }
    if (jmax > m || jmax < 1) {
        return false;
    }
    if (sol[imax][jmax] != 0) {
        return false;
    }
    if (i == n) {
        if (jmax < j) {
            return false;
        }
    }
    return true;
}

void back(int i, int j, int pas)
{
    if (i == xf && j == yf)
    {
        return;
    }

    int imax, jmax, k;
    int minim;
    int r1, r2;
    minim = 1000;

    for (k = 0; k < 8; k++)
    {
        imax = i + dx[k];
        jmax = j + dy[k];
        if (isOK(i,j, imax, jmax))
        {
            if (a[imax][jmax] > a[i][j] && a[imax][jmax] - a[i][j] < minim)
            {
                minim = a[imax][jmax] - a[i][j];
                r1 = imax;
                r2 = jmax;
            }
        }
    }
    sol[r1][r2] = pas;
    cout <<"("<< r1 << "," << r2 <<")" << endl;
    back(r1, r2, pas + 1);
}

void f()
{
    citire();
    afisare(a);
    cout << endl << "(" << xi << " " << yi << ")" << endl;
    back(xi, yi, 2);
    cout << endl;
    afisare(sol);
}