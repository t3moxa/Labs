#include <iostream>
using namespace std;

int n, N, i, j, M, k, v, f; //M - строки, N - коэффиценты
float key, z, c, nr, nrf = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* filein;
    const char* filename = "test.txt";
    filein = fopen(filename, "r");
    fscanf(filein, "%d", &M);
    fscanf(filein, "%d", &N);
    cout << M << " ";
    cout << N << "\n";
    float** DD = new float* [M];
    float* X = new float[M];
    if ((N + 1) > M)
        for (i = 0; i < N + 1; i++)
        {
            DD[i] = new float[i + 1];
        }
    else
        for (i = 0; i < M; i++)
        {
            DD[i] = new float[i + 1];
        }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N + 1; j++)
        {
            if (fscanf(filein, "%f", &key) != EOF)
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

    //Поиск на "нет решения" 
    for (f = 0; f < M; f++)
    {
        for (i = 0; i < M; i++)
        {
            if (!(f == i))
            {
                nrf = 1;
                for (j = 0; j < N; j++)
                {
                    if (!(DD[f][j] == DD[i][j]))
                        nrf = 0;
                }
            }
        }
    }
    if (nrf == 1)
    {
        cout << "Нет решения";
        exit(1);
    }
    for (i = 0; i < N - 1; i++)
    {
        v = i;             /*выбор ведущего элемента: A[v][i]*/
        for (j = i + 1; j < N; j++)
            if (abs(DD[j][i]) > abs(DD[v][i])) v = j;
        if (v != i)   /*перестановка  i–го уравнения с  v–м*/
            for (j = i; j <= N; j++)
            {
                z = DD[i][j]; DD[i][j] = DD[v][j]; DD[v][j] = z;
            }
        for (k = i + 1; k < N; k++) /*вычитание уравнений*/ //поправить для высоких матриц
        {
            c = DD[k][i] / DD[i][i];
            for (j = i; j <= N; j++)
                DD[k][j] -= c * DD[i][j];
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
    //Поиск на "нет решения" 2
    for (i = 0; i < M; i++)
    {
        nr = 0;
        for (j = 0; j < N; j++)
        {
            nr += DD[i][j];
        }
        if ((nr == 0) && (!(DD[i][N + 1] == 0)))
        {
            //|| ((!(nr = 0)) && (DD[i][N + 1] = 0)))
            nrf = 1;
        }
    }
    if (nrf == 1)
    {
        cout << "Нет решения";
        exit(1);
    }

    for (i = N - 1; i >= 1; i--)
    {
        for (k = 0; k <= i - 1; k++)     /*вычитание уравнений*/
        {
            c = DD[k][i] / DD[i][i];
            DD[k][N] -= c * DD[i][N];
            DD[k][i] = 0;
        }
    }

    for (i = 0; i < N; i++)
        X[i] = DD[i][N] / DD[i][i];

    cout << "\n";
    for (j = 0; j < M; j++)
    {
        cout << X[j] << " ";
    }
    delete DD;
}
