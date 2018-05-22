#include<bits/stdc++.h>
using namespace std;
int reverse(int num)
{
	int rev_num=0;
	while(num>0)
	{
		rev_num = (10*rev_num) + (num%10);
		num = num/10;	
	}
	return rev_num;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num1, num2;
		cin>>num1>>num2;
		int num3 = 0;
		int carry=0,sum=0;
		num1 = reverse(num1);
		num2 = reverse(num2);
		//cout<<num1<<" "<<num2<<endl;
		while(num1>0 && num2>0)
		{
		    sum = (carry + (num1%10) + (num2%10))%10;
			carry = (carry + (num1%10) + (num2%10))/10;
			num3 = (10*num3) + (sum);
			num1 = num1/10;
			num2 = num2/10;
		}
		while(num1>0)
		{
			sum = (carry + (num1%10))%10;
			carry = (carry + (num1%10))/10;
			num3 = (10*num3) + (sum);
			num1 = num1/10;
		}
		while(num2>0)
		{
			sum = (carry + (num2%10))%10;
			carry = (carry + (num2%10))/10;
			num3 = (10*num3) + (sum);
			num2 = num2/10;
		}
		if(carry>0)
			num3 = (10*num3) + carry;
		cout<<num3<<endl;
	}
	return 0;
}

