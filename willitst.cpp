#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
	mp::cpp_int n;
	cin>>n;
	mp::cpp_int arr[100];
	for(int i=0;i<100;i++)
	{
		arr[i] = (mp::cpp_int)pow(2,i);
	}
	for(int i=0; i<100; i++)
	{
		if(arr[i] == n)
		{
			cout<<"TAK";
			return 0;
		}
	}
	cout<<"NIE";
	return 0;
}
