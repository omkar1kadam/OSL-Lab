#include<iostream>
using namespace std;

#define MAX 100

typedef struct Node{
    char data;
    struct Node* left;
    struct Node* right;
}NODE;

NODE* createNODE(char ch){
    NODE* newNode = new NODE;
    newNode->data = ch;
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
        if(isFull()){
            cout<<"Stack OverFlow";
            return;
        }
        arr[++top] = n;
    }

    NODE* pop(){
        if(isEmpty()){
            cout<<"Stack Underflow";
            return NULL;
        }
        return arr[top--];
    }

    bool isEmpty(){
        return (top ==  -1);
    }

    bool isFull(){
        return (top == MAX - 1);
    }
};

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
                    NODE* left = st.pop();
                    NODE* right = st.pop();

                    NODE* node = createNODE(ch);
                    node->left = left;
                    node->right = right;

                    st.push(node);
                }
            }
            root = st.pop();
        }

        void preOrder(){
            if (root == NULL) {
                return;
            }
            NodeStack st;
            st.push(root);

            while(!st.isEmpty()){
                NODE* temp = st.pop();
                cout<< temp->data <<" ";

                if(temp->right != NULL){
                    st.push(temp->right);
                }
                if(temp->left != NULL){
                    st.push(temp->left);
                }
            }
        }

        void inOrder(){
            NodeStack st;
            NODE* curr = root;

            while(curr != NULL || !st.isEmpty()){
                while(curr != NULL){
                    st.push(curr);
                    curr = curr->left;
                }

                curr = st.pop();
                cout<< curr->data <<" ";
                curr = curr->right;
            }
        }

        void postOrder(){

            if(root == NULL){
                return;
            }
            NodeStack s1;
            NodeStack s2;

            s1.push(root);

            while(!s1.isEmpty()){
                NODE* temp = s1.pop();
                s2.push(temp);

                if(temp->left != NULL){
                    s1.push(temp->left);
                }
                if(temp->right != NULL){
                    s1.push(temp->right);
                }
            }

            while(!s2.isEmpty()){
                cout << s2.pop()->data << " ";
            }
        }
};


int main(){
    ExpressionTree Et;

    string prefix = "+--a*bc/def";
    Et.buildFromPrefix(prefix);
    Et.preOrder();
    cout<<endl;
    Et.inOrder();
    cout<<endl;
    Et.postOrder();
    return 0;
}
