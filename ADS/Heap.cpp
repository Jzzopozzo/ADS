#include<iostream>
using namespace std;
#define max 100

class Heap
{
	public:	
	int A[max];
	Heap()
	{
		int i;
		for(i=0; i<max; i++)
		{
			A[i]= -1;
		}
	}

	int Delete(int R, int N);			// to delete previous entry
	int Display(int N);
	int ReHeapUp(int N);			// to arrange in descending order from root to leaf
	int ReHeapDown(int N);		// to arrange in ascending order from root to leaf
};

int Heap:: Delete(int R, int N)
{
	int i;
	for(i=1; i<=N; i++)
	{
		if(i== R)
		{
			A[R]= A[R+1];
			cout<<"Deleted successfully!";
		}
	}
}

int Heap:: Display(int N)
{
	int i;
	cout<<endl;
	for(i=1; i<= N; i++)
	{		
		cout<< i<<":"<< A[i]<<"\t";
		cout<<endl;
	}
}
int Heap:: ReHeapDown(int N)
{
	int c, p, i;
	cout<< "\n Enter root:";
	cin>>A[1];
	for(i=2; i<=N; i++)
	{
		cin>> A[i];
		p= i/2;
		c= i;
		while(1)
		{
			if(A[c]< A[p])
			{
			int tmp;
			tmp= A[c];
			A[c]= A[p];
			A[p]= tmp;
			cout<<"\n Swapped parent"<< A[p] <<"with child"<< A[c]<<endl;
			}
			c= p;
 			p= p/2; 
			if(p< 1)
				break;
		}
	}
	cout<<"Minimum marks are"<< A[1];
}


int Heap:: ReHeapUp(int N)
{
	int c, p, i;
	cout<< "\n Enter root:";
	cin>>A[1];
	for(i=2; i<=N; i++)
	{
		cin>> A[i];
		p= i/2;
		c= i;
		while(1)
		{
			if(A[c]> A[p])
			{
			int tmp;
			tmp= A[c];
			A[c]= A[p];
			A[p]= tmp;
			cout<<"\n Swapped parent"<< A[p] <<"with child"<< A[c]<<endl;
			}
			c= p;
 			p= p/2; 
			if(p< 1)
				break;
		}
	}
	cout<<"Maximum marks are"<< A[1];
}
int main()
{
	Heap H;
	int n, ch, R;
	do
	{	
		cout<<"\n_________________________________________________";
		cout<< "\n Enter choice:\n 1. Delete marks \n 2. Arrange in ascending order\n 3. Arrange in descending order\n 4. Display list \n 0. Exit:\t";
	cin>> ch;
		cout<<"\n_________________________________________________";
		switch (ch)
		{	
			case 1:
				cout<<"\n Enter roll number whose marks fo you want to delete:";
				cin>>R;
				H. Delete(R, n);
				break;
	
			case 2:
				cout<< "\nHow many students are there in your class?";
				cin>> n;
				cout<< "\n Enter their marks:";
				H. ReHeapDown(n);
				break;
	
			case 3:
				cout<< "\nHow many students are there in your class?";
				cin>> n;
				cout<< "\n Enter their marks:";
				H. ReHeapUp(n);
				break;

			case 4:
				cout<<"\n  Sorted marks are:";
				H. Display(n);
				break;
		}	
	}while(ch!= 0);
	cout<<"\n ";
	return 0;
}


/*
Deletion pending
		OUTPUT:

_________________________________________________
 Enter choice:
 1. Delete marks 
 2. Arrange in ascending order
 3. Arrange in descending order
 4. Display list 
 0. Exit:	2

_________________________________________________
How many students are there in your class?5

 Enter their marks:
 Enter root:23
10

 Swapped parent10with child23
45
19

 Swapped parent19with child23
50
Minimum marks are10
_________________________________________________
 Enter choice:
 1. Delete marks 
 2. Arrange in ascending order
 3. Arrange in descending order
 4. Display list 
 0. Exit:	4

_________________________________________________
  Sorted marks are:
1:10	
2:19	
3:45	
4:23	
5:50	

_________________________________________________
 Enter choice:
 1. Delete marks 
 2. Arrange in ascending order
 3. Arrange in descending order
 4. Display list 
 0. Exit:	3

_________________________________________________
How many students are there in your class?5

 Enter their marks:
 Enter root:23
10
45

 Swapped parent45with child23
19

 Swapped parent19with child10
50

 Swapped parent50with child19

 Swapped parent50with child45
Maximum marks are50
_________________________________________________
 Enter choice:
 1. Delete marks 
 2. Arrange in ascending order
 3. Arrange in descending order
 4. Display list 
 0. Exit:	4

_________________________________________________
  Sorted marks are:
1:50	
2:45	
3:23	
4:10	
5:19	

_________________________________________________
 Enter choice:
 1. Delete marks 
 2. Arrange in ascending order
 3. Arrange in descending order
 4. Display list 
 0. Exit:	0

_________________________________________________

*/
