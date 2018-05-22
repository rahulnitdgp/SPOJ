#include<bits/stdc++.h>
using namespace std;
struct seg_tree
{
	long long sum;
	long long prefix_sum;
	long long suffix_sum;
	long long max_sum;
};
int arr[500010];
seg_tree tree[4*500010];
void build_tree(int node, int start, int end, int arr[], int n)
{
	//cout<<"NO";
	if(start==end)
	{
		tree[node].sum = arr[start];
		tree[node].prefix_sum = arr[start];
		tree[node].suffix_sum = arr[start];
		tree[node].max_sum = arr[start];
	}	
	else
	{
	//cout<<"YES";
	int mid = (start+end)>>1;
	build_tree(2*node + 1, start, mid, arr, n);
	build_tree(2*node + 2, mid+1, end, arr, n);
	tree[node].sum = tree[2*node + 1].sum + tree[2*node + 2].sum;
	tree[node].prefix_sum = max(tree[2*node+1].prefix_sum,tree[2*node+1].sum + tree[2*node+2].prefix_sum);
	tree[node].suffix_sum = max(tree[2*node+2].suffix_sum,tree[2*node+2].sum + tree[2*node+1].suffix_sum);
	tree[node].max_sum = max(tree[node].prefix_sum, max(tree[node].suffix_sum , max(tree[2*node+1].max_sum, max(tree[2*node+2].max_sum, tree[2*node+1].suffix_sum + tree[2*node+2].prefix_sum))));
}
}

seg_tree query_tree(int node, int start, int end, int l, int r, int arr[], int n)
{
	seg_tree result;
	result.sum = 0, result.prefix_sum = INT_MIN, result.suffix_sum = INT_MIN, result.max_sum = INT_MIN;
	if(start > r || end < l)
		return result;
	if(start>=l && end<=r)
		return tree[node];

		int mid = (start+end)>>1;
		seg_tree p1 = query_tree(2*node + 1, start, mid, l, r, arr, n);
		seg_tree p2 = query_tree(2*node + 2, mid+1, end, l, r, arr, n);
		result.sum = p1.sum + p2.sum;
	result.prefix_sum = max(p1.prefix_sum,p1.sum + p2.prefix_sum);
	result.suffix_sum = max(p2.suffix_sum,p2.sum + p1.suffix_sum);
	result.max_sum = max(result.prefix_sum, max(result.suffix_sum , max(p1.max_sum, max(p2.max_sum, p1.suffix_sum + p2.prefix_sum))));		 
	return result;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int m;
	cin>>m;
	build_tree(0,0,n-1,arr,n);
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		long long ans = query_tree(0,0,n-1,x-1,y-1,arr,n).max_sum;
		cout<<ans<<endl;
	}
	return 0;
}