#include <iostream>
#include <vector>
using namespace std;

int main(){
    int bobs_friends;
    cin >> bobs_friends;
    
    vector<int> not_fof;
    vector<int> ppl;
    int num_of_not_fof = 0;
    int num_of_ppl = 0;
    int input;
    int num_of_inputs;
    for (int i = 0; i < bobs_friends; i++){
        cin >> input >> num_of_inputs;
        not_fof.push_back(input);
        num_of_not_fof++;
        
        for (int j = 0; j < num_of_inputs; j++){
            cin >> input;
            ppl.push_back(input);
        }
        num_of_ppl += num_of_inputs;
    }

    int num_of_fof = 0;
    for (int i = 0; i < num_of_ppl; i++){
        bool isFof = true;
        for (int j = 0; j < num_of_not_fof; j++){
            if (not_fof[j] == ppl[i]){
                isFof = false;
                break;
            }
        }

        if (isFof){
            not_fof.push_back(ppl[i]);
            num_of_fof++;
            num_of_not_fof++;
        }
    }

    cout << num_of_fof << endl;

    return 0;
}