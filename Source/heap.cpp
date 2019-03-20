#include "heap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

//This function will make a empty heap object with 1 to n capacity
heap initalize(int k) {
    struct heap h;
    h.capactiy = k;
    h.size = 0;
    h.H = (element*)malloc(sizeof(element)*h.capactiy);
    return h;
}
//this function will create a heap data structor and insert elements from array[]input
void buildHeap(heap h, element A[], int n) {
     for (int i = 1; i < n; i++) {
         h.H[i].key = A[i].key;
     }
     minHeapify(h,1);
}
//inserts an element at the bottem of the array and then checks to make sure its not violating the min heap structor
void insert(heap *h, int flag, int k) {
    if (flag == 2 ) {
        printJustHeap((*h));
    }

    if ((*h).size == (*h).capactiy) {
        printf("Capacity reached cannot insert element!");
        return;
    }
    int i = (*h).size + 1;
    (*h).H[i].key = k;
    (*h).size++;

    //Check for the min heap
    while ((*h).H[((i-1)/2)].key > (*h).H[i].key && i != 1) {

        //swap(&h->H[i].key, &h->H[(i-1)/2].key);
        int temp = (*h).H[i].key;
        (*h).H[i].key = (*h).H[(i-1)/2].key;
        (*h).H[(i-1)/2].key = temp;
        i = (i-1)/2;
    }
    
    if(flag == 2) {
        printJustHeap((*h));
    }
    
}

//This function is to delete the minimum element in the heap which should be the root
int deleteMin(heap h,int flag) {
    int min;
    if (flag == 2) {
        printJustHeap(h);
    }
    //Nothing in heap
    if (h.size <= 0) {
        return 0;
    }
    //returns the root
    if (h.size >= 1) {
        h.size--;
        min = h.H[1].key;
    }
    //remove element
    h.H[1].key = h.H[h.size - 1].key;
    h.size--;
    minHeapify(h,1);
    return min;

    if (flag == 2) {
        printJustHeap(h);
    }
}

//swap function
void swap (int *y, int *x) {
    int temp; 
    temp = *x;
    *x = *y;
    *y = temp;
}

//Constructs a min heap from the arry inside of the object
void minHeapify(heap h,int i) {
    int left =  (2 * i + 1);
    int right = (2 * i + 2);

    int small = i;

    if (h.H[i].key > h.H[left].key && left < h.size)
        small = left;
    if (h.H[small].key > h.H[right].key && right < h.size)
        small = right;
    if(small != i) {
        //swap
        swap(&h.H[small].key ,&h.H[i].key);
        minHeapify(h, small);

    }
}
//This is to print just the indexes and the elements in the heap
void printJustHeap (heap h) {
    printf("Heap Elements: \n");
    printf("Index   Element\n");

    for(int i = 1; i < h.size; i++) {
        cout << i <<"   " <<h.H[i].key << endl;
    }

}
//This is the print function, it will print the capacity, the size and the index and the value at the array
void printHeap(heap h) {
    printf("Heap Info:\n");
    cout << "Capacity: " << h.capactiy-1 << endl;
    cout << "Size: " << h.size << endl;
    // printf("Capacity: %d\n" + h.capactiy);
    //printf("Size: %d\n" + h.size);
    printf("Heap Elements: \n");
    printf("Index   Element\n");

    for(int i = 1; i < h.size + 1; i++) {
        cout << "   " << i << "     " <<h.H[i].key << endl;
    }
        
}
//This function allows the user to unput the index value you want to decrease to and the flag to see if 
//you want the function to print as well.
void decreaseKey(int i, int val, int flag, heap h) {

//Checks to see if the input is less than the key
    if (val >= h.H[i].key) {
        printf("Value given is greater than the current key");
        return;
    }
    //prints the before change
    if (flag == 2) {
        printJustHeap(h);
    }
    //decrease the key
    h.H[i].key = val;

    //Checks to makes sure its still a min heap
    while (h.H[(i-1)/2].key > h.H[i].key && i != 1) {

        //does the swap
        swap(&h.H[(i-1)/2].key, &h.H[i].key);
        i = (i-1)/2;
    }
    //prints the after change
    if (flag == 2) {
        printJustHeap(h);
    }

}
