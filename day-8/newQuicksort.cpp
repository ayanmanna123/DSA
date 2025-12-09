#include <bits/stdc++.h>
using namespace std;

int pertition(vector<int> &arr,int s, int e){

    int pivotelement = arr[e];
    int point =s;
    for(int i=s;i<e;i++){
        if(arr[i]<pivotelement){
            swap(arr[point],arr[i]);
            point++;
        }
    }
    swap(arr[point],arr[e]);
    return point;
}

void quickSort(vector<int> &arr,int s, int e){

    if(s>=e){
        return;
    }
    int pivotindx= pertition(arr,s,e);
    quickSort(arr,s,pivotindx-1);
    quickSort(arr,pivotindx+1,e);


}

int main() {
    vector<int>arr={5,3,6,2,4,1};
    quickSort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
        cout<<" ";
    }

}