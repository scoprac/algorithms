#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pi;

void createEdge(vector<pi> graph[],int u,int v,int w)
{
	graph[u].push_back({w,v});
}

void dijkstra(vector<pi> graph[],vector<int> & vis,vector<int> & path,int source)
{
	priority_queue<pi,vector<pi>,greater<pi>> pq;
	path[source] = 0;
	
	pq.push({0,source});
	while(!pq.empty())
	{
		pi pair = pq.top();
		pq.pop();
		int weight = pair.first;
		int v = pair.second;

		if(!vis[v])
		{
			vis[v]=true;
			for(auto it = graph[v].begin();it!=graph[v].end();it++)
			{
				if(path[it->second] > weight+it->first)
				{
					path[it->second]=weight + it->first;
					pq.push({path[it->second],it->second});
				}
			}
		}
	}
}

int main()
{
	int source;
	cout<<"source: ";
	cin>> source;
	int vec = 6;
	vector<int> vis(vec,false);
	vector<int> path(vec,INT_MAX);
	path[source] = 0;
	vector<pi> graph[vec];
	createEdge(graph, 0, 1, 5);
	createEdge(graph, 0, 3, 10);
	createEdge(graph, 1, 2, 2);
	createEdge(graph, 1, 5, 10);
        createEdge(graph, 1, 4, 5);
	createEdge(graph, 2, 3, 1);
        createEdge(graph, 2, 4, 5);
        createEdge(graph, 2, 0, 3);
        createEdge(graph, 4, 5, 2);
	dijkstra(graph,vis,path,source);

	cout << "Shortest path from source vertex " << source << ": ";

	for (int i = 0; i < vec; i++)
	{
    		cout << path[i] << " ";
	}
  	cout << endl;
}
