#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin>>k;
	deque<int> q;
	for(int i=0;i<k;i++)
	{
		while(!q.empty() && arr[q.back()]<arr[i])
			q.pop_back();
		q.push_back(i);
	}
	for(int i=k;i<n;i++)
	{
		cout<<arr[q.front()]<<" ";
		while(!q.empty() && q.front()<=i-k)
			q.pop_front();
		while(!q.empty() && arr[q.back()]<arr[i])
			q.pop_back();
		q.push_back(i);
	}
	cout<<arr[q.front()];
	return 0;
}