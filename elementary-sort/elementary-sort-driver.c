#include <stdio.h>
#include <stdlib.h>
typedef int Item; //how does item work here?
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) { Item t = A; A = B; B = t;}
#define compexch(A,B) if(less(B,A)) exch(A,B)

// insertion sort implementation

void sort(Item a[], int l, int r)
  {
    int i, j;
    for(i=l+1; i <= r; i++)
      for(j = i; j > l; j--)
        compexch(a[j-1], a[j]);
  }

int main(int argc, char *argv[])
  { int i, N = atoi(argv[1]), sw = atoi(argv[2]);
    int *a = malloc(N*sizeof(int));
    if(sw){
      for (i=0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
      for (i = 0; i < N; i++) printf("%3d ", a[i]);
      printf("\n");
    }
    else{
      int count = 0;
      while (count < N && scanf("%d", &a[count]) == 1) count++;
      }
    sort(a, 0, N-1);
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n");
    return 0;
  }
