#include<bits/stdc++.h>
using namespace std;
 
int code(int m, int n, string s, int dp[])
{
	int num = 27;
	if(m > n-1)
	{
		return 1;
	}
	if(m <= n-2)
	{
		num = 10*(int)(s[m]-48) + (int)(s[m+1]-48);
	}
	//cout<<s[m]<<" ";
	if(dp[m]!=-1)
		return(dp[m]);
	else{
	if(s[m]=='0')
	{
		//cout<<'a'<<endl;
		if(num>9 && num<=26)
		{
		 return(dp[m] = code(m+2,n,s,dp));
		}
		else
		{
			return(dp[m] =  0);
		}
	}
	else
	{
		//cout<<'b'<<endl;
		if(num>9 && num<=26)
		{
			return(dp[m] = (code(m+2,n,s,dp) + code(m+1,n,s,dp)));
		}
		else
		{
			return(dp[m] = code(m+1,n,s,dp));
		}
	}
}
}
 
int main()
{
	string s;
	do
	{
		cin>>s;
		if(s=="0")
			return 0;
		int dp[100000];
		for(int i=0;i<s.length();i++)
		{
			dp[i] = -1;
		}
		//cout<<s.length()<<endl;
		int ans = code(0,s.length(),s,dp);
		cout<< ans << endl;
	}while(s!="0");
	return 0;
} 