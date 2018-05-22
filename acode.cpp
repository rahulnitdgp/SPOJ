//BOTTOM UP MANNER
//DONT CONSIDER 01 AS 1 OR 09 AS 9, ETC.
//STRING MAY CONTAIN 0

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	while(s!="0")
	{
		int dp[s.length()];
		dp[0] = 1;
		if(s.length()>=2)
		{
			if(s[1]=='0')
			{
				if(10*(s[0]-48)+(s[1]-48) <=26 && 10*(s[0]-48)+(s[1]-48) >9)
				{
					dp[1] = 1;
				}
				else
					dp[1] = 0;
			}
			else if(10*(s[0]-48)+(s[1]-48) <=26 && 10*(s[0]-48)+(s[1]-48) >9)
			{
				dp[1] = 2;
			}
			else
			{
				dp[1] = 1;
			}
		}
		for(int i=2;i<s.length();i++)
		{
			if(s[i]=='0')
			{
				if(10*(s[i-1]-48)+(s[i]-48) <=26 && 10*(s[i-1]-48)+(s[i]-48) >9)
				{
					dp[i] = dp[i-2];
				}
				else
					dp[i] = 0;
			}
			else if(10*(s[i-1]-48)+(s[i]-48) <=26 && 10*(s[i-1]-48)+(s[i]-48) >9)
			{
				dp[i] = dp[i-1]+dp[i-2];
			}
			else
			{
				dp[i] = dp[i-1];
			}
		}
		//for(int i=0;i<s.length();i++)
		//		cout<<dp[i]<<" ";
		//cout<<endl;
		cout<<dp[s.length()-1]<<endl;
		cin>>s;
	}
	return 0;
}