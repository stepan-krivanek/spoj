#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    bool visited = false;
    vector<Node*> kids;
};

int BFS(Node nodes[], int length){
    int max = 0;

    for (int i = 0; i < length; i++){
        if (nodes[i].visited == false){
            nodes[i].visited = true;
            max += 1;

            queue<Node*> q;
            q.push(&nodes[i]);

            while (!q.empty()){
                Node * current = q.front();
                q.pop();

                for (int j = 0; j < current->kids.size(); j++){
                    Node * node = current->kids.at(j);

                    if (node->visited == false){
                        node->visited = true;
                        q.push(node);
                    }
                }
            }
        }
    }

    return max;
}

int main(){
    int cases;
    cin >> cases;

    int friends;
    int relations;
    for (int i = 0; i < cases; i++){
        cin >> friends >> relations;
        Node arr[friends];

        int f1, f2;
        for(int j = 0; j < relations; j++){
            cin >> f1 >> f2;

            arr[f1].kids.push_back(&arr[f2]);
            arr[f2].kids.push_back(&arr[f1]);
        }

        cout << BFS(arr, friends) << endl;
    }

    return 0;
}