#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int l = 0;
//lは必要なカゴの数
    int q;
//qはA[z]の値を記録する
    int z;
    for(z = 0;z < n;z++){
        q = A[z];
        l = l + 1;
        while (q > m) {
            q = q - m;
            l = l + 1;
        }
//確かにA[m]で割ってたのは見返した時意味がわかりませんでした
//後々見返すと割り算より引き算の方がわかりやすかったのでそこも変更しました
        
        }
    return l <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
    lb = 0;
//lbを−１で始めるとmidが０になる時が出ちゃうんで０からにしました
    ub = A[n - 1];
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if(p(mid)){
            ub = mid;
        }
        else{
            lb = mid;
        }
    }
    printf("%d\n",ub);
  return 0;
}
