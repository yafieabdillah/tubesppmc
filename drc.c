#include <stdio.h>
#include <string.h>
#define m 40
#define n 40

void ftentukannode(char komponennode[10],char namanode[10]);

int main(){
	
//masukkan file eksternal .txt ke array
	int ch;
	char itoch;
	char str1[10];
	char gab[10];
	char arrdrc[40][40][40]; //array design rule checker
	int i=0, j=0, baristerakhirdrc;


	FILE *fp;

	fp = fopen("cek.txt","r");

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
			strcpy(arrdrc[i][j],gab);
			printf("arrdrc[%d][%d] = %s \n",i,j, arrdrc[i][j]);
		}
		strcpy(gab," ");
	}
	
	baristerakhirdrc = i;	
	fclose(fp);

//backtracking algorithm to find node

//FUNGSI panggil fungsi muat_proyek
//buat array baru arr.gab yg merupakan gabungan arr.routing dan arr.layout

char arrgab[40][40][40];
char arrnode[40][40][40];
char arrrouting[40][40][40];
char arrlayout[40][40][40];
char komponennode[10];
char namanode[10];
//array i x j = m x n

for (i=0;i<m;i++){
	for(j=0;j<n;j++){
		strcpy(arrgab[i][j], arrrouting[i][j]);
		//jika tidak kosong timpa routing dengan layout
		if(arrlayout[i][j][1] != ' '){
			strcpy(arrgab[i][j], arrlayout[i][j]);
		}
	}

}
//FUNGSI tampilkan layout

ftentukannode(komponennode,namanode);

//algoritma searching komponen arrdrc di arrgab
int k =0;

for (k=0;k<baristerakhirdrc;k++){
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if (arrgab[i][j] == arrdrc[k][0]){
				if ((arrdrc[k][1]) || (arrdrc[k][2]) == arrnode[i][j]){
					printf("mantap, node %s betul\n", arrgab[i][j]);
				}
				else
					printf("maaf node %s salah\n",arrgab[i][j] );
				}
			}
	}
}

printf("%d/%d RUle is checked N\n", baristerakhirdrc,baristerakhirdrc);
//bocor: kanan-mentokkiri-kanan-kiri
return(0);
}


void ftentukannode(char komponennode[10],char namanode[10]){
int i,j;

char arrnode[40][40][40];
char arrgab[40][40][40];
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		//start node saaat arrgab mendeteksi komponen
		if (komponennode == arrgab[i][j]){
			strcpy(arrnode[i][j],namanode);
			break;
			}  
		
	}
}

//looping tracking 
int stop =0;
while (stop < 5){
	//jalan kekanan
	j++;
	if (arrgab[i][j][1] != ' '){
		strcpy(arrnode[i][j],namanode);
	}
	else 
		{
		stop++;
		j--;
	//jalan ke bawah
		i++;
		
		if (arrgab[i][j][1] != ' '){
		strcpy(arrnode[i][j],namanode);
		}
		else {
			stop++;
			i--;
		//jalan ke kiri
			j--;
			
			if (arrgab[i][j][1] != ' '){
				strcpy(arrnode[i][j],namanode);
			}
			else
				{ 
				stop++;
				j++;
				//jalan ke atas
				i--;
				
				if (arrgab[i][j][1] != ' '){
					strcpy(arrnode[i][j],namanode);
					}
				else
				{
				stop++;
				i++;
				}	
				}
			}	
		}
	}

}


