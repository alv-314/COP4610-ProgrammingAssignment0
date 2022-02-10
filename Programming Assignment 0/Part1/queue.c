#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

/*
(10 points) Implement the queue ADT (FIFO) using a linked list in C. 
To do this, you need to implement functions 
enqueue (for adding an element of type int to the rear end of queue), 
dequeue (for removing an element of type int from the front end of the queue),
size (for returning the number of elements in the queue). 
Please test your implementation extensively to be sure about its correctness. 
You need to submit the C program containing you test cases along the queue implementation.
*/

Queue* create_q(int init){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = init;
    q->head = n;
    q->tail = q->head;
    q->head->next = NULL;
    return q;
}

int is_empty(Queue* q){
    if(q->head == NULL) return 1;
    return 0;
}

void enqueue(Queue* q, int val){
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    //if it's empty, new node is the head
    if(is_empty(q)){
        q->head = new;
        q->tail = q->head;
        return;
    }
    q->tail->next = new;
    q->tail = new;
}

int dequeue(Queue* q){
    //can't deque
    if(is_empty(q)){
        printf("Nothing to dequeue.");
        return -1;
    };
    
    int val = 0;
    val = q->head->val;
    
    Node* temp = q->head;
    q->head = q->head->next;

    free(temp);
    return val;
}

int get_head(Queue* q){
    if(!is_empty(q))return q->head->val;
    return 0;
}

int get_tail(Queue* q){
    if(!is_empty(q))return q->tail->val;
    return 0;
}

void print_q(Queue* q){
    Node* n = q->head;
    while(n != NULL){
        printf("%d", n->val);
        n = n->next;
    }
}

int size(Queue* q){
    if(is_empty(q)) return 0; 

    Node* n = q->head;
    int count = 1;
    while(n != NULL){
        n = n->next;
        count++;
    }
    return count;
}

void destroy_q(Queue* q){
    if(is_empty(q)){
        free(q);
        return;
    }
    q = dequeue(q);
    destroyQ(q);
}

void main(){

}