using namespace std;
#include <iostream>
#define DIM 100

void replace_sep(char s[], int len, char sep);

int main(){
    char s[DIM];
    cout << ">";
    cin.getline(s,DIM);
    replace_sep(s,DIM,'\t');
    replace_sep(s,DIM,'\n');
    
    cout << s << endl;
    return 0;
}
void replace_sep(char s[], int len, char sep){
    for(int i = 0; i < len && s[i] != '\0'; i++){
        if(s[i] == sep)
            s[i] = ' ';
    }
}