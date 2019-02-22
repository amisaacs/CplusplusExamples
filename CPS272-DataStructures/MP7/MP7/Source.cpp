#include"listlnk.h"
#include"hashtbl.h"

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

		//read next line from passFile
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
		tempPass.setKey(name);	//set user entered name to var, username which is the key
		passwords.retrieve(name, tempPass);
		/*if (passwords.retrieve(name, tempPass))
		{
			//What is the index where the name was found?
			//Did the retrieve function change tempPass to the Password object found? - yes
			cout << tempPass.getKey() << tempPass.getPass();

		}
			
		else
		{
			cout << "Username NOT found." << endl;
			cout << "Login: ";
			continue;
		}
		*/

		cout << "Password: ";
		cin >> pass;

		//**add lines here to compare retrieved user password to
		//**input password and print "Authentication failure"
		//**or "Authentication successful"
		if (pass == tempPass.getPass())
		{
			cout << "Authentication successful" << endl; 
		}
		else
		{
			cout << "Authentication failure" << endl;
		}
		

		cout << "Login: ";
	}
	cout << endl;
}