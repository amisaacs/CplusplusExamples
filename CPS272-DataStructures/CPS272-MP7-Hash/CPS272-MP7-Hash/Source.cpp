#include<iostream>
#include<string>
//#include"hastbl.h"
#include"listlnk.h"

using namespace std;

void main()
{
	List<int> practiceList;
	practiceList.insert(10);
	practiceList.insert(7);
	practiceList.insert(5);
	practiceList.showStructure();
	/*
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
	passFile >> tempPass.username;
	while (!passFile.eof() && !passwords.isFull())
	{
		//**add line here to insert passwords into the HashTbl

		passFile >> tempPass.password;
	}

	cout << "Printing the hash table:..." << endl;
	//**add line here to show (print) the HashTbl


	//*********************************************************
	// Step 2: Prompt for a Login and Password and check if valid
	//*********************************************************
	cout << "Login: ";
	while (cin >> name)  // to quit, type CTRL Z in Visual C++
	{
		//**add line here to retrieve user from HashTbl
*/
}
