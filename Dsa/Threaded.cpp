#include <iostream>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;  // Threaded flag
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory allocation error!" << endl;
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    newNode->isThreaded = false;
    return newNode;
}

// Function to insert a new node in the binary search tree
Node* insertNode(Node* root, int value) {
    // If the tree is empty, create a new node and set it as the root
    if (root == NULL) {
        return createNode(value);
    }

    // Perform recursive insertion
    if (value < root->data) {
        // If the value is less than the root's data, insert it in the left subtree
        root->left = insertNode(root->left, value);
        if (root->isThreaded) {
            // If the left child is threaded, update the thread to the newly inserted node
            root->left->right = root;
            root->left->isThreaded = true;
            root->isThreaded = false;
        }
    } else if (value > root->data) {
        // If the value is greater than the root's data, insert it in the right subtree
        if (root->isThreaded) {
            // If the right child is threaded, follow the thread to the next node
            root = root->right;
            root->right = insertNode(root->right, value);
            root->isThreaded = false;
        } else {
            // If the right child is not threaded, perform recursive insertion
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

// Function to find the leftmost node in the threaded binary search tree
Node* findLeftmostNode(Node* node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to perform in-order traversal without using a stack
void inOrderTraversal(Node* root) {
    Node* current = findLeftmostNode(root);
    while (current != NULL) {
        cout << current->data << " ";
        if (current->isThreaded) {
            current = current->right;
        } else {
            current = findLeftmostNode(current->right);
        }
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "------------------------" << endl;
        cout << "Threaded Binary Search Tree Menu" << endl;
        cout << "------------------------" << endl;
        cout << "1. Insert a new node" << endl;
        cout << "2. In-order traversal" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "In-order traversal: ";
                inOrderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
