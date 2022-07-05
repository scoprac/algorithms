#include<bits/stdc++.h>
using namespace std;
void createEdge(vector<int> graph[], int a,int b)
{
	graph[a].push_back(b);
}
void bfs(vector<int> graph[],vector<bool> &vis,int source)
{
	queue<int>que;
	que.push(source);
	while(!que.empty())
	{
		int top = que.front();
		que.pop();
		vis[top]=true;
		cout<<top<<" ";
		for(auto it=graph[top].begin();it!=graph[top].end();it++)
		{
			if(!vis[*it])
			{
				vis[*it]=true;
				que.push(*it);	
			}
		}
	}
}
int main()
{
	int vec = 7;
	int source = 0;
	vector<int> graph[vec];
	vector<bool> vis(vec,false);

	createEdge(graph, 0, 1);
    	createEdge(graph, 0, 2);
    	createEdge(graph, 1, 3);
    	createEdge(graph, 1, 4);
    	createEdge(graph, 2, 5);
    	createEdge(graph, 2, 3);
    	createEdge(graph, 1, 6);
	bfs(graph,vis,source);
}
