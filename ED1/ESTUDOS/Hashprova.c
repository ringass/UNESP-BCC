#include <stdio.h>

#define MAX 23

typedef struct{
    int data[MAX];
}hash_map;


void init(hash_map *map){

    for(int i = 0; i < MAX; i++){
        map->data[i] = -1;
    }

}


int hash(int x){
    
    return x % 23;
}

void insert(hash_map *map, int value){

    int index = hash(value);
    int start = index;

    while(map->data[index] != -1){

        if(map->data[index] == value){
            return;
        }

        index = (index + 1) % 23;

        if(index == start){
            printf("deu b.o");
            return;
        }
    }

    map->data[index] = value;

}

void print(hash_map v){

    for(int i = 0; i < MAX; i++){

        int p = v.data[i];

        if(p != -1){
            printf("%d: %d\n", i, p);
        }
        
    }

}


int main(){

    hash_map m;

    init(&m);

    insert(&m, 10);
    insert(&m, 21);
    insert(&m, 5);
    insert(&m, 9);
    insert(&m, 3);
    insert(&m, 10);
    insert(&m, 21);

    print(m);

}