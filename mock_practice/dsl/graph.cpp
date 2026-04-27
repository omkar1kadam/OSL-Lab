#include<iostream>
#include<ios>
#include<limits>
#include<cstring>
#define MAX 20
using namespace std;

typedef struct Node{
	int val;
	struct Node *next;
}NODE;

class Queue{
	private:
		int Q[MAX];
		int front , rear;
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
				if(rear == -1){ // brand new 
					front = rear = 0;
					Q[rear] = val;
				} else {
				Q[++rear] = val;
				}
			} else {
				cout<<"Queue is Full";
			}
		}
		
		int dequeue(){
			int val;
			if(!isEmpty()){
				if (front == rear){ //single 
					val = Q[front];
					front = rear = -1;
					return val;
				} else {
					return Q[front++];
				}
			} else {
				cout<<"Queue is Empty";
			}
			return val;
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
			for(int i=0; i<10; i++){
				for(int j=0; j<10; j++){
					GAM[i][j] =0;
				}
			}
			for(int i=0; i<10; i++){
				visited[i] = 0;
				headerGAL[i].val =i;
				headerGAL[i].next = NULL;
			}
		}

		void initGraph(){
			for(int i=0; i<10; i++){
				for(int j=0; j<10; j++){
					GAM[i][j] =0;
				}
			}
			for(int i=0; i<10; i++){
				visited[i] = 0;
				headerGAL[i].val =i;
				headerGAL[i].next = NULL;
			}
		}

		void CreateGraph(){
			bool flag = true;
			int s,d;

			NODE *p, *curr;

			cout<<"Enter the graph details";
			cout<<"How  many nodes are there in the graph";
			cin>>n;

			while(flag){
				cout<<"Enter the souce";
				cin>>s;
				cout<<"Enter the destination";
				cin>>d;

				GAM[s][d] = 1;

				p = new NODE;
				p->val = d;
				p->next = NULL;

				if(headerGAL[s].next == NULL){
					headerGAL[s].next = p;
				}else{
					curr = headerGAL[s].next;
					while(curr->next != NULL){
						curr = curr->next;
					}
					curr->next = p;
				}

				cout<<"Do you want to add more edges yes:1 ,,, No: 0";
				cin>>flag;
			}
		}

		void displayGAM(){
			cout<<"\nThe Graph as adjacency matrix\n\t";
			for(int i=1; i<=n; i++){
				cout<<Landmark[i-1]<<"\t";
			}

			for(int i=1;i<=n; i++){
				cout<<"\n"<<Landmark[i-1]<<"	";
				for(int j=1; j<=n; j++){
					cout<<GAM[i][j]<<"    ";
				}
			}
		}

		void displayGAL(){
			NODE *curr;
			cout<<"The graphh adjacency list is:";
			for(int i=1;i<=n;i++){
				cout<<"\n["<<Landmark[i-1]<<"|"<<headerGAL[i].next<<"]->";
				curr=headerGAL[i].next;
				while(curr){
					cout<<"["<<Landmark[curr->val-1]<<"|"<<curr->next<<"]->";
					curr = curr->next;
				}
				cout<<"NULL";
			}
		}

		void DFS(int v){
			if(!(v>=1 && v<= n)){
				return;
			}

			visited[v] = 1;
			cout<<Landmark[v-1]<<"->";
			for(int w=1; w<=n; w++){
				if(GAM[v][w] == 1 && visited[w] == 0){
					DFS(w);
				}
			}
		}

		void initVISITED(){
			for(int i=1;i<10;i++)
				visited[i]=0;
		}

		void BFS(int v){
			Queue Qobj;
			NODE *curr;

			if(!(v>=1 && v<= n)){
				return;
			}

			Qobj.enqueue(v);
			visited[v] = 1;

			while(!Qobj.isEmpty()){
				v = Qobj.dequeue();
				cout<<Landmark[v-1]<<"->";
				curr=headerGAL[v].next;

				while(curr){
					if(visited[curr->val] == 0){
						Qobj.enqueue(curr->val);
						visited[curr->val] = 1;
					}
					curr  = curr->next;
				}
			}
		}
};


int main(){
	GraphLandmarks G;
	int choice=0,s;

	while(choice != 6){
		cout<<"\n****************Graph Operations (DFS/BFS)**************";
		cout<<"\n1. Create Graph";
		cout<<"\n2. Display Graph as Adejececny Matrix";
		cout<<"\n3. Display Graph as Adejececny List";
		cout<<"\n4. Traveral Graph DFS";
		cout<<"\n5. Traveral Graph BFS";
		cout<<"\n6. Exit";
		cout<<"\nWhat operation you want::";
		cin>>choice;
		
		switch(choice){
			case 1:
				G.initGraph();
				G.CreateGraph();
				break;
			case 2:
				cout<<"\nDisplay Graph as Adejececny Matrix\n";
				G.displayGAM();
				break;
			case 3:
				cout<<"\nDisplay Graph as Adejececny List\n";
				G.displayGAL();
				break;
			case 4:
				cout<<"\nDFS on Graph Adejececny Matrix\n";
				cout<<"\nWhat is starting vertex::";
				cin>>s;
				G.initVISITED();
				G.DFS(s);
				break;
			case 5:
				cout<<"\nBFS on Graph Adejececny List\n";
				cout<<"\nWhat is starting vertex::";
				cin>>s;
				G.initVISITED();
				G.BFS(s);
				break;
			
			case 6:
				cout<<"\nThanks for using application!!";
				break;
			default:
				cout<<"\nWrong Choice!!";
		}
	}

	return 0;
}



























