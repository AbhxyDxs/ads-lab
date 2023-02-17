#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Definition of a binary search tree
typedef struct BST {
    Node* root;
} BST;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into a binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform an inorder traversal of a binary search tree
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform a preorder traversal of a binary search tree
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform a postorder traversal of a binary search tree
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the menu of options
void displayMenu() {
    printf("\n\nBinary Search Tree Traversal:\n");
    printf("1. Insert a node\n");
    printf("2. Inorder traversal\n");
    printf("3. Preorder traversal\n");
    printf("4. Postorder traversal\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    // Create a new binary search tree
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;

    int choice, data;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value of the new node: ");
                scanf("%d", &data);
                tree->root = insert(tree->root, data);
                printf("Node with value %d has been inserted into the binary search tree.\n", data);
                break;
            case 2:
                printf("Inorder traversal of the binary search tree: ");
                inorder(tree->root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal of the binary search tree: ");
                preorder(tree->root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal of the binary search tree: ");
                postorder(tree->root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}