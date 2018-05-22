//http://www.spoj.com/problems/SEGSQRSS/

#include<bits/stdc++.h>
using namespace std;
int tree[1000000],lazy1[1000000],lazy2[1000000],tree1[1000000];
int ar[100010];
void build_tree(int start, int end, int node, int ar[])
{
	if(start==end)
	{
		tree1[node] = ar[start];
		tree[node] = ar[start]*ar[start];
	}
	else
	{
		int mid = (start + end)/2;
		build_tree(start,mid,2*node,ar);
		build_tree(mid+1,end,2*node + 1,ar);
		tree[node] = tree[2*node] + tree[2*node + 1]; //stores the sum of the squares
		tree1[node] = tree1[2*node] + tree1[2*node + 1]; //stores the sum
	}
}

/* THE CONCEPT HERE IS USED THAT FOR ANY NODE, ONLY ONE TYPE OF UPDATE  SHOULD BE PENDING AT A TIME. BOTH TYPES OF
   UPDATES SHOULD NOT BE PENDING SIMULTANEOUSLY ON A NODE. OTHERWISE QUERY WOULD BE PROBLEMATIC.
   AT EVERY STEP I AM CHECKING FOR THE UPDATES PENDING. IF ANY UPDATE IS FOUND WHILE UPDATING THE OTHER TYPE
   THEN RESOLVE THE EXISTING UPDATE. */

