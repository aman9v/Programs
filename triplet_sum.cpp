#include <iostream>
#include <algorithm>
using namespace std;

// program to find a triplet that sum to a given value.

void findTriplet(int A[], int size, int sum){
    sort(A, A+size); // nlogn time for sorting
    int left, right = -1; // initializing left and right
    for (int i = 0; i<size-2; i++){
        left = i+1, right = size - 1;
        while(left < right){
            if(A[i] + A[left] + A[right] == sum){
            cout << A[i] << " " << A[left] << " " << A[right];
            return;
            }
            else if(A[i] + A[left] + A[right] < sum) left += 1;
            else right -= 1;
            }
        
        }
    cout << " No such triplet exists";    

    }

int main() {

	int numbers[] = {1, 4, 45, 6, 10, 8};
	int size = sizeof(numbers)/sizeof(numbers[0]);
	int sum = 50;
	findTriplet(numbers, size, sum);
	return 0;

}