//Paste this main after the
int main() {
	//srand(time(NULL));
	int size;
	cout<<"Enter size of array you want";
	cin>>size;
	RationalNumber *r;
	r = new RationalNumber[size];
	//initializing array
	for(int i=0;i<size;i++) {			
		r[i].setNumerator(rand()%11-5);
		r[i].setDenominator(rand()%11-5);
	}
	cout<<"ARRAY IS: "<<endl;
	for(int i=0;i<size;i++) {
		cout<<i+1<<": "; r[i].print(); cout<<endl;
	}
	RationalNumber largest = r[0];
	RationalNumber smallest = r[0];
	for(int i=1;i<size;i++) {
		if(largest<r[i]) {
			largest=r[i];
		}
		 else if(smallest>r[i]) {
			smallest=r[i];
		}
	}
	cout<<"Largest  Number: "; largest.print(); cout<<endl;
	cout<<"Smallest  Number: "; smallest.print(); cout<<endl;
	delete [] r;
	return 0;	
}
