using namespace std;
#include <iostream>
#define DIM 100

void conta_occorrenze(char s[],int len);
int main(){
    char s[DIM];

    cin.getline(s,DIM);

    conta_occorrenze(s,DIM);

    return 0;
}
void conta_occorrenze(char s[],int len){
    int o[26];
    for(int i = 0; i < 26; i++)
        o[i] = 0;
    for(int i = 0; i < len && s[i] != '\0';i++){
        o[s[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(o[i] > 0)
            cout << (char)(i+'a') << ": " << o[i] << endl;
    }
}