//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Lisa Margaretta S, M. Hanindya, M. Yafie Abdillah
// File Name : mainprogram.c
// Dependency : stdio.h,string.h,stdlib.h
//
// Description:
// Fungsi utama yang mencakup segala fungsi
//
// Status:
// 1. Lisa Margaretta S - 13217079 : Create the file
// 2. M Hanindya B P - 13217084 : membuat fungsi dan fix bug
// 3. M. Yafie Abdillah - 13217091 : Membuat fungsi dan fix bug
//***********************************************************//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
};

void layout_otomatis(){
    printf("fitur saat ini tidak tersedia\n");
}

void routing_otomatis(){
    printf("fitur saat ini tidak tersedia\n");
}

int cekmenu(int n){
    while ((n>=4)||(n<=0)){
        printf("Masukan salah\n");
        printf("Masukan: ");
        scanf("%d", &n);
    }
    return n;
}

int cekmode(int n){
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

void tampilkanrouting(char tabs[40][40], int panjang, int lebar){
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


void layout_manual(char array[][40][4], int n, int m){
    int i, j;
    char str_komp[4];
    struct point koor1,koor2,koor3;

    printf("[Mode Layout]\n");
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    printf("Pilih Komponen (R,C,T,J): ");scanf("%s",&str_komp);
    while ((str_komp[0]!='q')&&(str_komp[0]!='Q'))
    {
        if ((str_komp[0]=='R')||(str_komp[0]=='C')||(str_komp[0]=='J'))
        {
            printf("Koordinat Kaki 1: ");scanf("%d,%d",&koor1.x, &koor1.y);
            printf("Koordinat Kaki 2: ");scanf("%d,%d",&koor2.x, &koor2.y);
            if (str_komp[0]=='R')
            {
                while(((koor1.x==koor2.x)&&(abs(koor2.y-koor1.y)<3))||((abs(koor2.x-koor1.x)<3)&&(koor1.y==koor2.y))||(koor1.x>n)||(koor2.x>n)||(koor1.y>m)||(koor2.y>m))
                {
                    printf("Koordinat yang diberikan salah, kembali input koordinat.\n");
                    printf("Koordinat Kaki 1: ");scanf("%d,%d",&koor1.x, &koor1.y);
                    printf("Koordinat Kaki 2: ");scanf("%d,%d",&koor2.x, &koor2.y);

                }

            }
            else if (str_komp[0]=='C')
            {
                while(((koor1.x==koor2.x)&&(abs(koor2.y-koor1.y)<1))||((abs(koor2.x-koor1.x)<1)&&(koor1.y==koor2.y))||(koor1.x>n)||(koor2.x>n)||(koor1.y>m)||(koor2.y>m))
                {
                    printf("Koordinat yang diberikan salah, kembali input koordinat.\n");
                    printf("Koordinat Kaki 1: ");scanf("%d,%d",&koor1.x, &koor1.y);
                    printf("Koordinat Kaki 2: ");scanf("%d,%d",&koor2.x, &koor2.y);

                }
            }
            else if (str_komp[0]=='J')
            {
                while(((koor1.x==koor2.x)&&(abs(koor2.y-koor1.y)<0))||((abs(koor2.x-koor1.x)<0)&&(koor1.y==koor2.y))||(koor1.x>n)||(koor2.x>n)||(koor1.y>m)||(koor2.y>m)||((koor1.x==koor2.x)&&(koor1.y==koor2.y)))
                {
                    printf("Koordinat yang diberikan salah, kembali input koordinat.\n");
                    printf("Koordinat Kaki 1: ");scanf("%d,%d",&koor1.x, &koor1.y);
                    printf("Koordinat Kaki 2: ");scanf("%d,%d",&koor2.x, &koor2.y);

                }
            }
            strcpy(array[koor1.x][koor1.y],str_komp);
            printf("%s\n",array[koor1.x][koor1.y]);
            strcpy(array[koor2.x][koor2.y],str_komp);
            printf("%s\n",array[koor2.x][koor2.y]);
        }
        else if (str_komp[0]=='T')
        {
            printf("Koordinat Kaki 1: ");scanf("%d,%d",&koor1.x, &koor1.y);
            printf("Koordinat Kaki 2: ");scanf("%d,%d",&koor2.x, &koor2.y);
            printf("Koordinat Kaki 3: ");scanf("%d,%d",&koor3.x, &koor3.y);
            while ((koor1.x>n)||(koor2.x>n)||(koor3.x>n)||(koor1.y>m)||(koor2.y>m)||(koor3.y>m)||((koor1.x==koor2.x)&&(koor1.y==koor2.y))||((koor1.x==koor3.x)&&(koor1.y==koor3.y))||((koor2.x==koor3.x)&&(koor2.y==koor3.y)))
            {
                printf("Koordinat yang diberikan salah, kembali input koordinat.\n");
                printf("Koordinat Kaki 1: ");scanf("%d,%d",&koor1.x, &koor1.y);
                printf("Koordinat Kaki 2: ");scanf("%d,%d",&koor2.x, &koor2.y);
                printf("Koordinat Kaki 3: ");scanf("%d,%d",&koor3.x, &koor3.y);

            }
            strcpy(array[koor1.x][koor1.y],str_komp);
            printf("%s\n",array[koor1.x][koor1.y]);
            strcpy(array[koor2.x][koor2.y],str_komp);
            printf("%s\n",array[koor2.x][koor2.y]);
            strcpy(array[koor3.x][koor3.y],str_komp);
            printf("%s\n",array[koor3.x][koor3.y]);
        }
        printf("Pilih Komponen (R,C,T,J): ");scanf("%s",&str_komp);
    }
}

void plot(char arr[40][40],char sym, int x1, int x2, int y1, int y2){
    int i;

    if(x1==x2){
        if (y2>=y1){
            for(i=y1; i<=y2; i++){
                arr[x1][i]=sym;
            }
        } else if (y1>=y2){
            for(i=y2; i<=y1; i++){
                arr[x1][i]=sym;
            }
        }

    } else if (y1==y2){
        if (x2>=x1){
            for(i=x1; i<=x2; i++){
                arr[i][y1]=sym;
            }
        } else if (x1>=x2){
            for(i=x2; i<=x1; i++){
                arr[i][y1]=sym;
            }
        }
    }
}

void routing_manual(char arr_rout[][40], int n, int m){
    int i,j, xkoor_rout, ykoor_rout;
    char str_rout;
    int arr_koor[40][3];

    printf("[Mode Routing]\n");
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    printf("Isi 'n' atau 'N' untuk memulai pada simpul (node) baru\n");
    printf("Pilih Simbol (!,@,#,$,%,^,&,*,(,)): ");scanf("%s", &str_rout);
    while ((str_rout!='!')&&(str_rout!='@')&&(str_rout!='#')&&(str_rout!='$')&&(str_rout!='%')&&(str_rout!='^')&&(str_rout!='&')&&(str_rout!='*')&&(str_rout!='(')&&(str_rout!=')'))
    {
        printf("Simbol Routing Pilihanmu salah, harap isi kembali\n");
        printf("Pilih Simbol (!,@,#,$,%,^,&,*,(,)): ");
        scanf("%s",&str_rout);
    }

    int count=1;
    char koor_rout[4];
    memset(arr_koor,0,sizeof(arr_koor));
    printf("koordinat %d:",count);
    scanf("%s", &koor_rout);
    xkoor_rout = koor_rout[0]-48;
    ykoor_rout = koor_rout[2]-48;
    //printf("%d/%d", arr_koor[1][0], arr_koor[1][1]);
    while ((koor_rout[0]!='q')&&(koor_rout[0]!='Q')){
        if ((koor_rout[0]=='n')||(koor_rout[0]=='N')){
            if ((count!=1)&&(count!=2)){
                for(i=0;i<=count;i++){
                    plot(arr_rout, str_rout, arr_koor[i][0],arr_koor[i+1][0],arr_koor[i][1],arr_koor[i+1][1]);
                }
            }
            memset(arr_koor,0,sizeof(arr_koor));
            printf("%d", arr_koor[1][0]);
            printf("Pilih Simbol (!,@,#,$,%,^,&,*,(,)): ");
            scanf("%s",&str_rout);
            while ((str_rout!='!')&&(str_rout!='@')&&(str_rout!='#')&&(str_rout!='$')&&(str_rout!='%')&&(str_rout!='^')&&(str_rout!='&')&&(str_rout!='*')&&(str_rout!='(')&&(str_rout!=')')){
                printf("Simbol Routing Pilihanmu salah, harap isi kembali\n");
                printf("Pilih Simbol (!,@,#,$,%,^,&,*,(,)): ");
                scanf("%s",&str_rout);
            }
            count=1;
        }
        else if (((koor_rout[0]!='n')&&(koor_rout[0]!='N'))&&((xkoor_rout>=(m+1))||((xkoor_rout<=0))||((ykoor_rout)>=(n+1))||(ykoor_rout<=0))){
            printf("Koordinat tidak berada didalam range, isi kembali\n");
        }
        else{
            arr_koor[count][0] = koor_rout[0]-48;
            arr_koor[count][1] = koor_rout[2]-48;
            //printf("%d/%d", arr_koor[count][0], arr_koor[count][1]);
            count=count+1;
        }
        printf("koordinat %d:",count);
        scanf("%s",&koor_rout);
        xkoor_rout = koor_rout[0]-48;
        ykoor_rout = koor_rout[2]-48;
    }
    for(i=1;i<=count;i++){
       plot(arr_rout, str_rout, arr_koor[i][0],arr_koor[i+1][0],arr_koor[i][1],arr_koor[i][1]);
    }
    return;
}

void simpankeluar(FILE *file1, FILE *file2, char tabslay[][40][4], char tabsrout[][40], int lebar, int panjang){
    int i,j;

    for (i=1; i<=lebar; i++){
        for(j=1; j<=panjang; j++){
                //printf("%s \t", tabslay[i][j]);
                fprintf(file1, "%s,", tabslay[i][j]);
        }
        //printf("\n");
        fprintf(file1, "\n");
    }

    for (i=1; i<=lebar; i++){
        for(j=1; j<=panjang; j++){
                //printf("%c \t", tabsrout[i][j]);
                fprintf(file2, "%c,", tabsrout[i][j]);
        }
        //printf("\n");
        fprintf(file2, "\n");
    }
}

void proyekbaru(){
    FILE *file1;
    FILE *file2;
    char namafile[100],flayout[100],frouting[100];
    int panjang, lebar, mode, i, j;
    char tabslay[40][40][4];
    char tabsrout[40][40];

    printf("====== Membuat Proyek Baru ======\n");
    printf("Masukkan nama proyek:");
    scanf("%s", &namafile);
    strcpy(flayout, namafile);
    strcat(flayout, "_layout.csv");
    strcpy(frouting, namafile);
    strcat(frouting, "_routing.csv");
    file1=fopen(flayout,"w+");
    file2=fopen(frouting,"w+");

    printf("Masukkan ukuran PCB NxM (N,M<40):");
    scanf("%d %d", &panjang, &lebar);

    // mengisi array layout dengan NULL
    for (i=0; i<=lebar; i++){
        for(j=0; j<=panjang; j++){
                strcpy(tabslay[i][j], " ");
        }
    }

    /*//coba coba isi array layout
    strcpy(tabslay[1][1], "R1");
    strcpy(tabslay[1][3], "R1");
    strcpy(tabslay[2][2], "R1");
    strcpy(tabslay[3][3], "R1");

    //coba cetak isi array
    for (i=1; i<=lebar; i++){
        for(j=1; j<=panjang; j++){
                printf("%s \t", tabslay[i][j]);
        }
        printf("\n");
    }*/

    //mengisi array routing dengan spasi
    for (i=1; i<=lebar; i++){
        for(j=1; j<=panjang; j++){
                tabsrout[i][j] = ' ';
        }
    }


    printf("[Menu Utama]\n");
    printf("Pilih Mode: \n\t1. Tampilkan Layout \n\t2. Layouting Manual \n\t3. Tampilkan Routing \n\t4. Routing Manual");
    printf("\n\t5. Layout Otomatis \n\t6. Routing Otomatis \n\t7. Design Rule Checker \n\t8. Simpan Proyek dan Keluar\n");
    printf("Pilih Mode: ");
    scanf("%d", &mode);

    mode = cekmode(mode);

    while ((mode<=7)&&(mode>=1)){
        switch(mode){
            case 1 :
                tampilkanlayout(tabslay, panjang, lebar);
                break;
            case 2 :
                layout_manual(tabslay, panjang, lebar);
                break;
            case 3 :
                tampilkanrouting(tabsrout, panjang, lebar);
                break;
            case 4 :
                routing_manual(tabsrout, panjang, lebar);
                break;
            case 5 :
                layout_otomatis();
                break;
            case 6 :
                routing_otomatis();
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
        mode = cekmode(mode);
    }
    simpankeluar(file1, file2, tabslay, tabsrout, lebar, panjang);
    fclose(file1);
    fclose(file2);
    return;
}

void muat_proyek(){
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
    //printf("%s %s \n",flayout, frouting);

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
                //printf("\n");
                break;
            case ' ':
                tabslay[i][j][1]=d;
                //printf("/", tabslay[i][j][1]);
                strcpy(tabslay[i][j], "  ");
                break;
            case 'R':
            case 'J':
            case 'T':
            case 'C':
                tabslay[i][j][k]=d;
                //printf("%c", tabslay[i][j][k]);
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
                //printf("%c", tabslay[i][j][k]);
                k=k+1;
                break;
            //default :
                //printf("/%d/", d);
        }
        if(feof(file1)){
            break;
        }
    }

    //printf("i=%d, j=%d \n", i,count);
    lebar = i-1;
    panjang=(count/lebar);
    //printf("panjang %d \n", panjang);

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
                //printf("%c", tabsrout[i][j]);
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
                //printf("%c", tabsrout[i][j]);
        }
        if(feof(file2)){
            break;
        }
    }


    //Menu utama
    printf("[Menu Utama]\n");
    printf("Pilih Mode: \n\t1. Tampilkan Layout \n\t2. Layouting Manual \n\t3. Tampilkan Routing \n\t4. Routing Manual");
    printf("\n\t5. Layout Otomatis \n\t6. Routing Otomatis \n\t7. Design Rule Checker \n\t8. Simpan Proyek dan Keluar\n");
    printf("Pilih Mode: ");
    scanf("%d", &mode);

    mode = cekmode(mode);

    while ((mode<=7)&&(mode>=1)){
        switch(mode){
            case 1 :
                tampilkanlayout(tabslay, panjang, lebar);
                break;
            case 2 :
                layout_manual(tabslay,panjang,lebar);
                break;
            case 3 :
                tampilkanrouting(tabsrout, panjang, lebar);
                break;
            case 4 :
                routing_manual(tabsrout,panjang,lebar);
                break;
            case 5 :
                layout_otomatis();
                break;
            case 6 :
                routing_otomatis();
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
        mode = cekmode(mode);
    }
    fclose(file1);
    fclose(file2);
    return ;
}

int main(){
    int n;

    printf("Menu : \n");
    printf("\t1. Buat Proyek Baru\n");
    printf("\t2. Muat Proyek dari Berkas\n");
    printf("\t3. Keluar\n");
    printf("Masukan: ");
    scanf("%d", &n);

    n = cekmenu(n);

    //jika menu 1 dan 2
    while ((n==2)||(n==1)){
        if (n==1){
            proyekbaru();
        }else {
            muat_proyek();
        }
        printf("Menu : \n");
        printf("\t1. Buat Proyek Baru\n");
        printf("\t2. Muat Proyek dari Berkas\n");
        printf("\t3. Keluar\n");
        printf("Masukan: ");
        scanf("%d", &n);
        n = cekmenu(n);
    }
    return 0;
}
