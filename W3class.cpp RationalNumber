#include <iostream>
#include<cmath>
using namespace std;
class RationalNumber
{
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
	RationalNumber operator+(const RationalNumber&) const;
	RationalNumber operator+(const int&) const;
};

//Constructors
RationalNumber::RationalNumber()
{
	//As a default object, let us construct 0/1 rational number
	a = 0;
	b = 1;
}

RationalNumber::RationalNumber(const int& a, const int& b)
{
	//If the denominator parameter is 0, ignore it and use 1
	this->a = a;
	this->b = b != 0 ? b : 1;
	//Now that the object is created, standardize and reduce it
	standardize();
	reduce();
}

//Getters
int RationalNumber::getNumerator() const
{
	return a;
}
int RationalNumber::getDenominator() const
{
	return b;
}

//Setters
void RationalNumber::setNumerator(const int& a)
{
	this->a;
	//Now that numerator of an existing object is modified,
	//standardize it and reduce it
	standardize();
	reduce();
}
void RationalNumber::setDenominator(const int& b)
{
	//If the denominator parameter is 0, ignore it and use 1
	this->b = b != 0 ? b : 1;
	//Now that denominator of an existing object is modified,
	//standardize it and reduce it
	standardize();
	reduce();
}

//Additional member functions
double RationalNumber::toDouble() const
{
	return static_cast<double>(a)/b;
}
void RationalNumber::standardize()
{
	if (b < 0)
	{
		a *= -1;
		b *= -1;
	}
}
void RationalNumber::reduce()
{
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
void RationalNumber::print() const
{
	cout << a << "/" << b;
}

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
RationalNumber RationalNumber::operator+(const int&, RationalNumber & r) {
	return this
}
int main()
{
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
	r2=r1+3;
	cout<<"3+r1:"<<endl;
	r2.print();
	//Delete objects created on the heap
	delete r3;
	delete r4;

	system("Pause");
	return 0;
}
