#include<bits/stdc++.h>

using namespace std;

void merge(int arr[] , int low , int mid , int high){

    int i, j, k;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int l[n1], r[n2];

    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[low + i];
    }

    for (int j = 0; j < n2; j++)
    {
        r[j] = arr[mid+ j + 1];
    }

    i = 0;
    j = 0;
    k = low;

    while(i<n1&&j<n2){
        if(l[i]<=r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while(i<n1){

        arr[k] = l[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int low , int high){

    if(low<high){
        int mid = low + (high - low) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


int main (){

    int arr[] = {4, 56, 6, 34, 2, 9, 0};

    mergesort(arr, 0, 7);

    for (int i = 0; i <  7; i++)
    {
        cout << arr[i] << " ";
    }
    
}