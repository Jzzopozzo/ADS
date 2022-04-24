#include<iostream>
using namespace std;

class Node 
{
	Node *L, *R;
	char Data;
	public:
};

class ETree
{
	public:
		Node *Root;
		ETree()
		{
			Root= NULL;		
		}
		void Insert(Node *);
	
		bool Test(char ch)		//To check whether given charcter is a operand or operator
		{
			if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
			{
				cout<<"\n It is an operand!";
				return 0;	
			}
			else
			{
				cout<<"\n It is an operator!";
				return 1;
			}
		}
};

class Stack
{
	Node *a[20];
	int Top;

	public:
		Stack()
		{
			Top= -1;
		}
		
		void Push(Node *tmp)
		{
			a[++Top]= tmp;
		}
		
		Node* Pop()
		{
			Node *tmp;
			tmp= a[Top--];
			return tmp;
		}

		int IsEmpty()
		{
			if(Top== -1)
				return 1;
			
			else 
				return 0;
		}
};


void ETree:: Insert(Node *)
{
	Node *tmp;
	char ch;
	cout<<"\n Enter data:";
	cin>> ch;
	Test (ch);
}

int main()
{
	ETree E;
	E. Insert(E. Root);
}

