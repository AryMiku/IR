#include <iostream> //build ก่อน  แล้วไปรันใน cmd เก็บไฟล์ .txt ไว้ใน C:\....\test_Pattern\Debug
using namespace std;
void preQsBc(char *x,int m, int qsBc[]);
void QS(char *x,int m,char *y,int n);
void search(char text[],int n,char pat[],int m);
int main(int argc,char *argv[]){
	char fname[15];
	char szBuf[2048];
	char pat[10];
	char method[2];
	char c;
	int i;
	FILE *fp;

	switch(argc){
		case 1 : break; //เบรกเลยเพราะมี argument แค่ 1 ค่า คือไฟล์ .exe
		case 4 : strcpy(method,argv[3]); //coppy ค่า argv[3] ไปใส่เป็นค่า method **ไม่ต้องมีเบรกเพราะทำลงไปเลย จนถึง case2
		case 3 : strcpy(pat,argv[2]);
		case 2 : strcpy(fname,argv[1]); break;
		
		default : printf("usage : testfile[filename] pettern method\n"); 
			return 0;
	}

	if((fp=fopen(fname,"rb"))==NULL){
		printf("erroe: can't open file.\n");
		return 0;
	}

	do{
		i=0;
		while((i<2000)&&((c=getc(fp))!=EOF)){
			printf("c=%c\n",c);
			szBuf[i]=c;
			printf("szBuf[%d]=%c\n",i,szBuf[i]);
			i++;
		}
	}while(c!=EOF);
	fclose(fp);
	cout << method << endl;
	printf("pattern = %s\n",pat);
	printf("method = %s\n",method);
	if(strcmp(method,"b")==0){
		int m=strlen(pat);
		QS(pat,m,szBuf,i);		
	}
	else if(strcmp(method,"a")==0){
		int m=strlen(pat);
		search(szBuf,i,pat,m);
	}

	
	printf("\nTotal Message Size : %d bytes\nBYE!!\n",i);

}
void QS(char *x,int m,char *y,int n){
	int j,qsBc[256];
	preQsBc(x,m,qsBc);
	j=0;
	while(j<=n-m){
		if(memcmp(x,y+j,m)==0)
			printf("Found at %d\n",j);
		printf("Before add j = %d qsBc[%c] = %d\n",j,y[j+m],qsBc[y[j+m]]);
		j+=qsBc[y[j+m]];
		printf("After add j = %d\n",j);
	}
}
void preQsBc(char *x,int m, int qsBc[]){
	int i;
	for(i=0;i<256;++i){qsBc[i]=m+1;}
	for(i=0;i<m;++i){qsBc[x[i]]=m-i;}
}
void search(char text[],int n,char pat[],int m){
	int i,j,k,lim,count=0;

	printf("text = %s\n",text); //แสดง text ออกมาทั้งหมด 2048 ตัวตามที่ประกาศไว้ที่  szBuf
	printf("pattern = %s\n",pat);

	lim=n-m+1;

	for(i=0;i<=lim-1;i++){
		k=i;
		for(j=0;j<=m-1&&text[k]==pat[j];j++){k++;}
		if(j>m-1){printf("found at %d\n",i);}
		count++;
	} printf("count = %d\n",count);
}
