#include <iostream>
using namespace std;
void search(char text[],int n,char pat[],int m);
void main(){
	search("xabxyabxyabxz",13,"abxyabxz",8);
}

void search(char text[],int n,char pat[],int m){
//·Ó¡ÒÃ¤é¹ËÒ pat[0ä»¨¹¶Ö§m-1] ã¹ text[0ä»¨¹¶Ö§n-1]กดกด 
	int i,j,k,lim,count=0;
	printf("text = %s\n",text);
	printf("pat = %s\n",pat);

	lim = n-m+1; // ÁØÁÁÍ§¢Í§ User àÇÅÒà¢ÕÂ¹â»Ãá¡ÃÁµéÍ§»ÃÑºÅ´Å§ÍÕ¡ 1
	for (i = 0; i <= lim-1; i++){
		k = i;
		
		for (j=0; j <= m-1 && text[k] == pat[j]; j++){
			k++;
			count++;
		}
		if (j > m-1){
			printf("Found at %d \n",i);
			
		}
	}
	printf("count = %d\n",count);
}
