/*
CPS272 - C++ Data Structures
MP6 - Binary Trees
1. Inputs a line of text
2. Tokenizes the line into separate words.
3. Inserts the words into a binary search tree(BST)
4. Does a post-order traversal and prints.
5. Does a pre-order traversal and prints.
6. Does an in-order traversal and prints.
7. Prints the heights and number of leafs in each binary search.
*/

#include<string>
#include"BinaryTreeType.h"
//auxillary methods are coded below main
string parseInput(int &i, string str);

void main()
{
	/*  UNIT TEST - PARSING STRINGS
		types of strings to test:
		A. strings of one letter
		B. strings that contain punctuation that belongs in a word
		C. strings that contain non-alpha charactors that are not numbers.
		D. strings that contain numbers
		E. strings with double string deliminators i.e. double spaces, double commas, two line breaks in a row.
	*/
		string inputStr;	//inputed line of text
		string pStr;		//parsed string
		int index = 0;
		
		//A. strings of one letter
		inputStr = "m a r i e i s a a c";	//for testing
		cout << "Input string:" << inputStr<< endl;
		cout<< "Parsed input string:"<<endl;
		//parse string into tokens and print each token
		while (index != -1)
			cout<< parseInput(index, inputStr);
		
		inputStr = "G r 8 f u l";	//for testing
		cout << "Input string:" << inputStr<< endl;
		cout<< "Parsed input string:"<<endl;
		//parse string into tokens and print each token
		while (index != -1)
			cout<< parseInput(index, inputStr);
	
		
		
	/*
	//NodeType<string> *node;  May not need this for insert
	BinaryTreeType<string> tree;
	string inputStr;	//inputed line of text
	string pStr;		//parsed string
	int index = 0;
	bool goodInput = false;		//flag for a good parsed string

	while (!goodInput)
	{
		cout << "Enter a line of text(only alpha characters, no punctuation): " << endl;
		getline(cin, inputStr);
		for (int i = 0; i < inputStr.length(); ++i)
		{
			goodInput = true;
			if (!isalnum(inputStr.at(i)))
			{
				goodInput = false;
				continue;
			}
		}
	}
	
	
	
	//Loop through until all the tokens have been parsed and inserted in tree.
	//index is passed by reference to parseInput(index, inputStr) and is changed to -1 when all the tokens have been parsed.
	
	while (index != -1)
	{
		//parse string into tokens
		pStr = parseInput(index, inputStr);

		//insert string into tree
		tree.insert(pStr);
		//cout << pStr << " ";
	} 
	//print tree in preOrder(nLR
	cout << endl;
	cout <<"\npreOrder print:"<< endl;
	tree.preOrderPrint();
	cout << endl;
	cout << "\npostOrder print:" << endl;
	tree.postOrderPrint();
	cout << endl;
	cout << "\ninOrder print:" << endl;
	tree.inOrderPrint();

	cout << "\n\nNumber of leaves in the tree: " << tree.countTreeLeaves()<<endl;
	cout << "Height of the tree: " << tree.getTreeHeight() << "." << endl<<endl;
}//end main
*/

string parseInput(int &i, string str)
{
	int startPos = i + 1;
	int endPos;				//where the deliminator was found (deliminators are space(" "), comma (",") and newline ("\n") and period (".").
	int tLen;				//parsed string(token)'s length
	string token = "";		//parsed string(token) to return

	//find position of white space, '\n' or period
	endPos = str.find(" ",startPos);
	if (endPos == -1)//" " not found
	{
		endPos = str.find('.', startPos);
		if (endPos == -1) // period not found.
		{
			endPos = str.find('\n');
		}//period not found
	}// " " not found

	if (endPos != -1)
	{
		tLen = endPos - i;				//length of the token is where the space was found minus where the search started
		token = str.substr(i, tLen);
	}
	else
	{
		token = str.substr(i);
	}

	if (endPos != -1)
		i = endPos + 1;
	else
		i = endPos;//set i to the end position for the next search to parse the next token or stop the while loop
	return token;				
}