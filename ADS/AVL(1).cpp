#include<iostream>
#include<string.h>
using namespace std;

class Node
{
	public:
	int Ht;
	Node *L, *R;
	char Word[20];
	char Meaning[20];
};

class Dictionary
{
	public:
		Node *Root;
		Dictionary()
		{
			Root= NULL;
		}
		Node *RotateRight(Node *x);
		Node *RotateLeft(Node *x);
		Node *LL(Node *T);
		Node *RR(Node *T);
		Node *RL(Node *T);
		Node *LR(Node *T);
		int Height(Node *);
		int BF(Node *T);
		Node *Insert(Node *Root, char newkey[20], char Mean[20]);
		void InOrder(Node *Root);
		Node *Search(Node *Root, int Key);
};

Node *Dictionary:: RotateRight(Node *x)
{
	Node *y;
	y= x-> L;
	x-> L= y-> R;
	y-> R= x;
	x-> Ht= Height(x);
	y-> Ht= Height(y);
	return y;
}

Node *Dictionary:: RotateLeft(Node *x)
{
	Node *y;
	y= x-> R;
	x-> R= y-> L;
	y-> L= x;
	x-> Ht= Height(x);
	y-> Ht= Height(y);
	return y;

}

Node *Dictionary:: LL(Node *Root)
{
	cout<<"\n ***In LL rotation***";
	Root= RotateRight(Root);
	return Root;
}

Node *Dictionary:: RR(Node *Root)
{
	cout<<"\n ***In RR rotaion***";
	Root= RotateLeft(Root);
	return Root;
}

Node *Dictionary:: RL(Node *Root)
{
	cout<<"\n ***In RL rotation***";
	Root-> R= RotateRight(Root-> R);
	Root= RotateLeft(Root);
	return Root;
}

Node *Dictionary:: LR(Node *Root)
{
	cout<<"\n ***In LR rotation***";
	Root-> L= RotateLeft(Root-> L);
	Root= RotateRight(Root);
	return Root;
}

int Dictionary:: Height(Node *)
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
	HL= Height(Root-> L);
	HR= Height(Root-> R);
	
	if(HR> HL)
		return (HR+ 1);
		
		return (HL+ 1);
}

int Dictionary:: BF(Node *T)
{
	int lh, rh;
	if(T== NULL)
	{
		cout<<"\n No node in tree!";
		return 0;
	}
	else
	{
		if(T-> L== NULL)
		{
			lh= 0;
		}
		else
		{
			lh= 1+ T-> L-> Ht;
		}
		if(T-> R== NULL)
		{
			rh= 0;
		}
		else
		{
			rh= 1+ T-> R-> Ht;
		}
	}
	return (lh- rh);
}
/*
Node *Dictionary:: Insert(Node *Root, char newkey[20], char Mean[20])
{
	Node *curr;
	int lh, rh;
cout<<"\n inside insert\n";
	if(Root== NULL)
	{cout<<"inside if";
		curr= new Node;
		strcpy(curr-> Word, newkey);
		cout<<"\n 1";
		strcpy(curr-> Meaning, Mean);
		cout<<"\n2";
		curr-> Ht=0;
		cout<<"\n3";
		curr-> L= NULL;
		cout<<"\n4";
		curr-> R= NULL;
		cout<<"\n5";
		Root= curr;
		cout<<"\n Root assigned";
		cout<< Root->Word;
	}
	else
	{
		cout<<"\n"<< Root-> Word;
		if(strcmp(newkey, Root-> Word)< 0)
		{
			Root-> L= Insert(Root-> L, newkey, Mean);
			cout<<"\n Balance Factor:"<< Root-> Word<<": "<<BF(Root);
			if(BF(Root)==2)
			{
				if(strcmp(newkey, Root-> L-> Word)< 0)
				{
					Root= LL(Root);
					cout<<"\n LL rotation";
				}
				else
				{
					Root= LR(Root);
					cout<<"\n LR rotation";
				}
			}
		}
		else
		{
			if(strcmp(newkey, Root-> Word)> 0)
			{
				Root->R= Insert(Root-> R, newkey, Mean);
				cout<< "\n Balance factor:"<< Root-> Word<< ": "<< BF(Root);
				if(BF(Root)==-2)				
				{
					if(strcmp(newkey, Root-> R-> Word)> 0)
					Root= RR(Root);
				}
				else
				{
					Root= RL(Root);
				}
			}
		}
	}
}
*/

Node *Dictionary:: Insert(Node *Root, char newkey[20], char Mean[20])
{
	Node *NewNode;
	int lh, rh;
	Root-> Ht= Height(Root);
	if(Root== NULL)
	{
		NewNode= new Node;
		cout<<"\n New node created!";
		strcpy(NewNode-> Word, newkey);
		cout<<"\n Word accepted!";
		strcpy(NewNode-> Meaning, Mean);
		cout<<"\n Meaning accepted!";
		NewNode-> L= NULL;
		cout<<"\n L= NULL!";
		NewNode-> R= NULL;
		cout<<"\n R= NULL!";
		Root= NewNode;
	}
	else
	{
		if(strcmp(newkey, Root-> Word)< 0)
		{
			Root-> L= Insert(Root-> L, newkey, Mean);
			if(BF(Root)==2)
			{
				if(newkey< Root-> L-> Word)	
				{
					cout<<"\n *LL ROTATION*";
					Root= LL(Root);
				}
				else
				{
					cout<<"\n *LR ROTATION*";
					Root= LR(Root);
				}
			}
		}
		else if(strcmp(newkey, Root-> Word)> 0)
		{
			Root-> R= Insert(Root-> R, newkey, Mean);
			if(BF(Root)== -2)
			{
				if(newkey> Root-> R-> Word)
				{
					cout<< "\n *RR ROTATION*";
					Root= RR(Root);
				}			
				else
				{
					cout<<"\n *RL ROTATION*";
					Root= RL(Root);
				}
			}
		}
		else
			cout<<"\n DUPLICATE KEY!";
	}
	Root-> Ht= Height(Root);
	return Root;
}

void Dictionary:: InOrder( Node *Root)
{
	if(Root!= NULL)
	{
		InOrder(Root-> L);
		cout<< Root-> Word<<"\t";
		cout<< Root-> Meaning<<"\t";
		InOrder(Root-> R);
	}
}

int main()
{
	char key[20], mean[20];
	Dictionary D;
	Node *a;
	cout<<"\n Enter a word:\t";
	cin. getline(key, 20);
	cout<<"\n Enter what it means:\t";
	cin. getline(mean, 20);
	cout<<"\n Let's insert the word";
	D. Insert(a, key, mean);
	cout<<"\n Now see :";
	D. InOrder(a);
}