void update_tree(int start, int end, int node, int l, int r, int val, int ar[])
{
	if(lazy2[node]!=0)
	{
		tree1[node] = (end-start+1)*lazy2[node];
		tree[node] = (end - start + 1)*lazy2[node]*lazy2[node];
		if(start!=end)
		{
			int mid = (start+end)/2;
			if(lazy1[node*2]!=0)
			{
				tree[node*2] += (mid - start + 1)*(lazy1[node*2]*lazy1[node*2]) + (2*(lazy1[node*2])*(tree1[node*2]));
				tree1[node*2] += (mid-start+1)*(lazy1[node*2]);
				if(mid != start)
				{
					lazy1[node*2*2] += lazy1[node*2];
					lazy1[node*2*2 + 1] += lazy1[node*2];
				}
				lazy1[node*2] = 0;
			}
			if(lazy1[node*2 + 1]!=0)
			{
				tree[node*2 + 1] += (end - (mid+1) + 1)*(lazy1[node*2 + 1]*lazy1[node*2 + 1]) + (2*(lazy1[node*2 + 1])*(tree1[node*2 + 1]));
				tree1[node*2 + 1] += (end-(mid+1)+1)*(lazy1[node*2 + 1]);
				if(mid+1 != end )
				{
					lazy1[(node*2 + 1)*2] += lazy1[node*2 + 1];
					lazy1[(node*2 + 1)*2 + 1] += lazy1[node*2 + 1];
				}
				lazy1[node*2 + 1] = 0;
			}
			lazy2[node*2] += lazy2[node];
			lazy2[node*2 + 1] += lazy2[node];
		}
		lazy2[node] = 0;
	}
	if(lazy1[node]!=0)
	{
		tree[node] += (end - start + 1)*(lazy1[node]*lazy1[node]) + (2*(lazy1[node])*(tree1[node]));
		tree1[node] += (end-start+1)*(lazy1[node]);               
		if(start!=end) 
		{
			int mid = (start+end)/2;
			if(lazy2[node*2]!=0)
			{
				tree[node*2] = (mid-start+1)*lazy2[node*2]*lazy2[node*2];
				tree1[node*2] = (mid-start+1)*lazy2[node*2];
				if(mid != start)
				{
					lazy2[node*2*2] += lazy2[node*2];
					lazy2[node*2*2 + 1] += lazy2[node*2];
				}
				lazy2[node*2] = 0;
			}
			if(lazy2[node*2 + 1]!=0)
			{
				tree[node*2 + 1] = (end-(mid+1)+1)*lazy2[node*2 + 1]*lazy2[node*2 + 1];
				tree1[node*2 + 1] = (end-(mid+1)+1)*lazy2[node*2 + 1];
				if(mid+1 != end )
				{
					lazy2[(node*2 + 1)*2] += lazy2[node*2 + 1];
					lazy2[(node*2 + 1)*2 + 1] += lazy2[node*2 + 1];
				}
				lazy2[node*2 + 1] = 0;
			}	
			lazy1[node*2] += lazy1[node];
			lazy1[node*2 + 1] += lazy1[node];
		}
		lazy1[node] = 0;
	}
	if(start>r || end<l || start>end)
		return;
	if(start>=l && end<=r)
	{
		tree[node] += (end - start + 1)*(val*val) + 2*val*(tree1[node]);
		tree1[node] +=(end-start+1)*val;	
		if(start!=end)
		{
			int mid = (start+end)/2;
			if(lazy2[node*2]!=0)
			{
				tree[node*2] = (mid-start+1)*lazy2[node*2]*lazy2[node*2];
				tree1[node*2] = (mid-start+1)*lazy2[node*2];
				if(mid != start)
				{
					lazy2[node*2*2] += lazy2[node*2];
					lazy2[node*2*2 + 1] += lazy2[node*2];
				}
				lazy2[node*2] = 0;
			}
			if(lazy2[node*2 + 1]!=0)
			{
				tree[node*2 + 1] = (end-(mid+1)+1)*lazy2[node*2 + 1]*lazy2[node*2 + 1];
				tree1[node*2 + 1] = (end-(mid+1)+1)*lazy2[node*2 + 1];
				if(mid+1 != end )
				{
					lazy2[(node*2 + 1)*2] += lazy2[node*2 + 1];
					lazy2[(node*2 + 1)*2 + 1] += lazy2[node*2 + 1];
				}
				lazy2[node*2 + 1] = 0;
			}
			lazy1[node*2] += val;
			lazy1[node*2 + 1] += val;
		}
		return;
	}
		
	else
	{
		int mid = (start+end)/2;
		update_tree(start,mid,2*node,l,r,val,ar);
		update_tree(mid+1,end,2*node + 1,l,r,val,ar);
		tree[node] = tree[2*node] + tree[2*node + 1];
		tree1[node] = tree1[2*node] + tree1[2*node + 1];
	}
}
void update_range(int start, int end, int node, int l, int r, int val, int ar[])
{
if(lazy1[node]!=0)
	{
		tree[node] += (end - start + 1)*(lazy1[node]*lazy1[node]) + (2*(lazy1[node])*(tree1[node]));
		tree1[node] += (end-start+1)*(lazy1[node]);               
		if(start!=end) 
		{
			int mid = (start+end)/2;
			if(lazy2[node*2]!=0)
			{
				tree[node*2] = (mid-start+1)*lazy2[node*2]*lazy2[node*2];
				tree1[node*2] = (mid-start+1)*lazy2[node*2];
				if(mid != start)
				{
					lazy2[node*2*2] += lazy2[node*2];
					lazy2[node*2*2 + 1] += lazy2[node*2];
				}
				lazy2[node*2] = 0;
			}
			if(lazy2[node*2 + 1]!=0)
			{
				tree[node*2 + 1] = (end-(mid+1)+1)*lazy2[node*2 + 1]*lazy2[node*2 + 1];
				tree1[node*2 + 1] = (end-(mid+1)+1)*lazy2[node*2 + 1];
				if(mid+1 != end )
				{
					lazy2[(node*2 + 1)*2] += lazy2[node*2 + 1];
					lazy2[(node*2 + 1)*2 + 1] += lazy2[node*2 + 1];
				}
				lazy2[node*2 + 1] = 0;
			}	
			lazy1[node*2] += lazy1[node];
			lazy1[node*2 + 1] += lazy1[node];
		}
		lazy1[node] = 0;
	}
	if(lazy2[node]!=0)
	{
		tree1[node] = (end-start+1)*lazy2[node];
		tree[node] = (end - start + 1)*lazy2[node]*lazy2[node];
		if(start!=end)
		{
			int mid = (start+end)/2;
			if(lazy1[node*2]!=0)
			{
				tree[node*2] += (mid - start + 1)*(lazy1[node*2]*lazy1[node*2]) + (2*(lazy1[node*2])*(tree1[node*2]));
				tree1[node*2] += (mid-start+1)*(lazy1[node*2]);
				if(mid != start)
				{
					lazy1[node*2*2] += lazy1[node*2];
					lazy1[node*2*2 + 1] += lazy1[node*2];
				}
				lazy1[node*2] = 0;
			}
			if(lazy1[node*2 + 1]!=0)
			{
				tree[node*2 + 1] += (end - (mid+1) + 1)*(lazy1[node*2 + 1]*lazy1[node*2 + 1]) + (2*(lazy1[node*2 + 1])*(tree1[node*2 + 1]));
				tree1[node*2 + 1] += (end-(mid+1)+1)*(lazy1[node*2 + 1]);
				if(mid+1 != end )
				{
					lazy1[(node*2 + 1)*2] += lazy1[node*2 + 1];
					lazy1[(node*2 + 1)*2 + 1] += lazy1[node*2 + 1];
				}
				lazy1[node*2 + 1] = 0;
			}
			lazy2[node*2] += lazy2[node];
			lazy2[node*2 + 1] += lazy2[node];
		}
		lazy2[node] = 0;
	}
	if(start>r || end<l || start>end)
		return;
	if(start>=l && end<=r)
	{
		tree[node]  = (end - start + 1)*(val*val);
		tree1[node] = (end-start+1)*val;
		if(start!=end)
		{
			int mid = (start+end)/2;
			if(lazy1[node*2]!=0)
			{
				tree[node*2] += (mid - start + 1)*(lazy1[node*2]*lazy1[node*2]) + (lazy1[node*2]*(mid-start+1)*(start + mid));
				if(mid != start)
				{
					lazy1[node*2*2] += lazy1[node*2];
					lazy1[node*2*2 + 1] += lazy1[node*2];
				}
				lazy1[node*2] = 0;
			}
			if(lazy1[node*2 + 1]!=0)
			{
				tree[node*2 + 1] += (end - (mid+1) + 1)*(lazy1[node*2 + 1]*lazy1[node*2 + 1]) + (lazy1[node*2 + 1]*(end-(mid+1)+1)*(mid+1 + end ));
				if(mid+1 != end )
				{
					lazy1[(node*2 + 1)*2] += lazy1[node*2 + 1];
					lazy1[(node*2 + 1)*2 + 1] += lazy1[node*2 + 1];
				}
				lazy1[node*2 + 1] = 0;
			}
			lazy2[node*2]  += val;
			lazy2[node*2 + 1] += val;
		}
		return;
	}
	else
	{
		int mid = (start+end)/2;
		update_range(start,mid,2*node,l,r,val,ar);
		update_range(mid+1,end,2*node + 1,l,r,val,ar);
		tree[node] = tree[2*node] + tree[2*node + 1];
		tree1[node] = tree1[2*node] + tree1[2*node + 1];
	}
}

