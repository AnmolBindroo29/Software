typedef struct
{
    int *A;
    int rear, size;
}heap;

void init_heap(heap* h, int s);
void insert_heap(heap* h, int k);
void heapify(heap* h);
int delete_heap(heap* h);
void traverse_heap(heap h);
void swap_heap(int *a, int*b);
