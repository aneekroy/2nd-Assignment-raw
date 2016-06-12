/*4. Design an ARRAY class with the following features:
a. Array object may be declared for a specific size and a value for initializing all the elements. If this it is to be assumed as a 0.
b. An array object may be declared and initialized with another object.
c. An array object may be declared and initialized with another array (not the object, standard array as in C language).
	Let a and b are two objects:
		i. a+b will add corresponding elements.
		ii. a=b will do the assignment.
		iii. a[I] will return the ith element of the object.
		iv. a*5 or 5*a will multiply the element with 5.*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

template <class Type>

class Array
{
	Type *a;	/*Private data members*/
	int size;
	
	int get_size()
	{
		return size;
	} 
	
	public:			/*Public Function Members*/
	
	Array(int size1){
		size=size1;
		
		a= new Type[size];		/*User defined constructor*/
		for(int i=0;i<size;i++)
			a[i]=0;
	}
	
	void operator = (Type *f)
	{
		for(int i=0;i<size;i++)
			a[i]=*(f+i);		/*Assignment Opearion with a pointer of a particuar data type*/
	}	
	
	void operator = (Array b)
	{
		int c=b.get_size();
		
		if(c>size)
			c=size;			/*Assignment Opearion with another object of same data type*/
			
		for(int i=0;i<c;i++)
			a[i]=b.a[i];
	}
	
	int operator [] (int i)			/*Operator overloading to return array element*/
	{
		if(i>size)
			cout<<"\n\t Wrong access point";
			
		else
			return a[i];
	}
	
	Array operator * (int k)		/*Operator overloading for integer multiplication with an array(a*5 form)*/
	{
		Array b(size);
		for(int i=0;i<size;i++)
			b.a[i]=a[i]*k;
			
		return b;
	} 
	
	friend Array operator * (int a, Array b)	/*Operator overloading for integer multiplication with an array(5*a form)*/
	{
		return b*a;
	}
	
	Array operator + (Array b)		/*Operator overloading for adding two objects*/
	{
		Array c(size);
		
		for(int i=0;i<size;i++)
			c.a[i]=a[i]+b.a[i];
		
		return c;	
	}
	
	void print_array(void)			/*Print the desired array*/
	{
		for(int i=0;i<size;i++)
			cout<<a[i]<<endl;
	}
};


void for_float(int h)				
{
	int choice,n,k;
	float *f;
	Array<float> a(h),b(h),c(h);
	
	cout<<"\n\t Please enter the 1st array: "<<endl;	/*Declaration and manupulation for Array type float with general function*/
	f=new float[h];
	
	for(int i=0;i<h;i++)
		cin>>f[i];
	a=f;
	
	cout<<"\n\t Please enter the 2nd array: "<<endl;
		
	for(int i=0;i<h;i++)
		cin>>f[i];
	
	b=f;
	
	do
	{
		cout<<"\n\t Please input your choice\n\t1.Assign by another array\n\t2.Addition\n\t3.Return an array element\n\t4.Multiply with any const(a*5 i.e. form 1)\n\t5.Multiply with any const(5*a i.e. form 2)\n\t6.Print the array\n\t7.Exit ....->";
		
		cin>>choice;
		switch(choice)
		{
			
			case 1:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				if(n==1)
					c=a;		/*Switch case system for various required operations in float arena*/
				else
					c=b;
					
				cout<<"\n\t After Assignment the New array is: "<<endl;
				c.print_array();
				cout<<endl;
				break;
			
			case 2:
				c=a+b;
				break;
				
			case 3:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the array key: ";
				cin>>k;
				if(n==1)
					cout<<"\n\t So that particular element will be: "<<a[k]<<endl;
				else 
					cout<<"\n\t So that particular element will be: "<<b[k]<<endl;
				break;
				
			case 4:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the multiplier const: ";
				cin>>k;
				
				if(n==1)
					c=a*k;
				else 
					c=b*k;
				break;
				
			case 5:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the multiplier const: ";
				cin>>k;
				
				if(n==1)
					c=k*a;
				else 
					c=k*b;
				break;
				
			case 6:
				cout<<"\n\t So the resultant array is: "<<endl;
				c.print_array();
				cout<<endl;
				break;
				
			case 7:
				cout<<"\n\t Thank you.";
				exit(0);
				
			default:
				cout<<"\n\t Wrong Entry";
				break;
		}			
	
	}while(1);
}

