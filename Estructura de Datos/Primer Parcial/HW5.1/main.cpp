//Adrian Biller A01018940

//HW5


#include <iostream>

#include "LinkedList.h"
#include "Vector3D.h"

int main(void)
{
    
    LinkedList<Vector3D> list;
    std::cout << "Size of node: " << sizeof (Node<Vector3D>) << std::endl;
    std::cout << "Initial length: " << list.getLength() << std::endl;


//inserting all vectors
    list.insertTail(Vector3D(-3.5, 6.4, -5));
    list.insertTail(Vector3D(-6.2, 7.2, 4.8));
    list.insertTail(Vector3D(9.3, -8.1, -1.6));
    list.insertTail(Vector3D(4.5, 3.7, -5.1));
    list.insertTail(Vector3D(5.8, -3.1, 2.9));
    list.insertTail(Vector3D(-6.1, 2.8, 5.9));
    list.insertTail(Vector3D(0.5, -7.3, -4.2));
    list.insertTail(Vector3D(3.8, 4.1, -5.8));
    list.insertTail(Vector3D(7.9, 6, 2.4));
    
    std::cout << "New length: " << list.getLength() << std::endl;
    std::cout << "This is the list now: " << std::endl;
    list.printList();
    
    std::cout<<"Resultant vector: ";
    //creating a resultant vector
    Vector3D result(0,0,0);
    //summing up all vectors in a loop to the result
    for(int i  = 0; i<list.getLength(); i++)
    {
        result  = result + list.getItemAt(i)->getData();
    }
    
    std::cout<<result<<std::endl;
    //creating two list for upper and lower vectors with respect of z axis
    LinkedList<Vector3D> upper;
    LinkedList<Vector3D> lower;
    
    
    //conditional loop where all vectors get separated into the ones with higher values of z and lower values
    for(int i = 0; i< list.getLength(); i++)
    {
        if(list.getItemAt(i)->getData().getZ()>0)
        {
            upper.insertTail(list.getItemAt(i)->getData());
        }
        else
        {
            lower.insertTail(list.getItemAt(i)->getData());
        }
    }
    //prints both list
    std::cout<<"Upper List"<<std::endl;
    upper.printList();
    
    std::cout<<"Lower List"<<std::endl;
    lower.printList();
    
    //the delete process is automatic so theres no sweat.
    
    
    return 0;
}
