#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;
struct ver
{
    int num;
    double x, y;
    public:
    ver() :num(0), x(0), y(0)
    {
    }
    void set_ver(int n, double f, double l)
    {
        num = n;
        x = f;
        y = l;
    }
    static double get_dist(ver v1, ver v2)
    {
        return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
    }
    static int get_x(ver v)
    {
        return v.x;
    }
    static int get_y(ver v)
    {
        return v.y;
    }
    friend ostream& operator <<(ostream& stream, ver obj)
    {
        stream << obj.num << " " << obj.x << " " << obj.y;
        return stream;
    }
};
struct edge
{
    int a, b;
    double weight;
    public:
    edge():a(0), b(0), weight(numeric_limits<double>::infinity())
    {
    }
    void set_edge(int f, int l, double w)
    {
        a = f;
        b = l;
        weight = w;
    }
    friend ostream& operator <<(ostream& stream, edge obj)
    {
        stream << obj.a << " " << obj.b << " " << obj.weight;
        return stream;
    }
    int get_a() const
    {
        return a;
    }
    int get_b() const
    {
        return b;
    }
    double get_w() const
    {
        return weight;
    }
};

class WGraph
{
    int vernum, e, wsize, comptotal;
    double** Graph;
    double** OstGraph;
    const double inf = numeric_limits<double>::infinity();
    edge* R;
    edge* W;
    ver* V;
public:
    WGraph(int n) :e(0), wsize(0), comptotal(0), vernum(n)
    {
        Graph = new double* [vernum];
        OstGraph = new double* [vernum];
        V = new ver [vernum];
        R = new edge[vernum*vernum];
        W = new edge[vernum];
        for (int i = 0; i < vernum; i++)
        {
            Graph[i] = new double[vernum];
            V[i].set_ver(i, -50 + (rand()%100), -50 + (rand()%100));
        }
        for (int i = 0; i < vernum; i++)
        {
            OstGraph[i] = new double[vernum];
        }
        for (int i = 0; i < vernum; i++)
            for (int j = 0; j < vernum; j++)
            {
                OstGraph[i][j] = inf;
                if (i != j)
                    add_edge(i, j, ver::get_dist(V[i], V[j]));
                else
                    Graph[i][j] = inf;
            }
        /*add_edge(0, 1, ver::get_dist(V[0], V[1]));
        add_edge(1, 2, ver::get_dist(V[1], V[2]));
        add_edge(2, 3, ver::get_dist(V[2], V[3]));*/
    }
    void add_edge(int a, int b, double w)
    {
        if (a < 0 || a >= vernum) return;
        if (b < 0 || b >= vernum) return;
        Graph[a][b] = w;
        Graph[b][a] = w;
        R[e].set_edge(a, b, w);
        e++;
    }
    void show_graph() const
    {
        cout << "  ";
        for (int i = 0; i < vernum; i++)
            cout << setw(3) << i << "  ";
        cout << endl;
        for (int i = 0; i < vernum; i++)
        {
            printf("%2i ", i);
            for (int j = 0; j < vernum; j++)
            {
                if ((Graph[i][j] == inf))
                    cout << " INF" << " ";
                else
                    printf("%3.1f ", Graph[i][j]);
            }
            cout << endl;
        }
    }
    void show_OstGraph() const
    {
        cout << "  ";
        for (int i = 0; i < vernum; i++)
            cout << setw(3) << i << "  ";
        cout << endl;
        for (int i = 0; i < vernum; i++)
        {
            printf("%2i ", i);
            for (int j = 0; j < vernum; j++)
            {
                if ((OstGraph[i][j] == inf))
                    cout << " INF" << " ";
                else
                    printf("%3.1f ", OstGraph[i][j]);
            }
            cout << endl;
        }
    }
    void sort_edges(edge* R, int e)
    {
        int i, j; double z; edge v;
        for (i = 1; i < e; i++)
        {
            z = R[i].weight;
            v = R[i];
            for (j = i - 1; j >= 0 && R[j].weight > z; j--)
                R[j + 1] = R[j];
            R[j + 1] = v;
        }
    }
    int span_tree()
    {
        int k = 0, ra, rb, i, * A, * B, n = vernum;
        A = new int[n];
        B = new int[n];
        sort_edges(R, e);
        for (i = 0; i < n; i++) 
        {
            A[i] = i; B[i] = 1;
        }
        for (i = 0; k < n - 1 && i < e; i++) 
        {
            for (ra = R[i].a; ra != A[ra]; ra = A[ra]);
                for (rb = R[i].b; rb != A[rb]; rb = A[rb]);
                    if (ra == rb)  
                        continue;
                    W[k++] = R[i];
                    if (B[ra] >= B[rb])
                    {
                        A[rb] = ra; B[ra] += B[rb];
                    }
                    else 
                    { 
                        A[ra] = rb; 
                        B[rb] += B[ra]; 
                    }
        }
        sort_edges(W, k);
        wsize = k;
        for (int i = 0; i < vernum; i++)
        {
            OstGraph[W[i].get_a()][W[i].get_b()] = W[i].get_w();
            OstGraph[W[i].get_b()][W[i].get_a()] = W[i].get_w();
        }
        return k;
    }
    void show_W() const
    {
        for (int i = 0; i < wsize; i++)
            cout << W[i] << endl;
    }
    void show_R() const
    {
        for (int i = 0; i < e; i++)
            cout << R[i] << endl;
    }
    void show_V() const
    {
        for (int i = 0; i < vernum; i++)
            cout << V[i] << endl;
    }
    void cdeep(int cver, int* R)
    {
        R[cver] = comptotal;
        for (int i = 0; i < vernum; i++)
            if ((OstGraph[cver][i]!=inf) && !R[i]) 
                cdeep(i, R);
    }
    int* get_comp()
    {
        int i, 
        * R = new int[vernum];
        comptotal = 0;
        for (i = 0; i < vernum; i++) 
            R[i] = 0;
        for (i = 0; i < vernum; i++)
            if (!R[i])
            {
                comptotal++; 
                cdeep(i, R);
            }
        return R;
    }
    void Ocdeep(int cver, int* R)
    {
        R[cver] = comptotal;
        for (int i = 0; i < vernum; i++)
            if ((OstGraph[cver][i]!=inf) && !R[i]) 
                Ocdeep(i, R);
    }
    int* Oget_comp()
    {
        int i, 
        * R = new int[vernum];
        comptotal = 0;
        for (i = 0; i < vernum; i++) 
            R[i] = 0;
        for (i = 0; i < vernum; i++)
            if (!R[i])
            {
                comptotal++; 
                Ocdeep(i, R);
            }
        return R;
    }
    int comp() const
    {
        return comptotal;
    }
    int get_V_x(int n) const
    {
        return ver::get_x(V[n]);
    }
    int get_V_y(int n) const
    {
        return ver::get_y(V[n]);
    }
    void delete_W(int n)
    {
        for (int i = 0; i<n;i++)
        {
            OstGraph[W[wsize-1].get_a()][W[wsize-1].get_b()] = inf;
            OstGraph[W[wsize-1].get_b()][W[wsize-1].get_a()] = inf;
            wsize-=1;
        }
    }
};

