#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to perform a search operation in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Example usage
int main() {
    struct Node* root = NULL;
    int keys[] = {10, 5, 15, 2, 7, 12, 20};
    int searchKey = 7;

    // Insert keys into the BST
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        root = insert(root, keys[i]);
    }

    // Perform search operation
    struct Node* result = search(root, searchKey);

    // Display result
    if (result != NULL) {
        printf("Key %d found in the BST.\n", searchKey);
    } else {
        printf("Key %d not found in the BST.\n", searchKey);
    }

    return 0;
}
