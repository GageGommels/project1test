//=============================================================================
// The following is a partial program that calls "nextCommand" in util.cpp.
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <fstream>
#include <iostream>
#include <climits>
#include <string>
using namespace std;
//decided to go with a main thats a litter different, I could not for the life of me figure out the one provided for us so
//i improvised
int main() {

	struct heap h;
	int n, key_val, flag;
	int i,v;
	char input;

	while(1) {
		//print the menu
		printf("(S): Stops the program.\n");
		printf("(C n): Create a heap with capacity n.\n");
		printf("(R): reads the file from inputHeap\n");
		printf("(W): print the heap and the information with it.\n");
		printf("(I f k): Insert a value into the heap\n");
		printf("(D f): to delete the minium element in the heap\n");
		printf("(K f i v): This will call a function that decreases the key of an index given\n");
		printf("\n Enter command here: \n");
		cin >> input;

		switch (input) {
			case 'C':
				cin >> n;
				h = initalize(n + 1);
				printf("The heap was initalized with capactiy %d\n", n);
				break;
			case 'S':
				return 0;
			case 'K':
				cin >> flag;
				cin >> i;
				cin >> key_val;

				decreaseKey(i,v,flag,h);
				break;
			case 'R':
				readFile(&h);
				printf("elements in heap input was put into heap\n");
				break;
			case 'W':
				printHeap(h);
				break;
			case 'I':
				cin >> key_val;
				cin >> flag;


				insert(&h, flag, key_val);
				printf("the key was inserted\n");
				break;
			case 'D':
				cin >> flag;


				deleteMin(h,flag);
				printf("The root was detleted\n");
				break;
			default: 
			printf("Invalid input\n");
		}

	}
	return 0;
}


//This Function is to read the from a file
void readFile (heap *h) {
	
	//creates the size and array for the file
	int ary[50];
	int size;


	ifstream myfile("HEAPinput.txt");
		myfile >> size;
		//calls inset each time we find an element in the array
		for (int i = 1;i < size+1; i++) {
			myfile >> ary[i];

			insert(h , 1 , ary[i]);
		}
		myfile.close();
}
