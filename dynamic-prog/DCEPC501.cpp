#include <iostream>
#define ll long long
using namespace std;

void print_table(ll int* table, int size){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < size; j++){
            cout << *(table + j*3 + i) << " ";
        }
        cout << endl;
    }
}

ll int max_value(ll int a, ll int b, ll int c){
    if (a > b && a > c){
        return a;
    }
    if (b > c){
        return b;
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    int num_of_examples;
    cin >> num_of_examples;

    for (int i = 0; i < num_of_examples; i++){
        int num_of_toys;
        cin >> num_of_toys;

        int toy;
        int toys[num_of_toys + 5];
        for (int j = 0; j < num_of_toys; j++){
            cin >> toy;
            toys[j] = toy;
        }
        for (int j = 0; j < 5; j++){
            toys[num_of_toys + j] = 0;
        }

        int num_of_moves = (num_of_toys + 5) / 2;
        ll int table[num_of_moves][3]; 
        int* ptr = &toys[0];
        ll int extra = 0;
        for (int j = 0; j < num_of_moves; j++){
            int index = 2*j;
            table[j][0] = toys[index] + extra;
            table[j][1] = toys[index] + toys[index+1] + extra;
            table[j][2] = toys[index] + toys[index+1] + toys[index+2] + extra;

            if (j > 1){
                extra = max_value(table[j][0], table[j-1][1], table[j-2][2]);
            } else {
                if (j == 0){
                    extra = table[0][0];
                } else {
                    extra = table[1][0] > table[0][1] ? table[1][0] : table[0][1];
                }
            }
        }
        
        cout << table[num_of_moves - 1][0] << endl;
    }


    return 0;
}