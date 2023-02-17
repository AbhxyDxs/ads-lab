#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Define the structure of the binary search tree
typedef struct BST {
    Node* root;
} BST;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
Node* insert(Node* node, int data) {
    // If the tree is empty, create a new node and make it the root
    if (node == NULL) {
        return createNode(data);
    }
    // Otherwise, recursively insert the new node into the appropriate subtree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to delete a node from the binary search tree
Node* delete(Node* node, int data) {
    // If the tree is empty, return NULL
    if (node == NULL) {
        return NULL;
    }
    // Otherwise, recursively delete the node from the appropriate subtree
    if (data < node->data) {
        node->left = delete(node->left, data);
    } else if (data > node->data) {
        node->right = delete(node->right, data);
    } else {
        // Case 1: Node has no children
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }
        // Case 2: Node has one child
        if (node->left == NULL) {
            Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            free(node);
            return temp;
        }
        // Case 3: Node has two children
        Node* temp = node->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }
    return node;
}

// Function to search for a node in the binary search tree
Node* search(Node* node, int data) {
    // If the tree is empty or the node has been found, return the node
    if (node == NULL || node->data == data) {
        return node;
    }
    // Otherwise, recursively search for the node in the appropriate subtree
    if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

// Function to print the nodes of the binary search tree in order
void inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Function to display the menu of options
void displayMenu() {
    printf("\n\nBinary Search Tree Operations:\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Search for a node\n");
    printf("4. Print the nodes of the binary search tree in order\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    // Create a new binary search tree
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;

    int choice, data;
    Node* searchResult;

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
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                tree->root = delete(tree->root, data);
                printf("Node with value %d has been deleted from the binary search tree.\n", data);
                break;
            case 3:
                printf("Enter the value of the node to search for: ");
                scanf("%d", &data);
                searchResult = search(tree->root, data);
                if (searchResult != NULL) {
                    printf("Node with value %d found in the binary search tree.\n", data);
                } else {
                    printf("Node with value %d not found in the binary search tree.\n", data);
                }
                break;
            case 4:
                printf("Inorder traversal of the binary search tree: ");
                inorder(tree->root);
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