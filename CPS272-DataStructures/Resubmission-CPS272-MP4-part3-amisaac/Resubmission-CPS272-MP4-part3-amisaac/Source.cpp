#include<iostream>
#include<fstream>
#include<cmath>
#include<math.h>
#include<stack>
#include<string>
using namespace std;

/*
CPS-272 Fall 2017
Khaled Mansour
Tues 5:30 - 9:30pm

Machine Problem 3 - part 3
Open a file for input.
Verify that there are matches of ( {},().{} ) - or balanced
algorithm:
1. open file
2. read each line of file until end
3. if the char from the line has a match, pop the match from the stack
otherwise push the char if it is a valid char.
if it is an invalid char, save 'X' into c.
4. if there is anything left in the stack or c='X'
the string isn't balanced.
otherwise, the string is balanced.
5. write msg "Balanced" or "not Balanced" to output file
*/

void main()
{
	string filename = "";
	string outputfilename = "Output-";
	string line = "";
	char c = ' '; //from input file
	stack<char> myStack;

	//cout << "Enter filename (or X to quit): "; //uncomment AFTER testing
	//cin >> filename;  //uncomment AFTER testing
	filename = "balance.txt"; //DELETE AFTER testing
	ifstream inputfile(filename);
	outputfilename = outputfilename.append(filename);
	ofstream fout(outputfilename);

	if (filename == "X")
	{
		cout << "Thank you. Goodbye.";
		return;
	}

	if (inputfile.is_open())
	{
		while (getline(inputfile, line))
		{
			//If the char is valid ( {,(,[ ) and has a match ( },),] ) pop the match,
			//Otherwise, write the char if it is valid ( {,(,[,},),] ) ignore it if it isn't valid and make c='X' 
			int i;
			for (i = 0; i < line.length(); ++i)
			{
				c = line[i];
				//only process c if it is {}[]or()
				if (c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']')
				{
					if (myStack.empty())
						myStack.push(c);
					else
					{
						switch (c)
						{
						case '}':
							if (myStack.top() == '{')
								myStack.pop();
							else myStack.push(c);
							break;
						case ')':
							if (myStack.top() == '(')
								myStack.pop();
							else myStack.push(c);
							break;
						case ']':
							if (myStack.top() == '[')
								myStack.pop();
							else myStack.push(c);
							break;
						case '{':
						case '(':
						case '[': myStack.push(c); break;
						default: c = 'X';
							break;
						}
					}//end else
				}//end //only process c if it is {}[]or()
				 //		if (c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']')
			}//end for (i = 0; i < line.length(); ++i)
		}//end while (getline(inputfile, line))

		if (myStack.empty() && c != 'X')
			fout << "The symbols in file \"" << filename << "\" are balanced." << endl;
		else
			fout << "The symbols in file \"" << filename << "\" are NOT balanced." << endl;

		cout << "Output file: " << outputfilename << "has been created." << endl;
		outputfilename = "Output-";
	}

	else //if (inputfile.is_open())
	{
		cout << "There is no input file." << endl;
		outputfilename = "Output-";
	}
}