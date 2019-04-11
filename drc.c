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

}/*
//FUNGSI muat proyek----------------------------
FILE *file1;
    FILE *file2;
    char namafile[100],flayout[100],frouting[100];
    int panjang, lebar, mode, i, j, k, c, count, hitung;
    char d;
    char tabslay[40][40][4];
    char tabsrout[40][40];
    char data[50];

    printf("====== Memuat Proyek dari Berkas ======\n");
    printf("Masukkan nama proyek:");
    scanf("%s", &namafile);
    strcpy(flayout, namafile);
    strcat(flayout, "_layout.csv");
    strcpy(frouting, namafile);
    strcat(frouting, "_routing.csv");
    printf("%s %s \n",flayout, frouting);

    while(((file1=fopen(flayout,"r"))==NULL)||((file2=fopen(frouting,"r"))==NULL)){
        printf("file tidak ada\n");
        printf("Masukkan nama proyek:");
        scanf("%s", &namafile);
        strcpy(flayout, namafile);
        strcat(flayout, "_layout.csv");
        strcpy(frouting, namafile);
        strcat(frouting, "_routing.csv");
    }
    printf("file ketemu");

    file1=fopen(flayout, "r");
    file2=fopen(frouting, "r");

    printf("\n");

    //memasukkan isi file layout ke array layout
    i=1;
    j=1;
    k=0;
    count=0;
    while(file1){
        c = fgetc(file1);
        d=c;
        switch (d){
            case ',':
                k=0;
                j=j+1;
                count=count+1;
                break;
            case '\n':
                k=0;
                j=1;
                i=i+1;
                printf("\n");
                break;
            case ' ':
                tabslay[i][j][1]=d;
                printf("/", tabslay[i][j][1]);
                strcpy(tabslay[i][j], "  ");
                break;
            case 'R':
            case 'J':
            case 'T':
            case 'C':
                tabslay[i][j][k]=d;
                printf("%c", tabslay[i][j][k]);
                k=k+1;
                break;
            case '0' :
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
                tabslay[i][j][k]=d;
                printf("%c", tabslay[i][j][k]);
                k=k+1;
                break;
            default :
                printf("/%d/", d);
        }
        if(feof(file1)){
            break;
        }
    }

    //cobacoba
    printf("//%s// \n", tabslay[1][2]);
    printf("i=%d, j=%d \n", i,count);
    lebar = i-1;
    panjang=((count/lebar)+1);
    printf("panjang %d \n", panjang);

    //memasukkan isi file layout ke array routing
    i=1;
    j=1;
    hitung=0;
    while(file2){
        c = fgetc(file2);
        d=c;
        switch (d){
            case ',':
                hitung=hitung+1;
                j=j+1;
                break;
            case '\n':
                j=1;
                i=i+1;
                break;
            case ' ':
                tabsrout[i][j]=' ';
                printf("%c", tabsrout[i][j]);
                break;
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':
            case '^':
            case '&':
            case '*':
            case '(':
            case ')':
                tabsrout[i][j]=d;
                printf("%c", tabsrout[i][j]);
            default :
                printf("apanih \n", d);
        }
        if(feof(file2)){
            break;
        }
    }

//-------------------------------------
*/
//FUNGSI panggil fungsi muat_proyek
//buat array baru arr.gab yg merupakan gabungan arr.routing dan arr.layout

/*
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
		printf("(arrgab[%d][%d] = %s) \n", );
	}

    
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
*/

