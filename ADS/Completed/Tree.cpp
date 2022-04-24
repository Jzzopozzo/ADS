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
	int TreeHeight(Node *Root);
	int NoNode(Node * Root);
	int Leaf(Node *Root);
	void Mirror(Node * Root);
	void ITPre();
};

class Stack
{
	public:
		Node *stk[50];
		int Data, Top;
		Stack *s;
		
		Stack()
		{
			Top= -1;
		}
		bool IsEmpty()
		{
			if(Top==-1)
				return 1;
			
			else 
				return 0;
		}
		
		void Push(Node *x)
		{
			stk[Top++]=x;
		}
		
		Node *Pop()
		{
			Node *x;
			x= stk[Top--];
			return (x);
		}
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

int Tree::TreeHeight(Node *Root)
{
	int HL, HR;
	if(Root== NULL)
	{
		return 0;
	}
	if(Root-> L== NULL && Root->R== NULL)
	{
		return 0;
	}
	HL= TreeHeight(Root-> L);
	HR= TreeHeight(Root-> R);
	
	if(HR> HL)
		return (HR+ 1);
		
		return (HL+ 1);
}

int Tree:: NoNode(Node * Root)
{
	if(Root== NULL)	
		return 0;
		
	else
		return (1+ NoNode(Root-> R)+ NoNode(Root-> L));
}

int Tree:: Leaf(Node *Root) 
{
	if(Root== NULL)
		return 0;
	else if(Root->R== NULL && Root->L== NULL)
		return (1);
	else 
		return(Leaf(Root->L)+ Leaf(Root->R)) ;
}

void Tree:: Mirror(Node * Root)
{
	Node *tmp;
	if(Root!= NULL)
	{
		tmp= Root-> L;
		Root-> L= Root-> R;
		Root-> R= tmp;
		Mirror(Root-> L);
		Mirror(Root-> R);
	}
}

void Tree:: ITPre()  
{
	Node *tmp= Root;
	Stack S;
	while(1)	
	{
		while(tmp!=NULL)
		{
			S.Push(tmp);
			cout<<tmp->Data<<"\t";
			tmp= tmp->L;
		}
		if(S.IsEmpty())
			return;
		tmp= S.Pop();
		tmp= tmp->R;
	}
}

int main()
{
	Tree T1;
	Node *tmp, *tmq;
	int i, h, n, l, ch;
	do
	{	cout<<endl<< "------------------------------------------";
		cout<< endl<< "Operations on a binary search tree:"<< endl;
		cout<<endl<< "------------------------------------------";
		cout<< endl<< "Select choice to:(Press 0 to exit)";
		cout<< endl<<"1) Insert a node into tree";
		cout<< endl<<"2) Inorder traversal";
		cout<< endl<<"3) Preorder traversal";
		cout<< endl<<"4) Postorder traversal";
		cout<< endl<<"5) Calculate Height of tree";
		cout<< endl<<"6) Calculate number of nodes of tree";
		cout<< endl<<"7) Calculate number of leaf nodes of tree";
		cout<< endl<<"8) Mirror given tree:\t";
		cout<< endl<<"9) Iterative Preorder:\t";
		cin>> ch;
		cout<<endl<< "------------------------------------------";
		
		switch(ch)
		{
			case 1:
				cout<<endl<< "---------------------------";
				T1. InsertNode(tmp);
				cout<<endl<< "---------------------------";
				break;
				
			case 2:
				cout<<endl<< "---------------------------";
				cout<< "\nInorder traversal: \t";
				T1. InOrder(T1. Root);
				cout<<endl<< "---------------------------";
				break;
				
			case 3:
				cout<<endl<< "---------------------------";
				cout<< "\nPreOrder traversal:\t";
				T1. PreOrder(T1. Root);
				cout<<endl<< "---------------------------";
				break;
				
			case 4:
				cout<<endl<< "---------------------------";
				cout<< "\nPostorder traversal:\t";
				T1. PostOrder(T1. Root);
				cout<<endl<< "---------------------------";
				break;
			
			case 5:
				cout<<endl<< "---------------------------";
				cout<<endl<< "Height of tree:\t";
				h= T1. TreeHeight(T1. Root);
				cout<< h;
				cout<<endl<< "---------------------------";
				break;
				
			case 6:
				cout<<endl<< "---------------------------";
				cout<<endl<< "No. of nodes are:\t";
				n= T1.NoNode(T1. Root);
				cout<< n;
				cout<<endl<< "---------------------------";
				break;
			
			case 7:
				cout<<endl<< "---------------------------";
				cout<<endl<< "No. of Leaf nodes are:\t";
				l= T1.NoNode(T1. Root);
				cout<< l;
				cout<<endl<< "---------------------------";
				break;
			
			case 8:
			cout<<endl<< "---------------------------";
			cout<<endl<< "\n****Let's reflect tree now****\n";
			T1. Mirror(T1.Root);
			cout<< "\nLet's try traversal now:\n";

			cout<< "\nPreOrder:\t";
			T1. PreOrder(T1. Root);
			cout<< "\nPostorder:\t";
			T1. PostOrder(T1. Root);
			cout<< "\nInorder: \t";
			T1. InOrder(T1. Root);
			cout<<endl<< "---------------------------";
			break;
		
		case 9:
			T1.ITPre();
		}
	}while(ch!=0);
}
