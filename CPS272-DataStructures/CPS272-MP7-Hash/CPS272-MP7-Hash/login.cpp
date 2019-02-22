#include<string>
//--------------------------------------------------------------------
//                         login.cpp
//
//  program that reads in username/login pairs and then
//  performs authentication of usernames.
//--------------------------------------------------------------------


//This will be the data stored in the HashTbl (class T)
struct Password
{
	void setKey(string newKey) { username = newKey; }
	string getKey() const { return username; }

	//this hash converts a string to an integer
	int hash(const string str) const
	{
		int val = 0;

		for (unsigned int i = 0; i<str.length(); i++)
			val += str[i];
		return val;
	}
	string username,
		password;
};


cout << "Password: ";
cin >> pass;

//**add lines here to compare retrieved user password to
//**input password and print "Authentication failure"
//**or "Authentication successful"

cout << "Login: ";
	}
	cout << endl;
}