#include<bits/stdc++.h>
using namespace std;

//EFFICIENT USE OF BOOST

int cows(int pos, int arr[], int c, int n)
{
	int pos1 = arr[0];
	int cows = 1;
	for(int i=1;i<n;i++)
	{
		
		if(arr[i]-pos1>=pos)
		{
			pos1 = arr[i];
			cows++;
		}
		if(cows==c)
			return 1;
	}
	return 0;
}
int binary_search(int arr[], int n, int c)
{
	int low = 0, high = arr[n-1], mid,max = -1;
	while(high>low)
	{
		mid = (low+high)/2;
		if(cows(mid,arr,c,n))
		{
			if(mid>max)
			{
				max = mid;
			}
			low = mid+1;
		}
		else
			high = mid;
	}
	return max;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		cout<<binary_search(arr,n,c)<<endl;
	}
	return 0;
}