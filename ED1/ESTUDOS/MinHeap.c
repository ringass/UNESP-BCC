#include <stdio.h>

#define MAX_SIZE 100

typedef struct{
    int size;
    int data[MAX_SIZE];
}min_heap
;


void init(min_heap
 *h){
    h->size = 0;        
}
void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp; 

}

void heapifyUp(min_heap
 *heap, int index) {
    if (index == 0) return;  

    int parent = (index - 1) / 2;

    if (heap->data[parent] > heap->data[index]) {
        swap(&heap->data[parent], &heap->data[index]);
        heapifyUp(heap, parent);
    }
}

void insert(min_heap* heap, int value){
    
    if(heap->size == MAX_SIZE){
        return;
    }

    heap->data[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;

    
    }



// int hash(int value){

//     return value % 23;

// }

// void inserir (min_heap
//  *table, int value){

//     int index = hash(value);

//     while(table->data[index] != -1)
//         index = (index + 1) % MAX_SIZE;

//     table->data[index] = value;

//     return;
// }

void print(min_heap
 heap){

    for(int i = 0; i < heap.size; i++){
        printf("%d ", heap.data[i]);
    }

}

void heapifyDown(min_heap
 *heap, int index){

    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest
 = index;


    if(left < heap->size && heap->data[left] < heap->data[smallest
]){
        smallest
 = left;
    }

    
    if(right < heap->size && heap->data[right] < heap->data[smallest
]){
        smallest
 = right;
    }

    if(smallest
 != index){
        swap(&heap->data[index], &heap->data[smallest
]);
        heapifyDown(heap, smallest
);
    }

}

int get_min(min_heap
 *heap){

    if(heap->size == 0){
        return -1;
    }

    int min = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);

    return min
;

}

int main(){

    min_heap
 heap;


    init(&heap);

    insert(&heap, 25);
    insert(&heap, 40);
    insert(&heap, 15);
    insert(&heap, 10);
    insert(&heap, 50);
    insert(&heap, 30);
    insert(&heap, 20);
    insert(&heap, 35);
    insert(&heap, 5);


    print(heap);

    printf("\n%d\n", get_min(&heap));

    print(heap);


}

    