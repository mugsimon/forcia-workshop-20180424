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

int main(){
  return 0;
}

