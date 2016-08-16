#include <iostream>
using namespace std;





int hanoi(int n)
{
	if(n==1)
	{
		return 1;
	}
	else()
	{
		return (2*hanoi(n-1));
	}
}


int main ()
{
	int disk;
	cout<<"Insert number of disk in Hanoi Tower game: ";
	cin>>disk;
	cout<<"The number of moves needed are: "<<hanoi(disk)<<endl;
	return 0;
}