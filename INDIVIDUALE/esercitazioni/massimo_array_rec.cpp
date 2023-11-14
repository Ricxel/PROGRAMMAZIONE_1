using namespace std;
#include <iostream>

int max_it(int[], int);
int max_rec(int[],int,int,int);

int main(){
    int v[] = {1,5,10,4,13,21,78,10,23,5};

    cout << "max: " << max_rec(v,sizeof(v)/sizeof(int),0,0) << endl;
}

int max_it(int v[], int len){
    int max;
    max = v[0];
    for(int i = 1; i < len; i++){
        if(max < v[i])
            max = v[i];
    }
    return max;
}

int max_rec(int v[], int len, int i, int max){
    if(i == len - 1)
        return max;
    else{
        if(max < v[i]){
            max = v[i];
            cout << "max: " << max << endl;
        }
        return max_rec(v,len,++i,max);
    }
}