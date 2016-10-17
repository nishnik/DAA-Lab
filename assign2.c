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

void decompose(int x[], int n, int y[], int z[]) {
  int i, j, k;
  j = k = 0;
  for (i = 0; i < n; i++) {
    if (i < (n - n / 2)) {
      z[j++] = x[i];
    } else {
      y[k++] = x[i];
    }
  }
}

void merge(int a[], int n, int b[], int m, int c[]) {
  int i_a, i_b, i_c;
  i_a = i_b = i_c = 0;
  while (i_b < m && i_a < n) {
    if (a[i_a] < b[i_b]) {
      c[i_c++] = a[i_a++];
    } else {
      c[i_c++] = b[i_b++];
    }
  }
  while (i_b < m) {
    c[i_c++] = b[i_b++];
  }
  while (i_a < n) {
    c[i_c++] = a[i_a++];
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

void ms(int a[], int n) {
  int x[20], y[20];
  decompose(a, n, x, y);
  bs(x, n / 2);
  bs(y, n - n / 2);
  merge(x, n / 2, y, n - n / 2, a);
}

void rms(int a[], int n) {
  if (n > 1) {
    int x[20], y[20];
    decompose(a, n, x, y);
    rms(x, n / 2);
    rms(y, n - n / 2);
    merge(x, n / 2, y, n - n / 2, a);
  }
}

int main() {
  /*
  int n,m;
  int a[20],b[20],c[20];
  printf("\nGive n,m ");
  scanf("%d %d",&n,&m);
  rd(a,n);
  rd(b,m);
  merge(a,n,b,m,c);
  wr(c,n+m);
  */
  /*int y[20];
  int z[20];
  decompose(x,n,y,z);
  wr(z,n-n/2);
  wr(y,n/2);*/
  int n;
  int x[20];
  printf("\nGive n ");
  scanf("%d", &n);
  rd(x, n);
  // ms(x,n);
  rms(x, n);
  wr(x, n);
}
