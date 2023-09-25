#include <iostream>
using namespace std;

int N, M, M2, i, j,nrf,v,k,f,temp,p,r,u,h;//M - строки, N - коэффиценты
double key, eps = 0.00001,nr,c,z,k11,k12,k21,k22,k31,k32;

void main()
{
    setlocale(LC_ALL, "Russian");
    FILE* filein;
    const char* filename = "test.txt";
    filein = fopen(filename, "r");
    fscanf(filein, "%d", &M);
    fscanf(filein, "%d", &N);
    cout << M << " ";
    cout << N << "\n";
    double** DD = new double* [M];
    if ((N + 1) > M)
        for (i = 0; i < N + 1; i++)
        {
            DD[i] = new double[N+10];
        }
    else
        for (i = 0; i < M; i++)
        {
            DD[i] = new double[M+10];
        }
    cout << "Выберите номер задачи ";
    cin >> h;
    if (h == 3)
    {
        double** DD2 = new double* [M];
        if ((N + 1) > M)
            for (i = 0; i < N + 1; i++)
            {
                DD2[i] = new double[N + 10];
            }
        else
            for (i = 0; i < M; i++)
            {
                DD2[i] = new double[M + 10];
            }
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (fscanf(filein, "%lf", &key) != EOF)
                {
                    DD2[i][j] = key;
                }
            }
        }
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                DD[i][j] = DD2[i][j];
            }
        }
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                cout << DD[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        int* L = new int[M];
        float* X = new float[M];

        for (i = 0; i < N; i++) L[i] = i;

        i = 0;
        if (N < M) r = N; else r = M;
        while (i < r)
        {     /*выбор ведущего элемента A[v][u]*/
            v = i; u = i;
            for (j = i; j < M; j++)
                for (k = i; k < N; k++)
                    if (abs(DD[j][k]) > abs(DD[v][u]))
                    {
                        v = j; u = k;
                    }

            if (abs(DD[v][u]) < eps) r = i;
            else
            {/*перестановка  строк*/
                if (v != i)  /*перестановка  i-го уравнения с  v-м*/
                    for (j = i; j <= N; j++)
                    {
                        z = DD[i][j]; DD[i][j] = DD[v][j]; DD[v][j] = z;
                    }

                /*перестановка столбцов*/
                if (u != i) /* перестановка  i-го столбца с u-м*/
                {
                    for (k = 0; k < M; k++)
                    {
                        z = DD[k][i]; DD[k][i] = DD[k][u]; DD[k][u] = z;
                    }
                    p = L[i]; L[i] = L[u]; L[u] = p;
                }

                /*деление  i-й строки на  A[i][i]*/
                c = DD[i][i];
                for (j = i; j <= N + 1; j++) DD[i][j] /= c;

                /*вычитание уравнений*/
                for (k = 0; k < M; k++)
                    if (k != i)
                    {
                        c = DD[k][i];
                        for (j = i; j <= N; j++) DD[k][j] -= c * DD[i][j];
                    }

                i++;
            }
        }

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                cout << DD[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        i = r;
        while (i < M && abs(DD[i][N]) < eps) i++;
        if (i < M)
        {
                cout << "Точки пересечения не существует";
                exit(1);
        }
        else if (r == N) /*решение системы единственное*/
        {
                k11 = DD[0][N];
                k12 = DD[1][N];
        }

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                DD[i][j] = DD2[i+1][j];
            }
        }
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                cout << DD[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        for (i = 0; i < N; i++) L[i] = i;

        i = 0;
        if (N < M) r = N; else r = M;
        while (i < r)
        {     /*выбор ведущего элемента A[v][u]*/
            v = i; u = i;
            for (j = i; j < M; j++)
                for (k = i; k < N; k++)
                    if (abs(DD[j][k]) > abs(DD[v][u]))
                    {
                        v = j; u = k;
                    }

            if (abs(DD[v][u]) < eps) r = i;
            else
            {/*перестановка  строк*/
                if (v != i)  /*перестановка  i-го уравнения с  v-м*/
                    for (j = i; j <= N; j++)
                    {
                        z = DD[i][j]; DD[i][j] = DD[v][j]; DD[v][j] = z;
                    }

                /*перестановка столбцов*/
                if (u != i) /* перестановка  i-го столбца с u-м*/
                {
                    for (k = 0; k < M; k++)
                    {
                        z = DD[k][i]; DD[k][i] = DD[k][u]; DD[k][u] = z;
                    }
                    p = L[i]; L[i] = L[u]; L[u] = p;
                }

                /*деление  i-й строки на  A[i][i]*/
                c = DD[i][i];
                for (j = i; j <= N + 1; j++) DD[i][j] /= c;

                /*вычитание уравнений*/
                for (k = 0; k < M; k++)
                    if (k != i)
                    {
                        c = DD[k][i];
                        for (j = i; j <= N; j++) DD[k][j] -= c * DD[i][j];
                    }

                i++;
            }
        }

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                cout << DD[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        i = r;
        while (i < M && abs(DD[i][N]) < eps) i++;
        if (i < M)
        {
            cout << "Точки пересечения не существует";
            exit(1);
        }
        else if (r == N) /*решение системы единственное*/
        {
            k21 = DD[0][N];
            k22 = DD[1][N];
        }

            i = 0;
            for (j = 0; j < N + 1; j++)
            {
                DD[i][j] = DD2[i][j];
            }
            i = 2;
            for (j = 0; j < N + 1; j++)
            {
                DD[1][j] = DD2[i][j];
            }

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                cout << DD[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        for (i = 0; i < N; i++) L[i] = i;

        i = 0;
        if (N < M) r = N; else r = M;
        while (i < r)
        {     /*выбор ведущего элемента A[v][u]*/
            v = i; u = i;
            for (j = i; j < M; j++)
                for (k = i; k < N; k++)
                    if (abs(DD[j][k]) > abs(DD[v][u]))
                    {
                        v = j; u = k;
                    }

            if (abs(DD[v][u]) < eps) r = i;
            else
            {/*перестановка  строк*/
                if (v != i)  /*перестановка  i-го уравнения с  v-м*/
                    for (j = i; j <= N; j++)
                    {
                        z = DD[i][j]; DD[i][j] = DD[v][j]; DD[v][j] = z;
                    }

                /*перестановка столбцов*/
                if (u != i) /* перестановка  i-го столбца с u-м*/
                {
                    for (k = 0; k < M; k++)
                    {
                        z = DD[k][i]; DD[k][i] = DD[k][u]; DD[k][u] = z;
                    }
                    p = L[i]; L[i] = L[u]; L[u] = p;
                }

                /*деление  i-й строки на  A[i][i]*/
                c = DD[i][i];
                for (j = i; j <= N + 1; j++) DD[i][j] /= c;

                /*вычитание уравнений*/
                for (k = 0; k < M; k++)
                    if (k != i)
                    {
                        c = DD[k][i];
                        for (j = i; j <= N; j++) DD[k][j] -= c * DD[i][j];
                    }

                i++;
            }
        }

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                cout << DD[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        i = r;
        while (i < M && abs(DD[i][N]) < eps) i++;
        if (i < M)
        {
            cout << "Точки пересечения не существует";
            exit(1);
        }
        else if (r == N) /*решение системы единственное*/
        {
            cout << "Координаты точек пересечения \n";
            k31 = DD[0][N];
            k32 = DD[1][N];
        }
        cout << k11 << "," << k12 << " " << k21 << "," << k22 << " " << k31 << "," << k32 << "\n";
        cout << "Площадь треугольника равна " << 0.5 * abs(k11*(k21 - k32)+k22*(k32 - k12)+k31*(k12 - k21));
    }
    else
    {
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                if (fscanf(filein, "%lf", &key) != EOF)
                {
                    DD[i][j] = key;
                }
            }
        }
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                cout << DD[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        int* L = new int[M];
        float* X = new float[M];

        for (i = 0; i < N; i++) L[i] = i;

        i = 0;
        if (N < M) r = N; else r = M;
        while (i < r)
        {     /*выбор ведущего элемента A[v][u]*/
            v = i; u = i;
            for (j = i; j < M; j++)
                for (k = i; k < N; k++)
                    if (abs(DD[j][k]) > abs(DD[v][u]))
                    {
                        v = j; u = k;
                    }

            if (abs(DD[v][u]) < eps) r = i;
            else
            {/*перестановка  строк*/
                if (v != i)  /*перестановка  i-го уравнения с  v-м*/
                    for (j = i; j <= N; j++)
                    {
                        z = DD[i][j]; DD[i][j] = DD[v][j]; DD[v][j] = z;
                    }

                /*перестановка столбцов*/
                if (u != i) /* перестановка  i-го столбца с u-м*/
                {
                    for (k = 0; k < M; k++)
                    {
                        z = DD[k][i]; DD[k][i] = DD[k][u]; DD[k][u] = z;
                    }
                    p = L[i]; L[i] = L[u]; L[u] = p;
                }

                /*деление  i-й строки на  A[i][i]*/
                c = DD[i][i];
                for (j = i; j <= N + 1; j++) DD[i][j] /= c;

                /*вычитание уравнений*/
                for (k = 0; k < M; k++)
                    if (k != i)
                    {
                        c = DD[k][i];
                        for (j = i; j <= N; j++) DD[k][j] -= c * DD[i][j];
                    }

                i++;
            }
        }

        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N + 1; j++)
            {
                cout << DD[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        i = r;
        while (i < M && abs(DD[i][N]) < eps) i++;
        if (i < M)
        {
            if (h == 1)
                cout << "Точки пересечения не существует";
        }
        else if (r == N) /*решение системы единственное*/
        {
            if (h == 1)
            {
                cout << "Координаты точки пересечения \n";
                for (j = 0; j < N; j++)
                    X[L[j]] = DD[j][N];
                i = 0;
                while (X[i] > -1000)
                {
                    cout << X[i] << " ";
                    i++;
                }
            }
            if (h == 2)
            {
                cout << "Координаты точки пересечения \n";
                for (j = 0; j < N; j++)
                    X[L[j]] = DD[j][N];
                i = 0;
                while (X[i] > -1000)
                {
                    cout << X[i] << " ";
                    i++;
                }
            }
        }
        else
        {
            if (h == 1)
                cout << "Cистема имеет бесконечное множество решений \n";
            if (h == 2)
                cout << "Три плоскости проходят через одну прямую - система имеет бесконечное множество решений \n";
            for (i = r; i < N; i++)
                {
                    cout << "Введите значение переменной " << L[i] + 1 << " - ";
                    cin >> X[L[i]];
                }
                for (j = 0; j < r; j++)
                {
                    X[L[j]] = DD[j][N];
                    for (k = r; k < N; k++)
                        X[L[j]] -= DD[j][k] * X[L[k]];
                }
        
            if (h == 1)
            {
                cout << "Точка пересечения прямых: \n";
                for (i = 0; i < N-1; i++)
                {
                    cout << X[i] << " ";
                }
            }
            if (h == 2)
            {
                cout << "Точка пересечения плоскостей: \n";
                for (i = 0; i < N - 1; i++)
                {
                    cout << X[i] << " ";
                }
            }
        }
    }
}