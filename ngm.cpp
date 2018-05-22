#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	if(n%10==0)
	{
		cout<<2<<endl;
	}
	else
	{
		cout<<1<<endl;
		int ans = (n)-(10*(n/10));
		cout<<ans;
	}
	return 0;
}