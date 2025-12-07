#include <stdio.h>
int main(){
	int vals[150];
	int cnt=0;
	int a;
	while(scanf("%d",&a)!=EOF){
		if(cnt<150){
			vals[cnt++]=a;
		}
	}
	if(cnt==0){
		return 0;
	}
	int n=-1;
	int start=0;
	for(int i=1;i<12;i++){
		if(i*i==cnt){
			n=i;
			break;
		}
	}
	if(n==-1){
		if(cnt<2){
			return 0;
		}
		int possible=vals[0];
		if(possible>0&&possible<12&&possible*possible==cnt-1){
			n=possible;
			start=1;
		}else{
			return 0;
		}
	}
	int mat[12][12];
	int idx=start;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mat[i][j]=vals[idx++];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(mat[i][k]&&mat[k][j]){
					mat[i][j]=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d",mat[i][j]);
			if(j!=n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}