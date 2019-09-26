#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct StringStat
{
string s;
int lower, upper, digit;
}str;
int main() {
	str.s="GurKamalis12";
	str.lower=0;
	str.upper=0;
	str.digit=0;
	int l=str.s.length();
	for(int i=0;i<=l;i++) {
		if(islower(str.s[i]))
			str.lower++;
		else if(isupper(str.s[i]))
			str.upper++;
		else if(isdigit(str.s[i]))
			str.digit++;
		}
		cout<<"Upper: "<<str.upper<<endl;
		cout<<"Lower "<<str.lower<<endl;
		cout<<"Digit "<<str.digit<<endl;
	return 0;
}
