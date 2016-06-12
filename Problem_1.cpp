#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;

int main()
{
	int count=0,c,flip;
	srand(time(NULL));
	do
	{
		flip=rand()%2;
		if(flip)
		{
			cout<<"\n\t Heads";
			c++;
		}
		else
		{	
			cout<<"\n\t Tails";
			c=0;
		}
			
		count++;
	}while(c<3);
	
	cout<<"\n\n It tooks "<<count<<" flips to get three consecutive heads."<<endl;
	
	return 0;
}
