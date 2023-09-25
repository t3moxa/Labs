using namespace std;
#include <iostream>
int n, i, j, maxi;
float eps, currII, maxR, sumA = 0;
//Максимальная невязка меньше эпсилон - точность достигнута
int main()
{
	eps = 0.0000001;
	setlocale(LC_ALL, "Russian");
	cout << "Введите число неизвестных переменных \n";
	cin >> n;
	float** A = new float* [n];
	for (i = 0; i < n; i++)
	{
		A[i] = new float[n+1];
	}
	if (n == 6)
	{
		n = 3;
		A[0][0] = -10; A[0][1] = -2; A[0][2] = -2; A[0][3] = 6; A[1][0] = -1; A[1][1] = 10; A[1][2] = -2; A[1][3] = 7; A[2][0] = -1; A[2][1] = -1; A[2][2] = 10; A[2][3] = 8;
	}
	else
	{
		cout << "Введите матрицу \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				cin >> A[i][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		sumA = abs(A[i][i]);
		for (j = 0; j < n; j++)
		{
			if (i!=j)
			sumA = sumA - abs(A[i][j]);
		}
		if (sumA < 0)
		{
			cout << "\nУсловие сходимости не выполняется";
			exit(0);
		}
	}
	cout << "Условие сходимости выполняется\n";
	float** Ainit = new float* [n];
	for (i = 0; i < n; i++)
	{
		Ainit[i] = new float[n+1];
	}
	float** Atran = new float* [n];
	for (i = 0; i < n; i++)
	{
		Atran[i] = new float[n + 1];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			Ainit[i][j] = A[i][j];
		}
	}
	cout << "Исходная матрица:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	for (i = 0; i < n; i++)
	{
		currII = A[i][i];
		for (j = 0; j < n + 1 ; j++)
		{
			if (j == n)
				A[i][j] = A[i][j] /currII;
			else
				A[i][j] = (-1) * A[i][j] / currII;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			Atran[i][j] = A[i][j];
		}
	}
	cout << "Преобразованная матрица:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			printf("%3.2f   ", A[i][j]);
		}
		cout << "\n";
	}
	float* V = new float[n];
	for (i = 0; i < n; i++)
	{
		V[i] = i+1;
	}
	float* R = new float[n];
	for (i = 0; i < n; i++)
	{
		R[i] = 0;
		for (j = 0; j < n+1; j++)
		{
			R[i] = R[i] + A[i][j];
		}
		cout << R[i] << " ";
	}
	float sumR = 0;
	float sumAllR = 0;
	for (i = 0; i < n; i++)
	{
		sumAllR = sumAllR + abs(R[i]);
	}
	while (abs(sumAllR) > eps*n)
	{
		sumR = 0;
		maxR = 0;
		for (i = 0; i < n; i++)
		{
			if (abs(R[i]) > abs(maxR))
			{
				maxR = R[i];
				maxi = i;
			}
		}
		cout << "\n";
		cout << maxR << " eto nevyazka";
		for (i = 0; i < n + 1; i++)
		{
			if (i != maxi)
			{
				sumR = sumR + A[maxi][i];
			}
		}
		V[maxi] = V[maxi]*(-sumR/A[maxi][maxi]);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				A[i][j] = Atran[i][j];
				if (j!=n)
					A[i][j] = A[i][j] * V[j];
			}
		}
		for (i = 0; i < n; i++)
		{
			R[i] = 0;
			for (j = 0; j < n + 1; j++)
			{
				R[i] = R[i] + A[i][j];
			}
		}
		sumAllR = 0;
		for (i = 0; i < n; i++)
		{
			sumAllR = sumAllR + abs(R[i]);
		}
	}
	cout << "Корни уравнения:\n";
	for (i = 0; i < n; i++)
	{
		printf("%3.2f   ", V[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Ainit[i][j] = Ainit[i][j] * V[j];
		}
	}
	cout << "\n";
	cout << "Матрица с подставленными корнями: \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			printf("%3.2f   ", Ainit[i][j]);
		}
		cout << "\n";
	}
	cout << "Проверка:\n";
	for (i = 0; i < n; i++)
	{
		sumR = 0;
		for (j = 0; j < n; j++)
		{
			sumR = sumR + Ainit[i][j];
		}
		cout << sumR << " = " << Ainit[i][n] << "\n";
	}
}