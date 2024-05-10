#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

void fi(const string& text ,const string& pattern){


    int n = text.length();
    int m = pattern.length();

    int matchcount = 0;
    int matchindex = -1;
    int cnt = 0;

    for (int i = 0; i <= n - m; ++i){
        bool matchfound = true;

        for (int j = 0; j < m; ++j){
           if(text[i+j]!=pattern[j]){
               matchfound = false;
               break;
           }
        }

        if(matchfound){
            matchcount++;
            if(cnt<1){
                matchindex = i;
                cnt++;
            }
        }
    }

    cout << "The number of time match " << matchcount << endl;
    cout << "The first index is " << matchindex << endl;
}

int main() {
    string text = "abcdeabcfghijabc";
    string pattern = "abc";

    fi(text, pattern);

    return 0;
}
