#include <iostream>
#include <fstream>
using namespace std;

ifstream read("in.txt");

//Se da o tabla de sah cu dimensiunea NxN. Un cal se gaseste in linia 1 si coloana 1. Gasiti un sir de mutari ale calului astfel


//incat acesta sa acopere intreaga tabla de sah fara a trece printr-o casuta de 2 ori.
#include    <iostream>

using namespace std;

int n;
int matrice[105][105], xi = 0, yi = 0;

const int directii = 8;
const int di[directii] = { -2, -1, 1, 2,  2,  1, -1, -2 };
const int dj[directii] = { 1,  2, 2, 1, -1, -2, -2, -1 };

void Citire()
{
    cin >> n;
    cin >> xi >> yi;
    matrice[xi][yi] = 1;
}

bool isFull()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrice[i][j] == 0)
                return false;
    return true;
}

void Solutie()
{
    static int w = 1;

    cout << "Solutia nr. " << w << ": \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrice[i][j] << " ";
        cout << "\n";
    }

    w++;
    cout << "\n\n";

}

bool isOK(int i, int j)
{
    if (i > n - 1 || i < 0)
        return false;
    if (j > n - 1 || j < 0)
        return false;
    if (matrice[i][j])
        return false;

    return true;
}

void Rezolvare(int x, int y)
{
    static int r = 2;
    if (isFull())
    {
        Solutie();
        //exit(1);
        return;
    }
    for (int i = 0; i < directii; i++)
    {
        int imax = x + di[i];
        int jmax = y + dj[i];
        if (isOK(imax, jmax))
        {
            matrice[imax][jmax] = r++;
            Rezolvare(imax, jmax);
            matrice[imax][jmax] = 0;
            r--;
        }
    }
}

void sol()
{
    Citire();
    Rezolvare(xi, yi);
   
    

}