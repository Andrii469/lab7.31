#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

//≤“≈–¿÷≤…Õ»… —œŒ—≤¡

void CreateMatrix(int** a, const int n, const int low, const int high);
void PrintMatrix(int** a, const int n);
void Search(int** a, int* row, int* col, const int n);
int Suma(int** a, const int n, int S);
int find(int** a, const int n, int num);


int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n,
        low = -35, high = 45;


    cout << "¬‚Â‰≥Ú¸ ÓÁÏ≥ Í‚‡‰‡ÚÌÓø Ï‡ÚËˆ≥ (n*n): "; cin >> n;


    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    int* Row = new int[n];
    int* Col = new int[n];


    cout << "\\≤“≈–¿÷≤…Õ»… —œŒ—≤¡:" << endl; cout << endl;
    CreateMatrix(a, n, low, high);
    PrintMatrix(a, n); cout << endl;
    Search(a, Row, Col, n); cout << endl;
    cout << "\\CÛÏ‡ ÂÎÂÏÂÌÚ≥‚ Û ÚËı ˇ‰Í‡ı, ˇÍ≥ Ï≥ÒÚˇÚ¸ ıÓ˜‡ · Ó‰ËÌ ‚≥‰í∫ÏÌËÈ ÂÎÂÏÂÌÚ: ";
    cout << Suma(a, n, 0) << endl;

    delete[] Col;
    delete[] Row;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

//≤“≈–¿÷≤…Õ»… —œŒ—≤¡

void CreateMatrix(int** a, const int n, const int low, const int high)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = low + rand() % (high - low + 1);
}

void PrintMatrix(int** a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}
void Search(int** a, int* row, int* col, const int n)
{
    cout << "S=";
    for (int num = 0; num < n; num++)
    {
        int f = 0;
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            row[f] = a[num][i];
            col[f] = a[i][num];
            if (row[f] == col[f])
                r++;
            if (r == n)
                cout << setw(3) << num + 1;
            f++;
        }
    }
}
int Suma(int** a, const int n, int S)
{
    for (int num = 0; num < n; num++)
        if (find(a, n, num) < 0)
            for (int i = 0; i < n; i++)
                S += a[num][i];
    return S;
}
int find(int** a, const int n, int num)
{
    for (int i = 0; i < n; i++)
        if (a[num][i] < 0)
            return a[num][i];
}
