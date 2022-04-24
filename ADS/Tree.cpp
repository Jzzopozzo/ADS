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
	void Display(Node *ptr, int Level);
};

Node *CreateNode(Node *)
{
	Node *p;
	p=new Node;
	cout<< "\nEnter data to be inserted:";
	cin>> p-> Data;
	p-> R= NULL;
	p-> L= NULL;
	cout<<"Created: Node!!!\n";
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

void Tree:: PreOrder(Node *Root)
{
	if(Root!=NULL)
	{
		cout<<Root->Data<<"\t";
		PreOrder( Root-> L);
		PreOrder( Root-> R);
	}
}

void Tree::PostOrder(Node *Root)
{
	if(Root!= NULL)
	{
		PostOrder(Root-> L);
		PostOrder(Root-> R);
		cout<< Root-> Data<< "\t";
	}
}

void Tree:: InOrder( Node *Root)
{
	if(Root!= NULL)
	{
		InOrder(Root-> L);
		cout<< Root-> Data<<"\t";
		InOrder(Root-> R);
	}
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
		T1. PreOrder(T1. Root);
	cout<< "\nPostorder:\t";
		T1. PostOrder(T1. Root);
	cout<< "\nInorder: \t";
		T1. InOrder(T1. Root);
	
}
