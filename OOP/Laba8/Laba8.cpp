using namespace std;
#include <iostream>

int M, N, i, j, k, ecode, ed;//N - вершины, M - рёбра
char c, cecode;
char s[2];
int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* fileout, * fileout2, * fileout3;
    const char* filename = "fileout.txt";
    const char* filename2 = "fileout2.txt";
    const char* filename3 = "fileout3.txt";
    fileout = fopen(filename, "w");
    cout << "Введите количество вершин и количество рёбер\n";
    cin >> N >> M;
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
    cout << "Введите номера вершин между которыми есть ребро: \n";
    for (k = 0; k < M; k++)
    {
        cin >> i >> j;
        DD[i][j] = 1;
        DD[j][i] = 1;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            fprintf(fileout, "%d ", DD[i][j]);
        fprintf(fileout, "\n");
    }

    fclose(fileout);

    fileout = fopen(filename, "r");
    fileout2 = fopen(filename2, "w");
    int* S = new int[N];
    int* L = new int[N];
    int* D = new int[N * 2];
    int** DD2 = new int* [N];
    for (i = 0; i < N; i++)
    {
        DD2[i] = new int[N + 3];
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            fscanf(fileout, "%u", &DD2[i][j]);
        }
    }
    k = 0;
    for (i = 0; i < N; i++)
    {
        ed = 0;
        for (j = 0; j < N; j++)
            if (DD2[i][j] == 1)
            {
                ed += 1;
                D[k] = j;
                k += 1;
            }
        L[i] = ed;
    }
    ed = 0;
    if (L[0] > 0)
        S[0] = 1;
    for (i = 1; i < N; i++)
    {
        S[i] = S[i - 1] + L[i - 1];
    }
    for (i = 0; i < N; i++)
        fprintf(fileout2, "%d ", S[i]);
    fprintf(fileout2, "\n");
    for (i = 0; i < N; i++)
        fprintf(fileout2, "%d ", L[i]);
    fprintf(fileout2, "\n");
    for (i = 0; i < N * 2; i++)
        if (D[i] >= 0)
            fprintf(fileout2, "%d ", D[i]);

    fclose(fileout);
    fclose(fileout2);

    fileout2 = fopen(filename2, "r");
    fileout3 = fopen(filename3, "w");

    int* S2 = new int[N];
    int* L2 = new int[N];
    int* D2 = new int[N * 2];
    int** DD3 = new int* [N];
    for (i = 0; i < N; i++)
    {
        DD3[i] = new int[N + 3];
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            DD3[i][j] = 0;
    }

    i = 0;
    while ((fscanf(fileout2, "%c", &c)) && (c != '\n'))
    {
        j = c - 48;
        if (j >= 0)
        {
            S2[i] = j;
            i++;
        }
    }
    i = 0;
    while ((fscanf(fileout2, "%c", &c)) && (c != '\n'))
    {
        j = c - 48;
        if (j >= 0)
        {
            L2[i] = j;
            i++;
        }
    }
    i = 0;
    while ((fscanf(fileout2, "%c", &c)) != EOF)
    {
        j = c - 48;
        if (j >= 0)
        {
            D2[i] = j;
            i++;
        }
    }
    j = 0;
    for (i = 0; i < N; i++)
    {
        if (i + 1 < N)
        {
            for (j = S2[i]; j < S2[i + 1]; j++)
            {
                if (DD3[i][D2[j - 1]] == 0)
                {
                    fprintf(fileout3, "%d", i);
                    fprintf(fileout3, "%d ", D2[j - 1]);
                    DD3[i][D2[j - 1]] = 1;
                    DD3[D2[j - 1]][i] = 1;
                }
            }
        }
        else
        {
            j = S2[i];
            while (D2[j - 1] >= 0)
            {
                if (DD3[i][D2[j - 1]] == 0)
                {
                    fprintf(fileout3, "%d", i);
                    fprintf(fileout3, "%d ", D2[j - 1]);
                    DD3[i][D2[j - 1]] = 1;
                    DD3[D2[j - 1]][i] = 1;
                }
                j++;
            }
        }
    }

    fclose(fileout2);
    fclose(fileout3);
}
