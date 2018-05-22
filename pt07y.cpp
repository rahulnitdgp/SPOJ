#include<bits/stdc++.h>
using namespace std;

//NOTE: Do always declare the iterator of any stl
// in the loop itself.
int isCycle(int start, int visited[], int parent, list<int> adj[])
{
	visited[start] = 1;
	//cout<<"current"<<start<<" ";
	for(list<int>::iterator it=adj[start].begin(); it!=adj[start].end(); it++)
	{
		//cout<<endl<<"child"<<*it<<" ";
		if(!visited[*it])
		{
			if(isCycle(*it,visited,start,adj))
				return 1;
		}
		else
		{
			if(*it != parent)
			{
				cout<<start<<" "<<*it<<" "<<parent;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int n,m;
	cin>>n>>m;
	list<int> adj[n+1];
	int u,v;
	while(m--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	/*for(int i=1;i<=n;i++)
	{
		for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}*/
	int visited[n+1];
	for(int i=1;i<=n;i++)
	{
		visited[i] = 0; 
	}
	if(isCycle(1,visited,0,adj))
	{
		cout<<"NO"<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		cout<<"YES"<<endl;
	}
	return 0;
}