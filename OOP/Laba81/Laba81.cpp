using namespace std;
#include <iostream>
int r1, r2, i, k, j, N, M, q, C[20], S[20], D[40], L[20], Comp[20], cnt; //N - вершины, M - рёбра
void cdeеp(int k)
{
    int i, j;
    for (i = S[k]; i < S[k] + L[k]; i++)
    {
        j = D[i];
        if (C[j] == 0)
        {
            C[j] = q;
            cdeеp(j);
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int length;
    cin >> length;
    if (length > 20)
    {
        cout << "Length is too big";
        exit(0);
    }
    char* A = new char[length];
    srand(time(NULL));
    cout << A << "\n";
    for (int i = 0; i < length; i++)
    {
        A[i] = rand() % 26 + 97;
        cout << A[i] << i;
    }
    A[length] = '\0';
    cout << "\n" << A;
    //return A;
    /*
    FILE* filein, *fileout;
    const char* fileinname = "filein.txt";
    const char* fileoutname = "fileout.txt";
    filein = fopen(fileinname, "r");
    fileout = fopen(fileoutname, "w");
    fscanf(filein, "%d", &N);
    fscanf(filein, "%d", &M);
    int** DD = new int* [N];
    for (i = 0; i < N; i++)
    {
        DD[i] = new int[N + 3];
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            DD[i][j] = 0;
    }
    r1 = r2 = 1;
    while (!((r1 == 0)&&(r2 == 0)))
    {
        fscanf(filein, "%d", &r1);
        fscanf(filein, "%d", &r2);
        if ((r1 == 0) && (r2 == 0))
            break;
        DD[r1][r2] = 1;
        DD[r2][r1] = 1;
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
    for (i = 1; i < N; i++)
    {
        S[i] = S[i - 1] + L[i - 1];
    }
    for (i = 0; i < N; i++)
        cout << S[i];
    cout << "\n";
    for (i = 0; i < N; i++)
        cout << L[i];
    cout << "\n";
    for (i = 0; i < M*2; i++)
        cout << D[i];
    for (i = 0; i < N; i++)
        C[i] = 0;
    q = 0;
    for (i = 0; i < N; i++)
        if (C[i] == 0)
        {
            q++;
            C[i] = q;
            cdeеp(i);
        }
    i = 0;
    while (C[i]>0)
    {
        Comp[C[i]] += 1;
        i++;
    }
    i = 1;
    cnt = 0;
    while (Comp[i]>0)
    {
        fprintf(fileout, "Вершин, принадлежащих %d-му генеалогическому дереву - %d, номера этих вершин - ", i, Comp[i]);
        j = 0;
        i++;
        cnt++;
        for (j = 0; j < N; j++)
            if (C[j]==cnt)
                fprintf(fileout, " %d,", j);
        fprintf(fileout, "\n");
    }
    fprintf(fileout, "Всего несвязанных генеалогических деревьев: %d", cnt);
    */
}