#include <stdio.h>

#define MAX_Vertices 20
#define MAX_Length 20

typedef struct
{
    int A[MAX_Vertices][MAX_Vertices];
    int n;
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            G->A[i][j] = 0;
        }
    }
}

// Them cung vao do thi
void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

void read_file(Graph *G)
{
    freopen("graph.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    // Khoi tao do thi
    init_graph(G, n);

    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(G, u, v);
    }
}

// Kiem tra x va y co phai ket noi voi nhau khong?
int adjacent(Graph G, int x, int y)
{
    return (G.A[x][y] == 1 || G.A[y][x] == 1);
}

// Tinh bac cua dinh x trong do thi G
int degree(Graph G, int x)
{
    int deg = 0;
    for (int i = 1; i <= G.n; i++)
    {
        if (G.A[i][x] == 1)
        {
            deg++;
        }
    }
    return deg;
}

// Khai bao cau truc danh sach List
typedef struct
{
    int data[MAX_Length];
    int size;
} List;

// Tao danh sach rong
void init_list(List *list)
{
    list->size = 0;
}

// Lay mot dinh trong list vi tri i
int element_at(List list, int i)
{
    return list.data[i];
}

// Them mot dinh vao cuoi danh sach
void push_back(List *list, int x)
{
    list->size++;
    list->data[list->size] = x;
}

// Tim lang gieng cua dinh x
List neighbors(Graph G, int x)
{
    List L;
    init_list(&L);
    for (int i = 1; i <= G.n; i++)
    {
        if (adjacent(G, x, i))
        {
            push_back(&L, i);
        }
    }
    return L;
}

// In ra neighbors
void neighbors_result(Graph G)
{
    List L;
    init_list(&L);
    for (int i = 1; i <= G.n; i++)
    {
        L = neighbors(G, i);
        printf("Neighbors[%d] = [", i);
        for (int j = 1; j <= L.size; j++)
        {
            if (j == L.size)
                printf("%d]\n", element_at(L, j));
            else
                printf("%d ", element_at(L, j));
        }
    }
}

// in ra matrix dinh - dinh
void matrix(Graph G)
{
    printf("Matrix: Vertex - Vertext\n");
    for (int i = 1; i <= G.n; i++)
    {
        for (int j = 1; j <= G.n; j++)
        {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Graph G;
    read_file(&G);

    neighbors_result(G);

    matrix(G);
    return 0;
}