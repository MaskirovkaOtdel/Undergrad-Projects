#include <iostream>
using namespace std;

void Matrix() {
    const int size = 5; 
    int arr[size] = {2, 4, 6, 8, 10}; 
    
    int sum = 0;
    int min = arr[0];
    int max = arr[0];
    
    
    for (int i = 0; i < size; i++) {
        sum += arr[i]; 
        
        
        if (arr[i] < min) {
            min = arr[i];
        }
        
        
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    
    cout << "Sum is: " << sum << endl;
    cout << "Minimum is: " << min << endl;
    cout << "Maximum is: " << max << endl;
}

int main() {
    Matrix(); 
    return 0;
}
