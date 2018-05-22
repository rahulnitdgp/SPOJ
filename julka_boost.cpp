#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
	int t=10;
	while(t--)
	{
	mp::cpp_int total;
	mp::cpp_int more;
	mp::cpp_int klaudia;
	mp::cpp_int natalia;
	cin>>total>>more;

	klaudia = (total + more)/2;
	natalia = total - klaudia;
	cout<<klaudia<<endl;
	cout<<natalia<<endl;
}
	return 0;
}

//NOTE: BOOST LIBRARY IN C++ PROVIDES INTEGER,RATIONAL AND FLOATING TYPES WHICH HAVE MORE RANGE AND PRECISION THAN BUILT IN 
//TYPES IN C++. THEY CAN ONLY BE USED IN C++14.