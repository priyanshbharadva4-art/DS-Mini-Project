#include <stdio.h>
#include <stdlib.h>

/* Order */
struct Order {
    int id, price, qty;
};

/* Queue */
struct Queue {
    struct Order a[10];
    int front, rear;
};

/* Stack */
struct Stack {
    struct Order a[10];
    int top;
};

/* Tree */
struct Node {
    int price;
    struct Node *left, *right;
};

/* Add order to Queue */
void enqueue(struct Queue *q, struct Order o) {
    if (q->rear == 9)
        printf("Queue Full\n");
    else
        q->a[++q->rear] = o;
}

/* Display Queue */
void display(struct Queue q) {
    int i;
    for (i = q.front; i <= q.rear; i++)
        printf("ID:%d  Price:%d  Qty:%d\n",
               q.a[i].id, q.a[i].price, q.a[i].qty);
}

/* Add cancelled order to Stack */
void push(struct Stack *s, struct Order o) {
    if (s->top < 9)
        s->a[++s->top] = o;
}

/* BST insertion */
struct Node* insert(struct Node *root, int price) {
    if (root == NULL) {
        root = malloc(sizeof(struct Node));
        root->price = price;
        root->left = root->right = NULL;
        return root;
    }

    if (price < root->price)
        root->left = insert(root->left, price);
    else if (price > root->price)
        root->right = insert(root->right, price);

    return root;
}

/* Display prices in sorted order */
void inorder(struct Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->price);
        inorder(root->right);
    }
}

/* Match Buy and Sell orders */
void match(struct Queue *buy, struct Queue *sell) {
    int i, j, qty;

    for (i = buy->front; i <= buy->rear; i++) {
        for (j = sell->front; j <= sell->rear; j++) {

            if (buy->a[i].qty > 0 &&
                sell->a[j].qty > 0 &&
                buy->a[i].price >= sell->a[j].price) {

                qty = buy->a[i].qty < sell->a[j].qty ?
                      buy->a[i].qty : sell->a[j].qty;

                printf("\nTRADE: %d shares at Rs.%d\n",
                       qty, sell->a[j].price);

                buy->a[i].qty -= qty;
                sell->a[j].qty -= qty;
            }
        }
    }
}

int main() {
    struct Queue buy = { .front = 0, .rear = -1 };
    struct Queue sell = { .front = 0, .rear = -1 };
    struct Stack cancelled = { .top = -1 };
    struct Node *root = NULL;

    struct Order b1 = {1, 105, 100};
    struct Order b2 = {2, 102, 50};

    struct Order s1 = {3, 100, 60};
    struct Order s2 = {4, 104, 40};

    /* Add Buy Orders */
    enqueue(&buy, b1);
    enqueue(&buy, b2);

    /* Add Sell Orders */
    enqueue(&sell, s1);
    enqueue(&sell, s2);

    /* Store prices in BST */
    root = insert(root, 105);
    root = insert(root, 102);
    root = insert(root, 100);
    root = insert(root, 104);

    printf("BUY ORDERS\n");
    display(buy);

    printf("\nSELL ORDERS\n");
    display(sell);

    printf("\nMATCHING ORDERS");
    match(&buy, &sell);

    printf("\n\nSORTED PRICES (BST): ");
    inorder(root);

    /* Example cancelled order */
    push(&cancelled, b2);

    printf("\n\nCancelled Order: ID %d\n",
           cancelled.a[cancelled.top].id);

    printf("\nTrader Graph:\n");
    printf("Trader 1 -- Trader 2 -- Trader 3\n");

    return 0;
}