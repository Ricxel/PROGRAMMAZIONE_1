#include "strings.h"

int strlen(char *s){
    if(*s == '\0')
        return 0;
    return 1 + strlen(s+1);
}
int index_of(char *s, char c, int i){
    if(s[i] == '\0'){
        return -1;
    }
    if(s[i] == c){
        return i;
    }
    return index_of(s,c,i+1);
}
int last_index_of(char *s, char c, int len){
    if(len < 0)
        return -1;
    if(s[len-1] == c){
        return len-1;
    }
    return last_index_of(s,c,len-1);
}
void substring(char *s, char *buffer, int index, int n){
    if(n <= 0){
        *buffer = '\0';
        return;
    }
    if(*(s+index) == '\0'){
        *buffer = '\0';
        return;
    }
    *buffer = *(s+index);
    substring(s+1,buffer+1,index,n-1);
}


static bool verify_pattern(char *s,char *t){
    if(*t == '\0'){
        return true;
    }
    if(*s != *t){
        return false;
    }
    return verify_pattern(s+1,t+1);
}
int last_index_of_pattern(char *s, char *t, int i){
    if(s[i] == '\0')
        return -1;
    if(verify_pattern(s,t)){
        return i;
    }
    return last_index_of_pattern(s,t,i+1);
}