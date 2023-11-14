using namespace std;
#include <iostream>

int main(int argc, char** argv)
{
    cout << "-----TABELLA AND-----" << endl;
    int _1 = 0;
    int _2 = 0;

    for (int i = 0; i < 4; i++)
    {
        int n = _1&&_2;
        cout <<  _1 << "\t" << _2 << "\t" << n << endl;
        _1 = _1 == 0 ? 1:0;
        if(_2 == 0 && i == 1){
            _2 = 1;
        }
    }  

    cout << "-----TABELLA OR-----" << endl;
    _1 = 0;
    _2 = 0;

    for (int i = 0; i < 4; i++)
    {
        int n = _1||_2;
        cout <<  _1 << "\t" << _2 << "\t" << n << endl;
        _1 = _1 == 0 ? 1:0;
        if(_2 == 0 && i == 1){
            _2 = 1;
        }
    }   
    
}