#include<iostream>
#include<ios>
#include<limits>
#include<cstring>
#define MAX 20
using namespace std;

typedef struct Node{
    int val;
    struct Node* next;
}NODE;

class Queue{
    
    private:
        int Q[MAX];
        int front,rear;

    public:
        Queue(){
            front = rear = -1;
        }

        bool isEmpty(){
            return (front == -1);
        }

        bool isFull(){
            return (rear == MAX-1);
        }

        void enqueue(int val){
            if(!isFull()){
                if(rear == -1){
                    front = rear =0;
                } else {
                    rear++;
                }
                Q[rear] = val;
            } else {
                cout<< "Queue  is Full";
            }
        }

        int dequeue(){
            if(!isEmpty()){
                int val = Q[front];
                if(front = rear){
                    front = rear = -1;
                } else {
                    front ++;
                }
                return val;
            } else {
                cout<<"Queue is Empty";
                return -1;
            }
        }
};

class GraphLandmarks{
    private:
        int GAM[10][10];
        int n;
        int visited[10];
        NODE headerGAL[10];

        string Landmark[10] = {"Admin","Canteen","Sports","Workshop"};

    public:
        GraphLandmarks(){
            initGraph();
        }

        void initGraph(){
            for(int i=0; i<10; i++){
                for(int j=0; j<10; j++){
                    GAM[i][j] = 0;
                }
            }

            for(int i=0; i<10; i++){
                visited[i] = 0;
                headerGAL[i].val = i;
                headerGAL[i].next = NULL;
            }
        }

        void CreateGraph(){
            bool flag = true;
            int s,d;
            NODE *p, *curr;

            cout<<"Enter the graph details\n";
			cout<<"How many nodes are there in the graph: ";
			cin>>n;

            while(flag){
                cout<<"Enter the source (1 to "<<n<<"): ";
				cin>>s;
				cout<<"Enter the destination: ";
				cin>>d;

                GAM[s][d] = 1;

                p= new NODE;
                p->val = d;
                p->next = NULL;

                if(headerGAL[s].next ==NULL){
                    headerGAL[s].next = p;
                } else {
                    curr = headerGAL[s].next;
                    while(curr->next != NULL){
                        curr = curr->next;
                    }
                    curr->next = p;
                }

                cout<<"Add more edges? yes:1 no:0 : ";
				cin>>flag;
            }
        }
};