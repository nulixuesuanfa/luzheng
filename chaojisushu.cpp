#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;
const int MAXN=1000;
bool notprime[MAXN];//值为 false 表示素数，值为 true 表示非素数
void init() {
	memset(notprime,false,sizeof(notprime));
	notprime[0]=notprime[1]=true;
	for(int i=2; i<MAXN; i++)
		if(!notprime[i]) {
			if(i>MAXN/i)continue;
			for(int j=i*i; j<MAXN; j+=i)
		notprime[j]=true;
	}
}
int main (){
	int i,j,k;int tot=0,sum=0,maxn=0;
	init();
	for(i=1;i<=9;i++)
	for(j=0;j<=9;j++)
	for(k=0;k<=9;k++){
		if(!notprime[i*100+j*10+k]&&!notprime[i+j+k]&&!notprime[i*j*k]&&!notprime[i*i+j*j+k*k]){
			tot+=1;sum+=i*100+j*10+k;maxn=max(maxn,i*100+j*10+k);
		}
	}
	printf("%d\n%d\n%d\n",tot,sum,maxn);
	return 0;
}
