 //Better method: count the no of divisors upto((floor)sqrt(i)) where 1<=i<=n

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum = 0;
	int i=1;
	while( (n/i)-(i-1) > 0 )
	{
		sum = sum + (n/i)-(i-1);
		i++;
	}
	cout<<sum<<endl;
	return 0;
}