#include <stdio.h>
#include <stdlib.h>

#define MOD 10000

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    Pair* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->capacity =capacity;

    queue->front =queue->size=0;
    queue->rear  =capacity-1;
    queue->data  =(Pair*)malloc(queue->capacity*sizeof(Pair));

    return queue;
}

int isFull(Queue* queue) { return queue->size==queue->capacity; }

int isEmpty(Queue* queue) { return queue->size==0; }

void enqueue(Queue* queue, int first, int second) {
    if (isFull(queue)) return;

    queue->rear=(queue->rear+1)%queue->capacity;
    queue->data[queue->rear].first  =first;
    queue->data[queue->rear].second =second;

    queue->size++;
}

Pair dequeue(Queue* queue) {
    Pair ret=queue->data[queue->front];

    queue->front =(queue->front + 1) % queue->capacity;
    queue->size -=1;

    return ret;
}

int bfs(int ini, int fin) {
    if (ini==fin) return 0;

    Queue* Q=createQueue(10000);
    enqueue(Q, ini, 0);

    int visited[MOD]={0};
    int v, d, tmp;

    while (!isEmpty(Q)) {
        Pair current=dequeue(Q);
        v=current.first;
        d=current.second+1;

        // SUM
        tmp=(v+1)%MOD;
        if (!visited[tmp]) {
            if (tmp==fin) {
                free(Q->data);
                free(Q);
                return d;
            }

            visited[tmp]=1;
            enqueue(Q, tmp, d);
        }

        // MUL
        tmp=(v*2)%MOD;
        if (!visited[tmp]) {
            if (tmp==fin) {
                free(Q->data);
                free(Q);
                return d;
            }

            visited[tmp]=1;
            enqueue(Q, tmp, d);
        }

        // DIV
        tmp=(v/3)%MOD;
        if (!visited[tmp]) {
            if (tmp==fin) {
                free(Q->data);
                free(Q);
                return d;
            }

            visited[tmp]=1;
            enqueue(Q, tmp, d);
        }
    }

    free(Q->data);
    free(Q);
    return 0;
}

int resuelveCaso() {
    int ini, fin;
    if (scanf("%d %d", &ini, &fin)!=2) return 0;

    printf("%d\n", bfs(ini, fin));
    return 1;
}

int main() {
    while (resuelveCaso());
    
    return 0;
}
