#include <iostream>
using namespace std;
void search(char text[],int n,char pat[],int m);
void main(){
	search("xabxyabxyabxz",13,"abxyabxz",8);
}

void search(char text[],int n,char pat[],int m){
//�ӡ�ä��� pat[0仨��֧m-1] � text[0仨��֧n-1]
	int i,j,k,lim,count=0;
	printf("text = %s\n",text);
	printf("pat = %s\n",pat);

	lim = n-m+1; // ����ͧ�ͧ User ������¹�������ͧ��ѺŴŧ�ա 1
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