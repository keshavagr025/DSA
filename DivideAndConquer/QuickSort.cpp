// #include <iostream>
// using namespace std;

// void PrintArr(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     cout << endl;
    
// }

// int partition(int arr[], int si, int ei)
// {
//     int i = si - 1;
//     int pivot = arr[si];

//     for (int j = si; j < ei; j++)
//     {
//         if(arr[j] <= pivot)
//         {
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }

//     i++;
//     swap(arr[i], arr[ei]);

//     return i;
    
// }

// void quickSort(int arr[], int si, int ei)
// {
//     if( si >= ei)
//     {
//         return;
//     }

//     int pivotIdx = partition(arr, si, ei);

//     quickSort(arr, si, pivotIdx - 1);
//     quickSort(arr, pivotIdx + 1, ei);
// }

// int main()
// {
//     int arr[] = {5,9,87,6,4,3,5};
//     int n = 7;

//     quickSort(arr, 0 , n-1);
//     PrintArr(arr, n);
// }

#include <iostream>
using namespace std;

void PrintArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int si, int ei)
{
    int pivot = arr[si]; // Choosing the first element as the pivot
    int i = si;          // Pointer for elements smaller than pivot

    for (int j = si + 1; j <= ei; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i], arr[si]); // Place the pivot in its correct position
    return i; // Return the index of the pivot
}

void quickSort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int pivotIdx = partition(arr, si, ei);

    quickSort(arr, si, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, ei);
}

int main()
{
    int arr[] = {5, 9, 87, 6, 4, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    PrintArr(arr, n);

    return 0;
}
