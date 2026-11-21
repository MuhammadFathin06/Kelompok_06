#include <iostream>
#include <cstring>
using namespace std;

struct Buku {
    char kodeBuku[10], judul[50], penulis[50];
    int tahunTerbit, stok;
};

const int MAX_BUKU = 100;
Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

void tampilkanHeader() {
    cout << "\n===================================\n";
    cout << "   MANAJEMEN PERPUSTAKAAN (CLI)    \n";
    cout << "===================================\n";
}

void tampilkanMenu() {
    cout << "1. Lihat Semua Buku\n";
    cout << "2. Tambah Buku\n";
    cout << "3. Cari Buku\n";
    cout << "4. Ubah Buku\n";
    cout << "5. Hapus Buku\n";
    cout << "6. Statistik\n";
    cout << "7. Keluar\n";
    cout << "-----------------------------------\n";
}

void tampilkanSemuaBuku() {
    tampilkanHeader();
    cout << "--- DAFTAR BUKU ---\n\n";

    if (jumlahBuku == 0) {
        cout << "Belum ada data buku.\n";
        return;
    } 

    for (int i = 0; i < jumlahBuku; i++) {
        cout << i + 1 << ". Kode : " << daftarBuku[i].kodeBuku << endl;
        cout << "   Judul : " << daftarBuku[i].judul << endl;
        cout << "   Penulis: " << daftarBuku[i].penulis << endl;
        cout << "   Tahun : " << daftarBuku[i].tahunTerbit << endl;
        cout << "   Stok  : " << daftarBuku[i].stok << " eks\n";
        cout << "-----------------------------------\n";
    }
}

void tambahBuku() {
    tampilkanHeader();
    cout << "--- TAMBAH BUKU ---\n\n";

    if (jumlahBuku >= MAX_BUKU) {
        cout << "Penyimpanan penuh!\n";
        return;
    }

    Buku b ;
    cout << "Kode Buku  : ";
    cin >> b.kodeBuku;

    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].kodeBuku, b.kodeBuku)== 0) {
            cout << "Kode sudah ada!\n";
            return;
        }
    }

    cout << "Judul Buku : ";
    cin.getline(b.judul, 50);

    cout << "Penulis    : ";
    cin.getline(b.penulis, 50);

    cout << "Tahun Terbit: ";
    cin >> b.tahunTerbit;

    cout << "Stok       : ";
    cin >> b.stok;

    daftarBuku[jumlahBuku] = b;
    jumlahBuku++;
    cout << "\nBuku berhasil ditambah!\n";
}

void cariBuku() {
    tampilkanHeader();
    cout << "--- CARI BUKU ---\n\n";

    if (jumlahBuku == 0) {
        cout << "Data kosong.\n";
        return;
    }

    char cari[10];
    cout << "Masukkan Kode: ";
    cin >> cari;

    bool ketemu = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].kodeBuku, cari)==0) {
            cout << "\nDitemukan!\n";
            cout << "Judul : " << daftarBuku[i].judul << endl;
            cout << "Penulis: " << daftarBuku[i].penulis << endl;
            cout << "Tahun : " << daftarBuku[i].tahunTerbit << endl;
            cout << "Stok  : " << daftarBuku[i].stok << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu) cout << "Tidak ditemukan.\n";
}

void ubahBuku() {
    tampilkanHeader();
    cout << "--- UBAH BUKU ---\n\n";

    char kode[10];
    cout << "Kode Buku yang diubah: ";
    cin >> kode;

    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].kodeBuku, kode)== 0) {
            cin.ignore();
            cout << "Judul Baru : ";
            cin.getline(daftarBuku[i].judul, 50);

            cout << "Penulis Baru: ";
            cin.getline(daftarBuku[i].penulis, 50);

            cout << "Tahun Baru : ";
            cin >> daftarBuku[i].tahunTerbit;

            cout << "Stok Baru  : ";
            cin >> daftarBuku[i].stok;

            cout << "\nBerhasil diubah!\n";
            return;
        }
    }
    cout << "Kode tidak ditemukan.\n";
}

void hapusBuku() {
    tampilkanHeader();
    cout << "--- HAPUS BUKU ---\n\n";

    char kode[10];
    cout << "Kode Buku yang dihapus: ";
    cin >> kode;

    int idx = -1;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].kodeBuku, kode)==0) {
            idx = i;
            break;
        }
    }

    if (idx != -1) {
        for (int i = idx; i < jumlahBuku - 1; i++) {
            daftarBuku[i] = daftarBuku[i + 1];
        }
        jumlahBuku--;
        cout << "Buku berhasil dihapus!\n";
    } else {
        cout << "Kode tidak ditemukan.\n";
    }
}

void hitungStatistikPerpus() {
    tampilkanHeader();
    cout << "--- STATISTIK ---\n\n";

    if (jumlahBuku == 0) {
        cout << "Data kosong.\n";
        return;
    }

    int totalStok = 0;
    int maxStok = daftarBuku[0].stok;
    int minStok = daftarBuku[0].stok;
    int idxMax = 0, idxMin = 0;

    for (int i = 0; i < jumlahBuku; i++) {
        totalStok += daftarBuku[i].stok;
        if (daftarBuku[i].stok > maxStok) {
            maxStok = daftarBuku[i].stok;
            idxMax = i;
        }
        if (daftarBuku[i].stok < minStok) {
            minStok = daftarBuku[i].stok;
            idxMin = i;
        }
    }

    cout << "Total Judul Buku : " << jumlahBuku << endl;
    cout << "Total Semua Stok : " << totalStok << endl;
    cout << "Stok Terbanyak   : " << daftarBuku[idxMax].judul << " (" << maxStok << ")\n";
    cout << "Stok Tersedikit  : " << daftarBuku[idxMin].judul << " (" << minStok << ")\n";
}

int main() {
      
    int pilihan = 0;

    do {
        tampilkanHeader();
        tampilkanMenu();
        cout << "Pilih (1-7): ";

        if (!(cin >> pilihan)) {
            cout << "Input salah!\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        switch (pilihan) {
            case 1: tampilkanSemuaBuku(); break;
            case 2: tambahBuku(); break;
            case 3: cariBuku(); break;
            case 4: ubahBuku(); break;
            case 5: hapusBuku(); break;
            case 6: hitungStatistikPerpus(); break;
            case 7: 
                cout << "=============================" << endl;
                cout << "  SAYONARA SEMUA BUKU AMAN   " << endl;
                cout << "=============================" << endl;
                break;
            default: cout << "Pilihan tidak valid.\n";
        }

        if (pilihan != 7) {
            cout << "\nTekan Enter...";
            cin.ignore(100, '\n');
            cin.get();
        }

    } while (pilihan != 7);

    return 0;
}