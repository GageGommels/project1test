#ifndef HEAP_H
#define HEAP_H
//element structor
struct element {
    int key;
};

//heap structor
struct heap {
    int size;
    int capactiy;
    struct element *H;
};
//declared funbtions
    heap initalize(int k);
    void buildHeap(heap h, element A[],int n);
    void insert(heap *h, int flag, int k);
    void minHeapify(heap, int);
    void decreaseKey(int, int, int, heap);
    void printHeap(heap);
    void printJustHeap(heap);
    int deleteMin(heap, int);
    void swap (int *y, int *x);
    int parent(int);
#endif