#include <stdio.h>
#include <stdlib.h>
//#include "heap.h"

int main()
{
    int key;
    heap h;
    init_heap(&h, 30);


    delete_heap(&h);

    insert_heap(&h, 10);
    insert_heap(&h, 20);
    insert_heap(&h, 30);
    insert_heap(&h, 40);
    insert_heap(&h, 50);
    insert_heap(&h, 10);
    insert_heap(&h, 90);

    traverse_heap(h);

//    delete_heap(&h);
//    traverse_heap(h);
//
//    delete_heap(&h);
//    traverse_heap(h);
//
//    delete_heap(&h);
//    traverse_heap(h);

    toMaxHeap(&h,7);
    traverse_heap(h);

    return 0;
}
