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
    printf("array[%d]=%d ", i, array[i]);
  }
  printf("\n");
}

void optimize_array(int array[], int n, int newarray[], int max){
  int i, j, min;
  min = array[0];
  for(i = 0, j = min; i < n; i++){ //array
    while(array[i] > j){
      newarray[++j]=newarray[j-1];     
    }
    newarray[j]++;
  }         
}

int search(int array[], int min, int max){
  return array[max]-array[min-1];
}

void print_answer(int oarray[], int qarray[], int q){
  int i;
  for(i = 0; i < q * 2; i += 2){
    printf("%d\n", search(oarray, qarray[i], qarray[i+1]));
  }
}
  
void get_array(int array[], int n){
  int i;
  for(i = 0; i < n; i++){
    array[i] = read_int();
  }
}

void forcia_workshop(void){
  int n, q;
  n = read_int();
  q = read_int();
  int inputArray[n];
  int queryArray[q * 2];
  get_array(inputArray, n);
  get_array(queryArray, q * 2);
  quick_sort(inputArray, n);
  int max;
  max=inputArray[n] + 1;
  int optimizedArray[max];
  optimize_array(inputArray, n, optimizedArray, max);
  print_answer(optimizedArray, queryArray, q);
}

int main(){
  forcia_workshop();
  return 0;
}

