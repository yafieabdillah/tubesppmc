#include <stdio.h>

void cekmenu(int n){
    while ((n>=4)||(n<=0)){
        printf("Masukan salah\n");
        printf("Masukan: ");
        scanf("%d", &n);
    }
    return n;
}

void proyekbaru(){
    printf("proyek BARU jalan\n");
}

void proyekberkas(){
    printf("proyek BERKAS jalan\n");
}

int main(){
    int n;

    printf("Menu : \n");
    printf("\t1. Buat Proyek Baru\n");
    printf("\t2. Muat Proyek dari Berkas\n");
    printf("\t3. Keluar\n");
    printf("Masukan: ");
    scanf("%d", &n);

    cekmenu(n);

    while ((n==2)||(n==1)){
        if (n==1){
            proyekbaru();
        }else {
            proyekberkas();
        }
        printf("Menu : \n");
        printf("\t1. Buat Proyek Baru\n");
        printf("\t2. Muat Proyek dari Berkas\n");
        printf("\t3. Keluar\n");
        printf("Masukan: ");
        scanf("%d", &n);
        cekmenu(n);
    }
    return 0;
}
