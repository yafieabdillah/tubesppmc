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
