#include<iostream>
#include<cstring>
using namespace std;

class Student
{
	public:
		int RNo;
		char Name[50];
		char Address[50];
		float Marks;
		void GetData()
		{
			int i, n;
			cout<<endl<<"Enter number of students:\t";
			cin>>n;
			for(i=1; i<=n; i++)
			{
				cout<<endl<<"Enter Roll No:\t";
				cin>>RNo;
				cout<<endl<<"Enter Name:\t";
				cin>>Name;
				cout<<endl<<"Enter Address:\t";
				cin>>Address;
				cout<<endl<<"Enter Marks:\t";
				cin>>Marks;
			}
			cout<<"\n Details accepted!";
		}
		void PutData()
		{
			int i, n;
			cout<<endl<<"*DETAILS:*";
			for(i=1; i<=n; i++)
			{
				cout<<endl<<"Roll No:\t";
				cout<<RNo;
				cout<<endl<<"Name:\t";
				cout<<Name;
				cout<<endl<<"Address:\t";
				cout<<Address;
				cout<<endl<<"Marks:\t";
				cout<<Marks;
			}
			cout<<"\n Details displayed!";
		}
};

class File : public Student
{
	public:
		Student S;
		fstream f;
		char Filename[50];
		void ReadFileName();
		void Insert();
		void Update();
		void Search();
		void Display();
		File()
		{
			Student S;
			int RNo= 3;
			strcpy(Name, "Jzzo");
			strcpy(Address, "Nashik");
			Marks= 78.67;
		}
};

void File:: ReadFileName()
{
	cout<<endl<<"Enter file to be opened:\t";
	cin>>Filename;
}

void File:: Insert()
{
	f.open(Filename, ios::out | ios::app);
	Student S;
	S. GetData();
	f.write((char *)&S, sizeof(S));
	f.close();
	cout<<"\n INSERT PERFORMED SUCCESSFULLY!";	
}

void File:: Display() 
{
	f. open(Filename, ios::in);
	Student S1;
	int cnt= 0;
	while(!f.eof())
	{
		f. read((char *)&S1, sizeof(S1));
		cnt ++;
	}
	cout<<"\n Read from file";
	cnt--;
	f. close();
	f. open(Filename, ios::in);
	while(cnt!=0)
	{
		f. read((char*)&S1, sizeof(S1));
		S1. PutData();
		cnt--;
	}			
	f. close();
}

int main()
{
	File fp;
	fp. ReadFileName();
	fp. Insert();
	cout<<"\n Let's now display containts of file........";
	fp. Display();
}

