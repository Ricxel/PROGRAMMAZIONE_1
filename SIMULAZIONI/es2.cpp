using namespace std;
#include <iostream>
#include <fstream>

void get_elements(char *, int, char *, int, char *, int );
int main(){

    return 0;
}

void get_elements(char *source, int dim_source, char *dest1, int * dim_d1, char *dest2, int * dim_d2 ){
    if(dim_source < 0){
        return;
    }
    if(*source >= 'a' && *source <= 'z'){
        *dest1 = *source;
        *dim_d1++;
        get_elements(source+1, dim_source - 1, dest1 + 1, *dim_d1, dest2, *dim_d2);
    }
    if(*source >= '0' && *source <= '9'){
        *dest2 = *source;
        *dim_d2++;
        get_elements(source+1, dim_source - 1, dest1, *dim_d1, dest2+1, *dim_d2);
    }
}