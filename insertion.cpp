#include<bits/stdc++.h>

using namespace std;

void insertion(int arr[], int n ){

    for (int i = 1; i < n; i ++){
        int key = arr[i];
        int j = i - 1;

        while(j>=0&&arr[j]>key){
            arr[j + 1] = arr[j];
            j--;

        }
        arr[j + 1] = key;
    }
}
int main (){

    int arr[] = {4, 56, 6, 34, 2, 9, 0};

    insertion(arr, 7);

    for (int i = 0; i <  7; i++)
    {
        cout << arr[i] << " ";
    }
    
}