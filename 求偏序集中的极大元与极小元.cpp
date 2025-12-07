#include <stdio.h>
#include <string.h>

int main(){
	char e[30];
	char r[300];
	char s[30];
	int sz = 0;
	int inc[30] = {0};
	int out[30] = {0};
	
	fgets(e, sizeof(e), stdin);
	int len = strlen(e);
	for(int i = 0; i < len; i++){
		if(e[i] >= 'a' && e[i] <= 'z'){
			s[sz++] = e[i];
		}
	}
	
	fgets(r, sizeof(r), stdin);
	len = strlen(r);
	
	for(int i = 0; i < len; i++){
		if(r[i] == '<'){
			i++;
			char f = 0, t = 0;
			if(i < len && r[i] >= 'a' && r[i] <= 'z'){
				f = r[i];
				i++;
			}
			if(i < len && r[i] == ','){
				i++;
			}
			if(i < len && r[i] >= 'a' && r[i] <= 'z'){
				t = r[i];
			}
			
			if(f && t){
				for(int j = 0; j < sz; j++){
					if(s[j] == f){
						out[j] = 1;
					}
					if(s[j] == t){
						inc[j] = 1;
					}
				}
			}
		}
	}
	
	char mn[30];
	int mcnt = 0;
	for(int i = 0; i < sz; i++){
		if(!inc[i]){
			mn[mcnt++] = s[i];
		}
	}
	
	char mx[30];
	int xcnt = 0;
	for(int i = 0; i < sz; i++){
		if(!out[i]){
			mx[xcnt++] = s[i];
		}
	}
	
	for(int i = 0; i < mcnt - 1; i++){
		for(int j = i + 1; j < mcnt; j++){
			if(mn[i] > mn[j]){
				char tmp = mn[i];
				mn[i] = mn[j];
				mn[j] = tmp;
			}
		}
	}
	
	for(int i = 0; i < xcnt - 1; i++){
		for(int j = i + 1; j < xcnt; j++){
			if(mx[i] > mx[j]){
				char tmp = mx[i];
				mx[i] = mx[j];
				mx[j] = tmp;
			}
		}
	}
	
	for(int i = 0; i < mcnt; i++){
		printf("%c", mn[i]);
		if(i < mcnt - 1){
			printf(",");
		}
	}
	printf("\n");
	
	for(int i = 0; i < xcnt; i++){
		printf("%c", mx[i]);
		if(i < xcnt - 1){
			printf(",");
		}
	}
	printf("\n");
	
	return 0;
}