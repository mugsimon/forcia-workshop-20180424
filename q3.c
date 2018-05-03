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
  swap(array, left, (left + right)/2);
  lright = left;
  for(i = left + 1; i <= right; i++){
    if(array[left] > array[i]){
      lright++;
      swap(array, lright, i);
    }
  }
  swap(array, left, lright);
  quick_sort2(array, left, lright - 1);
  quick_sort2(array, lright + 1, right);
}

void quick_sort(int array[], int n){
  quick_sort2(array, 0, n-1);
}

void init_array(int array[], int n){
  int i;
  for(i = 0; i <= n; i++){
    array[i] = 0;
  }
}

void optimize_array(int array[], int n, int newarray[]){
  int i, j, min, max;
  min = array[0];
  max = array[n-1];
  init_array(newarray, max);
  for(i = 0, j = min; i < n; i++){ 
    while(array[i] > j){
      j++;
      newarray[j]=newarray[j-1];     
    }
    newarray[j]++;
  }         
}

int search(int array[], int min, int max){
  printf("min=%d, max=%d\n", min, max);//
  printf("array[%d]=%d, array[%d]=%d, array[%d]=%d\n", min-1, array[min-1], min, array[min], max, array[max]);
  return array[max]-array[min-1];
}

void print_answer(int oarray[], int min, int max, int qarray[], int q){
  int i, answer;
  printf("min=%d, max=%d\n", min, max);//
  for(i = 0; i < q * 2; i += 2){
    if(qarray[i]>max){
      answer=0;
    }else if(qarray[i+1]>max){
      answer=search(oarray, qarray[i], max);
    }else{
      answer=search(oarray, qarray[i], qarray[i+1]);
    }
    printf("(%d, %d)=", qarray[i], qarray[i+1]);//
    printf("%d\n", answer);
  }
}
  
void get_array(int array[], int n){
  int i;
  for(i = 0; i < n; i++){
    array[i] = read_int();
  }
}
//
void print_array(int array[], int n){
  int i;
  for(i=0;i<n;i++){
    printf("array[%d]=%d ", i, array[i]);
  }
  printf("\n");
}
//
void forcia_workshop(void){
  int n, q;
  n = read_int();
  q = read_int();
  int inputArray[n];
  int queryArray[q * 2];
  get_array(inputArray, n);
  get_array(queryArray, q * 2);
  quick_sort(inputArray, n);
  int min, max, newN;
  min = inputArray[0];
  max = inputArray[n-1];
  newN = max + 1;
  int optimizedArray[newN];
  optimize_array(inputArray, n, optimizedArray);
  print_array(optimizedArray, newN);//
  
  print_answer(optimizedArray, min, max, queryArray, q);
}

int main(){
  forcia_workshop();
  return 0;
}

