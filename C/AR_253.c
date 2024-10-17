#include <stdio.h>
#include <string.h>

#define MAX_N 100 
#define MAX_ENTRIES 1000

typedef struct {
    int key;
    int value;
} MapEntry;

typedef struct {
    MapEntry entries[MAX_ENTRIES];
    int size;
} Map;

typedef struct {
    int position;
    int moves;
} QueueEntry;

void insertMap(Map* map, int key, int value) {
    if (map->size<MAX_ENTRIES) {
        map->entries[map->size].key=key;
        map->entries[map->size].value=value;

        map->size++;
    }
}

int getMap(Map* map, int key) {
    int i;

    for (i=0;i<map->size;i++) {
        if (map->entries[i].key==key) return map->entries[i].value;
    }

    return key; 
}

int bfs(int N, int K, Map* serpientes, Map* escaleras) {
    int i;

    int visited[MAX_N*MAX_N+1]={0};
    QueueEntry queue[MAX_N*MAX_N+1];
    int front=0, rear=0;
    
    queue[rear++]=(QueueEntry){1, 0};
    visited[1]=1;
    
    while (front<rear) {
        QueueEntry current=queue[front++];
        int position=current.position;
        int moves=current.moves;
        
        if (position==N*N) return moves;
        
        for (i=1;i<=K && position+i<=N*N;i++) {
            int next_position=position+i;
            
            next_position=getMap(escaleras, next_position);
            next_position=getMap(serpientes, next_position);
            
            if (!visited[next_position]) {
                visited[next_position]=1;
                queue[rear++]=(QueueEntry){next_position, moves+1};
            }
        }
    }
    
    return -1; 
}

int resuelveCaso() {
    int i;

    int N, K, S, E;
    if (scanf("%d %d %d %d", &N, &K, &S, &E)!=4) return 0;
    if (N==0 && K==0 && S==0 && E==0) return 0;

    Map serpientes={0}, escaleras={0};

    int a, b;
    for (i=0;i<S;i++) {
        scanf("%d %d", &a, &b);
        insertMap(&serpientes, a, b);
    }

    for (i=0;i<E;i++) {
        scanf("%d %d", &a, &b);
        insertMap(&escaleras, a, b);
    }

    int result=bfs(N, K, &serpientes, &escaleras);
    printf("%d\n", result);

    return 1;
}

int main() {
    while (resuelveCaso());
    
    return 0;
}