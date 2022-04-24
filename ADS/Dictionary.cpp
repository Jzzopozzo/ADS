#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Node
{
	public:
	Node *L, *R;
	char Word[50];
	char Meaning[50];
};
class Dictionary
{
	Node *Root;	
	public:
	
	Dictionary()
	{
		Root= NULL;
		//strcpy(" ", Word);
		//strcpy(" ", Meaning);
	}
	int Insert(Node *);
	int Display(Node *);
	Node *GetRoot(Node *);
	
};

int Dictionary:: Insert(Node *)
{
	Node *tmp, *p;
	char w[50], m[50];
	int i;
	
	cout<<endl<< "Enter the word:\t";
	cin>>w;
	cin. ignore();
	cout<<endl<< "What does it mean?\t";
	cin.getline(m, 50);
	cout<< endl<<"You entered that "<<w<< " means "<< m;
	/*for(i=0; m[i]!='\0'; i++)
	{
		if(m[i]>='A' || m[i]<='Z')
		{
			m[i]= m[i]- 32;
			cout<<m[i];
		}
		else
		{
			//m[i]= m[i];
	//		cout<<m[i];
		}
	}*/
	p= new Node;
	strcpy(p-> Word, w);
	strcpy(p-> Meaning, m);
	p-> L= p-> R= NULL;
	if(Root==NULL)
	{
		Root= p;
		cout<<endl<<p-> Word<< " is the root node.";
	}
	else
	{
		tmp= Root;
		while(tmp!= NULL)
		{
			if(strcmp(p-> Word, tmp-> Word)<0)	
			{
				cout<<endl<< "Root is greater!";
				if(tmp-> L== NULL)
				{
					tmp-> L= p;	
					cout<<endl<<p->Word<<" has been assigned to left of "<<Root-> Word;
					break;
				}

				tmp= tmp-> L;
			}
			else
			{
				cout<<endl<< "Root is smaller!";
				if(tmp-> R== NULL)
				{cout<<"in right";
					tmp-> R= p;
					cout<<endl<< p-> Word<< " has been assigned to right of "<<Root->Word;
					break;
				}
				tmp= tmp->R;
			}
		}
	}
	cout<<endl<<"Mission Insertion";
	return 1;
}

Node *Dictionary:: GetRoot(Node *)
{
	return Root;	
}

int Dictionary:: Display(Node *)
{
	Node *tmp;
	Node *tmq= GetRoot(tmp);

		cout<<"\n inside Display\n ";
	if(Root!= NULL)
	{
		cout<<"\n Inorder??";
		Display(GetRoot(tmp)->L);
		cout<<"\n Root displaying";
		cout<<Root->Word<<":"<<Root->Meaning;
		Display(Root->R);
	}
	return 1;
}
int main()
{
	Dictionary D;
	Node *tmq;
	int i;
	for(i=0; i<3; i++)
	{
		D. Insert(D. GetRoot(tmq));	
	}
	cout<<"\n Let's display it now:\n";
	D.Display(tmq);
}
/* check display fn and upper to lower case conversion
if inside while is not executing- SOLVED!

*/
