#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a1,a2,a3;
	cin>>a1>>a2>>a3;
	while(a1!=0 || a2!=0 || a3!=0)
	{
		if(a2-a1 == a3-a2)
		{
			int a4 =  2*a3 - a2;
			cout<<"AP"<<" "<<a4<<endl;
		}
		else if((a2/a1) == (a3/a2))
		{
			int a4 = a3*a3/a2;
			cout<<"GP"<<" "<<a4<<endl;	
		}
		cin>>a1>>a2>>a3;
	}
	return 0;
}