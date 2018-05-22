#include<bits/stdc++.h>
using namespace std;

struct seg_tree
{
	int first;
	int last;
	int count;
};

seg_tree tree[100000];
void build_tree(int node, int start, int end, int arr[], int n)
{
	if(start==end)
	{
		tree[node].first = arr[start];
		tree[node].last = arr[start];
		tree[node].count = 1;
	}
	else
	{
		int mid = (start+end)>>1;
		build_tree(2*node + 1,start,mid,arr,n);
		build_tree(2*node + 2,mid+1,end,arr,n);	
		tree[node].first = min(tree[2*node + 1].first, tree[2*node + 2].first);
		tree[node].last = max(tree[2*node + 1].last, tree[2*node + 2].last);
		if(tree[2*node + 1].last == tree[2*node + 2].first || tree[2*node + 1].last == tree[2*node + 2].last || 
			tree[2*node + 1].first == tree[2*node + 2].first || tree[2*node + 1].first == tree[2*node + 2].last)
		{
			tree[node].count = tree[2*node + 1].count + tree[2*node + 2].count - 1;
		}
		else			
			tree[node].count = tree[2*node + 1].count + tree[2*node + 2].count;
	}
}
seg_tree query_tree(int node, int start, int end, int l, int r, int arr[], int n)
{
	//cout<<"YES"<<" ";
	seg_tree result;
	result.first = INT_MAX, result.last = INT_MIN, result.count = 0;
	if(l>end || r<start)
		return result;
	if(start>=l && end<=r)
		return tree[node];
	int mid = (start+end)>>1;
	seg_tree left = query_tree(2*node + 1,start,mid,l,r,arr,n);
	seg_tree right = query_tree(2*node + 2,mid+1,end,l,r,arr,n);	
	result.first = min(left.first, right.first);
	result.last = max(left.last, right.last);
	if(left.last == right.first || left.last == right.last || left.first == right.first || left.first == right.last)
		result.count = left.count + right.count - 1;
	else			
		result.count = left.count + right.count;
	return result;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	build_tree(0,0,n-1,arr,n);
	/*for(int i=0;i<2*n -1;i++)
		cout<<tree[i].count<<" ";*/
	//cout<<endl;
	int q;
	cin>>q;
	int x,y;
	while(q--)
	{
		//map<int,int> m;
		cin>>x>>y;	
		//cout<<x<<" "<<y<<"";
		cout<<query_tree(0,0,n-1,x-1,y-1,arr,n).count<<endl;	
	}
	return 0;
}