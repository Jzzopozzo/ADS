#include<iostream>
using namespace std;

class Binary
{
	
	int A[10];
	
	public:
	void Sort(int n);
	void Search(int A[], int key, int High, int Low);
};

void Binary:: Sort(int n)
{
	int i, j, Min, tmp;
	for(i=0; i<n; i++)	
	{
		for(j=0; j<n; j++)
		{
			if(A[j]> A[j+1])
			{
				tmp= A[j];
				A[j]= A[j+1];	
				A[j+1]= tmp;
			}
		}
			cout<<endl<<A[i]<<"\t";
	}

}

void Search(int A[], int key, int High, int Low)
{
	int i, n, mid;
	Low=0;
	High=n-1;
	mid=(High+ Low)/2;
	for(i=0; i<n; i++)
	{
		if(key==mid)
			cout<<"\n Key has found on position"<<i+1;

		else if(key<mid)
			Search(A, key, mid-1, Low);

		else if(key>mid)
			Search(A, key, High, mid+1);
	}
}

int main()
{
	Binary Array;
	int N, j, B[10];
	cout<<endl<<"Enter number of elements:";
	cin>>N;
	cout<<endl<<"Enter elements:";
	for(j=0;j<N;j++)
	{
		cin>>B[j];
	}
	cout<<endl<<"Sorting...";
	Array.Sort(N);
}
