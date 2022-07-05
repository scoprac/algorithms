
#include <bits/stdc++.h>

using namespace std;
void createEdge(vector<int> graph[], int a, int b)
{
    graph[a].push_back(b);
}
void dfs(vector<int> graph[], vector<bool> vis, int source)
{
    vis[source] = true;
    cout<<source<<" ";
    for(auto it = graph[source].begin();it!=graph[source].end();it++)
    {
        if(!vis[*it])
        {
          dfs(graph,vis,*it;
        }
    }
}
int main()
{
    int vec = 5;
    int source = 0;
    vector<int> graph[vec]; // Create an array of vectors
    vector<bool> vis(vec, false); // have a visted vector initialized to false
    createEdge(graph, 0, 1);
    createEdge(graph, 0, 2);
    createEdge(graph, 1, 3);
    createEdge(graph, 1, 4);
    dfs(graph, vis,0);
    cout<<endl;
}
