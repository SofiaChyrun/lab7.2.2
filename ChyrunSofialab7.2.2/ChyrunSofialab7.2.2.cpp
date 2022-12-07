// ChyrunSofialab7.2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_07_2.cpp
// < Чирун Софія >
// Лабораторна робота № 7.2.2
// Опрацювання багатовимірних масивів рекурсивним способом
// Варіант 18

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Min(int** a, int& jmin, const int k, int& min, int& imin, int i);
int Max(int** a, int& jmax, const int k, int& max, int& imax, int i);
void Change(int** a, const int k, const int n, int j);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 23;
	int k = 7;
	int n = 6;
	int min = High, imin = 0;
	int max = Low, imax = 0;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High, 0, 0);
	Print(a, k, n, 0, 0);
	Change(a, k, n, 0);
	Print(a, k, n, 0, 0);
	for (int i = 0; i < k; i++)
		delete[] a[i];
	    delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
	   Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
		   Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
	   Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
		   cout << endl;
		   Print(a, rowCount, colCount, i + 1, 0);
		}
		else
		   cout << endl << endl;
}

void Min(int** a, int& jmin, const int k, int& min, int& imin, int i)
{
	if (a[i][jmin] < min)
	{
	   min = a[i][jmin];
	   imin = i;
	}
	if (i < k - 1)
	   Min(a, jmin, k, min, imin, i + 1);
}

int Max(int** a, int& jmax, const int k, int& max, int& imax, int i)
{
	if (a[i][jmax] > max)
	{
	   max = a[i][jmax];
	   imax = i;
	}
	if (i < k - 1)
	   return Max(a, jmax, k, max, imax, i + 1);
	return max;
}

void Change(int** a, const int k, const int n, int j)
{
	int tmp, min, max, imin = 0, imax = 0, b;
	b = j + 1;
	min = a[imin][b];
	Min(a, b, k, min, imin, 0);
	cout << min << "  " << imin << endl;
	max = a[imax][j];
	Max(a, j, k, max, imax, 0);
	cout << max << "  " << imax << endl;
	tmp = a[imax][j];
	a[imax][j] = a[imin][b];
	a[imin][b] = tmp;
	imax = 0;
	imin = 0;
	if (j < n - 2)
	   Change(a, k, n, j + 2);
}