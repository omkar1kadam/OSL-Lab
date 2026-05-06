void DFS_GAM(int v){
    if(!(v>=1 && v<=n)) return;

    visited[v] = 1;
    cout << Landmark[v-1] << " -> ";

    for(int w=1; w<=n; w++){
        if(GAM[v][w] == 1 && visited[w] == 0){
            DFS_GAM(w);
        }
    }
}

void DFS_GAL(int v){
    if(!(v>=1 && v<=n)) return;

    visited[v] = 1;
    cout << Landmark[v-1] << " -> ";

    NODE *curr = headerGAL[v].next;

    while(curr){
        if(visited[curr->val] == 0){
            DFS_GAL(curr->val);
        }
        curr = curr->next;
    }
}

void BFS_GAM(int v){
    if(!(v>=1 && v<=n)) return;

    Queue Qobj;
    Qobj.enqueue(v);
    visited[v] = 1;

    while(!Qobj.isEmpty()){
        v = Qobj.dequeue();
        if(v == -1) break;

        cout << Landmark[v-1] << " -> ";

        for(int w=1; w<=n; w++){
            if(GAM[v][w] == 1 && visited[w] == 0){
                Qobj.enqueue(w);
                visited[w] = 1;
            }
        }
    }
}

void BFS_GAL(int v){
    if(!(v>=1 && v<=n)) return;

    Queue Qobj;
    NODE *curr;

    Qobj.enqueue(v);
    visited[v] = 1;

    while(!Qobj.isEmpty()){
        v = Qobj.dequeue();
        if(v == -1) break;

        cout << Landmark[v-1] << " -> ";

        curr = headerGAL[v].next;

        while(curr){
            if(visited[curr->val] == 0){
                Qobj.enqueue(curr->val);
                visited[curr->val] = 1;
            }
            curr = curr->next;
        }
    }
}