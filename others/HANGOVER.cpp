#include <iostream>
using namespace std;

int main(){
    double input;
    cin >> input;
    double table[275];
    table[0] = 0.5;
    int index = 0;
    
    while (input != 0){
        int i = 0;
        while (1){ //while condition not working?
            if (input < table[i]){ //i++ not working?
                break;
            }
            i++;
            if (i > index){
                index++;
                table[index] = table[index-1] + (double)1/(index + 2);
            }
        }
        
        int result = i + 1;
        cout << result << " card(s)" << endl;
        cin >> input;
    }

    return 0;
}