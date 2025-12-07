#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int judge(char* t,int* mp1,int* mp2){
    for(int i=0;i<strlen(t);i++){
        if(mp1[t[i]]>mp2[t[i]]) return 0;
    }
        return 1;
}
char* minWindow(char *s,char *t){
    static char ans[10000];
	int n=strlen(s),m=strlen(t);
	int mp1[256]={0},mp2[256]={0},min=1e6;
	//利用字符暗转int类型记录字符出现
    for(int i=0;i<m;i++){
        mp1[t[i]]++;
    }
    //双指针法（这里用int代替）其实是懒得写指针
	for(int l=0,r=0;l<n;l++){
        //如果右指针比左指针大，同时右指针没有到边界，而且此时还没有到达题目要求，右指针加加
        while(l<=r&&r<n&&!judge(t,mp1,mp2)){
            mp2[s[r]]++;
            r++;
        }
        //跳出循环的时候就是左指针在当前最短的左，右指针在当前最短的右边
        //从循环出来的时候也要判断，因为可能存在右指针到了边界，光左指针进行移动的情况
        if(!judge(t,mp1,mp2)) continue;
        int len=r-l+1;
        //维护最小的子串
        if(min>len){
        	memset(ans,'\0',sizeof(ans));//初始化ans字符串
        	int num=0;//初始化计数器
            min=len;
            for(int i=l;i<r;i++){
                ans[num]=s[i];
                num++;
            }
        }
        mp2[s[l]]--;
    }
    return ans;
}
int main(){
    char input[100000];
    char S[10000], T[10000];
    // 读取一整个字符串  
    scanf("%s", input);
    // 使用 strtok() 函数分割字符串
    // 第一个字符串存入S
    char *ptr=strtok(input,",");
    if (ptr!=NULL) {
    int len=strlen(ptr);
    if (len>=2&&ptr[0]=='"'&&ptr[len-1]=='"'){
        ptr[len-1]='\0';
        memmove(ptr,ptr+1,len-1);
    }
    strncpy(S,ptr,len);
    S[len-1]='\0';
    }
    //第二个字符串存入T   
    ptr=strtok(NULL,",");
    if(ptr!=NULL){
    int len=strlen(ptr);
    if(len>=2&&ptr[0]=='"'&&ptr[len-1]=='"'){
        ptr[len-1]='\0';
        memmove(ptr,ptr+1,len-1);
    }
    strncpy(T,ptr,len);
    T[len-1]='\0';
    }
    //求最小覆盖字串并打印  
	printf("\"%s\"\n", minWindow(S,T));
    return 0;
}
//"XDOYEZODEYXNZ","XDOYXN"