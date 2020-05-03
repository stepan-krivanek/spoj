//Christmas
#include <iostream>
using namespace std;

int partition(unsigned long int *a,int start,int end){
    unsigned long int pivot = a[end];
    //P-index indicates the pivot value index

    int P_index = start;
    int i;
    unsigned long int t; //t is temporary variable

    //Here we will check if array value is 
    //less than pivot
    //then we will place it at left side
    //by swapping 

    for (i = start; i < end; i++){
        if(a[i] <= pivot){
            t = a[i];
            a[i] = a[P_index];
            a[P_index] = t;
            P_index++;
        }
    }
    //Now exchanging value of
    //pivot and P-index
    t = a[end];
    a[end] = a[P_index];
    a[P_index] = t;

    //at last returning the pivot value index
    return P_index;
}

void quicksort(unsigned long int *a,int start,int end){
    if(start < end){
        int P_index = partition(a,start,end);
        quicksort(a,start,P_index-1);
        quicksort(a,P_index+1,end);
    }
}

int main(){
    int num_of_cases;
    cin >> num_of_cases;

    int num_of_soldiers;
    int num_of_kids;
    for (int i = 0; i < num_of_cases; i++){
        cin >> num_of_kids >> num_of_soldiers;
        unsigned long int kids[num_of_kids];

        unsigned long int height;
        for (int j = 0; j < num_of_kids; j++){
            cin >> height;
            kids[j] = height;
        }

        if (num_of_soldiers < 2){
            cout << 0 << endl;
            continue;
        }

        quicksort(kids, 0, num_of_kids-1);

        unsigned long int min = 1000000000;
        int last_index = num_of_soldiers - 1;
        int index = 0;
        unsigned long int height_diff;
        while (last_index < num_of_kids){
            height_diff = kids[last_index++] - kids[index++];
            if (height_diff < min){
                min = height_diff;
            }
        }

        cout << min << endl;
    }

    return 0;
}