#include <iostream>
using namespace std;
//Метод Данилевского, вариант 5
int n, i, j, z, x, c, rootNumber = 0;
double BorderHigh, BorderLow, BorderSCenter, BorderSHigh, BorderSLow, Step, eps;
double poly(double*kf, int n, double x);
void dih(double*kf,double* roots, double BH, double BL);
int main()
{
	eps = 0.00000000001;
	setlocale(LC_ALL, "Russian");
	cout << "Введите число неизвестных переменных \n";
	cin >> n;
	double** A = new double* [n];
	for (i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}
	if (n == 7)
	{
		n = 4;
		A[0][0] = 2.4; A[0][1] = 0.5; A[0][2] = 2; A[0][3] = 1; A[1][0] = 0.5; A[1][1] = 1; A[1][2] = 0.8; A[1][3] = 2; A[2][0] = 2; A[2][1] = 0.8; A[2][2] = 1; A[2][3] = 0.5; A[3][0] = 1; A[3][1] = 2; A[3][2] = 0.5; A[3][3] = 1.2;
	}
	else
	{
		cout << "Введите матрицу \n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> A[i][j];
			}
		}
	}
	double* kf = new double[n];
	double* roots = new double[n];//Лямба - корни полинома, собственные числа матрицы А
	double*** M = new double** [n];
	for (i = 0; i < n - 1; i++)
	{
		M[i] = new double* [n];
		for (j = 0; j < n; j++)
		{
			M[i][j] = new double[n];
		}
	}
	double*** Mr = new double** [n];
	for (i = 0; i < n - 1; i++)
	{
		Mr[i] = new double* [n];
		for (j = 0; j < n; j++)
		{
			Mr[i][j] = new double[n];
		}
	}
	double** Ainit = new double* [n];
	for (i = 0; i < n; i++)
	{
		Ainit[i] = new double[n];
	}
	double** Atemp = new double* [n];
	for (i = 0; i < n; i++)
	{
		Atemp[i] = new double[n];
	}
	double** Atemp2 = new double* [n];
	for (i = 0; i < n; i++)
	{
		Atemp2[i] = new double[n];
	}
	double** S = new double* [n];//Матрица из перемноженных M
	for (i = 0; i < n; i++)
	{
		S[i] = new double[n];
	}
	double** X = new double* [n];//Матрица собственных векторов
	for (i = 0; i < n; i++)
	{
		X[i] = new double[n];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			X[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Ainit[i][j] = A[i][j];
		}
	}
	cout << "Исходная матрица \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%3.2f   ", A[i][j]);
		}
		cout << "\n";
	}
	for (z = 0; z < n - 1; z++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == j)
					M[z][i][j] = 1;
				else
					M[z][i][j] = 0;
			}
		}
	}
	for (z = 0; z < n - 1; z++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == j)
					Mr[z][i][j] = 1;
				else
					Mr[z][i][j] = 0;
			}
		}
	}
	for (z = n - 1; z > 0; z--)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				Atemp[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				Atemp2[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++)
		{
			if (z - 1 == i)
			{
				if (A[z][z - 1] == 0)
				{
					cout << "\nДелитель равен нулю, метод неприменим";
					exit(0);
				}
				M[abs(n - 1 - z)][z - 1][i] = 1 / A[z][z - 1];
			}
			else
			{
				if (A[z][z - 1] == 0)
				{
					cout << "\nДелитель равен нулю, метод неприменим";
					exit(0);
				}
				M[abs(n - 1 - z)][z - 1][i] = (-1) * A[z][i] / A[z][z - 1];
			}
			Mr[abs(n - 1 - z)][z - 1][i] = A[z][i];
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (x = 0; x < n; x++)
				{
					Atemp[i][j] = Atemp[i][j] + Mr[abs(n - 1 - z)][i][x] * A[x][j];
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (x = 0; x < n; x++)
				{
					Atemp2[i][j] = Atemp2[i][j] + Atemp[i][x] * M[abs(n - 1 - z)][x][j];
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				A[i][j] = Atemp2[i][j];
			}
		}
	}
	cout << "Матрица в канонической форме Фробениуса \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%3.2f   ", A[i][j]);
		}
		cout << "\n";
	}
	for (i = 0; i < n; i++)
	{
		kf[i] = (-1) * A[0][i];
	}
	BorderLow = -10000; BorderHigh = 10000; BorderSLow = BorderLow; Step = (abs(BorderHigh) + abs(BorderLow)) / 1000000; BorderSHigh = BorderSLow + Step;
	while (BorderSHigh < BorderHigh)
	{
		if (poly(kf, n, BorderSLow) * poly(kf, n, BorderSHigh) < 0)
		{
			dih(kf, roots, BorderSHigh, BorderSLow);
		}
		BorderSHigh = BorderSHigh + Step;
		BorderSLow = BorderSLow + Step;
	}
	cout << "Корни собственного многочлена матрицы А:\n";
	for (i = 0; i < n; i++)
	{
		cout << roots[i] << " ";
	}
	cout << "\n";
	/*for (i = 0; i < n; i++)
	{
		if (abs(poly(kf, n, roots[i])) < eps)
		{
			cout << "Неточно";
		}
	}*/
	for (z = 0; z < n - 2; z++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				Atemp[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (x = 0; x < n; x++)
				{
					Atemp[i][j] = Atemp[i][j] + M[z][i][x] * M[z + 1][x][j];
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				M[z + 1][i][j] = Atemp[i][j];
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				S[i][j] = Atemp[i][j];
			}
		}
	}
	cout << "Матрица S: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3.2f   ", S[i][j]);
		}
		cout << "\n";
	}
	for (z = 0; z < n; z++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				X[i][z] = X[i][z] + S[i][j] * pow(roots[z], abs(j - n + 1));
			}
		}
	}
	cout << "Матрица собственных векторов: \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%3.2f   ", X[i][j]);
		}
		cout << "\n";
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Atemp[i][j] = 0;
		}
	}
	for (z = 0; z < n; z++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				Atemp[i][z] = Atemp[i][z] + Ainit[i][j] * X[j][z];
			}
		}
	}
	cout << "Матрица А и собственные числа, поочерёдно умноженные на собственные вектора: \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << Atemp[i][j] << "  " << roots[j] * X[i][j] << "\n";
		}
		cout << "---\n";
	}
}

double poly(double* kf, int n, double x)
{
	double result = 0;
	for (int i = 0; i < n+1; i++)
	{
		if (i == 0)
			result = result + pow(x, abs(i - n));
		else
			result = result + kf[i - 1] * pow(x, abs(i - n));
	}
	return result;
}

void dih(double* kf,double *roots, double BH, double BL)
{
	double BC = (BH + BL)/2;
	if (abs(BC - BH) > eps)
	{
		if ((poly(kf, n, BC) * poly(kf, n, BH)) < 0)
			dih(kf, roots, BH, BC);
		else
			dih(kf, roots, BC, BL);
	}
	else
	{
		roots[rootNumber] = BC;
		rootNumber++;
	}
}