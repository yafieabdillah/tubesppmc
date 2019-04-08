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
    int panjang, lebar, mode, i, j;
    char tabs[40][40][3];
    char a[100];

    printf("====== Membuat Proyek Baru ======\n");
    printf("Masukkan nama proyek:");
    scanf("%s", &namafile);
    strcpy(flayout, namafile);
    strcat(flayout, "_layout.csv");
    strcpy(frouting, namafile);
    strcat(frouting, "_routing.csv");
    printf("%s %s", flayout, frouting);
    file1=fopen(flayout,"w+");
    file2=fopen(frouting,"w+");

    printf("Masukkan ukuran PCB NxM (N,M<40):");
    scanf("%d %d", &panjang, &lebar);

    for (i=0; i<=lebar; i++){
        for(j=0; j<=panjang; j++){
                strcpy(tabs[i][j], "");
        }
    }

    strcpy(tabs[1][1], "R1");
    strcpy(tabs[1][3], "R1");
    strcpy(tabs[2][2], "R1");
    strcpy(tabs[3][3], "R1");

    for (i=1; i<=lebar; i++){
        for(j=1; j<=panjang; j++){
                printf("%s \t", tabs[i][j]);
        }
        printf("\n");
    }

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
