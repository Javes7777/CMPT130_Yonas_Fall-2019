// by recursion
/*RationalNumber elementAt(int n) {
	RationalNumber r1(2,6),r2(3,6);
	if(n==1)
		return r1;
	else if(n==2)
		return r2;
	else {
		return elementAt(n-1) + elementAt(n-2);
	}
}*/
// By for loop
RationalNumber elementAt(int n) {
	RationalNumber r1(2,6),r2(3,6),r;
	if(n==1)
		return r1;
	else if(n==2)
		return r2;
	else {
		for(int i=3;i<=n;i++) {
			r=r1+r2;
			r1=r2;
			r2=r;
		}
		return r;
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

