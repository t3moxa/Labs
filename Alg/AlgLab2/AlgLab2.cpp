#include <iostream>
using namespace std;

class HashTable
{
public:
    int q, r, s, CompareAmount;
    const char** Table;
    // const char * const * const Table = {};
    HashTable()
    {
        CompareAmount = 0;
        cout << "Size of the table:\n";
        cin >> q;
        Table = new const char* [q];
        for (int i = 0; i < q; i++)
            Table[i] = NULL;
        cout << "r and s for second function:\n";
        cin >> r >> s;
    }
    static int HashFunc(const char* S, int L, int q)
    {
        int f = 0;
        for (int i = 0; i < L; i++)
        {
            f += S[i];
            f = f % q * 31;
        }
        f = f % q;
        return f;
    }
    static int HashFunc2(int f1, HashTable t)
    {
        return f1 % t.r + t.s;
    }
    static void AddToTable(const char* S, int L, HashTable t)
    {
        int f1 = HashFunc(S, L, t.q);
        int f2 = HashFunc2(f1, t);
        if (SearchString(S, L, t)==-1)
        {
            
        }
        while (t.Table[f1] != NULL)
            f1 = (f1 + f2) % t.q;
        t.Table[f1] = S;
        //cout << S << " added" << endl;
    }
    void ShowTable() const
    {
        for (int i = 0; i < q; i++)
        {
            if (this->Table[i] == NULL)
                cout << "-" << endl;
            else
                cout << Table[i] << endl;
        }
    }
    static int SearchString(const char* S, int L, HashTable t)
    {
        int f1 = HashFunc(S, L, t.q);
        int f2 = HashFunc2(f1, t);
        while ((t.Table[f1] != NULL) && (t.Table[f1] != S))
        {
            f1 = (f1 + f2) % t.q;
            t.CompareAmount++;
        }
        if (t.Table[f1] == S)
            return f1;
        else
            return -1;
    }
    static void ShowString(int i, const HashTable t)
    {
        cout << t.Table[i];
    }
};

char* RandString(int l)
{
    char* c = new char[l];
    for (int i = 0; i < l; i++)
    {
        c[i] = char('a' + rand() % ('z' - 'a'));
    }
    c[l] = '\0';
    return c;
}
int main()
{
    cout << "sizeof(int) = " << sizeof(int) << " sizeof(HashTable) = " << sizeof(HashTable) << endl;
    int l, i, amount, UniqueCount = 0;
    HashTable aboba;
    cout << "Enter amount of strings:\n";
    cin >> amount;
    cout << "Enter size of the strings:\n";
    cin >> l;
    char **c = new char*[amount];
    //HashTable::ShowTable(aboba);
    for (i = 0; i < amount; i++)
    {
        c[i] = RandString(rand()%5);
        cout << c[i] << endl;
        if (HashTable::SearchString(c[i], l, aboba) == -1)
        {
            UniqueCount++;
            HashTable::AddToTable(c[i], l, aboba);
        }
    }
    cout << "UniqueCount = " << UniqueCount << endl;
    const char *SearchedString = "foo";
    //HashTable::ShowTable(aboba);
    aboba.ShowTable();
    //cout << endl << SearchedString << " " << endl << HashTable::SearchString(SearchedString, l, aboba) << endl;
    if (HashTable::SearchString(SearchedString, l, aboba) != -1)
    {
        cout << "Found string: ";
        HashTable::ShowString(HashTable::SearchString(SearchedString, l, aboba), aboba);
        cout << endl;
    }
    else
        cout << "String not found" << endl;
    cout << aboba.CompareAmount;
}