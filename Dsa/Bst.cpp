#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int findLongestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftPath = findLongestPath(root->left);
    int rightPath = findLongestPath(root->right);

    return 1 + max(leftPath, rightPath);
}

int findMinimumValue(Node* root) {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return -1;
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root->data;
}

Node* mirrorImage(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* temp = root->left;
    root->left = mirrorImage(root->right);
    root->right = mirrorImage(temp);

    return root;
}

bool searchValue(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    if (value < root->data) {
        return searchValue(root->left, value);
    } else {
        return searchValue(root->right, value);
    }
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    // User input for constructing the binary search tree
    int numValues;
    cout << "Enter the number of values to insert: ";
    cin >> numValues;

    vector<int> values(numValues);
    cout << "Enter the values: ";
    for (int i = 0; i < numValues; i++) {
        cin >> values[i];
    }

    // Sort the values
    sort(values.begin(), values.end());

    // Construct the binary search tree
    for (int i = 0; i < numValues; i++) {
        root = insert(root, values[i]);
    }

    // i. Insert new node
    int newNodeValue;
    cout << "Enter the value of the new node to insert: ";
    cin >> newNodeValue;
    root = insert(root, newNodeValue);

    // ii. Find number of nodes in longest path
    int longestPath = findLongestPath(root);
    cout << "Number of nodes in the longest path: " << longestPath << endl;

    // iii. Minimum data value found in the tree
    int minimumValue = findMinimumValue(root);
    cout << "Minimum value in the tree: " << minimumValue << endl;
    
     // v. Search a value
    int valueToSearch;
    cout << "Enter a value to search in the tree: ";
    cin >> valueToSearch;

    bool found = searchValue(root, valueToSearch);

    if (found) {
        cout << "Value " << valueToSearch << " found in the tree." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the tree." << endl;
    }

    
    

    // iv. Change a tree so that the roles of the left and right pointers are swapped at every node
    root = mirrorImage(root);
    cout << "Inorder traversal of the mirror image tree: ";
    inorderTraversal(root);
    cout << endl;

   
    return 0;
}

