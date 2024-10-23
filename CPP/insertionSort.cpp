#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
  for (int i = 1; i < n; ++i)
  {
    int key = arr[i];
    int j = i - 1;

    /* Move elements of arr[0..i-1], that are
       greater than key, to one position ahead
       of their current position */
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void inputArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
}

int main()
{
  int n;
  cout << "Enter the number of element: ";
  cin >> n;

  int arr[n];
  cout << "Input the elements of array" << endl;
  inputArray(arr, n);

  // insertion Sort
  insertionSort(arr, n);

  cout << "printing the sorted array" << endl;
  for (int j = 0; j < n; j++)
  {
    cout << arr[j] << " ";
  }

  return 0;
}