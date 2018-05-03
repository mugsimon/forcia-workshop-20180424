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
  int a[10]={3,4,8,9,1,2,5,6,0,7};
  printf("%d\n", sizeof(a));
  
  print_array(a);
  quick_sort(a);
  print_array(a);
  return 0;
}

