#include<iostream>
#include<cstring>
using namespace std;

typedef struct Node{
    char key[20], meaning[100];
    struct Node *left, *right;
}NODE;

int height(NODE* T){
    if (T == NULL) {
        return 0;
    }
    int leftHeight = height(T->left);
    int rightHeight = height(T->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int getbalance(NODE* T){
    if (T == NULL){
        return 0;
    }
    return height(T->left) - height(T->right);
}


// LL
NODE* rightRotate(NODE* y){
    NODE* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

//RR
NODE* leftRotate(NODE* x){
    NODE* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

NODE* insert(NODE* root, char key[], char meaning[]){
    if(root == NULL){
        NODE* n = new NODE;
        strcpy(n->key,key);
        strcpy(n->meaning,meaning);
        n->left = n->right = NULL;
        return n;
    }

    if(strcmp(key,root->key) < 0){
        root->left = insert(root->left, key,meaning);
    } else if(strcmp(key,root->key) > 0){
        root->right = insert(root->right,key,meaning);
    } else{
        return root;
    }

    int balance = getbalance(root);

    // LL
    if(balance > 1 && strcmp(key,root->left->key) < 0){
        return rightRotate(root);
    }

    // RR
    if(balance < -1 && strcmp(key,root->right->key) > 0){
        return leftRotate(root);
    }

    if(balance > 1 && strcmp(key,root->left->key) > 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && strcmp(key,root->right->key) < 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(NODE* root){
    if(root) {
        inorder(root->left);
        cout << root->key << " : " << root->meaning << endl;
        inorder(root->right);
    }
}

// MAIN
int main() {
    NODE* root = NULL;
    int ch;
    char key[20], meaning[100];

    do {
        cout << "\n1.Insert\n2.Display\n3.Exit\n";
        cin >> ch;
        cin.ignore();

        switch (ch) {
        case 1:
            cout << "Enter key: ";
            cin.getline(key, 20);
            cout << "Enter meaning: ";
            cin.getline(meaning, 100);
            root = insert(root, key, meaning);
            break;

        case 2:
            inorder(root);
            break;
        }
    } while (ch != 3);

    return 0;
}