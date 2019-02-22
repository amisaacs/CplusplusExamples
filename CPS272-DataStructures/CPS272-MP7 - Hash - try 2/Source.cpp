#include<iostream>
#include<string>
#include"listlnk.h"
#include"hashtbl.h"

using namespace std;

void main()
{
	HashTbl<Password, string> passwords(10);
	Password tempPass;
	string name;      // user-supplied name
	string pass;      // user-supplied password
					  //bool userFound;   // is user in table?

					  //*********************************************************
					  // Step 1: Read in the password file
					  //*********************************************************
	ifstream passFile("password.txt");

	if (!passFile)
	{
		cout << "Unable to open 'password.txt'!" << endl;
		exit(0);
	}
	passFile >> tempPass.username;	//reads from passFile and stores in tempPass.username
	passFile >> tempPass.password;	//reads from passFile and stores in tempPass.password
	while (!passFile.eof() && !passwords.isFull())
	{
		//**add line here to insert passwords into the HashTbl
		passwords.insert(tempPass);
		passFile >> tempPass.username;
		passFile >> tempPass.password;
		
	}

	cout << "Printing the hash table:..." << endl;
	//**add line here to show (print) the HashTbl
	passwords.showStructure();

	//*********************************************************
	// Step 2: Prompt for a Login and Password and check if valid
	//*********************************************************
	cout << "Login: ";
	while (cin >> name)  // to quit, type CTRL Z in Visual C++
	{
		//**add line here to retrieve user from HashTbl
		tempPass.setKey(name);
		tempPass.hash(name);
		index = newDataItem.hash(newDataItem.getKey()) % tableSize;	//hash the username
		passwords.retrieve(name, name);

		/*Don't touch below here yet.*/
		cout << "Password: ";
		cin >> pass;

		//**add lines here to compare retrieved user password to
		//**input password and print "Authentication failure"
		//**or "Authentication successful"

		cout << "Login: ";
	}
	cout << endl;
}
