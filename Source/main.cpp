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


//this funtion was origionally my read funtion but it slowly became my Build Heap function and due to me being scared to refactor the name for all of the assignemnt I am leaving it as readFile
void readFile (heap *h) {
	
	//creates the size and array for the file
	int ary[50];
	int size;
	fstream myfile;
	int counter = 0;

	myfile.open ("HEAPinput.txt");


	if(myfile.is_open()) {
		if(size > h->capactiy) {
			cout << "Sorry!!! It cannot be done. Please increase the capacity of the heap first!" << endl;
			myfile.close();
			return;
		}
		myfile >> size;
		//calls inset each time we find an element in the array

		//inserts the elements into an array
		for (int i = 1;i < size+1; i++) {
			myfile >> ary[i];
		}


		//counter for the array
		for(int i = 1;i < size+1; i++) {
			if(ary[i] != 0) {
				counter++;
			}
		}

		//checks to see if the number of element matches the specified size at the begining
		if(counter != size) {
			cout << "Sorry!!! It cannot be done. The number of elements in file is less than specified in the beginning of file" << endl;
			myfile.close();
			return;
		}

		//Checks to see if the size will fit the capacity
		if(size > h->capactiy) {
			cout << "Sorry!!! It cannot be done. Please increase the capacity of the heap first!" << endl;
			myfile.close();
			return;
		}
		//inserts the elements into the array
		for (int i = 1;i < size+1; i++) {
			insert(h , 1 , ary[i]);
		}
		myfile.close();
	} else {
		cout << "There was a problem opening file HEAPinput.txt for reading" << endl;
	}
		
}
