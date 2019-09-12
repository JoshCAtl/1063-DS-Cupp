#include<iostream>
using namespace std;

int main()
{
    1.
    int a[] = {25, -3, 6, 0, -3, 6};
    int n = a[1];

    n = -3;

    2.
     int n = 0;
  for (int i=0; i<6; i++) {
    if (a[i] < 0) {
      n++;
    }
  }

  n = 2

  3.
  int n;
  for (int i=0; i<6; i++) {
    a[i] = a[i]+1;
  }
  n = a[2];
  
  n = 7

  4.
  int n = 0;
  for (int i=0; i<5; i++) {
    for (int j=i+1; j<6; j++) {
      if (a[i] == a[j]) {
         n++;
      }
    }
  }
  n = 1

  5.
  n = a[3]+1;
  n = 1

  6.
  n = a[3+1];
  n = -3

  7.
  n = a[3+1]+1;
  n = -2

  8.
  n = a[3+1]+a[1];
  n = 0

  9.
  a[3+1] = a[3]+1;
  a = 1

  10.
  a[3] = a[3]+a[1+3]*2;
  a = -6  


}