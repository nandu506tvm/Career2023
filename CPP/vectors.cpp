#include <iostream>
#include <vector>
#include <string>

using namespace std;

double average(vector<int> & salary) {

    double result = 0.0;
    unsigned int vecSize = (salary.size()) - 2;
    int min = salary[0];
    int max = salary[1];

    /* Find the minimum and maximum */
    for (auto element: salary) {
        if (element < min) {
            min = element;
        }
        else if (element > max) {
            max = element;
        }
    }

    /* Calulcate the average excluding min,max */
    for (auto element: salary) {
        if ((element != min) && (element != max)) {
            result += element;
        }
    }
    return result/vecSize;
}

int main(int argc, char const *argv[]) {

    vector<int> salary= {4000,3000,1000,2000};
    cout << average(salary) << endl;

    return 0;
}

