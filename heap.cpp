#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[],int high , int i){
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if(left<high &&arr[left]>arr[largest]){
        largest = left;
    }
    if(right<high &&arr[right]>arr[largest]){
        largest = right;
    }
    if (largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr, high, largest);
    }
}

void heapsort(int arr[],int low , int high){

    for(int i = (high/2)-1 ;i>=0;i--){
        heapify(arr, high, i);
    }
    for (int i = high - 1; i > 0; i --){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main (){

    int arr[] = {4, 56, 6, 34, 2, 9, 0};

    heapsort(arr, 0, 7);

    for (int i = 0; i <  7; i++)
    {
        cout << arr[i] << " ";
    }
    
}