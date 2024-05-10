#include<bits/stdc++.h>

using namespace std;

void ss(char s[]){
    int freq[256] = {0};
    for (int i = 0; i < strlen(s);i++){
        freq[s[i]]++;
    }
    for (int i = 0; i < strlen(s); i ++){

        for (int j = i + 1; j < strlen(s);j++){

            if(freq[s[i]]>freq[s[j]]||freq[s[i]]==freq[s[j]]&&s[i]>s[j]){
                swap(s[i], s[j]);
            }
        }
    }
}
int main (){

    char s[] = " hello world";

    ss(s);
    cout << s << endl;
}