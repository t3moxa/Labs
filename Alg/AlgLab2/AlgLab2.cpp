#include <iostream>
using namespace std;

class HashTable
{
public:
    int q, r, s;
    char** Table;
    HashTable()
    {
        cout << "Size of the table:\n";
        cin >> q;
        Table = new char* [q];
        for (int i = 0; i < q; i++)
            Table[i] = NULL;
        cout << "r and s for second function:\n";
        cin >> r >> s;
    }
    static int Collision(int f1, HashTable t)
    {
        int s = 0;
        while ((f1 + s) != NULL)
            s += HashFunc2(f1, t);
        return s;
    }
    static int HashFunc(char* S, int L, HashTable t)
    {
        int f = 0;
        for (int i = 0; i < L; i++)
        {
            f += S[i];
            f = f % t.q * 31;
        }
        f = f % t.q;
        return f;
    }
    static int HashFunc2(int f1, HashTable t)
    {
        return f1 % t.r + t.s;
    }
    static void AddToTable(char* S, int L, HashTable t)
    {
        int f1 = HashFunc(S, L, t);
        int f2 = HashFunc2(f1, t);
        if (t.Table[f1] == NULL)
        {
            cout << "fit" << endl;
        }
        else
        {
            cout << "not fit" << endl;
            while (t.Table[f1] != NULL)
                f1 = (f1 + f2) % t.q;
        }
        t.Table[f1] = S;
        cout << S << " added" << endl;
    }
    static void ShowTable(HashTable t)
    {
        for (int i = 0; i < t.q; i++)
        {
            if (t.Table[i] == NULL)
                cout << "-" << endl;
            else
                cout << t.Table[i] << endl;
        }
    }
    static int SearchString(char* S, int L, HashTable t)
    {
        int f1 = HashFunc(S, L, t);
        int f2 = HashFunc2(f1, t);
        while (t.Table[f1] != NULL && t.Table[f1] != S)
            f1 = (f1 + f2) % t.q;
        if (t.Table[f1] == S)
            return f1;
        else
            return -1;
    }
    static void ShowString(int i, HashTable t)
    {
        cout << t.Table[i];
    }
};

char* RandString(int l)
{
    char* c = new char[l+1];
    for (int i = 0; i < l; i++)
    {
        c[i] = char('a' + rand() % ('z' - 'a'));
    }
    c[l] = '\0';
    return c;
}
int main()
{
    int l, i, amount;
    HashTable aboba;
    cout << "Enter amount of strings:\n";
    cin >> amount;
    cout << "Enter size of the strings:\n";
    cin >> l;
    char **c = new char*[amount];
    HashTable::ShowTable(aboba);
    for (i = 0; i < amount; i++)
    {
        c[i] = RandString(l);
        cout << c[i] << endl;
        if (HashTable::SearchString(c[i], l, aboba) == -1)
            HashTable::AddToTable(c[i], l, aboba);
    }
    cout << endl;
    HashTable::ShowTable(aboba);
    HashTable::ShowString(HashTable::SearchString(c[2], l, aboba), aboba);
}
