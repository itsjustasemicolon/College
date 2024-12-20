#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void findPreSuc(Node* root, Node** pre, Node** suc, int key) {
    if (root == NULL)
        return;
    if (root->key == key) {
        if (root->left != NULL) {
            Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            *pre = temp;
        }
        if (root->right != NULL) {
            Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            *suc = temp;
        }
        return;
    }
    if (key < root->key) {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else {
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, key;
    Node *pre, *suc;

    while (1) {
        printf("\n1. Create/Insert\n2. Search\n3. Find In-order Predecessor and Successor\n4. Insert Key\n5. Delete Key\n6. Display In-order\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                Node* found = search(root, key);
                if (found)
                    printf("Key found: %d\n", found->key);
                else
                    printf("Key not found\n");
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                pre = suc = NULL;
                findPreSuc(root, &pre, &suc, key);
                if (pre)
                    printf("Predecessor: %d\n", pre->key);
                else
                    printf("No Predecessor\n");
                if (suc)
                    printf("Successor: %d\n", suc->key);
                else
                    printf("No Successor\n");
                break;
            case 4:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 5:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 6:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
