#include<bits/stdc++.h>
using namespace std;

#define SIZE 100010
#define MAX 9999999

int dis[SIZE];
int parent[SIZE];
bool hasNegativeCycle = false;
vector< vector< pair< int, int > > > graph;

void bellmanFord(int v,int e,int start)
{
    for(int i=0;i<v;i++)
    {
        dis[i]=MAX;
    }

    dis[start]=0;
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<graph[j].size();k++)
            {
                pair<int,int>child =graph[j][k];
                dis[child.first]=min(dis[child.first],dis[j]+child.second);
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            pair<int,int>child =graph[i][j];
            if(dis[child.first] > child.second + dis[i])
            {
                hasNegativeCycle=true;
            }
        }
    }
    hasNegativeCycle ? cout <<  "Yes" : cout << "No" ;
    cout<<endl; 
}

int main()
{
    int v, e, x, y, w;
	cin >> v >> e;
	graph.resize(v);

	for (int i = 0; i < e; i++)
	{
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
		//graph[y].push_back(make_pair(x, w));
	}

	bellmanFord(v, e, 0);

	for (int i = 0; i < v; i++)
		cout << i << " " << dis[i] << endl;
}
