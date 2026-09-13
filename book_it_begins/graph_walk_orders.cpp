// graph_walk_orders.cpp

#include <conio.h>
#include <locale.h>

#define LOG printf
#define MAX_QUEUE_SIZE 256

typedef struct node
{
    int id;
    int child_count;
    struct node** child; /* Массив указателей на узлы-потомки */
    struct node*  parent;
} node_t;

void iteratee(node_t* n)
{
    if(n->parent) LOG("%d->%d\n", n->id, n->parent->id);
    else  LOG("%d\n", n->id);
}

void walkPostOrder(node_t* root, void (*visit)(node_t*))
{
    if (root == NULL) return;

    /* Спуск по потомкам  */
    for (int i = 0; i < root->child_count; ++i) walkPostOrder(root->child[i], visit);

    visit(root);
}

void walkPreOrder(node_t* root, void (*visit)(node_t*))
{
    if (root == NULL) return;

    visit(root); /* Вызов обработчика ДО обхода потомков */

    for (int i = 0; i < root->child_count; ++i) walkPreOrder(root->child[i], visit);
}

void walkInOrder(node_t* root, void (*visit)(node_t*))
{
    if (root == NULL) return;

    /* Рекурсивный обход самого первого потомка (индекс 0) */
    if (root->child_count > 0) walkInOrder(root->child[0], visit);


    visit(root); /* Визит текущего узла */

    /* Рекурсивный обход всех последующих потомков (индексы от 1 до N-1) */
    for (int i = 1; i < root->child_count; ++i) walkInOrder(root->child[i], visit);
}

void walkBFS(node_t* root, void (*visit)(node_t*))
{
    if (root == NULL) return;

    node_t* queue[MAX_QUEUE_SIZE];
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail)
    {
        node_t* item = queue[head++];
        visit(item);

        for (int i = 0; i < item->child_count; ++i)
        {
            if (tail < MAX_QUEUE_SIZE) queue[tail++] = item->child[i];
        }
    }
}


void init_node(node_t* n, int id, int child_count, node_t** child)
{
    n->id = id;
    n->child_count = child_count;
    n->child = child;
    n->parent = NULL;

    for (int i = 0; i < child_count; ++i) child[i]->parent = n;
}
int main(void)
{
    /*
     * Инициализация тестового графа (дерева):
     *        [10] (Корень)
     *       /    \
     *    [20]    [30]
     *            /  \
     *          [40] [50]
     */

    node_t n20, n40, n50, n30, root;

    /* Сборка графа снизу вверх */
    init_node(&n20, 20, 0, NULL);
    init_node(&n40, 40, 0, NULL);
    init_node(&n50, 50, 0, NULL);

    node_t* c30[] = { &n40, &n50 };
    init_node(&n30, 30, 2, c30);

    node_t* c10[] = { &n20, &n30 };
    init_node(&root, 10, 2, c10);

    LOG("; --- DFS PostOrder Walk ---\n; This is Halftone lang code. Put it to https://arborjs.org/halfviz/ graph visualizer.\n");
    walkPostOrder(&root, iteratee);

    LOG("; --- DFS PreOrder Walk ---\n; This is Halftone lang code. Put it to https://arborjs.org/halfviz/ graph visualizer.\n");
    walkPreOrder(&root, iteratee);

    LOG("; --- DFS InOrder Walk ---\n; This is Halftone lang code. Put it to https://arborjs.org/halfviz/ graph visualizer.\n");
    walkInOrder(&root, iteratee);

    LOG("; --- BFS Walk ---\n; This is Halftone lang code. Put it to https://arborjs.org/halfviz/ graph visualizer.\n");
    walkBFS(&root, iteratee);

    getch();
    return 0;
}
