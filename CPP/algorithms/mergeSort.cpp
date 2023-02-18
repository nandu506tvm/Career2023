/* Merge sort takes O(nlogn) time - Divide and conquer algorithm*/

#include <iostream>

using namespace std;

/* Merging array takes O(n/2) + O(n/2) = O(n) time */
/* Space complexity O(n) */
void merge_sorted_array(int A[], int low, int high, int mid)
{
    int list1ptr = low;
    int list2ptr = mid +1;
    int resultIndex = low;
    int size = low + high +1;
    int result[size] ;

    while (list1ptr <= mid && list2ptr <= high)
    {
        if (A[list1ptr] < A[list2ptr])
        {
            result[resultIndex] = A[list1ptr];
            resultIndex++;
            list1ptr++;
        }
        else
        {
            result[resultIndex] = A[list2ptr];
            resultIndex++;
            list2ptr++;
        }
    }
    while (list1ptr <= mid)
    {
        result[resultIndex] = A[list1ptr];
        resultIndex++;
        list1ptr++;
    }
    while (list2ptr <= high)
    {
        result[resultIndex] = A[list2ptr];
        resultIndex++;
        list2ptr++;
    }

    // Copy the resultant array to main array.
    for (int i = low; i < resultIndex; i++)
    {
        A[i] = result[i];
    }
}


void merge_sort(int arr[], int lindex, int  rindex)
{
    /* Base case*/
    if (lindex >= rindex) return;
   
    /* split the array using mid  and assume recursion will sort the two arrays*/ 
    int mid = (lindex+rindex)/2;
    merge_sort(arr, lindex, mid);
    merge_sort(arr, mid+1, rindex);
    
    /* Merge the two sorted arrays*/
    merge_sorted_array(arr, lindex, rindex, mid);
   
}

int main(int argc, char const *argv[])
{
    int arr_size;

    cout << "Enter input array length: ";
    cin >> arr_size;

    int arr[arr_size];
    cout << "Enter " << arr_size << " elements: \n";
    for (int j=0; j< arr_size; j++)
    {
        cin >> arr[j]; 
    }

    merge_sort(arr, 0, arr_size-1);
    for (int i=0; i<arr_size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}
