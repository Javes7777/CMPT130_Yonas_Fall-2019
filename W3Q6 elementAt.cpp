RationalNumber elementAt(int n) {
	RationalNumber r1(2,6),r2(3,6);
	if(n==1)
		return r1;
	else if(n==2)
		return r2;
	else {
		return elementAt(n-1) + elementAt(n-2);
	}
}
//Test main()
int main() {
	int n;
	cout<<"Please enter the index";
	cin>>n;
	RationalNumber e=elementAt(n);
	cout<<"Element at: "; e.print(); cout<<endl; 
	return 0;
}

