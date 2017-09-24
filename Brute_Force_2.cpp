#include <iostream>
using namespace std;
void search(char text[],int n,char pat[],int m);
void main(){
	search("xabxyabxyabxz",13,"abxyabxz",8);
}

void search(char text[],int n,char pat[],int m){
//ทำการค้นหา pat[0ไปจนถึงm-1] ใน text[0ไปจนถึงn-1]
	int i,j,k,lim,count=0;
	printf("text = %s\n",text);
	printf("pat = %s\n",pat);

	lim = n-m+1; // มุมมองของ User เวลาเขียนโปรแกรมต้องปรับลดลงอีก 1
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