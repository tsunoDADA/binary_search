#include <stdio.h>

int n;
int k;
int A[100000];
int B[1000000000];

int p(int m){
    int l = 0;
    int z;
    for(z = 0;z < n;z++){
        l = l + A[z] / B[m];
    }
    return l >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int y;
  for(y = 0;y <= A[n - 1];y++){
      B[y] = A[n - 1] - y;
  }
  lb = -1;
  ub = y - 1;
  while(ub - lb > 1){
      int mid = (lb + ub) / 2;
      if(p(mid)){
          ub = mid;
      }
      else{
          lb = mid;
      }
  }
  printf("%d\n",B[ub]);
  return 0;
}
