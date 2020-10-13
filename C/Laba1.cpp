#include <iostream>
using namespace std;


int **createMatrix(int n, int m) // Выделение памяти под матрицу
{
	int **matrix;
	matrix = new int *[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];
	return matrix;
}

void enterMatrix(int **matrix, int n, int m) // Ввод данных в матрицу
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "enter item [" << i << "] [" << j << "] = ";
			cin >> matrix[i][j];
		}
}

void viewMatrix(int** matrix, int n, int m)	// Просмотр матрицы
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << "["<<matrix[i][j]<<"]";
		cout << "\n";
	}
}

void clearMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
		delete []matrix[m];
}


void sumzerolines(int** matrix, int n, int m) // Сумма значений ячеек, не содержащих нулей
{
	int s = 0,c;
	for (int i = 0; i < n; i++)
	{
		c = 0;
		for (int j = 0; j < m; j++)
			if (matrix[i][j] != 0)
			{
				c++;
				if (c == m)
					for (int j = 0; j < m; j++)
						s = s + matrix[i][j];
			}
	}
	if (s == 0)
		cout << "none zero lines \n";
    else 
		cout << s <<"\n";
}

int main()
{
	int **a, n, m;
	cout << "enter n = "; cin >> n;
	cout << "enter m = "; cin >> m;

	a = createMatrix(n, m);
	enterMatrix(a, n, m);
	viewMatrix(a, n, m);
	sumzerolines(a, n, m);
	clearMatrix(a, n, m);
	system("pause");
	return 0;
}
 
