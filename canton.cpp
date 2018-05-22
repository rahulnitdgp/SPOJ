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
		double diag;
		diag = ceil((-1 + sqrt(1 + 8*n))/2);
		int end = diag*(diag+1)/2;
		int start = end - diag + 1;
		int ans_top, ans_bottom;
		if(int(diag)%2 == 0)
		{
			ans_top = 1 + (n-start);
			ans_bottom = diag - (n-start);
		}
		else
		{
			ans_top = diag - (n-start);
			ans_bottom = 1 + (n-start);	
		}
		cout<<"TERM"<<" "<<n<<" "<<"IS "<<ans_top<<"/"<<ans_bottom<<endl;
	}
	return 0;
}