#include <iostream>
using namespace std;
int partision(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count=0;
    for (int i = s+1; i <=e; i++)
    {
         if(arr[i]<=pivot){
            count ++;
         }

         
    }
    int pivotindex=s+count;
    swap(arr[pivotindex],arr[s]);
    int i=s ,j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
    
}
void quicksort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partision(arr, s, e);
    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main()
{
    int arr[5] = {2, 4, 1, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}