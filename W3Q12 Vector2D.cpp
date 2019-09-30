#include<iostream>
#include<cmath>
using namespace std;
class Point {
	private: 
		float x,y;
	public:
		Point() {
			setX(0.00);
			setY(0.000);
		}
		Point(float Newx, float Newy) {
			x=Newx;
			y=Newy;
		} 
		
		void print() {
			cout<<"("<<x<<","<<y<<")";
		}
		void setX(float Newx) {
			x=Newx;
		}
		float getX() {
			return x;
		}
		void setY(float Newy) {
		y=Newy;
		}
		float getY() {
			return y;
		}
};

class Vector2D {
	private:
		Point x;
	public:
		Vector2D() {
			x.print();
		}
		Vector2D(Point y) {
			x=y;
		}
		Vector2D(float a, float b) {
			x.setX(a);
			x.setY(b);
		}
		Point getVector() const{
			return x;
		}
		void setVector(Point y) {
			x=y;
		}
		void setVector(float a, float b) {
			x.setX(a);
			x.setY(b);
		}
		void printVector() {
			Point o;
			o.print(); cout<<"---";	x.print();
		}
		
		//length calculator
		float getLength() const;
		//double getangle();
		
		// the operators
		Vector2D operator+(const Vector2D ) const;
		Vector2D operator-(const Vector2D )	const;
		Vector2D operator++() ;
		Vector2D operator++(int DUMMY);
		Vector2D operator--();
		Vector2D operator--(int DUMMY);
		
		//friend streaming operators
		friend istream& operator>>(istream& in , Vector2D& p); 
		friend ostream& operator<<(ostream& out, Vector2D& p);		
};
float Vector2D::getLength() const {
	float a = this->getVector().getX();
	float b = this->getVector().getY();
	float d=sqrt(abs(pow(a,2)));	// calculating distance of point from origin
}
Vector2D Vector2D::operator+(const Vector2D v) const {
	float a1 = this->getVector().getX();
	float b1 = this->getVector().getY();
	float a2 = v.getVector().getX();
	float b2 = v.getVector().getY();
	Vector2D r(a1+a2,b1+b2); // adding x to x and y to y
	return r;	
}
Vector2D Vector2D::operator-(const Vector2D v) const {
	Vector2D r(this->getVector().getX()-v.getVector().getX(),this->getVector().getY()-v.getVector().getY()); //subtracting x from x and...
	return r;	
}
Vector2D Vector2D::operator++() { 
	float d=this->getLength();
	d=pow(d,2);
	Point x((this->getVector().getX()/d),(this->getVector().getY()/d));
	Vector2D r(x);
	*this=*this+r;
	return *this;	
}
Vector2D Vector2D::operator++(int Dummy) { 
	float d=this->getLength();
	d=pow(d,2);
	Point x((this->getVector().getX()/d),(this->getVector().getY()/d));
	Vector2D r(x),temp=*this;
	*this=*this+r;
	return temp;	
}  
Vector2D Vector2D::operator--() { 
	float d=this->getLength();
	d=pow(d,2);
	Point x((this->getVector().getX()/d),(this->getVector().getY()/d));
	Vector2D r(x);
	*this=*this-r;
	return *this;	
}
Vector2D Vector2D::operator--(int Dummy) { 
	float d=this->getLength();
	d=pow(d,2);
	Point x((this->getVector().getX()/d),(this->getVector().getY()/d));
	Vector2D r(x),temp=*this;
	*this=*this-r;
	return temp;	
}

istream& operator>>(istream& in, Vector2D& p) {
	cout<<endl;
	float a, b;
	cout<<"Enter the x coordinate of the vector";
	in>>a;
	cout<<"Enter the y coordinate of the vector";
	in>>b;
	p.setVector(a,b);
	return in;
}
ostream& operator<<(ostream& out, Vector2D& p) {
	out<<"(0,0)----("<<p.getVector().getX()<<","<<p.getVector().getY()<<")";
	return out;
}
int main() {
	Vector2D v;
	cin>>v;
	v--;
	cout<<"Vector v is: ";
	cout<<v;
	cout<<endl;
	return 0;
}
