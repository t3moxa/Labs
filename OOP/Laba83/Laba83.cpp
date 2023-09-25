using namespace std;
#include <iostream>
int L[22][22], i, j, n, ib, ik, jk, jb;
int Pi[401], Pj[401], r, t, q, k;
int Mi[401], Mj[401];
char S[21], c;

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* filein;
    const char* fileinname = "filein.txt";
    filein = fopen(fileinname, "r");
    fscanf(filein, "%d", &n);
    for (i = 0; i <= n; i++)
    {
        j = 1;
        while ((fscanf(filein, "%c", &c)) && (c != '\n'))
        {
            cout << c;
            if (c == '-')
                L[i][j] = 0;
            else
                L[i][j] = 1000;
            j++;
        }
        cout << "\n";
    }
    for (j = 0; j <= n + 1; j++)
    {
        L[0][j] = 1000; L[n + 1][j] = 1000;
    }
    for (i = 1; i <= n; i++)
    {
        L[i][0] = 1000; L[i][n + 1] = 1000;
    }
    fscanf(filein, "%d%d", &ib, &jb);
    fscanf(filein, "%d%d", &ik, &jk);
    for (i = 0; i <= n + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
            cout << L[i][j] << " ";
        cout << "\n";
    }

    Pi[1] = ib; Pj[1] = jb; r = 1; t = 1;
    L[ib][jb] = 1;
    while (t <= r)
    {
        i = Pi[t]; j = Pj[t]; q = L[i][j] + 1;
        if (L[i - 1][j] == 0)
        {
            L[i - 1][j] = q; r++; Pi[r] = i - 1; Pj[r] = j;
        }
        if (L[i][j - 1] == 0)
        {
            L[i][j - 1] = q; r++; Pi[r] = i; Pj[r] = j - 1;
        }
        if (L[i + 1][j] == 0)
        {
            L[i + 1][j] = q; r++; Pi[r] = i + 1; Pj[r] = j;
        }
        if (L[i][j + 1] == 0)
        {
            L[i][j + 1] = q; r++; Pi[r] = i; Pj[r] = j + 1;
        }
        if (L[i + 1][j + 1] == 0)
        {
            L[i + 1][j + 1] = q; r++; Pi[r] = i + 1; Pj[r] = j + 1;
        }
        if (L[i - 1][j + 1] == 0)
        {
            L[i - 1][j + 1] = q; r++; Pi[r] = i - 1; Pj[r] = j + 1;
        }
        if (L[i + 1][j - 1] == 0)
        {
            L[i + 1][j - 1] = q; r++; Pi[r] = i + 1; Pj[r] = j - 1;
        }
        if (L[i - 1][j - 1] == 0)
        {
            L[i - 1][j - 1] = q; r++; Pi[r] = i - 1; Pj[r] = j - 1;
        }
        t++;
    }
    for (i = 0; i <= n + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
            cout << L[i][j] << " ";
        cout << "\n";
    }
    k = L[ik][jk]; i = ik; j = jk;
    while (k > 0)
    {
        Mi[k] = i;
        Mj[k] = j;
        if (L[i - 1][j] < L[i][j])
            i--;
        else if (L[i][j - 1] < L[i][j])
            j--;
        else if (L[i + 1][j] < L[i][j])
            i++;
        else if (L[i][j + 1] < L[i][j])
            j++;
        else if (L[i - 1][j - 1] < L[i][j])
        {
            i--;
            j--;
        }
        else if (L[i + 1][j - 1] < L[i][j])
        {
            i++;
            j--;
        }
        else if (L[i - 1][j + 1] < L[i][j])
        {
            i--;
            j++;
        }
        else if (L[i + 1][j + 1] < L[i][j])
        {
            i++;
            j++;
        }
        k--;
    }
    for (i = 1; i <= L[ik][jk]; i++)
    {
        cout << Mi[i] << " ";
    }
    cout << "\n";
    for (i = 1; i <= L[ik][jk]; i++)
    {
        cout << Mj[i] << " ";
    }
    cout << "\n";
    for (i = 1; i <= L[ik][jk]; i++)
        L[Mi[i]][Mj[i]] = 1001;
    for (i = 0; i <= n + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
            cout << L[i][j] << " ";
        cout << "\n";
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (L[i][j] == 1001)
                cout << "*";
            else if (L[i][j] == 1000)
                cout << "#";
            else
                cout << "-";
        }
        cout << "\n";
    }
}