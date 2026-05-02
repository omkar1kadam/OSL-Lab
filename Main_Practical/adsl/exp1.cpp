#include<iostream>
#include<cstring>
#include<ios>
#include<limits>
#define MAX 20
using namespace std;

typedef struct Node{
    Node* left;
    string word;
    string meaning;
    Node* right;
}NODE;

NODE* createNODE(string Gword,string Gmeaning){
    NODE* newNode = new NODE;
    newNode->word = Gword;
    newNode->meaning = Gmeaning;
    newNode->left = newNode->right = NULL;
    return newNode;
}

class Stack{
    NODE *stack[MAX];
    int top;

    public:
    Stack(){
        top = -1;
    }

    void push(NODE* val){
        if(!isFull()){
            stack[++top] = val;
        } else {
            cout<<"Stack is Full";
        }
    }

    NODE* pop(){
        if(!isEmpty()){
            return stack[top--];
        } else {
            cout<<"Stack is Empty";
        }
        return NULL;
    }

    bool isFull(){
        return (top == MAX-1);
    }

    bool isEmpty(){
        return (top == -1);
    }
};

class BinaryTree{
    private:
        NODE* root;
        Stack S;

    public:
        BinaryTree(){
            root = NULL;
        }

        void addNode(string word,string meaning){
            if (root == NULL){
                root = createNODE(word,meaning);
                return;
            }

            NODE* curr = root;

            while(true){
                if(word < curr->word){
                    if(curr->left == NULL){
                        curr->left = createNODE(word,meaning);
                        return;
                    }
                    curr = curr->left;
                }
                else if(word > curr->word){
                    if(curr->right == NULL){
                        curr->right = createNODE(word,meaning);
                        return;
                    }
                    curr = curr->right;
                } 
                else {
                    cout<<"Duplicate values";
                    return;
                }
            }    
        }

        void display(){
            inorder(root);
        }

        void inorder(NODE* root){
            if(root == NULL){
                return;
            }
            inorder(root->left);
            cout<<"["<<root->word<<"|"<<root->meaning<<"]"<<"->";
            inorder(root->right);
        }

        void deleteNode(string word){
            root = deleteNodeRec(root,word);
        }

        NODE* deleteNodeRec(NODE* root,string word){
            if(root == NULL){
                return NULL;
            }

            if(word < root->word){
                root->left = deleteNodeRec(root->left,word);
            } else if(word > root->word){
                root->right = deleteNodeRec(root->right,word);
            }

            else { // root is found 
                //case 1: 0 children
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    return NULL;
                }

                //case 2: 1 children
                if(root->left == NULL){
                    NODE* temp = root->right;
                    delete root;
                    return temp;
                }

                if(root->right == NULL){
                    NODE* temp = root->left;
                    delete root;
                    return temp;
                }

                //case 3: 2 children
                NODE* successor = findMin(root->right);
                root->word = successor->word;
                root->meaning = successor->meaning;

                root->right = deleteNodeRec(root->right, successor->word);

            }
            return root;   
        }

        NODE* findMin(NODE* root){
            while(root->left != NULL){
                root = root->left;
            }
            return root;
        }

        void seachNode(string word){
            int count = 0;
            if(root == NULL){
                return ;
            }

            NODE* curr = root;

            while(curr){
                count++;
                if(word == curr->word) {
                    cout<<"Count taken is: "<<count<<endl;
                    cout<<"Found "<<endl;
                    return;
                }
                else if(word < curr->word){
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                } 
            }
            cout<<"Not found"<<endl;
        }

        void updateNode(string word){
            if(root == NULL){
                return ;
            }

            NODE* curr = root;

            while(curr){
                if(word == curr->word) {
                    cout<<"Found "<<endl;
                    cout<<"Enter the meaning you want to update: ";
                    cin>>curr->meaning;
                    return;
                }
                else if(word < curr->word){
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                } 
            }
            cout<<"Not found"<<endl;
        }

        void displayAscBst(NODE* root){
            if(root){
                displayAscBst(root->left);
                cout<<"["<<root->word<<"|"<<root->meaning<<"]"<<"->";
                S.push(root);
                displayAscBst(root->right);
            }
        }

        void displayDescBst(){
            while(!S.isEmpty()){
                NODE* t = S.pop();
                cout<<"["<<t->word<<"|"<<t->meaning<<"]"<<"->";
            }
        }    

        NODE* returnRoot(){
            return root;
        }
};


int main(){
    cout<<"running"<<endl;
    BinaryTree bst;

    bst.addNode("mango", "root node");
bst.addNode("dog", "animal");
bst.addNode("tiger", "wild animal");
bst.addNode("ant", "small insect");
bst.addNode("horse", "fast animal");
bst.addNode("zebra", "striped animal");
bst.addNode("goat", "farm animal");
bst.addNode("lion", "king of jungle");
bst.addNode("yak", "mountain animal");


    bst.display();
    cout<<"Completed"<<endl;

    bst.deleteNode("dog");
    bst.display();
    cout<<"Completed"<<endl;

    cout<<"searching"<<endl;
    bst.seachNode("lion");
    cout<<"Completed"<<endl;

    // cout<<"updating"<<endl;
    // bst.updateNode("zebra");
    // cout<<"Completed"<<endl;

    bst.display();
    cout<<"Completed"<<endl;

    bst.displayAscBst(bst.returnRoot());
    cout<<"Completed"<<endl;
    bst.displayDescBst();
    cout<<"Completed"<<endl;
}