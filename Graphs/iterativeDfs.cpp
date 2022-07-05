#include<bits/stdc++.h>
using namespace std;

void createEdge(vector<int> graph[], int a, int b)
{
	graph[a].push_back(b);
}
void dfs(vector<int> graph[], vector<bool> &vis, int source)
{
	stack<int>stk;
	stk.push(source);
	while(!stk.empty())
	{
		int top = stk.top();
		stk.pop();
		vis[top] = true;
		cout<<top<<" ";
		for(auto it=graph[top].begin();it!=graph[top].end();it++)
		{
			if(!vis[*it])
			{
				stk.push(*it);
				vis[*it]=true;
			}
		}
	}

}
int main()
{
	int vec = 7;
	int source = 0;
	vector<int> graph[vec]; // Create an array of vectors
    	vector<bool> vis(vec, false); // have a visted vector initialized to false
    	createEdge(graph, 0, 1);
    	createEdge(graph, 0, 2);
    	createEdge(graph, 1, 3);
    	createEdge(graph, 1, 4);
    	createEdge(graph, 2, 5);
  	createEdge(graph, 2, 3);
    	createEdge(graph, 1, 6);
    	dfs(graph,vis,0);
}
