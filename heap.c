#include <stdlib.h>
#include "heap.h"
#include <limits.h>
void init_heap(heap* h, int s)
{
    h->size = s;
    h->rear = -1;
    h->A = (int*)malloc(sizeof(int) * s);

    return;
}

void insert_heap(heap* h, int k)
{
    //if heap is full
    if(h->rear == h->size -1)
        return;

    h->A[++h->rear] = k;
    int i = h->rear;
    int j = (i - 1)/2;

    while((i >= 0) && (h->A[i] > h->A[j]))
    {
        swap_heap(&(h->A[i]), &(h->A[j]));
        i = j;
        j = (i - 1)/2;
    }
    return;
}

void swap_heap(int *a, int*b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void heapify(heap* h)
{
    // are there any elements remaining in the tree OR only one element is in the heap??
    // then it's already a heap
    if(h->rear <= 0)
        return;

    int i, l, r, m;
    i = 0;

    while(i <= h->rear)
    {
        l = 2*i + 1;
        r = 2*i + 2;
        if(l > h->rear)         // i th node is a leaf
            return;
        if(r > h->rear)         // only one child of i th node      //compare i th & l th node and swap if required
        {
            if(h->A[i] < h->A[l])
                swap_heap((&h->A[i]), &(h->A[l]));
            return;
        }
        // now we're sure that node i has both l and r
        // find the greater of l th and r th nodes

        if(h->A[l] > h->A[r])
            m = l;
        else
            m = r;
        swap_heap((&h->A[i]), &(h->A[m]));

        i = m;
    }
    return;
}

int delete_heap(heap* h)
{
    int e = INT_MIN;

    //heap is empty
    if(h->rear == -1)
    {
        printf("Empty heap\n");
        return e;
    }

    e = h->A[0];

    //copy last element to 0th location
    h->A[0] = h->rear;

    //heap size to reduce
    h->rear--;

    //this function will convert tree to heap again
    heapify(h);

    printf("\n\nElement Deleted: %d\n", e);
    return e;
}

void traverse_heap(heap h)
{
    int i = 0;
    printf("Heap: ");
    while(i < h.rear)
    {
        printf("%d ", h.A[i]);
        i++;
    }
    return;
}

void toMaxHeap(heap* h, int n)
{
    for (int i = (n-2)/2; i >= 0; --i)
        heapify(h);

}
