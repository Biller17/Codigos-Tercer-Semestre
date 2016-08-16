#include <iostream>
using namespace std;


int main ()
{
    
    int variable;
    int another;
    int* pointer;
    
    
    variable = 2345;
    pointer = &variable; //giving pointer the direction where variable is stored
    cout<<"Value of variable "<<variable<<endl;
    cout<<"Adress of variable "<<&variable<<endl;
    cout<<"Value of pointer "<<pointer<<endl;
    cout<<"Address of pointer "<<&pointer<<endl;
    cout<<"Value pinted to by pointer: "<<*pointer<<endl;
    
    
    //arrays
    
    int numbers[5];
    int *p;
    p = numbers; //numbers ya es una direccion entonces no es necesario poner &
    *p = 10;
    
    p++;
    *p = 20;
    
    p = &numbers[2];
    *p = 30;
    
    p = numbers +3;
    *p = 40;
    
    p = numbers;
    *(p+4) = 50;
    
    for(int i = 0; i<5; i++)
    {
        cout<<numbers[i]<<",";
    }
    cout<<endl;
    
    
    
    
    
    return 0;
}