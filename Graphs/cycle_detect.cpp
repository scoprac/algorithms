#include<iostream>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;

struct edge{
	int src,dest;
};

class Graph
{
public:
	vector<vector<int> > adj;
	Graph(vector<edge> const &edges,int n)
	{
		adj.resize(n);
		for(auto &edg: edges)
		{
			adj[edg.src].push_back(edg.dest);
			adj[edg.dest].push_back(edg.src);
		}
	}
};
bool dfs(Graph graph,int s,vector<bool> & vis,int parent)
{
	vis[s]=true;
	for(int i:graph.adj[s])
	{
		if(!vis[i])
		{
			if(dfs(graph,i,vis,s))
			{
				return true;
			}
		}
		else if(i!=parent)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	vector <edge> edges =
	{
	        {0, 1}, {0, 6}, {0, 7}, {1, 2}, {1, 5}, {2, 3},
		{2, 4}, {7, 8}, {7, 11}, {8, 9}, {8, 10}, {10, 11}
	};
	int n = 12;

	Graph graph(edges,n);
	vector<bool>vis(n,false);
	if(dfs(graph,0,vis,-1))
	{
		cout<<"cycle present";
	}
	else
	{
		cout<<"no cycle";
	}

	return 0;
}
