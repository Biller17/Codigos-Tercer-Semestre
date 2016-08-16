#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;




int* fillRandomSortedArray (int a[], int size)
{
    int i;
    int total = 0;
    int num;
    
    for(i = 0; i < size; i++)
    {
        num = rand()%10;
        total += num;
        a[i] = total;
    }
    return a;
}

int quicksort(int a[], int l, int r )
{
    int i = l;
    int j = r;
    int b;
    int m = a[(l+r)/2];
    
    while(i <= j)
    {
        while(a[i]< m)
            i++;
        while (a[j]> m)
            j--;
        if(i <= j)
        {
            b = a[i];
            a[i] = a[j];
            a[j] = b;
            i++;
            j--;
        }
    }
    if(l < j)
        quicksort(a, l, j);
    if(r > i)
        quicksort(a, i, r);
    
    return 1;
}



int search(int a[], int l, int r, int s)
{
    int i = l;
    int j = r;
    int m = (l+r)/2;
    
    while(1)
    {
        if(a[m]>s)
        {
            search(a, i, m, s);
        }
        else
        {
            search(a, m, j, s);
        }
        return a[i];
    }
}


void print(int a[], int size)
{
    for(int i = 0; i<size; i++)
    {
        cout<<"[ "<<a[i]<<" ]"<<endl;
    }
}

int main ()
{
    
    srand(time(0));
    int op;
    int op2;
    cout<<"What is the size of the desired array?";
    cin>>op;
    int a[op];
    fillRandomSortedArray(a, op-1);
    print(a, op-1);
    
    cout<<"What number do you wish to search"<<endl;
    cin>>op2;
    if(search(a, 0, op-1, op2))
        cout<<op2<<" is located in the array";
    else
        cout<<op<<" Is not located in the array";
    return 1;
}







