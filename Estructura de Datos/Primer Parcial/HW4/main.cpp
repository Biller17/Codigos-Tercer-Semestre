//Adrián Biller aA01018940

//HW4

//Search names

//Compiled in xcode


#include <iostream>
#include <string.h>
#include <cstring>
#include <fstream>
using namespace std;




int quicksort(string a[], int l, int r )
{
    int i = l;
    int j = r;
    string b;
    string m = a[(l+r)/2];
    
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
    int i = 0;
    int j = 24;
    int opcion = 1;
    int m  = (i+j)/2;
    string names [25];
    string line;
    ifstream file ("words.txt");
    
    if (file.is_open())
    {
        while(getline(file, line))
        {
            names[i] = line;
            i++;
        }
        file.close();
    }
    else
        cout<<"The file could not be read"<<endl;
    
    
    
    quicksort(names, 0, 25);
    
    

    while(opcion == 1)
    {
        cout<<"Enter the name you wish to search: ";
        getline(cin,line);
        while(line<names[m] && i<m)
        {
            if(names[i] == line)
            {
                cout<<"The name "<<line<<" is on the list in the position"<<i+1<<endl;
                return 1;
            }
            i++;
        }
        
        while(line>names[m] && m<j)
        {

            if(names[j] == line)
            {
                cout<<"The name "<<line<<" is on the list in the position "<<j+1<<endl;
                return 1;
            }
            j--;
        }
        if(i>j)
        {
            cout<<"The name is not found on the list"<<endl;
            return 0;
        }
        cout<<"Do you wish to search for another name?(1 yes/ 0 no)";
        cin>>opcion;
    }

    return 0;
}













