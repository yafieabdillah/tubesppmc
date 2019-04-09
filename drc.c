#include <stdio.h>
#include <string.h>

int main(){
	int ch;
	char itoch;

//masukkan file eksternal ke array
	char str1[10];
	char gab[10];
	char arr[40][40][40];
	int i=0, j=0;

	FILE *fp;

	fp = fopen("cek.txt","r");

	//asumsi file txt sesuai spesifikasi dan dipisahkan oleh tab
	/*ch = fscanf(fp,"%s %s",str1,str2);
	printf ("%s",str1);
	printf("%d",ch);
	
	while (1){
		ch = fscanf(fp,"%s",str1);
		
	
		if (feof(fp)){
				break;
			}
		}
	*/
	while ((ch = fgetc(fp)) != EOF)
	{		
		if (ch == '\t')
			j++;
		else if (ch == '\n')
			i++;
		else 
		{	//fgetc sudah membaca satu karakter, maka karakter perlu dibaca kembali
			fscanf(fp,"%s",str1);
			itoch = ch;
			gab[0]=itoch;
			strcat(gab,str1);
			strcpy(arr[i][j],gab);
			printf("arr[%d][%d] = %s \n",i,j, arr[i][j]);
		}
		strcpy(gab," ");
	}
	
	fclose(fp);

	return(0);
}
