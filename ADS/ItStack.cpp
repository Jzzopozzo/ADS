#include<iostream>
using namespace std;

class Node
{
	public:
	int Data;
	Node * L, *R;
};

class Tree
{
	public:
	Node * Root;
	Tree()
	{
		Root= NULL;
	}
	/*int IsEmpty()
	{
		return(Root=NULL);
	}*/
	Node *CreateNode(Node *);
	void InsertNode(Node *);
	void DeleteNode();
	void PreOrder(Node *);
	void InOrder(Node *);
	void PostOrder(Node *);
	void Pre();
	void In();
	void Post();
};

class Stack
{
	Node *A[20];
	int Top;
	public:
	Stack()
	{
		Top= -1;
	}

	void Push(Node *tmp)
	{
		A[++Top]= tmp;
	}

	Node *Pop()
	{
		Node *tmp;
		tmp= A[Top--];
		return tmp;
	}

	int IsEmpty()
	{
		if(Top==-1)	
			return 1;
		else 
			return 0;
	}
};


class Stack1
{
	char A[20];
	int Top;
	public:
	Stack1()
	{
		Top= -1;
	}

	void push(char ch)
	{
		A[++Top]= ch;
	}

	int pop()
	{
		char ch;
		ch= A[Top--];
		return ch;
	}

	int Isempty()
	{
		if(Top==-1)	
			return 1;
		else 
			return 0;
	}
};

void Tree:: Pre()
{
	Node *tmp= Root;
	Stack st;
	while(1)
	{
		while(tmp!= NULL)
		{
			cout<<"	"<<tmp-> Data;
			st. Push(tmp);
			tmp= tmp-> L;
		}
		if(!st. IsEmpty())
		{
			tmp= st. Pop();
			tmp= tmp-> R;
		}
		else
			break;
	}
}

void Tree:: In()
{
	Node * tmp= Root;
	Stack st;
	while(1)
	{
		while(tmp!= NULL)
		{
			st. Push(tmp);
			tmp= tmp-> L;
		}
		if(!st. IsEmpty())
		{
			tmp= st. Pop();
			cout<<"\t"<< tmp-> Data;
			tmp= tmp-> R;
		}
		else 
			break;
	}
}

void Tree:: Post()
{
	Node *tmp= Root;
	Stack s;
	Stack1 s1;
	char flag;
	while(1)	
	{
		while(tmp!= NULL)
		{
			s. Push(tmp);
			s1. push('L');
			tmp= tmp-> L;
		}
		if(s. IsEmpty())
		{
			return;
		}
		else
		{
			tmp= s.Pop();
			flag= s1. pop();
			if(flag=='R')
			{
				cout<<tmp->Data<<"\t";
				tmp== NULL;
			}
			else
			{
				s. Push(tmp);
				s1. push('R');
				tmp= tmp-> R;
			}
		}
	}
}

void Tree:: InsertNode(Node *)
{
	Node *tmp, *p, *Parent;
	int Val;
		p= new Node;
		cout<<"\nWhat does your Node have?";
		cin>>Val;
		p-> Data=Val;
		p->L= NULL;
		p->R= NULL;
		Parent= NULL;
		if(Root== NULL)
			Root=p;
		else 
		{
			tmp=Root;
			while(tmp!=NULL)
			{
				Parent= tmp;
				if(Val< tmp-> Data)
				{
					tmp= tmp->L;
					cout<< "\n 	Node has been inserted to left!";
				}
				else 
				{
					tmp= tmp->R;
					cout<< "\n 	Node has been inserted on right!";
				}
			}
			if(Val< Parent->Data)
				Parent-> L= p;
			else
				Parent->R=p;
			
		}
		cout<<"\nOK! I accept this!\n";
}

int main()
{
	Tree T1;
	Node *tmp, *tmq;
	int i;
	//CreateNode( tmp);
	for(i=1; i<=4; i++)
	{
		T1. InsertNode(tmp);
		//T1. InsertNode(tmq);
		cout<<"\n--------\n";
	}
	cout<< "\nLet's try traversal now:\n";

	cout<< "\nPreOrder:\t";
		//T1. Pre();
	cout<< "\nPostorder:\t";
		T1. Post();
	cout<< "\nInorder: \t";
		//T1. In();
	

}
