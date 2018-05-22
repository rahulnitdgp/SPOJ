#include<bits/stdc++.h>
using namespace std;

long answer(int n)
{
	long  ans = 0;
	for(int i=0;i<n;i++)
	{
		ans = ans + pow(n-i,2);
	}
	return ans;
}
int main()
{
	int number;
	cin>>number;
	while(number!=0)
	{
		cout<<answer(number)<<endl;
		cin>>number;
	}
	return 0;
}
	
