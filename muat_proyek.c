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

void tampilkanlayout(char tabs[][40][4], int panjang, int lebar){
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

void tampilkanrouting(char tabs[][40], int panjang, int lebar){
    int i, j;

    for (i=1; i<=panjang; i++){
        printf("\t %d", i);
    }
    printf("\n");
    for (i=1; i<=lebar;i++){
        printf("%d", i);
        for (j=1; j<=panjang; j++){
            printf("\t %c", tabs[i][j]);
        }
        printf("\n");
    }
}

int main(){
    FILE *file1;
    FILE *file2;
    char namafile[100],flayout[100],frouting[100];
    int panjang, lebar, mode, i, j, k, c, d, count, hitung;
    char tabslay[40][40][4];
    char tabsrout[40][40];
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
        printf("masuk\n");
        d=c;
        switch (d){
            case ',':
                hitung=hitung+1;
                printf("koma");
                break;
            case '\n':
                j=1;
                i=i+1;
                printf("enter\n");
                break;
            case ' ':
                tabsrout[i][j]=d;
                printf("%c", tabsrout[i][j]);
                printf("kosong");
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
                printf("isi");
                j=j+1;
            default :
                printf("/%c/ \n", d);
        }
        if(feof(file2)){
            break;
        }
    }

    //cobacoba
   /* printf("//%c// \n", tabsrout[1][2]);
    printf("i=%d, j=%d \n", i,hitung);
    lebar = i-1;
    panjang=((hitung/lebar)+1);
    printf("panjang %d", panjang);*/


    //Menu utama
    printf("[Menu Utama]\n");
    printf("Pilih Mode: \n\t1. Tampilkan Layout \n\t2. Layouting Manual \n\t3. Tampilkan Routing \n\t4. Routing Manual");
    printf("\n\t5. Layout Otomatis \n\t6. Routing Otomatis \n\t7. Design Rule Checker \n\t8. Simpan Proyek dan Keluar\n");
    printf("Pilih Mode: ");
    scanf("%d", &mode);

    cekmode(mode);

    while ((mode<=7)&&(mode>=1)){
        switch(mode){
            case 1 :
                tampilkanlayout(tabslay, panjang, lebar);
                break;
            case 2 :
                tampilkanrouting(tabsrout, panjang, lebar);
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
