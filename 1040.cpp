#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int MaxLen=1010;
char str[MaxLen];
int dp[MaxLen][MaxLen];


void init(){
  int i=0;
  while(scanf("%c",str+i)&&str[i]!='\n'){
    i++;
  }
  //init
  int len=i;
  
  int maxLength=1;
  for(i=0;i<len;i++){
    dp[i][i]=1;
    dp[i][i+1]=(str[i]==str[i+1])?1:0;
    if(dp[i][i+1]) maxLength=2;
  }
  int j;
  for(int k=3;k<=len+1;k++){
    for(i=0;i<len;i++){
      j=i+k-1;
      if(dp[i+1][j-1]&&str[i]==str[j]){
        dp[i][j]=1;
        maxLength=k;
      }
    }
  }
  printf("%d",maxLength);
}

int main(void){
  init();
  return 0;
}
