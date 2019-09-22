#include <iostream>
#include<cmath>
using namespace std;
class RationalNumber {
	/*
	This class is designed to represent Rational Number objects.
	A rational number is a number of the form a/b with integers
	a and b such that b is different from 0.
	*/
private:
	int a, b;
public:
	//Constructors
	RationalNumber();						// constructors are never constant
	RationalNumber(const int&, const int&);	// '' '' ''

	//Getters
	int getNumerator() const;
	int getDenominator() const;

	//Setters
	void setNumerator(const int& num);
	void setDenominator(const int& denom);

	//Additional member functions
	double toDouble() const;
	void standardize(); 
	void reduce(); 
	void print() const;
	// basic mathematics
	RationalNumber operator+(const RationalNumber&) const;
	RationalNumber operator+(const int&) const;
	RationalNumber operator-(const RationalNumber&) const;
	RationalNumber operator-(const int&) const;
	RationalNumber operator*(const RationalNumber&) const;
	RationalNumber operator*(const int&) const;
	RationalNumber operator/(const RationalNumber&) const;
	RationalNumber operator/(const int&) const;
	//basic binary compounds
	RationalNumber operator+=(const RationalNumber& r) const; 
	RationalNumber operator+=(const int& x) const; 
	RationalNumber operator*=(const RationalNumber& r) const; 
	RationalNumber operator*=(const int& x) const; 
	RationalNumber operator/=(const RationalNumber& r) const; 
	RationalNumber operator/=(const int& x) const; 
	RationalNumber operator-=(const RationalNumber& r) const;
	RationalNumber operator-=(const int& x) const; 
	//logical
	bool isEqual(const RationalNumber& ) const;
	bool operator==(const RationalNumber& ) const;
	bool operator==(const int& ) const;
	bool operator!=(const RationalNumber& ) const;
	bool operator!=(const int& ) const;
	bool operator<(const RationalNumber& ) const;
	bool operator<(const int& ) const;
	bool operator<=(const RationalNumber& ) const;
	bool operator<=(const int& ) const;
	bool operator>(const RationalNumber& ) const;
	bool operator>(const int& ) const;
	bool operator>=(const RationalNumber& ) const;
	bool operator>=(const int& ) const;
	//increment and decrement unary operators.
	RationalNumber operator++();
	RationalNumber operator--();
};

//Constructors
RationalNumber::RationalNumber() {
	//As a default object, let us construct 0/1 rational number
	a = 0;
	b = 1;
}

RationalNumber::RationalNumber(const int& a, const int& b) {
	//If the denominator parameter is 0, ignore it and use 1
	this->a = a;
	this->b = b != 0 ? b : 1;
	//Now that the object is created, standardize and reduce it
	standardize();
	reduce();
}

//Getters
int RationalNumber::getNumerator() const {
	return a;
}
int RationalNumber::getDenominator() const {
	return b;
}

//Setters
void RationalNumber::setNumerator(const int& a) {
	this->a;
	//Now that numerator of an existing object is modified,
	//standardize it and reduce it
	standardize();
	reduce();
}
void RationalNumber::setDenominator(const int& b) {
	//If the denominator parameter is 0, ignore it and use 1
	this->b = b != 0 ? b : 1;
	//Now that denominator of an existing object is modified,
	//standardize it and reduce it
	standardize();
	reduce();
}

//Additional member functions
double RationalNumber::toDouble() const  {
	double d = static_cast<double>(a/b);
	return d;
}
void RationalNumber::reduce() {
	if (a == 0)
	{
		b = 1;
		return;
	}
	else
	{
		//Remeber that the denominator is NEVER zero by design
		//Therefore here both numerator and denominator are non-zero.
		int m = abs(a);
		int n = abs(b);
		int gcd = m < n ? m : n;
		while (gcd > 0)
		{
			if (m % gcd == 0 && n % gcd == 0)
				break;
			gcd--;
		}
		a /= gcd;
		b /= gcd;
	}
}
void RationalNumber::print() const {
	cout << a << "/" << b;
}
bool RationalNumber::isEqual(const RationalNumber& r) const {
	if(this->a*r.b==r.a*this->b) 
		return true;
	else
		return false;
}

