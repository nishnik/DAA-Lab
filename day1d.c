

// 14MA 20021  -->  NISHANT NIKHIL
/////////////////////////////////////// QUESTION 14 TO 15
////////////////////////////////////////////////

#include <stdio.h>

void rd(int a[], int n) {
  int i;
  printf("\nGive Elements: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

int scan(int a[], int n) {
  int i;
  int pos = -1;
  for (i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      a[i] = a[i] + a[i + 1];
      a[i + 1] = a[i] - a[i + 1];
      a[i] = a[i] - a[i + 1];
      pos = i;
    }
  }
  return pos + 1;
}

void bubble_sort(int arr_a[], int n) {
  int z;
  int t = n;
  do {
    z = scan(arr_a, t);
    t = z;
  } while (t != 0);
  printf("\nBubble Sort: ");
  for (t = 0; t < n; t++) {
    printf("%d ", arr_a[t]);
  }
}

int main() {
  int n;
  printf("\nEnter Size of array A: ");
  scanf("%d", &n);
  int arr_a[1000];
  rd(arr_a, n);
  bubble_sort(arr_a, n);
}
