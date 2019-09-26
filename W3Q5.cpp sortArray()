void sortArray(RationalNumber* r, int n) {
   int i, j, min;
   RationalNumber temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
         if (r[j] < r[min])
            min = j;
      temp = r[i];
      r[i] = r[min];
      r[min] = temp;
   }
}
int main() {
	srand(time(NULL));
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
	cout<<"ARRAY BEFORE SORTING IS: "<<endl;
	for(int i=0;i<size;i++) {
		cout<<i+1<<": "; r[i].print(); cout<<endl;
	}
	sortArray(r,size);
	cout<<"ARRAY AFTER SORTING IS: "<<endl;
	for(int i=0;i<size;i++) {
		cout<<i+1<<": "; r[i].print(); cout<<endl;
	}
	delete[] r;
	return 0;
}
