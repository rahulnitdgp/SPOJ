#include<bits/stdc++.h>
using namespace std;

void palin(int count, string arr)
{
	int leftsmaller = 0;
	int mid = count/2;
	int i = mid-1;
	int j = (count%2)? mid+1 : mid;
	while(i>=0 && arr[i]==arr[j] && j<count)
	{
		i--;
		j++;
	}
	if(i<0 || arr[i]<arr[j])
		leftsmaller = 1;
	while(i>=0)
	{
		arr[j] = arr[i];
		i--;
		j++;
	}
	if(leftsmaller)
	{
		int carry = 1;
		i = mid-1;
		if(count%2==1)
		{
			int ans =  (arr[mid]-'0') + carry;
			carry = ans/10;
			ans%=10;
			arr[mid] = ans + 48;
			j = mid+1;
		}
		else
			j = mid;
		while(i>=0)
		{
			int ans = (arr[i]-'0')+carry;
			carry = ans/10;
			ans = ans%10;
			arr[i] = ans + 48;
			arr[j++] = arr[i--];
		}
	}
	for(int i=0;i<count;i++)
			cout<<arr[i];
	cout<<endl;
}
int isNine(int count, string arr)
{
	for(int i=0;i<count;i++)
	{
		if(arr[i]!='9')
			return 0;
	}
	return 1;
}

int main()
{
	int t;
	cin>>t;
	string k;
	while(t--)
	{
		int count = 0;
		int i=0;
		cin>>k;
		count = k.length();
		if(isNine(count,k))
		{
			cout<<1;
			for(int i=0;i<count-1;i++)
				cout<<0;
			cout<<1<<endl;
			continue;
		}
	   palin(count,k);
		
	}
	return 0;
}