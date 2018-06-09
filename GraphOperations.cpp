#include<iostream>
#include<vector>
#include<list>
#include<iterator>

using namespace std;

void addEdge(vector<int> adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

void BFS(int s,int V, vector<int> adj[])
{
    bool *visited = new bool[V];
    for(int i = 0; i<V; i++)
        visited[i] = false;
    list<int>q;

    visited[s] = true;
    q.push_back(s);
    vector<int>::iterator i;
    while(!q.empty())
    {
        s = q.front();
        cout<<s<<" ";
        q.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    printGraph(adj,V);
    cout<<endl;
    BFS(0,V,adj);
    return 0;

}
