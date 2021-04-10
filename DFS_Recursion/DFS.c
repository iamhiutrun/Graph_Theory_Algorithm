#include <stdio.h>

#define MAX_Vertices 20
#define MAX_Length 20
#define MAX_Element 40

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

// in ra matrix dinh - dinh
void matrix(Graph G)
{
    printf("\nMatrix: Vertex - Vertext\n");
    for (int i = 1; i <= G.n; i++)
    {
        for (int j = 1; j <= G.n; j++)
        {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}

int mark[MAX_Vertices];
int parent[MAX_Vertices];
// Depth First Search
void depth_first_search(Graph G, int u, int p)
{
    if (mark[u])
    {
        return;
    }
    printf("Duyet: %d\n", u);
    mark[u] = 1;
    parent[u] = p;
    List list = neighbors(G, u);
    for (int i = 1; i <= list.size; i++)
    {
        depth_first_search(G, element_at(list, i), u);
    }
}

int main()
{
    Graph G;
    read_file(&G);

    //neighbors_result(G);
    int mark_dfs[MAX_Vertices];
    for (int i = 1; i <= G.n; i++)
    {
        mark[i] = 0;
        parent[i] = -1;
    }

    for (int i = 1; i <= G.n; i++)
    {
        if (mark[i] == 0)
        {
            depth_first_search(G, 1, 0);
        }
    }

    for (int i = 1; i <= G.n; i++)
    {
        printf("%d %d\n", i, parent[i]);
    }
    matrix(G);
    return 0;
}