#include<iostream>
#include<cmath>
using namespace std;
class Money {
private:
	int dollars;
	int cents;
public:
	Money() {
		dollars=0;
		cents=0;
	}
	Money(int d, int c) {			//money m(12,134)
		dollars=d;
		cents=c;
		standardize();
	}
	void standardize(); 
	float getMoney() const;
	void setMoney(int ,int);
	void print() ;
	
};
float Money::getMoney() const {
	float m;
	m=cents;
	m=m/100+dollars;
	return m;
}
void Money::setMoney(int d, int c) {
	dollars=d;
	cents=c;
	this->standardize();
}
void Money::print()  {
	cout<<"The balance is: "<<this->dollars<<" dollars and "<<this->cents<<" cents.";
}
void Money::standardize() {
	if(cents>=100) {
		int q=cents/100;
		dollars+=q;
		cents=cents%100;
	}
} 
int main() {
	Money m(12,134);
	cout<<m.getMoney();
	return 0;
}
