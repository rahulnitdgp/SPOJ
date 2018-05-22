#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int trail_zero = 0, k=1;
		int fraction = INT_MIN;
		while(fraction <= n)
		{
			fraction = pow(5,k);
			trail_zero += n/fraction;
			k++;
		}
		cout<<trail_zero<<endl;
	}
	return 0;
}