//binary operators basic
RationalNumber RationalNumber::operator+(const RationalNumber& r) const {	
	int a1=this->a;
	int b1=this->b;
	int a2=r.a;
	int b2=r.b;
	RationalNumber answer(a1*b2+a2*b1, b1*b2);
	answer.standardize();
	answer.reduce();
}
RationalNumber RationalNumber::operator+(const int &x) const {
	RationalNumber temp(x,1);
	return *this+temp;
}
RationalNumber operator+(const int &x , RationalNumber & r) {
	return r+x;
}
RationalNumber RationalNumber::operator*(const RationalNumber& r) const {
	int a1=r.a;
	int b1=r.b;
	int a2=this->a;
	int b2=this->b;
	RationalNumber product(a1*a2,b1*b2);
	return product;
}
RationalNumber RationalNumber::operator*(const int &x) const {
	RationalNumber temp(x,1);
	return *this+temp; 	
}
RationalNumber operator*(const int &x, const RationalNumber& r) {
	return r*x;
}
RationalNumber RationalNumber::operator/(const RationalNumber& r) const {
	int a1=r.a;
	int b1=r.b;
	int a2=this->a;
	int b2=this->b;
	RationalNumber div(a1*b2,b1*a2);
	return div;
}
RationalNumber RationalNumber::operator/(const int &x) const {
	RationalNumber temp(x,1);
	return *this/temp; 	
}
RationalNumber operator/(const int &x, const RationalNumber& r) {		// well division is not commutative my friend
	RationalNumber div(r.getDenominator()*x,r.getNumerator());
	return div;
}
RationalNumber RationalNumber::operator-(const RationalNumber& r) const {
	int a1=this->a;
	int b1=this->b;
	int a2=r.a;
	int b2=r.b;
	RationalNumber answer(a1*b2-a2*b1, b1*b2);
	answer.standardize();
	answer.reduce();
}
RationalNumber RationalNumber::operator-(const int& x) const {
	RationalNumber temp(x,1);
	return *this-temp;	
}
RationalNumber operator-(const int &x, const RationalNumber& r) {
	return r-x;
}
//binary compound operators
RationalNumber RationalNumber::operator+=(const RationalNumber& r) const {
	return *this+r;
}
RationalNumber RationalNumber::operator+=(const int& x) const {
	return *this+x;
}
RationalNumber RationalNumber::operator*=(const RationalNumber& r) const {
	return *this*r;
}
RationalNumber RationalNumber::operator*=(const int& x) const {
	return *this*x;
}
RationalNumber RationalNumber::operator/=(const RationalNumber& r) const {
	return *this/r;
}
RationalNumber RationalNumber::operator/=(const int& x) const {
	return *this/x;
}
RationalNumber RationalNumber::operator-=(const RationalNumber& r) const {
	return *this-r;
}
RationalNumber RationalNumber::operator-=(const int& x) const {
	return *this-x;
}
//logical operators
bool RationalNumber::operator==(const RationalNumber& r ) const {
	return this->isEqual(r);		// {r.isEqual(*this);}	should also work according to commutative property.
}
bool RationalNumber::operator==(const int& x) const {
	RationalNumber temp(x,1);
	return this->isEqual(temp);	
}
bool operator==(const int& x, const RationalNumber& r) {
	if(r==x)
		return true;
	else
		return false;
}
bool RationalNumber::operator!=(const RationalNumber& r ) const {
	return !(this->isEqual(r));		// negation of {r.isEqual(*this);}	should also work according to commutative property.
}
bool RationalNumber::operator!=(const int& x) const {
	RationalNumber temp(x,1);
	return !(this->isEqual(temp));	
}
bool operator!=(const int& x, const RationalNumber& r) {
	if(r!=x)
		return true;
	else
		return false;
}
bool RationalNumber::operator<(const RationalNumber& r ) const {
	if((this->a*r.b)<(this->b*r.a))
		return true;
	else 
		return false;
}
bool RationalNumber::operator<(const int& x) const {
	RationalNumber temp(x,1);
	return !(*this<temp);	
}
bool operator<(const int& x, const RationalNumber& r) {
	if(r<x)
		return false;
	else
		return true;
}
bool RationalNumber::operator<=(const RationalNumber& r ) const {
	if((this->a*r.b)<=(this->b*r.a))
		return true;
	else 
		return false;
}
bool RationalNumber::operator<=(const int& x) const {
	RationalNumber temp(x,1);
	return !(*this<=temp);	
}
bool operator<=(const int& x, const RationalNumber& r) {
	if(r<=x)			//r>=x condition should also work but point to be noted here that the condition you are using should be defined.
		return false;
	else
		return true;
}
bool RationalNumber::operator>(const RationalNumber& r ) const {
	if((this->a*r.b)>(this->b*r.a))
		return true;
	else 
		return false;
}
bool RationalNumber::operator>(const int& x) const {
	RationalNumber temp(x,1);
	return !(*this>temp);	
}
bool operator>(const int& x, const RationalNumber& r) {
	if(r>x)
		return false;
	else
		return true;
}
bool RationalNumber::operator>=(const RationalNumber& r ) const {
	if((this->a*r.b)>=(this->b*r.a))
		return true;
	else 
		return false;
}
bool RationalNumber::operator>=(const int& x) const {
	RationalNumber temp(x,1);
	return !(*this>=temp);	
}
bool operator>=(const int& x, const RationalNumber& r) {
	if(r>=x)			//r>=x condition should also work but point to be noted here that the condition you are using should be defined.
		return false;
	else
		return true;
}
//unary operators
RationalNumber RationalNumber::operator++() {
	return *this+=1;
}
RationalNumber RationalNumber::operator++() {
	return *this-=1;
}
RationalNumber& operator++(RationalNumber& r) {
	return &(r+=1);	
}
RationalNumber& operator--(RationalNumber& r) {
	return &(*r-=r);
}

int main() {
	//Test constructors
	const RationalNumber r1;
	RationalNumber r2(-5, 6);
	const RationalNumber *r3	= new RationalNumber();
	const RationalNumber *r4;
	r4 = new RationalNumber(4, -6);

	//Test getters
	cout << "r1 numerator is " << r1.getNumerator() << endl;
	cout << "r3 denominator is " << r3->getDenominator() << endl;

	//Test setters, standardize, reduce and print member functions
	r2.setDenominator(-10);
	cout << "r2 is now "; r2.print(); cout << endl;
	
	//Print all the objects
	cout << "r1 = "; r1.print(); cout << endl;
	cout << "r2 = "; r2.print(); cout << endl;
	cout << "r3 = "; r3->print(); cout << endl;
	cout << "r4 = "; r4->print(); cout << endl;

	//Test toDouble member function
	cout << "In double format, r4 = " << r4->toDouble() << endl;
	r2=3*r1;;
	cout<<"3+r1:"<<endl;
	r2.print();
	//Delete objects created on the heap
	delete r3;
	delete r4;

	system("pause");
	return 0;
}
