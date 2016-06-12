#include<iostream>
#include<cstdio>

using namespace std;

void print_using_combinational_function(int rows)
{
	for(int i=0;i<rows;i++)
	{
		int values=1;
		for(int j=0;j<rows-i-1;j++)
		{
			cout<<"   ";
		}
		
		for(int k=0;k<=i;k++)
		{
			printf("%3d   ",values);
			values=values*(i-k)/(k+1);
		}
		cout<<endl<<endl;
	}
}

void space_print(int n)
{
	for(int i=0;i<n;i++)
		cout<<"   ";
}

int pascal_triangle_using_recurrsion(int r,int c)
{
	if(c==0 || c>r) 
	return 0;
	
	else if(r==1&&c==1)
	return 1;
	
	else
	return (pascal_triangle_using_recurrsion(r-1,c-1)+pascal_triangle_using_recurrsion(r-1,c));
}

void check_value(void)
{
	int row,column;
	
	cout<<"\n\t Please enter the x coordinate: ";
	cin>>row;
	
	cout<<"\n\t Please enter the y coordinate: ";
	cin>>column;
	
	cout<<"\n\t So the value would be: "<<pascal_triangle_using_recurrsion(row+1,column+1)<<endl;
}


int main()
{
	int  rows;
	
	cout<<"\n\t Please enter the number of rows: ";
	cin>>rows;
	
	cout<<endl;
	
	cout<<"\n\t Pascal triangle using Simple combinational formula: "<<endl;
	print_using_combinational_function(rows);
	
	cout<<endl;
	
	check_value();
	
	cout<<endl;
	
	cout<<"\n\t Pascal triangle using recurrsion: "<<endl;
	for(int i=0;i<=rows;i++)
	{
		space_print(rows-i);
		
		for(int j=1;j<=i;j++)
		{
			printf("%3d",pascal_triangle_using_recurrsion(i,j));
			space_print(1);
		}
		cout<<endl<<endl;
	}
	return 0;
}
