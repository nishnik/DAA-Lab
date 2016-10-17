#include <stdio.h>

void rd(int x[], int n) {
  printf("\nEnter %d values: \n", n);
  int i = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
}

void wr(int x[], int n) {
  printf("\nThe %d values are: \n", n);
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("%d ", x[i]);
  }
}

void insert(int a[], int n, int b, int c[]) {
  int i = 0;
  int flag = -1;
  ;
  for (i = 0; i < n; i++) {
    c[i] = a[i];
  }
  for (i = 0; i < n; i++) {

    if (a[i] > b) {
      flag = i;
      break;
    }
  }
  if (flag == -1)
    c[i] = b;
  else {
    for (i = n; i > flag; i--) {
      c[i] = c[i - 1];
    }
    c[flag] = b;
  }
}
void bs(int x[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (x[j] > x[j + 1]) {
        int temp = x[j];
        x[j] = x[j + 1];
        x[j + 1] = temp;
      }
    }
  }
}
void is(int a[], int n, int b[]) {
  bs(a, n - 1);
  insert(a, n - 1, a[n - 1], b);
}

int main() {
  int n;
  int x[20], c[20];
  printf("\nGive n ");
  scanf("%d", &n);
  rd(x, n);
  //    insert(x,n,0,c);
  //      wr(c,n+1);
  is(x, n, c);
  wr(c, n);
}
