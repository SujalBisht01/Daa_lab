#include<bits/stdc++.h>

using namespace std;

void countsort(int arr[], int n , int max ){

    int count[max + 1] = {0};
    int output[n];

    for (int  i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i < max +1 ; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n-1; i >=0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    
    
    
    
} 

int main (){

    int arr[] = {4, 56, 6, 34, 2, 9, 0};

    countsort(arr,  7,  56);

    for (int i = 0; i <  7; i++)
    {
        cout << arr[i] << " ";
    }
    
}