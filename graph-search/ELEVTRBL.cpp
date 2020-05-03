#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int BFS(int f, int s, int g, int u, int d){
    bool visited[f];
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;

    bool reached = false;
    int moves = -1;
    while(!q.empty()){
        moves += 1;

        int size = q.size();
        for (int s = 0; s < size; s++){
            int current = q.front();
            q.pop();

            if (current == g){
                reached = true;
                break;
            }

            int next = current + u;
            if (visited[next] == false && next >= 0 && next < f){
                visited[next] = true;
                q.push(next);
            }

            next = current - d;
            if (visited[next] == false && next >= 0 && next < f){
                visited[next] = true;
                q.push(next);
            }
        }

        if (reached){
            break;
        }
    }

    if (reached){
        return moves;
    }

    return -1;
}

int main(){
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    int clicks = BFS(f, s-1, g-1, u, d);
    
    if (clicks == -1){
        cout << "use the stairs" << endl;
    } else {
        cout << clicks << endl;
    }

    return 0;
}