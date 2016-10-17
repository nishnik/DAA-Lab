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
int count(int a[], int n, int p) {
  int count = 0;
  int i = 0;
  for (i = 0; i < n; i++) {
    if (a[i] > p)
      count++;
  }
  return count;
}

void break_fn(int a[], int n, int b[], int c[], int p) {
  int i_a, i_b, i_c;
  i_a = i_b = i_c = 0;
  for (i_a = 0; i_a < n; i_a++) {
    if (a[i_a] > p)
      b[i_b++] = a[i_a];
    else
      c[i_c++] = a[i_a];
  }
}

void join(int a[], int n, int b[], int m, int c[]) {
  int i_a, i_b, i_c;
  i_a = i_b = i_c = 0;
  while (i_a < n)
    c[i_c++] = a[i_a++];
  while (i_b < m)
    c[i_c++] = b[i_b++];
}

void qs(int a[], int n) {
  int x[20], y[20];
  int k = count(a, n, a[1]);
  break_fn(a, n, x, y, a[1]);
  bs(x, k);
  bs(y, n - k);
  join(y, n - k, x, k, a);
}

void rearrange(int a[], int n, int p) {
  int start = 0;
  int end = n - 1;
  while (start < end) {
    while (a[start] <= p && start < n) {
      start++;
    }
    while (a[end] > p && end >= 0) {
      end--;
    }
    if (start < end) {
      int temp = a[start];
      a[start] = a[end];
      a[end] = temp;
    }
  }
}

void bsr(int x[], int p, int q) {
  int c[20];
  int i = 0;
  int n = q - p + 1;
  for (i = 0; i < n; i++) {
    c[i] = x[i + p - 1];
  }
  bs(c, n);
  for (i = 0; i < n; i++) {
    x[i + p - 1] = c[i];
  }
}

void eqs(int a[], int n) {
  int k = count(a, n, a[1]);
  rearrange(a, n, a[1]);
  bsr(a, 1, n - k);
  bsr(a, n - k + 1, n);
}

int main() {
  /*int n;
  int x[20],y[20],z[20];
  printf("\nGive n ");
  scanf("%d",&n);
  rd(x,n);
  int k=count(x,n,19);
  //printf("%d",k);
  break_fn(x,n,y,z,19);
  wr(y,k);
  wr(z,n-k);*/
  /*	int n,m;
          int a[20],b[20],c[20];
          printf("\nGive n,m ");
          scanf("%d %d",&n,&m);
          rd(a,n);
          rd(b,m);
          join(a,n,b,m,c);
          wr(c,n+m);
    */
  int n;
  int x[20], c[20];
  printf("\nGive n ");
  scanf("%d", &n);
  rd(x, n);
  // qs(x,n);
  //	rearrange(x,n,19);
  //       bsr(x,3,6);
  eqs(x, n);
  wr(x, n);
}
