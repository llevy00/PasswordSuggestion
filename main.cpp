#include <iostream>
#include <string>

using namespace std;

//-PROTOTYPES----------------
// (1) add the function prototypes here to match their definitions (below)

string getUserPassword();
bool acceptedLength(string);
bool acceptedPhrase(string);
void displayPassword(string);
int numberOfDigits(string);

//---------------------------

//-MAIN PROGRAM--------------
int main()
{
    string entry; // keeps track of what the user entered
    bool isGoodLength = false; // whether it is an acceptable length
    bool isGoodWord = false; // whether it is an acceptable word
    int digits = 0; 

    do
    {
        // (2) call the getUserPassword function and store its return in entry
        entry = getUserPassword();
        // (3) call the acceptedLength function w/ the entry argument
        //     and store its return in isGoodLength
        isGoodLength = acceptedLength(entry);
        // (4) call the acceptedPhrase function w/ the entry argument
        //     and store its return in isGoodWord
        isGoodWord = acceptedPhrase(entry);
        digits = numberOfDigits(entry);

    }while( !isGoodLength || !isGoodWord || digits < 2 );

    cout<<"Password ";
    // (5) call the displayPassword function w/ the entry argument
    displayPassword(entry);
    cout<<" has been set\n";

    return 0;
}
//----------------------------

//-FUNCTION-DEFINITIONS-------

//asks the user for their password and returns what they entered
string getUserPassword()
{
    string entered;
    cout<<"Please enter your password, between 8-20 characters: ";
    getline(cin, entered);
    return entered;
}

// receives a password and verifies whether or not it is between
// 8 and 20 characters long
bool acceptedLength(string password)
{
    int characters = password.length();

    if( characters >=8 && characters <= 20 )
    {
        return true;
    }
    else
    {  
        return false;
    } 
}

// receives a password as a string and returns whether or not it is an
// accepted word (e.g. "password" is not a valid password
bool acceptedPhrase(string password)
{
    bool acceptable;
    if( password == "password" || password == "12345678"
        || password =="123456789" || password == "qwertyuiop")
    {
        acceptable = false;
    }
    else
    {
        acceptable = true;
    } 
    return acceptable;
}

// receives a password and displays it with *'s replacing each character
void displayPassword(string password)
{
    for(int i=0; i<password.length(); i++)
    {
        cout<<"*";
    }
}

int numberOfDigits(string password)
{
    int counter = 0;
    for(int i=0; i<password.length(); i=0)
    {
        if(password.at(i)==0||password.at(i)==1||password.at(i)==2||password.at(i)==3||password.at(i)==4)
        {
           counter++; 
        }
        else if(password.at(i)==5||password.at(i)==6||password.at(i)==7||password.at(i)==8||password.at(i)==9)
        {
            counter++;
        }
    }
 return counter;
}
//----------------------------
