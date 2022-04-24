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
/*		for(i=1; i< Max; i++)
		{
			for(j= Pos+1; j!=(Pos+ i)% 10; j++)
			{
				cout<<"\n inside for";							
			}
		}*/
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
	int K;
	cout<<"\n Enter the number to be searched:\t";
	cin>>key;
	K= key% 10;
	for(i=0; i<Max; i++)
	{
		if(Tel[K]!= -1)
		{
			cout<<"\n The key"<< key<<" has found on location"<< i;
		}
	}
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
		cout<<"\n Select choice:\n 1. Insert\n 2. Display \n 3. Search \n 0. Exit\t";
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

-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	1

 Enter telephone number:9823031018

-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	2

	0	:-1
	1	:-1
	2	:-1
	3	:-1
	4	:-1
	5	:-1
	6	:-1
	7	:-1
	8	:9823031018
	9	:-1
-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	1

 Enter telephone number:9850743850

-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	2

	0	:9850743850
	1	:-1
	2	:-1
	3	:-1
	4	:-1
	5	:-1
	6	:-1
	7	:-1
	8	:9823031018
	9	:-1
-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	1

 Enter telephone number:9404906046  

-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	2

	0	:9850743850
	1	:-1
	2	:-1
	3	:-1
	4	:-1
	5	:-1
	6	:9404906046
	7	:-1
	8	:9823031018
	9	:-1
-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	1

 Enter telephone number:8999943549 

-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	2

	0	:9850743850
	1	:-1
	2	:-1
	3	:-1
	4	:-1
	5	:-1
	6	:9404906046
	7	:-1
	8	:9823031018
	9	:8999943549
-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	1 

 Enter telephone number:7721840345

-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	2

	0	:9850743850
	1	:-1
	2	:-1
	3	:-1
	4	:-1
	5	:7721840345
	6	:9404906046
	7	:-1
	8	:9823031018
	9	:8999943549
-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	1

 Enter telephone number:7588109227

-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	2

	0	:9850743850
	1	:-1
	2	:-1
	3	:-1
	4	:-1
	5	:7721840345
	6	:9404906046
	7	:7588109227
	8	:9823031018
	9	:8999943549
-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	1    

 Enter telephone number:7787875985

 This is the case of collision.
 Here we've reached the end of loop
 Wrapping to the start.............
-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	2

	0	:9850743850
	1	:7787875985
	2	:-1
	3	:-1
	4	:-1
	5	:7721840345
	6	:9404906046
	7	:7588109227
	8	:9823031018
	9	:8999943549
-----------------------------------
		MENU
-----------------------------------
 Select choice:
 1. Insert
 2. Display
 0. Exit	0

*/