int main()
{
    int n, minx, maxx, miny, maxy, k;
    double sumx, sumy;
    cout << "Enter vernum:" << endl;
    cin >> n;
    cout << "Enter compnum:" << endl;
    cin >> k;
    WGraph aboba(n);
    aboba.show_graph();
    aboba.show_R();
    cout << aboba.span_tree();
    cout << endl;
    cout << "W:" << endl;
    aboba.show_W();
    cout << endl << "R: " << endl;
    //aboba.show_R();
    aboba.show_OstGraph();
    aboba.delete_W(k-1);
    cout << "Mod W:" <<endl;
    aboba.show_W();
    cout<< endl;
    aboba.show_OstGraph();
    int *R = aboba.Oget_comp();
    for (int i = 0; i < n; i++)
        cout << R[i];
    cout << endl;
    int* CompNum = new int[aboba.comp()];
    for (int i = 0; i < aboba.comp(); i++)
        CompNum[i] = 0;
    for (int i = 0; i < n; i++)
        CompNum[R[i]-1]++;
    for (int i = 0; i < aboba.comp(); i++)
        cout << CompNum[i] << " ";
    ver* Center = new ver[aboba.comp()];
    int allsumx, allsumy;
    for (int i = 0; i < aboba.comp(); i++)
    {
        Center[i].set_ver(0,0,0);
        minx = 60;
        maxx = -60;
        miny = 60;
        maxy = -60;
        allsumx = 0;
        allsumy = 0;
        for (int j = 0; j < n; j++)
            if ((R[j] - 1) == i)
            {
                if (aboba.get_V_x(j) > maxx)
                    maxx = aboba.get_V_x(j);
                if (aboba.get_V_x(j) < minx)
                    minx = aboba.get_V_x(j);
                if (aboba.get_V_y(j) > maxy)
                    maxy = aboba.get_V_y(j);
                if (aboba.get_V_y(j) < miny)
                    miny = aboba.get_V_y(j);
                allsumx+=aboba.get_V_x(j);
                allsumy+=aboba.get_V_y(j);
            }
        sumx = maxx + minx;
        sumy = maxy + miny;
        /*Center[i].set_ver(i+1, sumx / 2, sumy / 2);
        cout << "Comp: " << i << ", maxx: " << maxx << ", minx: " << minx << ", maxy: " << maxy << ", miny: " << miny << ", center: " << Center[i] << endl;*/
        Center[i].set_ver(i+1, allsumx/CompNum[i], allsumy/CompNum[i]);
        cout << "Comp: " << i << ", maxx: " << maxx << ", minx: " << minx << ", maxy: " << maxy << ", miny: " << miny << ", center: " << Center[i] << endl;
    }
    /*
    cout << endl;
    aboba.show_V();
    cout << endl;
    for (int i = 0; i < aboba.comp(); i++)
        cout << Center[i] << endl;
    aboba.delete_W(k-1);
    cout << "Mod W:" <<endl;
    aboba.show_W();
    cout << endl;
    aboba.show_graph();*/
}