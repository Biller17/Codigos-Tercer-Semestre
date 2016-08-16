#include <iostream>
using namespace std;


int factorial()
{
    int num;
    int num2 = 1;
    
    cout<<"Insert number:"<<endl;
    cin>>num;
    while(num > 0)
    {
        num2*=num;
        num--;
    }
    
    cout<<"The factorial of "<<num<<" is:"<<num2<<endl;
    return num2;
}

int recursiveFactorial(int n)
{
    if(n==0)
    {
        cout<<n;
        return 1;
    }
    return n*recursiveFactorial(n-1);
}





int main()
{
    int number;
    factorial();
    cout<<"insert number:"<<endl;
    cin>>number;
    recursiveFactorial(number);
    return 0;
}
