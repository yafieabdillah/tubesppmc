#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cekmode(int n){
    while ((n>=9)||(n<=0)){
        printf("Masukan salah\n");
        printf("Pilih Mode ");
        scanf("%d", &n);
    }
    return n;
}

void tampilkanlayout(char tabs[][40][3], int panjang, int lebar){
    int i,j;

    for (i=1; i<=panjang; i++){
        printf("\t %d", i);
    }
    printf("\n");
    for (i=1;i<=lebar;i++){
        printf("%d", i);
        for (j=1; j<=panjang; j++){
            printf("\t %s", tabs[i][j]);
        }
        printf("\n");
    }
}

int main(){
    FILE *file1;
    FILE *file2;
    char namafile[100],flayout[100],frouting[100];
    int panjang, lebar, mode, i, j, k, c, d,length;
    char tabs[40][40][3];
    char a[100];
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

    i=1;
    j=1;
    k=0;
    while(1){
        c = fgetc(file1);
        d=c;
        switch (d){
            case ',':
                k=0;
                j=j+1;
                break;
            case '\n':
                k=0;
                j=1;
                i=i+1;
                printf("\n");
                break;
            case ' ':
                tabs[i][j][1]=d;
                printf("%c", tabs[i][j][1]);
                break;
            case 'R' :
                tabs[i][j][k]=d;
                printf("%c", tabs[i][j][k]);
                k=k+1;
                break;
            default :
                tabs[i][j][k]=d;
                printf("%c", tabs[i][j][k]);
                printf("lain");
                //printf("%s", tabs[i][j]);
                break;
        }
        if(feof(file1)){
            break;
        }
    }
    printf("%s", tabs[1][1]);
    printf("i=%d, j=%d \n", i,j);

    /*c=1;
    while(fgets(data,50,file1)!=NULL) //membaca dan mengulang sampai data habis
    {
        printf("Data ke-%d : %s", c, data);
        length=strlen(data);
        printf("%d", length);
        for(d=0;d<=(length-1);d++){
            switch (data[d]){
                case ',':
                    k=1;
                    j=j+1;
                break;
                case '\n':
                    k=1;
                    j=1;
                    i=i+1;
                    printf("\n");
                    break;
                case ' ':
                    strcpy(tabs[i][j], data[d]);
                    printf("%s", tabs[i][j]);
                    break;
                case 'R' :
                    tabs[i][j][1]=data[d];
                    printf("%c", tabs[i][j][1]);
                    k=k+1;
                    break;
                default :
                    tabs[i][j][2]=data[d];
                    printf("%s", tabs[i][j]);
                    break;
            }
            d=d+1;
        }
        c++;
    }
    fclose(file1);*/

    printf("[Menu Utama]\n");
    printf("Pilih Mode: \n\t1. Tampilkan Layout \n\t2. Layouting Manual \n\t3. Tampilkan Routing \n\t4. Routing Manual");
    printf("\n\t5. Layout Otomatis \n\t6. Routing Otomatis \n\t7. Design Rule Checker \n\t8. Simpan Proyek dan Keluar\n");
    printf("Pilih Mode: ");
    scanf("%d", &mode);

    cekmode(mode);

    while ((mode<=7)&&(mode>=1)){
        switch(mode){
            case 1 :
                tampilkanlayout(tabs, panjang, lebar);
                break;
            default :
                printf("ups salah\n");
        }
        printf("\n");
        printf("[Menu Utama]\n");
        printf("Pilih Mode: \n\t1. Tampilkan Layout \n\t2. Layouting Manual \n\t3. Tampilkan Routing \n\t4. Routing Manual");
        printf("\n\t5. Layout Otomatis \n\t6. Routing Otomatis \n\t7. Design Rule Checker \n\t8. Simpan Proyek dan Keluar\n");
        printf("Pilih Mode: ");
        scanf("%d", &mode);
        cekmode(mode);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}