long query_tree(int start, int end, int node, int l, int r, int ar[])
{

	if(start>r || end<l || start>end)
		return 0;
	if(lazy1[node]!=0)
	{
		tree[node] += (end - start + 1)*(lazy1[node]*lazy1[node]) + (2*(lazy1[node])*(tree1[node]));
		tree1[node] += (end-start+1)*(lazy1[node]);               
		if(start!=end) 
		{
			int mid = (start+end)/2;
			if(lazy2[node*2]!=0)
			{
				tree[node*2] = (mid-start+1)*lazy2[node*2]*lazy2[node*2];
				tree1[node*2] = (mid-start+1)*lazy2[node*2];
				if(mid != start)
				{
					lazy2[node*2*2] += lazy2[node*2];
					lazy2[node*2*2 + 1] += lazy2[node*2];
				}
				lazy2[node*2] = 0;
			}
			if(lazy2[node*2 + 1]!=0)
			{
				tree[node*2 + 1] = (end-(mid+1)+1)*lazy2[node*2 + 1]*lazy2[node*2 + 1];
				tree1[node*2 + 1] = (end-(mid+1)+1)*lazy2[node*2 + 1];
				if(mid+1 != end )
				{
					lazy2[(node*2 + 1)*2] += lazy2[node*2 + 1];
					lazy2[(node*2 + 1)*2 + 1] += lazy2[node*2 + 1];
				}
				lazy2[node*2 + 1] = 0;
			}	
			lazy1[node*2] += lazy1[node];
			lazy1[node*2 + 1] += lazy1[node];
		}
		lazy1[node] = 0;
	}
	if(lazy2[node]!=0)
	{
		tree1[node] = (end-start+1)*lazy2[node];
		tree[node] = (end - start + 1)*lazy2[node]*lazy2[node];
		if(start!=end)
		{
			int mid = (start+end)/2;
			if(lazy1[node*2]!=0)
			{
				tree[node*2] += (mid - start + 1)*(lazy1[node*2]*lazy1[node*2]) + (2*(lazy1[node*2])*(tree1[node*2]));
				tree1[node*2] += (mid-start+1)*(lazy1[node*2]);
				if(mid != start)
				{
					lazy1[node*2*2] += lazy1[node*2];
					lazy1[node*2*2 + 1] += lazy1[node*2];
				}
				lazy1[node*2] = 0;
			}
			if(lazy1[node*2 + 1]!=0)
			{
				tree[node*2 + 1] += (end - (mid+1) + 1)*(lazy1[node*2 + 1]*lazy1[node*2 + 1]) + (2*(lazy1[node*2 + 1])*(tree1[node*2 + 1]));
				tree1[node*2 + 1] += (end-(mid+1)+1)*(lazy1[node*2 + 1]);
				if(mid+1 != end )
				{
					lazy1[(node*2 + 1)*2] += lazy1[node*2 + 1];
					lazy1[(node*2 + 1)*2 + 1] += lazy1[node*2 + 1];
				}
				lazy1[node*2 + 1] = 0;
			}
			lazy2[node*2] += lazy2[node];
			lazy2[node*2 + 1] += lazy2[node];
		}
		lazy2[node] = 0;
	}

	if(start>=l && end<=r)
		return(tree[node]);
	int mid = (start+end)/2;
	long p1 = query_tree(start,mid,node*2,l,r,ar);
	long p2 = query_tree(mid+1,end,node*2 + 1,l,r,ar);
	return(p1 + p2);
}

int main()
{

	int t,j=1;
	cin>>t;
	while(t--)
	{
		int n,q,t,st,nd,x;
		cin>>n>>q;
		for(int i=1;i<=1000000;i++)
		{
			lazy1[i] = lazy2[i] = tree[i] =  tree1[i]= 0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>ar[i];
		}
		build_tree(1,n,1,ar);
		cout<<"Case "<<j<<":"<<endl;
		j++;
		for(int i=1;i<=q;i++)
		{
			cin>>t;
			if(t==2)
			{
				cin>>st>>nd;
				cout<<query_tree(1,n,1,st,nd,ar)<<endl;
			}
			else
			{
				if(t==1)
				{
					cin>>st>>nd>>x;
					update_tree(1,n,1,st,nd,x,ar);
				}
				else
				{
					cin>>st>>nd>>x;
					update_range(1,n,1,st,nd,x,ar);
				}
			}
		}
	}
	return 0;
}
