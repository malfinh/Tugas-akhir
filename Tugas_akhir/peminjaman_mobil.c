#include <stdio.h>
#include <string.h>

char namaPeminjam[100][50];
char mobilDipinjam[100][50];
int jumlahPeminjam = 0;

void pinjamMobil() {
    if (jumlahPeminjam >= 100) {
        printf("Maaf, kapasitas peminjaman sudah penuh.\n");
        return;
    }

    printf("Masukkan nama peminjam: ");
    scanf("%s", namaPeminjam[jumlahPeminjam]);
    
    printf("Masukkan nama mobil yang dipinjam: ");
    scanf("%s", mobilDipinjam[jumlahPeminjam]);
    
    jumlahPeminjam++;
    printf("Mobil berhasil dipinjam!\n");
}

void lihatPeminjaman() {
    if (jumlahPeminjam == 0) {
        printf("Tidak ada peminjaman saat ini.\n");
        return;
    }

    printf("Daftar peminjaman:\n");
    for (int i = 0; i < jumlahPeminjam; i++) {
        printf("Peminjam: %s, Mobil: %s\n", namaPeminjam[i], mobilDipinjam[i]);
    }
}

void kembalikanMobil() {
    char nama[50];
    printf("Masukkan nama peminjam yang ingin mengembalikan mobil: ");
    scanf("%s", nama);
    
    int found = -1;
    for (int i = 0; i < jumlahPeminjam; i++) {
        if (strcmp(namaPeminjam[i], nama) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Peminjam tidak ditemukan.\n");
        return;
    }

    // Hapus peminjaman
    for (int i = found; i < jumlahPeminjam - 1; i++) {
        strcpy(namaPeminjam[i], namaPeminjam[i + 1]);
        strcpy(mobilDipinjam[i], mobilDipinjam[i + 1]);
    }
    jumlahPeminjam--;
    printf("Mobil berhasil dikembalikan!\n");
}

int main() {
    int pilihan;

    do {
        printf("\nMenu Peminjaman Mobil\n");
        printf("1. Pinjam Mobil\n");
        printf("2. Lihat Peminjaman\n");
        printf("3. Kembalikan Mobil\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                pinjamMobil();
                break;
            case 2:
                lihatPeminjaman();
                break;
            case 3:
                kembalikanMobil();
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 4);

    return 0;
}