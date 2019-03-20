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
	bool inialize = false;
	bool insert_elements = false;

	while(1) {
		cin >> input;

		switch (input) {
			case 'C':
				cin >> n;
				h = initalize(n + 1);
				inialize = true;
			break;


			case 'S':
				return 0;


			case 'K':
				if (inialize == true && insert_elements == true) {
					cin >> flag;
					cin >> i;
					cin >> key_val;
					decreaseKey(i,v,flag,h);
				} else {
					cout << "Sorry!!! It cannot be done. Please inialize the heap first and put the elements into it" << endl;
				}
			break;


			case 'R':
				if (inialize == true) {
					readFile(&h);
					printf("elements in heap input was put into heap\n");
					insert_elements = true;
				} else {
					cout << "Sorry!!! It cannot be done. Please inialize the heap first" << endl;
				}
			break;
				


			case 'W':
				if (inialize == true) {
					printHeap(h);
					
				} else {
					cout << "Sorry!!! It cannot be done. Please inialize the heap first" << endl;
				}
			break;
				


			case 'I':
				if (inialize == true) {
					cin >> key_val;
					cin >> flag;
					insert(&h, flag, key_val);
				} else {
					cout << "Sorry!!! It cannot be done. Please inialize the heap first" << endl;
				}
				
				printf("the key was inserted\n");
			break;


			case 'D':
				if (inialize == true && insert_elements == true) {
					cin >> flag;
					deleteMin(h,flag);
				} else {
					cout << "Sorry!!! It cannot be done. Please inialize the heap first and put the elements into it" << endl;
				}
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


	if(myfile.is_open) {
		myfile >> size;
		//calls inset each time we find an element in the array
		for (int i = 1;i < size+1; i++) {
			myfile >> ary[i];

			insert(h , 1 , ary[i]);
		}
		myfile.close();
	} else {
		cout << "There was a problem opening file HEAPinput.txt for reading" << endl;
	}
		
}
