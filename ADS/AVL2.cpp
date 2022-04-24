#include<iostream>
#include<string.h>
#include<stdlib.h>
#define pow2(n) (1<<(n))

using namespace std;

struct Node
{
	char Word[50];
	char Mean[50];
	int Ht;
	struct Node *L;
	struct Node *R;
	
};

class Tree
{
	public:
		Node *Root;
		int Height(Node *);
		int BF(Node *);
		Node *RotateRight(Node *);
		Node *RotateLeft(Node *);
		Node *RR(Node *);
		Node *LL(Node *);
		Node *RL(Node *);
		Node *LR(Node *);
		
		Node *Balance(Node *);
		Node *Insert(Node*, char Key[], char Mean[]);
		void Display(Node*, int);
		void InOrder(Node*);
		void PreOrder(Node *);
		void PostOrder(Node *);
	
	Tree()
	{
		Root= NULL;
	}
};

int main()
{
	int ch;
	Tree T;
	Node *a;
	char w[50];
	char m[50];
	while(1)
	{
		cout<<endl<<"-------------------------";
		cout<<endl<<"AVL TREE IMPLEMENTATION:";
		cout<<endl<<"-------------------------";
		cout<<endl<<"1. Insert element";
		cout<<endl<<"2. Display tree";
		cout<<endl<<"3. Delete element";
		cout<<endl<<"4. InOrder traversal of elements";
		cout<<endl<<"5. Exit";
		cout<<endl<<"Enter your choice:\t";
		cin>> ch;
		switch(ch)
		{	
			case 1:
				cout<<endl<<"Enter a word:\t";
				cin. getline(w, 50);
				//cin. clear();
				//cin. sync();
std::cin.ignore(1000,'\n');
//				cin. ignore(256, '\n');
				cout<<endl<<"Enter its meaning:\t";
				cin. getline(m, 50);
//cin. ignore();
				T. Insert(a, w, m);
				break;
			
			case 2:
				if(a== NULL)
				{
					cout<<endl<< "Tree is empty.";
					continue;
				}
				cout<<endl<<"Balanced AVL tree:"<<endl;
				T. Display(a, 1);		
				break;
		/*	
			case 3:
				break;
		*/		
			case 4:
				T. InOrder(a);
				break;
			
			case 5:
				exit(1);
				break;
		}
	}
	return 0;
}

int Tree:: Height(Node *tmp)
{
	int H= 0;
	if(tmp!= NULL)
	{
		int LH= Height(tmp-> L);	//Height of left subtree
		int RH= Height(tmp-> R);	//Height of right subtree
		int MH= max(LH, RH);		
		H= MH+ 1;					//Height
	}
}

int Tree:: BF(Node *tmp)
{
	int LH, RH;
	if(tmp== NULL) 
		return 0;
	else
	{
		if(tmp->L== NULL)
			LH=0;
		
		else
			LH= 1+ tmp-> L-> Ht;
			
		if(tmp-> R== NULL)
			RH=0;
		
		else
			RH= 1+ tmp-> R-> Ht;
	}
	return (LH- RH);
}

Node *Tree:: RotateRight(Node *x)
{
	Node *y;
	y= x-> L;
	x-> L= y-> R;
	y-> R= x;
	x-> Ht= Height(x);
	y-> Ht= Height(y);
	return y;
}

Node *Tree:: RotateLeft(Node *x)
{
	Node *y;
	y= x-> R;
	x-> R= y-> L;
	y-> L= x;
	x-> Ht= Height(x);
	y-> Ht= Height(y);
	return y;
}

Node *Tree:: RR(Node *Root)
{
	Root= RotateRight(Root);
	return Root;
}

Node *Tree:: LL(Node *Root)
{
	Root= RotateLeft(Root);
	return Root;
}

Node *Tree:: RL(Node *Root)
{
	Root-> R= RotateRight(Root-> R);
	Root= RotateLeft(Root);
	return Root;
}

Node *Tree:: LR(Node *Root)
{
	Root-> R= RotateLeft(Root-> R);
	Root= RotateRight(Root);
	return Root;
}

Node *Tree:: Balance(Node *tmp)
{
	int Bf= BF(tmp);
	if(Bf> 1)
	{
		if(BF(tmp-> L)> 0)
			tmp= LL(tmp);
			
		else
			tmp= LR(tmp);
	}
	else if(Bf< -1)
	{
		if(BF(tmp-> R)>0)
			tmp= RL(tmp);
		
		else
			tmp= RR(tmp);
	}
	return tmp;
}

Node *Tree:: Insert(Node*, char Key[], char Mean[])
{
	if(Root== NULL)
	{
		Root= new Node;
		strcpy(Root-> Word, Key);
		strcpy(Root-> Mean, Mean);
		Root-> L= Root-> R= NULL;
		return Root;
	}
	else if(strcmp(Root-> Word, Key)<0)
	{
		Root-> L= Insert(Root-> L, Key, Mean);
		Root= Balance(Root);
	}
	else if(strcmp(Root-> Word, Key)>0)
	{
		Root-> R= Insert(Root->R, Key, Mean);
		Root= Balance(Root);
	}
	return Root;
}

void Tree:: Display(Node *ptr, int level)
{
	int i;
	ptr= Root;
	cout<<"\n Inside Display";
	if(ptr!= NULL)
	{
cout<<"\n INSIDE IF";
		Display(ptr-> R, level+1);
		cout<<"\n";
		if(ptr== Root)
		{
			cout<<"Root->";
			cout<<"\n ROOT DISPLAYED";
		}
		for(i= 0; i<level && ptr!= Root; i++)
			cout<<"		";
			
			cout<<ptr-> Word;
			Display(ptr-> L, level+ 1);
	}
}

void Tree:: InOrder(Node *tree)
{
	if (tree == NULL)
        return;
	InOrder (tree-> L);
	cout<< tree-> Word<<"  ";
	InOrder (tree-> R);
}

void Tree:: PreOrder(Node *)
{
	
}

void Tree:: PostOrder(Node *)
{
	
}

