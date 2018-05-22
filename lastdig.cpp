#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		long b;
		cin>>a>>b;
		int rem = b%4;
		int last = a%10;
		int ans=0;
		if(b==0)
		{
			ans = 1;
		}
		else if(last==0 || last==1 || last==5|| last==6)
		{
			ans = last;
		}
		else
		{
			if(rem == 1)
			{
				ans = last;
			}
			else if(rem == 2)
			{
				ans = (last*last)%10;
			}
			else if(rem == 3)
			{
				ans = (last*last*last)%10;
			}
			else if(rem == 0)
			{
				ans = (last*last*last*last)%10;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}