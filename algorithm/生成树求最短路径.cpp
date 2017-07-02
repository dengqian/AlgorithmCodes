#include <iostream>
#include <vector>
using namespace std;
#define INF 512
#define MOD 100000

typedef struct edge
{
    int v;
    int len;
}edge;

void short_routes(int n, vector<edge> * nodes, int * route)
{
    bool * choose = new bool[n];
    for(int i = 0; i < n; i ++)
    {
        choose[i] = false;
        route[i] = -1;
    }
    choose[0] = true;
    route[0] = 0;
    for(int i = 1; i < n; i ++)
    {
        int min = INF, front, rear;
        for(int j = 0; j < n; j ++)
            if(choose[j])
                for(vector<edge>::iterator itr = nodes[j].begin(); itr != nodes[j].end(); itr ++)
                    if(!choose[itr->v] && itr->len < min)
                    {
                        min = itr->len;
                        front = j;
                        rear = itr->v;
                    }
        if(min == INF)
            return;
        else
        {
            choose[rear] = true;
            int len = 1;
            for(int k = 0; k < min; k ++)
            {
                len = (len * 2) % MOD;
            }
            route[rear] = (route[front] + len) % MOD;
        }
    }
    delete [] choose;
}

int main(int argc, char ** argv)
{
    int n, m;
    while(cin >> n && cin >> m)
    {
        vector<edge> * nodes = new vector<edge>[n];
        int i, j;
        edge e;
        for(int k = 0; k < m; k ++)
        {
            cin >> i >> j;
            e.len = k;
            e.v = j;
            nodes[i].push_back(e);
            e.v = i;
            nodes[j].push_back(e);
        }
        int * route = new int[n];
        short_routes(n, nodes, route);
        for(int k = 1; k < n; k ++)
            cout << route[k] << endl;
        delete [] nodes;
        delete [] route;
    }
    return 0;
}
