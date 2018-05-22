#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		mp::cpp_int a;
		mp::cpp_int b;
		cin>>a>>b;
		mp::cpp_int rem = b%4;
		mp::cpp_int last = a%10;
		mp::cpp_int ans=0;
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