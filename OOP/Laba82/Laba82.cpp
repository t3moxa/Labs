#include <iostream>
using namespace std;
int i, t, j, k, N, M, r1, r2, q, B, E, r, nom, R[20], DD[20][20];//N - вершины, M - рёбра

void deеp(int k)
{
    int i;
    for (i = 0; i < N; i++)
        if ((DD[k][i] == 1) && (R[i] == 0))
        {
            nom++;
            R[i] = nom;
            deеp(i);
        }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* filein, * fileout;
    const char* fileinname = "filein.txt";
    const char* fileoutname = "fileout.txt";
    filein = fopen(fileinname, "r");
    fileout = fopen(fileoutname, "w");
    fscanf(filein, "%d", &N);
    fscanf(filein, "%d", &M);
    fscanf(filein, "%d", &B);
    fscanf(filein, "%d", &E);
    int* S = new int[N];
    int* L = new int[N];
    int* D = new int[M];
    int* P = new int[N];
    int* V = new int[N];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            DD[i][j] = 0;
    }
    r1 = r2 = 1;
    while (!((r1 == 0) && (r2 == 0)))
    {
        fscanf(filein, "%d", &r1);
        fscanf(filein, "%d", &r2);
        if ((r1 == 0) && (r2 == 0))
            break;
        DD[r1][r2] = 1;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            cout << DD[i][j] << " ";
        cout << "\n";
    }
    k = 0;
    for (i = 0; i < N; i++)
    {
        q = 0;
        for (j = 0; j < N; j++)
            if (DD[i][j] == 1)
            {
                q += 1;
                D[k] = j;
                k += 1;
            }
        L[i] = q;
    }
    q = 0;
    S[0] = 0;
    for (i = 1; i < N; i++)
    {
        S[i] = S[i - 1] + L[i - 1];
    }
    for (i = 0; i < N; i++)
        cout << S[i] << " ";
    cout << "\n";
    for (i = 0; i < N; i++)
        cout << L[i] << " ";
    cout << "\n";
    for (i = 0; i < M; i++)
        cout << D[i] << " ";
    cout << "\n";

    P[0] = B; r = 0; t = 0; //очередь из одной вершины a
    for (i = 0; i < N; i++) V[i] = 0;
    V[B] = 1; //уровень для вершины a
    while (t <= r)
    {
        k = P[t];
        q = V[k] + 1;
        for (i = S[k]; i <= S[k] + L[k] - 1; i++)
        {
            j = D[i];
            if (V[j] == 0)
            {
                V[j] = q;
                r++;
                P[r] = j;
            }
        }
        t++;
    }


    for (i = 0; i < N; i++)
        cout << V[i] << " ";
    cout << "\n";
    for (i = 0; i < N; i++)
        cout << P[i] << " ";
    cout << "\n";
    cout << r << " " << t;
}
