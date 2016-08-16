#include <iostream>
using namespace std;


//Adrián Biller A01018940
//HW1

int fib(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}


int hanoi(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return (2*hanoi(n-1)+1);
    }
    
}
int main()
{
    
    int f;
    cout<<"Insert position of the Fibbonacci sequence desired:";
    cin>>f;
    cout<<"The position is: "<<fib(f)<<endl;
    
    int h;
    cout<<"How many disks are on play?";
    cin>>h;
    cout<<hanoi(h);
    
}
