#include <iostream>
#include <string.h>
using namespace std;

//recursive function to test  a palindrome

int test_palindrome(string w, int left, int right)
{
    //Test the case of an empty string
    if(right< left)
        return 1;
    //test the case of a string of length 1
    if(left == right)
        return 1;
    
    //any other case
    int valid;
    int valid_substring;
    
    //check the characters at the limits
    valid = (w[left] == w[right]);
    
    //check the rest of the string
    valid_substring = test_palindrome(w, left+1, right-1);
    
    return (valid && valid_substring);//to return a true, both part have to be true
    
    
}


int main ()
{
    string word;
    int answer = 0;
    
    cout<<"Enter the word to test: ";
    
    cin>>word;

    answer = test_palindrome(word, 0, word.length()-1);
    
    if(answer)
    {
        cout<<"The word "<<word<<" is a palindrome"<<endl;
    }
    else
    {
        cout<<"This word is not a palindrome"<<endl;
    }
    
    
    
    return 0;
}