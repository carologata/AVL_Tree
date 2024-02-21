/* Code originally from Steve Lorimer
https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
The code was originally in cpp
*/

#include "binary_tree.h"

t_tree_node* createNode(int data) {
    t_tree_node* newNode = (t_tree_node*)malloc(sizeof(t_tree_node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int maxDepth(t_tree_node* n) {
    if (n == NULL)
        return 0;
    int leftDepth = maxDepth(n->left);
    int rightDepth = maxDepth(n->right);
    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

void printTree(t_tree_node* n) {
    if (n == NULL)
        return;

    int depth = maxDepth(n);

    int lastLevel = 0;
    int offset = (1 << depth) - 1;

    // using a queue for breadth-first traversal
    struct Queue {
        t_tree_node* node;
        int level;
        struct Queue* next;
    } * front = NULL, * rear = NULL;

    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->node = n;
    newNode->level = lastLevel;
    newNode->next = NULL;
    front = rear = newNode;

    while (front != NULL) {
        t_tree_node* current = front->node;
        int currentLevel = front->level;

        if (lastLevel != currentLevel) {
            printf("\n");
            lastLevel = currentLevel;
            offset = (1 << (depth - currentLevel)) - 1;
        }

        if (current != NULL) {
            printf(" %*s%d%*s", offset, " ", current->data, offset, " ");
            if (current->left != NULL) {
                struct Queue* leftNode = (struct Queue*)malloc(sizeof(struct Queue));
                leftNode->node = current->left;
                leftNode->level = lastLevel + 1;
                leftNode->next = NULL;
                rear->next = leftNode;
                rear = leftNode;
            }
            if (current->right != NULL) {
                struct Queue* rightNode = (struct Queue*)malloc(sizeof(struct Queue));
                rightNode->node = current->right;
                rightNode->level = lastLevel + 1;
                rightNode->next = NULL;
                rear->next = rightNode;
                rear = rightNode;
            }
        }
        struct Queue* temp = front;
        front = front->next;
        free(temp);
    }
    printf("\n");
}

/* int main() {
    
    t_tree_node* head = createNode(10);
    head->left = createNode(1);
    head->right = createNode(2);
    head->left->left = createNode(3);
    head->left->right = createNode(4);
    head->right->left = createNode(5);
    head->right->right = createNode(6);

    printTree(head);

    return 0;
} */
