#include <iostream>
#include <string>
#include <vector>

using namespace std;

double average(vector<int> &salary) {
    double result = 0.0;
    unsigned int vecSize = (salary.size()) - 2;
    int min = salary[0];
    int max = salary[1];

    /* Find the minimum and maximum */
    for (auto element : salary) {
        if (element < min) {
            min = element;
        } else if (element > max) {
            max = element;
        }
    }

    /* Calulcate the average excluding min,max */
    for (auto element : salary) {
        if ((element != min) && (element != max)) {
            result += element;
        }
    }
    return result / vecSize;
}

int main(int argc, char const *argv[]) {

    // Initialize the array with size 10 and all elements set to 7.
    vector<int> salary(10, 7);

    // pop_back the last element
    salary.pop_back();

    
    salary.push_back(4000);
    salary.push_back(3000);
    salary.push_back(1000);
    salary.push_back(2000);

    // This will show the current capacity of the vector
    cout << salary.capacity() << endl;

    // Call the function to calculate the average
    cout << average(salary) << endl;

    return 0;
}
