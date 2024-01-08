#include <iostream>
#include <cstddef>

using namespace std;

void print(const char a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int & s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}
void get_elements(char *source, int dim_s, char *dest1, int max_d1, int &dim_d1, char *dest2, int max_d2, int &dim_d2){
  if(*source != '\0' && dim_d1 < max_d1 && dim_d2 < max_d2){
    if(*source >= 'a' && *source <= 'z'){
      dest1[dim_d1++] = *source - ('a' - 'A');
    }
    else if(*source >= '0' && *source <= '9'){
      dest2[dim_d2++] = '9' - *source + '0';
    }
    get_elements(source + 1, dim_s, dest1, max_d1, dim_d1, dest2, max_d2, dim_d2);
  }
}

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  char d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  char d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
