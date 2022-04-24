#include<iostream>
using namespace std;

struct MyPair
	{
	    	std::string s;
		int i;
	};
int main()
{
	MyPair letter;
MyPair number;
	MyPair pairAr[2];
	MyPair myPair;
	myPair.letter = 'a';
	myPair.number = 1;
	pairAr[0] = myPair;
	cout<<pairAr;
}
