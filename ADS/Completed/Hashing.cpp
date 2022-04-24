#include<iostream>
using namespace std;

#define Max 10
class Hash
{
	public:
	long int Tel[Max];
	
	int N;
	Hash()
	{
		int i;
		for(i=0; i<Max; i++)
		{
			Tel[i]=-1;
		}
	}
	int HashFunction(long int key);
	int Insert();
	int Display();
	int Search();
	int InNoReplace();
};

int Hash:: HashFunction(long int key)
{
	int Pos;
	Pos= key %10;
	return Pos;
}

int Hash:: Insert()
{
	long int key;
	int i, Pos, j;
	cout<<"\n Enter telephone number:";
	cin>> key;
	Pos= HashFunction(key);
	if(Tel[Pos]== -1)
	{
		Tel[Pos]= key;
	}
	else
	{
		cout<<"\n This is the case of collision.";
		for(i=1; i< Max; i++)
		{	
			if(Tel[(Pos + i)%10]==-1)
			{
				Tel[(Pos + i)%10]= key;
				break;
			}
			if((Pos+ i)%10 ==9)
			{
				cout<<"\n Here we've reached the end of loop";
				cout<<"\n Wrapping to the start.............";
			}
		}		
	}
}

int Hash:: Display()
{
	int i;
	for(i=0; i<Max; i++)
	{
		cout<<endl;
		cout<<"\t"<< i<< "\t:"<< Tel[i];
	}
}

int Hash:: Search()
{
	long int key;
	int i;
	cout<<"\n Enter the number to be searched:\t";
	cin>>key;
	Pos= HashFunction(key);
	if(Tel[Pos]== key)
	{
		cout<<"\n *BEST CASE*";
		cout<<"\n The key "<< key<<" has found on location"<< Pos+ i;
	}
	else
	{
		for(i=1; i<Max; i++)
		{
			if(Tel[(Pos+ i)% 10]== key)
			{
				cout<<"\n The key "<< key<<" has found on location "<< ((Pos+ i)%10);			
			}
		}
	}
	return 0;
}

int Hash:: InNoReplace()
{
	long int key;
	int i, Pos, j;
	cout<<"\n Enter telephone number:";
	cin>> key;
	Pos= HashFunction(key);
	if(Tel[Pos]== -1)
	{
		Tel[Pos]= key;
	}
	else
	{
		cout<<"\n This is the case of collision.";
		for(i=1; i< Max; i++)
		{	
			if(Tel[(Pos + i)%10]==-1)
			{
				Tel[(Pos + i)%10]= key;
				break;
			}
			else if(Tel[Pos]!= -1) //Continue from here
			if((Pos+ i)%10 ==9)
			{
				cout<<"\n Here we've reached the end of loop";
				cout<<"\n Wrapping to the start.............";
			}
		}		
	}	
	retrurn 1;
}

int main()
{
	Hash H;
	int i, ch;

	do
	{
		cout<<"\n-----------------------------------";
		cout<<"\n\t\tMENU";
		cout<<"\n-----------------------------------";
		cout<<"\n Select choice:\n 1. Insert\n 2. Display \n 3. Search\n 0. Exit\t";
		cin>> ch;
		switch(ch)
		{
			case 1:
				H. Insert();
				break;
			case 2:
				H. Display();
				break;
			case 3:
				H. Search();
				break;
		}
	}while(ch!=0);
}

/*

			OUTPUT:
if((Pos+ i)%10 ==9)
		{
			cout<<"\n Here we've reached the end of loop";
			cout<<"\n Wrapping to the start.............";
		}
*/
