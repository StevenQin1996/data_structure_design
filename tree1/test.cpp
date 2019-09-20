#include <iostream>
#include "p2bst2.h"
using namespace std;

int main()
{
	cout << "* This program tests an implementation of a Binary Search Tree *\n\n";
	
	Tree<int> tree;
	initialize(tree);
	
	string command;
	int value;
	while(true)
	{
		cin >> command;
		
		if( command == "Quit" )
			break; // quit loop/program
		
		if( command == "Insert" ) 
		{
			cin >> value;
			insert(tree, value);
		}
		
		else if( command == "Contains" )
		{
			cin >> value;
			int d = contains(tree, value);
			if( d >= 0 )
				cout << ">> Depth: " << d << "\n";
			else
				cout << ">> Value not found\n";
		}
		else if( command == "Count" )
		{
			cout << ">> " << countNodes(tree) << endl;
		}

		else if( command == "Height" )
		{
			if( countNodes(tree) == 0 )
				cout << ">> Tree empty" << endl;
			else				
				cout << ">> " << height(tree) << endl;
		}
				
		else if( command == "Lowest" )
		{
			if( countNodes(tree) == 0 )
				cout << ">> Tree empty\n";
			else
				cout << ">> " << minValue(tree) << endl;
		}
		
		else if( command == "Highest" )
		{
			if( countNodes(tree) == 0 )
				cout << ">> Tree empty\n";
			else
				cout << ">> " << maxValue(tree) << endl;
		}
	}		
	destroy(tree);
}