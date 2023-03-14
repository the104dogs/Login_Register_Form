#include <iostream> 
#include <fstream> // can write and read out files
#include <string>

using namespace std; // reduces need to write std

bool IsLoggedIN() // clarifies if the user is logged in
{
    string username, password, un, pw; // un and pw are the comparison strings
    std::cout << "Enter username: "; cin >> username; // asking for username
    cout << "Enter password: "; cin >> password; // asking for passowrd

    ifstream read(username + ".txt"); // read is the variable, and filename is the user name typed
    getline(read, un); // if stream variable reading the filename
    getline(read, pw); //  

    if (un == username && pw == password) { // comparison statements for if the conditions are met

        return true;
    }
    else {

        return false;

    }
}


int main() // main function of the program 
{

    int choice; // choice of whether you want to register or login

    cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;
    if (choice == 1) // register
    {
        string username; // creates the string for the username and password
        string password;

        cout << "select a username: "; cin >> username; // taking user input for registry
        cout << "select a password: "; cin >> password;

        ofstream file; // creating a file with ofstream
        file.open(username + ".txt"); // opens the file

        file << username << endl << password; // writes the username to the file first and then writes the password
        file.close(); // file is then closed

        main(); // resets the program to either register or login
    }
    else if (choice == 2) // login
    {
        bool status = IsLoggedIN(); // checks the status of the IsLoggedIN and has to do that function first

        if (!status) // checked if condition is not true (!)
        {
            cout << "False login!" << endl;
            system("PAUSE");
            return 0; // has to return an int
        }
        else
        {
            cout << "Successfully logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}