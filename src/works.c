#include <stdio.h>

int n;
int k;
int A[100000];
int B[1000000000];

int p(int m){
    int kk = 1;
    int sigoto = 0;
    int y;
    for(y = 0;y < n;y++){
        if(A[y] > m) return 0;
    }
    for(y = 0;y < n;y++){
        if(sigoto <= m){
            sigoto = sigoto + A[y];
            if(sigoto > m){
                sigoto = A[y];
                kk++;
            }
        }
    }
    
    return kk <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
    int sum = 0;
    int x;
    for(x = 0;x < n;x++){
        sum = sum + A[x];
    }
    int z;
    for(z = 0;z <= sum;z++){
        B[z] = z;
    }
    
    lb = -1;
    ub = sum;
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
