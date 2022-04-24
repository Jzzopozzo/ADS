#include<iostream>
using namespace std;
#define max 10
class AM
{
	public:
		int Time[max][max];
		int Fuel[max][max];
		int Data;
		AM()
		{
			Data=0;
		}
		void Insert(int n, string CName[20]);
		void Display(int n, string CName[20]);
		void Delete();
		void DisplayF(int n, string CName[20]);
		void DisplayT(int n, string CName[20]);
		void CTName();
		void Traverse();
};

void AM:: CTName()
{
	int i, j, n;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			
		}
	}
}

void AM:: Insert(int n, string CName[20])
{
	int i, j;
	//int Time[max][max];
	//int Fuel[max][max];
//	string CName[20][n];
	cout<<"\n Enter names:\n";
	for(i=1; i<=n; i++)
	{
		cout<<"\n City No:"<< i<<"\t";
		cin>>CName[i];
	}
	
	cout<<"\n Enter the values of time and fuel for respetive cities if there's a flight:";
	for(i=1; i<=n; i++)
	{
	//	cout<<"\n Enter city name:";	
	//	cin>> CName[20];
		 for(j=1; j<=n; j++)
		{
			T: cout<<"\n Enter time for flight["<<i <<"]["<< j<<"]:";
			cin>> Time[i][j];
		
			if(Time[i][j]==0)
			{
				Fuel[i][j]=0;
				j++;
				if(j>n)
				{
					i++, j=1;
					//break;
					if(i>n)
					{
						break;
					}
			
				}
				goto T;
				}
			else
			{
				cout<<"\n Enter fuel:";
				cin>> Fuel[i][j];
			}
				
		}
	}
}

void AM:: Display(int n, string CName[20])
{
	int i, j;
	//int Time[max][max];
	//int Fuel[max][max];
	cout<<"\n Status of flights are as follows:\n";
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			cout<<"Time["<< i <<"]["<< j<< "] : ";
			cout<< Time[i][j];

			cout<<"\t Fuel["<< i <<"]["<< j<< "] : ";
			cout<< Fuel[i][j];
			cout<< endl;
		}
	}

}

int main()
{
	AM A;
	int n, i;
	string Name[20];
	cout<<"\n Enter number of cities:\t";
	cin>> n;

	A. Insert(n, Name);
	A. Display(n, Name);
	A. DisplayF(n, Name);
}

void AM:: DisplayF(int n, string CName[20])
{
	int i, j;
	//int Time[max][max];
	//int Fuel[max][max];
	cout<<"\n Status of fuel required for flights are as follows:\n";
	for(i=1; i<=n; i++)
	{
//		cout<< CName<<"\t";
		for(j=1; j<=n; j++)
		{
			if(i==j)
			{
				j++;
			}
			else
			{
				cout<<"\n Flight from "<<CName[i]<<" to "<< CName[j]<<"takes ";
				cout<< Fuel[i][j]<<" liters of fuel\n";
			}
		}
		cout<<endl;
	}

}

void AM:: DisplayT(int n, string CName[20])
{
	int i, j;
	int Time[max][max];
	int Fuel[max][max];
	cout<<"\n Status of flights are as follows:\n";
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			cout<<"Time["<< i <<"]["<< j<< "] : ";
			cout<< Time[i][j];

			cout<<"\t Fuel["<< i <<"]["<< j<< "] : ";
			cout<< Fuel[i][j];
			cout<< endl;
		}
	}

}
