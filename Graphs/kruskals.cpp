#include<bits/stdc++.h>
using namespace std;

#define SIZE 100010
#define MAX 9999999
#define edge pair<int,int>

int dis[SIZE];
int parent[SIZE];
bool hasNegativeCycle = false;
vector< pair<int, edge > > graph;
vector< pair<int, edge > > MST;

int find_set(int i)
{
    if(i==parent[i])
    {
        return i;
    }
    else
    {
        return find_set(parent[i]);
    }
}
void union_set(int x,int y)
{
    parent[x] = parent[y];
}
void kruskal(int v,int e)
{
    int x,y;
    sort(graph.begin(),graph.end());
    for(auto it = graph.begin();it!=graph.end();it++)
    {
        x = find_set((*it).second.first);
        y = find_set((*it).second.second);
        if(x!=y)
        {
            MST.push_back(*it);
            union_set(x,y);
        }
    }
}
int main()
{
    int v, e, x, y, w;
	cin >> v >> e;
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
	for (int i = 0; i < e; i++)
	{
		cin >> x >> y >> w;
		graph.push_back(make_pair(w, edge(x, y)));
	}
    kruskal(v,e);
    for (int i = 0; i < MST.size(); i++) {
        cout << MST[i].second.first << " - " << MST[i].second.second << " : "<< MST[i].first;
        cout << endl;
    }

}