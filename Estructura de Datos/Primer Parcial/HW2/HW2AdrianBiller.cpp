//Adrián Biller A01018940

//Tarea 2

//Merge Sort

#include <iostream>
#include <time.h>
using namespace std;

void merge(int a[], int size, int l, int m, int r)
{
    int b[size];
    for(int i = l; i<=r; i++)
    {
        b[i] = a[i];
    }
    int i = l;
    int j = m+1;
    int k = l;
    
    while(i<=m && j<=r)
    {
        if(b[i]<=b[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = b[j];
            ++j;
        }
        ++k;
    }
    while(i<=m)
    {
        a[k] = b[i];
        k++;
        i++;
    }
    
}

void sort(int a[], int size, int l, int r)
{
    if(l<r)
    {
        int m =(l+r)/2;
        sort(a,size, l, m);
        sort(a,size, m+1, r);
        merge(a, size, l, m, r);
    }
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
    
    sort(a,length,0, length);
    
    cout<<"Your array in order is: "<<endl;
    
    for(int i = 0; i<=length; i++ )
    {
        cout<<"[  "<<a[i]<<"  ]"<<endl;
    }
    
    return 1;
}