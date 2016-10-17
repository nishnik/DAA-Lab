#include <stdio.h>
#define MAXSIZE 1000

void adjust_up(int arr[], int i) {
  while (arr[i / 2] > arr[i] && i != 1) {
    arr[i / 2] = arr[i] + arr[i / 2];
    arr[i] = arr[i / 2] - arr[i];
    arr[i / 2] = arr[i / 2] - arr[i];
    i /= 2;
  }
}
void print(int arr[], int n) {
  printf("\n");
  int i;
  for (i = 1; i <= n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
void insert(int arr[], int n) {
  arr[0] = -1; // not using the index 0
  int i = 0;
  for (i = 1; i <= n; i++) {
    printf("\nEnter the number %d element: ", i);
    int c;
    scanf("%d", &c);
    if (i == 1)
      arr[i] = c;
    else {
      arr[i] = c;
      adjust_up(arr, i);
    }
  }
}

void adjust_down(int arr[], int i, int size) {
  while (1) {
    if (2 * i > size)
      break;
    else if (2 * i <= size && 2 * i + 1 > size && arr[2 * i] < arr[i]) {
      arr[2 * i] = arr[i] + arr[2 * i];
      arr[i] = arr[2 * i] - arr[i];
      arr[2 * i] = arr[2 * i] - arr[i];
      i = 2 * i;
    } else {
      int ind = (arr[2 * i] < arr[2 * i + 1] ? 2 * i : 2 * i + 1);
      if (arr[i] > arr[ind]) {
        arr[ind] = arr[i] + arr[ind];
        arr[i] = arr[ind] - arr[i];
        arr[ind] = arr[ind] - arr[i];
        i = ind;
      } else
        break;
    }
  }
}

int delete_min(int arr[], int n) {
  int temp = arr[1];
  arr[1] = arr[n];
  n--;
  adjust_down(arr, 1, n);
  //	print(arr,n);
  return temp;
}

void heap_sort(int arr[], int n, int res[]) {
  res[0] = -1; // not using it
  int i = 0;
  int size = n;
  for (i = 1; i <= size; i++) {
    res[i] = delete_min(arr, n);
    n--; // one element deleted the prev decrement not reflected here
    //		printf("\n ele del is %d \n",res[i]);
  }
}

void heapify(int arr[], int n) {
  int i;
  for (i = n / 2; i >= 1; i--) {
    adjust_down(arr, i, n);
  }
}

int main() {
  printf("\n First Operation:\n");
  printf("\nEnter the number of elements: ");
  int n;
  scanf("%d", &n);
  int arr[MAXSIZE];
  int res[MAXSIZE];
  insert(arr, n);
  printf("\n Heap Contains: \n");
  print(arr, n);
  heap_sort(arr, n, res);
  printf("\nHeap Sorted Array: \n");
  print(res, n);

  printf("\n Second Operation: Enter the number of elements in array: ");
  scanf("%d", &n);
  int i = 0;
  printf("\n Enter Elements:\n");
  for (i = 1; i <= n; i++) {
    printf("\nEnter the number %d element: ", i);
    scanf("%d", &arr[i]);
  }
  heapify(arr, n);
  printf("\n Heap Contains: \n");
  print(arr, n);
}
