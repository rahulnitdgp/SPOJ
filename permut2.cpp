#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		int flag = 1;
		int arr[n+1];
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		for(int i=1;i<=n;i++)
		{
			if(arr[arr[i]]!=i)
			{
				//cout<<"not ambiguous"<<endl;
				flag = 0;
				break;
			}
		}
		if(flag == 0)
			cout<<"not ambiguous"<<endl;
		else
			cout<<"ambiguous"<<endl;
		cin>>n;
	}
	return 0;
}