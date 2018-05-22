#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		int term;
		int ans;
		if(y==x)
		{
			term = y+1;
			if(term%2==0)
			{
				ans = 2*term - 3;
			}
			else
			{
				ans = 2*term - 2;
			}
		}
		else if(y==x-2)
		{
			term = y+1;
			if(term%2==0)
			{
				ans = 2*term - 1;
			}
			else
			{
				ans = 2*term ;
			}	
		}
		else
		{
			cout<<"No Number"<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}