void for_integer(int h)
{
	int choice,n,k;
	int *i1;
	Array<int> a(h),b(h),c(h);
	
	cout<<"\n\t Please enter the 1st array: "<<endl;       /*Declaration and manupulation for Array type integer with general function*/
	i1=new int[h];
	
	for(int i=0;i<h;i++)
		cin>>i1[i];
	a=i1;
	
	cout<<"\n\t Please enter the 2nd array: "<<endl;
		
	for(int i=0;i<h;i++)
		cin>>i1[i];
	
	b=i1;
	
	do
	{
		cout<<"\n\t Please input your choice\n\t1.Assign by another array\n\t2.Addition\n\t3.Return an array element\n\t4.Multiply with any const(a*5 i.e. form 1)\n\t5.Multiply with any const(5*a i.e. form 2)\n\t6.Print the array\n\t7.Exit ....->";
		
		cin>>choice;
		switch(choice)
		{
			
			case 1:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				if(n==1)
					c=a;		/*Switch case system for various required operations in integer arena*/
				else
					c=b;
					
				cout<<"\n\t After Assignment the New array is: "<<endl;
				c.print_array();
				cout<<endl;
				break;
			
			case 2:
				c=a+b;
				break;
				
			case 3:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the array key: ";
				cin>>k;
				if(n==1)
					cout<<"\n\t So that particular element will be: "<<a[k]<<endl;
				else 
					cout<<"\n\t So that particular element will be: "<<b[k]<<endl;
				break;
				
			case 4:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the multiplier const: ";
				cin>>k;
				
				if(n==1)
					c=a*k;
				else 
					c=b*k;
				break;
				
			case 5:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the multiplier const: ";
				cin>>k;
				
				if(n==1)
					c=k*a;
				else 
					c=k*b;
				break;
				
			case 6:
				cout<<"\n\t So the resultant array is: "<<endl;
				c.print_array();
				cout<<endl;
				break;
				
			case 7:
				cout<<"\n\t Thank you.";
				exit(0);
				
			default:
				cout<<"\n\t Wrong Entry";
				break;
		}			
	
	}while(1);
}

void for_double(int h)
{
	int choice,n,k;
	double *d;
	Array<double> a(h),b(h),c(h);
	
	cout<<"\n\t Please enter the 1st array: "<<endl;
	d=new double[h];
	
	for(int i=0;i<h;i++)					/*Declaration and manupulation for Array type double with general function*/
		cin>>d[i];
	a=d;
	
	cout<<"\n\t Please enter the 2nd array: "<<endl;
		
	for(int i=0;i<h;i++)
		cin>>d[i];
	
	b=d;
	
	do
	{
		cout<<"\n\t Please input your choice\n\t1.Assign by another array\n\t2.Addition\n\t3.Return an array element\n\t4.Multiply with any const(a*5 i.e. form 1)\n\t5.Multiply with any const(5*a i.e. form 2)\n\t6.Print the array\n\t7.Exit ....->";
		
		cin>>choice;
		switch(choice)
		{
			
			case 1:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				if(n==1)
					c=a;		/*Switch case system for various required operations in double arena*/
				else
					c=b;
					
				cout<<"\n\t After Assignment the New array is: "<<endl;
				c.print_array();
				cout<<endl;
				break;
			
			case 2:
				c=a+b;
				break;
				
			case 3:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the array key: ";
				cin>>k;
				if(n==1)
					cout<<"\n\t So that particular element will be: "<<a[k]<<endl;
				else 
					cout<<"\n\t So that particular element will be: "<<b[k]<<endl;
				break;
				
			case 4:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the multiplier const: ";
				cin>>k;
				
				if(n==1)
					c=a*k;
				else 
					c=b*k;
				break;
				
			case 5:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the multiplier const: ";
				cin>>k;
				
				if(n==1)
					c=k*a;
				else 
					c=k*b;
				break;
				
			case 6:
				cout<<"\n\t So the resultant array is: "<<endl;
				c.print_array();
				cout<<endl;
				break;
				
			case 7:
				cout<<"\n\t Thank you.";
				exit(0);
				
			default:
				cout<<"\n\t Wrong Entry";
				break;
		}			
	
	}while(1);
}

int main()
{
	int h;
	char choice[6];
	cout<<"\n\t Please mention the type of the input do you want(int/double/float):  ";
	cin>>choice;
	
	cout<<"\n\t Please mention the no of the input do you want include:  ";
	cin>>h;
	
	do
	{
		if(!strcmp(choice,"int"))	/*Looping around to choose the datatype of that particular array required*/
		{
			for_integer(h);
			break;
		}					/*And calling that particular function for operations*/
		
		else if(!strcmp(choice,"double"))
		{	
			for_double(h);
			break;
		}
		else if(!strcmp(choice,"float"))
		{	
			for_float(h);
			break;
		}	
	
		else
			cout<<"\n\t Wrong Entry";
			
	}while(1);

	return 0;
}
