#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Character(int** a, const int k, const int j)
{
	int S = 0;
	for (int i = 0; i < k; i++)
	{
		if (a[i][j] < 0 && !(a[i][j] % 2 == 0))
			S += abs(a[i][j]);
	}
	return S;
}
void Change(int** a, const int col1, const int col2, const int k)
{
	int tmp;
	for (int i = 0; i < k; i++)
	{
		tmp = a[i][col1];
		a[i][col1] = a[i][col2];
		a[i][col2] = tmp;
	}
}
void Sort(int** a, const int k, const int n)
{
	for (int i0 = 0; i0 < n - 1 ; i0++)
		for (int i1 = 0; i1 < n - i0 - 1; i1++)
			if (Character(a, k, i1) < Character(a, k, i1 + 1))
				Change(a, i1, i1 + 1, k);
}
int Sum(int** a, const int k, int n)
{
	for (int j = 0; j < n; j++)
	{
		int ifirst = 0;
		int s = 0;
		for (int i = 0; i < k; i++)
		{
			if (a[i][j] < 0 && ifirst < 0)
			{
				ifirst = i;
				break;
			}
		}
		for (int i = 0; i < k; i++)
			s += a[i][j];
		return s;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 15;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	//Create(a, k, n, Low, High);
	Input(a, k, n);
	Print(a, k, n);

	
	cout << "sum = " << Sum(a, k, n) << endl;

	Sort(a, k, n);
	Print(a, k, n);

	
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;

}