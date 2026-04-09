#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int vertex;
};
typedef struct node *GNODE;
GNODE graph[20];

/* helper function to create a node */
GNODE createNode(int v) {
    GNODE temp = (GNODE)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}

void addEdge(int src, int dest) {
    GNODE temp = createNode(dest);
    GNODE cur;

    if (graph[src] == NULL) {
        graph[src] = temp;
    } else {
        cur = graph[src];
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }
}

void print(int *N) {
    int i;
    GNODE temp;

    for (i = 1; i <= *N; i++) {
        if (graph[i] != NULL) {
            printf("%d=>", i);
            temp = graph[i];
            while (temp != NULL) {
                printf("%d\t", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

void insertVertex(int *N) {
    int inEdges, outEdges;
    int i, src, dest;

    (*N)++;
    graph[*N] = NULL;

    printf("Enter the number of edges from existing vertices to the new vertex : ");
    scanf("%d", &inEdges);

    for (i = 0; i < inEdges; i++) {
        printf("Enter the source vertex : ");
        scanf("%d", &src);

        if (src < 1 || src >= *N) {
            printf("Invalid vertex.\n");
        } else {
            addEdge(src, *N);
        }
    }

    printf("Enter the number of edges from the new vertex to existing vertices : ");
    scanf("%d", &outEdges);

    for (i = 0; i < outEdges; i++) {
        printf("Enter the destination vertex : ");
        scanf("%d", &dest);

        if (dest < 1 || dest >= *N) {
            printf("Invalid vertex.\n");
        } else {
            addEdge(*N, dest);
        }
    }

    printf("After inserting vertex the adjacency list is : \n");
    print(N);
}

void insertEdge(int *N) {
    int src, dest;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);

    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);
  if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    addEdge(src, dest);

    printf("After inserting edge the adjacency list is : \n");
    print(N);
}
void deleteVertex(int *N) {
    int v, i;
    GNODE temp, prev, del;

    if (*N == 0) {
        printf("Graph is empty.\n");
        return;
    }

    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if (v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    /* delete all outgoing edges of vertex v */
    temp = graph[v];
    while (temp != NULL) {
        del = temp;
        temp = temp->next;
        free(del);
    }
    graph[v] = NULL;

    /* delete all incoming edges to vertex v */
    for (i = 1; i <= *N; i++) {
        if (i == v)
            continue;

        temp = graph[i];
        prev = NULL;

        while (temp != NULL) {
            if (temp->vertex == v) {
                if (prev == NULL) {
                    graph[i] = temp->next;
                    del = temp;
                    temp = temp->next;
                    free(del);
                } else {
                    prev->next = temp->next;
                    del = temp;
                    temp = temp->next;
                    free(del);
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }


  /* shift lists left */
    for (i = v; i < *N; i++) {
        graph[i] = graph[i + 1];
    }
    graph[*N] = NULL;

    /* update vertex numbers in adjacency lists */
    for (i = 1; i < *N; i++) {
        temp = graph[i];
        while (temp != NULL) {
            if (temp->vertex > v) {
                temp->vertex--;
            }
            temp = temp->next;
        }
    }

    (*N)--;

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}

void deleteEdge(int *N) {
    int src, dest;
    GNODE temp, prev;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);

    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    temp = graph[src];
    prev = NULL;

    while (temp != NULL) {
        if (temp->vertex == dest) {
            if (prev == NULL) {
                graph[src] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}