#include <iostream>
#define ll long long
using namespace std;

int main(){
    int num_of_subjects;
    cin >> num_of_subjects; 

    int num_of_monsters;
    for (int subject = 1; subject <= num_of_subjects; subject++){
        cin >> num_of_monsters;
        
        ll int monster;
        ll int take = 0;
        ll int tmp;
        ll int not_take = 0;
        for (int i = 0; i < num_of_monsters; i++){
            cin >> monster;

            tmp = not_take;
            not_take = take > not_take ? take : not_take;
            take = tmp + monster;
        }

        cout << "Case " << subject << ": " << (take > not_take ? take : not_take) << endl;
    }
    
    return 0;
}