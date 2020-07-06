#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int l = 0;
    int z;
    for(z = 0;z < n;z++){
        l = l + 1 + A[z] / A[m];
        if(A[z]%A[m] == 0){
            l = l - 1;
        }
    }
    return l <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
    lb = -1;
    ub = n;
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if(p(mid)){
            ub = mid;
        }
        else{
            lb = mid;
        }
    }
    printf("%d\n",A[ub]);
  return 0;
}
