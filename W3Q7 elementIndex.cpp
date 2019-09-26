int elementIndex(RationalNumber r) {
	RationalNumber r1(1,3), r2(1,2), r3;
	int index=2;
	if(r==r1)
		return 1;
	else if(r==r2) 
		return 2;
	else {
		while(true) {
			r3=r1+r2;
			index++;
			if(r==r3) 
				return index;
			else if(r3>r) 
				return -1;
			else {
				r1=r2;
				r2=r3;
			}	
		}
	}
}
//Test main()
int main() {
	int n, d;
	cout<<"Please enter the numerator";
	cin>>n;
	cout<<"Please Enter the denominator"; 
	cin>>d;
	RationalNumber r(n,d); 
	int i = elementIndex(r);
	if(i>0)
		cout<<"Element found at Index: "<<i; 
	else
		cout<<"Sorry could'nt found";
	return 0;
}
