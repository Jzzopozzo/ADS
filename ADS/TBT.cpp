#include<iostream>
using namespace std;

class Node
{
	public:
		int Data;
		Node *RC;
		Node *LC;
		bool RT;
		bool LT;
};

class TBT
{
	public:	
	Node *Head, *Root;
	int flag;
	TBT()
	{
		Head= new Node;
		Head-> Data=0;
		Head-> RC= Head-> LC= Head;
		Head-> LT= 0;
		Head-> RT= 0;
		Root= NULL;
	}
	void Create();
	void Delete();
	void Pre(Node * Root);
	void Post(Node * Root);
	void In(Node * Root);
};

void TBT:: Create()
{
	int ch;
	Node *tmp, *curr;
	do
	{
		curr= new Node;
		cout<<"\n Enter node data:";
		cin>> curr-> Data;
		curr-> LT= curr-> RT= 1;
		if(Root== NULL)
		{
			Root= curr;
			Root-> LC= Root-> RC= Head;
			Head-> LC= Root;
			Head-> RC= 0;
		}
		else
		{
			tmp= Root;
			while(1)
			{
				if(curr-> Data< tmp-> Data)
				{
					if(tmp-> LT== 1)
					{
						curr-> LC= tmp-> LC;
						tmp-> LC= curr;
						tmp-> LT=0;
						curr-> RC= tmp;
						break;
					}
					else
					{
						tmp= tmp-> LC;
					}
				}
				else
				{
					if(tmp-> RT==1)
					{
						curr-> RC= tmp-> RC;
						tmp-> RC= curr;
						tmp-> RT=0;
						curr-> LC= tmp;
						break;
					}
					else
					{
						tmp= tmp-> RC;
					}
				}//inner if
			}//while
		}// outermost if
		cout<<"\n Continue?";
		cin>>ch;
	}while(ch!=0); //do
}

void TBT:: Pre(Node * Root)
{
	cout<<"\n *****PREORDER*****\t";
	Node *tmp= Root;
	bool Flag=0;
	cout<< tmp-> Data<<"\t";
	while(tmp!= Head)
	{
		if(flag==0)
		{
			cout<< tmp-> Data<<"\t";
		}
		if(tmp-> LT==0 && Flag==0)
		{
			tmp= tmp->LC;
		}
		else
		{
			if(tmp-> RT== 0)
			{
				tmp= tmp-> RC;
				flag= 0;
			}
			else
			{
				tmp= tmp-> RC;
				flag=1;				
			}
		}
	}
}

void TBT:: Post(Node * Root)
{
	cout<<"\n *****POSTORDER*****\t";
	Node *tmp= Root;
	bool Flag=0;
	while(tmp!= Head)
	{
		if(flag==0)
		{
			cout<< tmp-> Data<<"\t";
		}
		if(tmp-> LT==0 && Flag==0)
		{
			tmp= tmp->LC;
		}
		else
		{
			if(tmp-> RT== 0)
			{
				tmp= tmp-> RC;
				flag= 0;
			}
			else
			{
				tmp= tmp-> RC;
				flag=1;				
			}
		}
	}
	cout<< Root-> Data<<"\t";
}

void TBT:: In(Node * Root)
{
	cout<<"\n *****INORDER*****\t";
	Node *tmp= Root;
	bool Flag=0;
	while(tmp!= Head)
	{

		if(tmp-> LT==0 && Flag==0)
		{
			tmp= tmp->LC;
		}
		else
		{
			if(flag==0)
			{
				cout<< tmp-> Data<<"\t";

			}
			if(tmp-> RT== 0)
			{
				tmp= tmp-> RC;
				flag= 0;
			}
			else
			{
				tmp= tmp-> RC;
				flag=1;				
			}
		}
	}
}

int main()
{
	TBT T;
	cout<<"\n Let's insert node:\n";
	T. Create();
	cout<<"\n Now let's traverse those nodes:";
	T. Pre(T. Root);
	T. Post(T. Root);
	T. In(T. Root);
}

