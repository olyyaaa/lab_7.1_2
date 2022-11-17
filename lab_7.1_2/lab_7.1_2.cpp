// lab_7.1_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** b, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	b[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(b, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(b, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** b, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << b[i][j];
	if (j < colCount - 1)
		Print(b, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(b, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Change(int** b, const int row1, const int row2, const int colCount, int j)
{
	int tmp;
	tmp = b[row1][j];
	b[row1][j] = b[row2][j];
	b[row2][j] = tmp;

	if (j < colCount - 1)
		Change(b, row1, row2, colCount, j + 1);
}
void Sort(int** b, const int rowCount, const int colCount, int i0, int i1)
{
	if ((b[i1][0] > b[i1 + 1][0])
		||
		(b[i1][0] == b[i1 + 1][0] &&
			b[i1][1] > b[i1 + 1][1])
		||
		(b[i1][0] == b[i1 + 1][0] &&
			b[i1][1] == b[i1 + 1][1] &&
			b[i1][3] > b[i1 + 1][3]))
		Change(b, i1, i1 + 1, colCount, 0);

	if (i1 < rowCount - i0 - 1 - 1)
		Sort(b, rowCount, colCount, i0, i1 + 1);
	else
		if (i0 < rowCount - 1 - 1)
			Sort(b, rowCount, colCount, i0 + 1, 0);
}
void Calc(int** b, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (b[i][j] % 2 != 0 || !(b[i][j] % 8 == 0))
	{
		S += b[i][j];
		k++;
		b[i][j] = 0;
	}

	if (j < colCount - 1)
		Calc(b, rowCount, colCount, S, k, i, j + 1);
	else
		if (i < rowCount - 1)
			Calc(b, rowCount, colCount, S, k, i + 1, 0);

}
int main()
{
	srand((unsigned)time(NULL));
	int i;
	int j;
	int Low = 8;
	int High = 73;
	int rowCount = 7;
	int colCount = 6;
	int tmp;
	int** b = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		b[i] = new int[colCount];
	Create(b, rowCount, colCount, Low, High, 0, 0);
	Print(b, rowCount, colCount, 0, 0);
	Sort(b, rowCount, colCount, 0, 0);
	Print(b, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	Calc(b, rowCount, colCount, S, k, 0, 0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(b, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] b[i];
	delete[] b;
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
