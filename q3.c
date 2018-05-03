#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int read_int(void){
  int input;
  scanf("%d", &input);
  return input;
}

void swap(int array[], int i, int j){
  int tmp;
  tmp = array[i];
  array[i]=array[j];
  array[j]=tmp;
}

void quick_sort2(int array[], int left, int right){
  int lright, i;
  if(left >= right) return;
  swap(array, left, right);
  lright = left;
  for(i = left + 1; i <= right; i++){
    if(array[left] > array[i]){
      swap(array, ++lright, i);
    }
  }
  swap(array, left, lright);
  quick_sort2(array, left, lright - 1);
  quick_sort2(array, lright + 1, right);
}

void quick_sort(int array[], int n){
  quick_sort2(array, 0, n);
}

void print_array(int array[], int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(){
  return 0;
}

