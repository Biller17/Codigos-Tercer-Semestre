//Adrián Biller A01018940

//HW3

//Quicksort implementation


#include <iostream>
#include <time.h>
using namespace std;


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

int main ()
{
    
    int length = 10 ;
    int a [length];
    
    srand(time(0));
    for(int i = 0; i<=10; i++)
    {
        a[i]=rand()%50;
    }
    
    quicksort(a, 0, length);
    
    cout<<"Your array in order  by quicksort is: "<<endl;
    
    for(int i = 0; i<=length; i++ )
    {
        cout<<"[  "<<a[i]<<"  ]"<<endl;
    }

}
