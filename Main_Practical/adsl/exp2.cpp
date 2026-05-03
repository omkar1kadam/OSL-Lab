#include<iostream>
using namespace std;

#define MAX 100

typedef struct Node{
    char data;
    struct Node* left;
    strcut Node* right;
}NODE;

NODE* createNODE(char ch){
    NODE* newNode = new NODE;
    newNODE->data = ch;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

class NodeStack{
    NODE* arr[MAX];
    int top;

    public:
    NodeStack(){
        top = -1;
    }

    void push(NODE* n){
        if(!isFull()){
            cout<<"Stack OverFlow";
            return;
        }
        arr[++top] = n;
    }

    NODE* pop(){
        if(!isEmpty()){
            cout<<"Stack Underflow";
            return;
        }
        return arr[top--];
    }

    bool isEmpty(){
        return (top ==  -1);
    }

    bool isFull(){
        return (top == MAX - 1);
    }
}

class ExpressionTree {
    public:
        NODE* root;

        ExpressionTree(){
            root = NULL;
        }

        bool isOperand(char ch){
            return( 
                (ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9')
            );
        }

        bool isOperator(char ch){
            return(
                ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'
            );
        }

        void  buildFromPrefix(string prefix){
            NodeStack st;

            for(int i = prefix.length() -1; i>= 0; i--){
                char ch = prefix[i];

                if(isOperand(ch)){
                    st.push(createNODE(ch));
                } 
                else if (isOperator(ch)){
                    
                }
            }
        }
}