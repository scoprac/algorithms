#include<bits/stdc++.h>
using namespace std;

void createEdge(vector<int> graph[], int a, int b)
{
	graph[a].push_back(b);
}
void topological(vector<int> graph[],int vec)
{
	vector<int>indegree(vec,0);
	for(int i=0;i<vec;i++)
	{
		for(auto it=graph[i].begin();it!=graph[i].end();it++)
		{
			indegree[*it]++;
		}
	}
	queue <int> que;
	for(int i=0;i<vec;i++)
	{
		if(indegree[i]==0)
		{
			que.push(i);
		}
	}
	while(!que.empty())
	{
		int top = que.front();
		cout<<top<<" ";
		que.pop();
		for(auto i=graph[top].begin();i!=graph[top].end();i++)
		{
			indegree[*i]--;
			if(indegree[*i]==0)
			{
				que.push(*i);
			}
		}

	}
}
int main()
{
	int vec = 6;
	int source = 0;
	vector<int> graph[vec]; // Create an array of vectors
    	vector<bool> vis(vec, false); // have a visted vector initialized to false
	createEdge(graph, 0, 1);
  	createEdge(graph, 0, 3);
  	createEdge(graph, 1, 2);
  	createEdge(graph, 1, 3);
  	createEdge(graph, 2, 3);
  	createEdge(graph, 2, 4);
  	createEdge(graph, 2, 5);
  	createEdge(graph, 3, 4);
  	createEdge(graph, 3, 5);
  	createEdge(graph, 4, 5);
    	topological(graph,vec);
}
