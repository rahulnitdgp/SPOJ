#include<bits/stdc++.h>
using namespace std;
int main()
{
	int col,row;
	cin>>col;
	while(col!=0)
	{
		string s;
		cin>>s;
		row = s.length()/col;
		int cnt = 1;
		for(int i=0;i<col;i++)
		{
			int count = 0;
			for(int j=i;count<row;)
			{
				cout<<s[j];
				if(count%2==0)
				{
					j = j + (2*col - cnt);
				}
				else
				{
					j = j+cnt;
				}
				count++;
			}

			cnt+=2;
		}
		cout<<endl;
		cin>>col;
	}
	return 0;
}