#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>

using namespace std;

class STRING
{
	char *a;
	
	public:
	
	STRING()
	{
		a='\0';
	}
	
	STRING (const STRING &t)
	{
		a=new char[strlen(t.a)+1];
		strcpy(a,t.a);
	}
	
	STRING(std::string b)
	{
		a=new char[b.size()+1];
		strcpy(a,b.c_str());
	}
	
	void operator =(const char *f)
	{
		a=new char[strlen(f)+1];
		strcpy(a,f);
	}
	
	void operator =(char *f)
	{
		a=new char[strlen(f)+1];
		strcpy(a,f);	
	}
	
	friend STRING operator +(STRING c,STRING b)
	{
		STRING s1;
		s1.a=new char[strlen(b.a)+strlen(c.a)+1];
			
		strcat(s1.a,c.a);
		strcat(s1.a,b.a);
		
		return s1;
	}
	
	void scan(void)
	{
		string s2;
		getline(cin,s2);
		a=new char[s2.size()+1];
		strcpy(a,s2.c_str());
	}
	
	friend ostream &operator <<(ostream &t,STRING &s)
	{
		t<<"\n\t The resultant string will be: "<<s.a<<endl ;
		return t;
	}
	
	friend int operator <(STRING b,STRING c)
	{
		if(strcasecmp(b.a,c.a)<0)
		return 1;
	}
	
	friend int operator >(STRING b,STRING c)
	{
		if(strcasecmp(b.a,c.a)>0)
		return 1;
	}	
	
	friend int operator ==(STRING b,STRING c)
	{
		if(strcasecmp(b.a,c.a)==0)
		return 1;
	}	 	
		
};
int main()
{
	STRING a,b,c;
	int choice;
	
	do
	{
		cout<<"\n\t Please input your choice: \n\t1.Want to enter a number of string\n\t2.Concatinate\n\t3.Compare\n\t4.Display\n\t5.Exit.....->";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cin.ignore();
					
				cout<<"\n\t Please input the 1st string: ";
				a.scan();
		
				cout<<"\n\t Please input the 2nd string: ";
				b.scan();
					
				break;
				
			case 2:
				c=a+b;
				cout<<"\n\t Both the string has been concatinated.";
				break;
				
			case 3:
				if(a>b)
					cout<<"\n\t 1st string is grater than the 2nd one.";
				
				else if(a==b)
					cout<<"\n\t Both the strings are same,";
				
				else if(a<b)
					cout<<"\n\t 2nd String is grater than the 1st one. ";
				break;
				
			case 4:
				cout<<c;
				break;
					
			case 5:
				cout<<"\n\t Thank you."<<endl;
				exit(0);
				
			default:
				cout<<"\n\t Wrong Entry.";
				break;
		}
			
	}while(1);
	
	return 0;
}
