#pragma once
#ifndef TOKO_GADGET_CPP
#define TOKO_GADGET_CPP

#include <iostream>
#include <string>
#include <vector>
#include "Produk.cpp"

using namespace std;

// Kelas TokoGadget yang menerapkan konsep Composition (has-a)
// TokoGadget memiliki kumpulan objek Produk yang disimpan dalam bentuk Array of Objects (vector<Produk*>)
class TokoGadget {
private:
    string namaToko;
    string alamat;
    vector<Produk*> daftarProduk;

public:
    // Constructor default
    TokoGadget() {
        this->namaToko = "";
        this->alamat = "";
    }

    // Constructor berparameter
    TokoGadget(string namaToko, string alamat) {
        this->namaToko = namaToko;
        this->alamat = alamat;
    }

    // Destructor untuk membersihkan heap memory seluruh objek Produk
    ~TokoGadget() {
        for (Produk* p : daftarProduk) {
            if (p != nullptr) {
                delete p;
            }
        }
        daftarProduk.clear();
    }

    // Getter dan Setter
    void setNamaToko(string namaToko) {
        this->namaToko = namaToko;
    }

    string getNamaToko() const {
        return this->namaToko;
    }

    void setAlamat(string alamat) {
        this->alamat = alamat;
    }

    string getAlamat() const {
        return this->alamat;
    }

    // Menambahkan produk ke dalam daftar (Array of Objects)
    void tambahProduk(Produk* produk) {
        if (produk != nullptr) {
            daftarProduk.push_back(produk);
        }
    }

    // Mengembalikan jumlah produk yang ada di dalam toko
    int getJumlahProduk() const {
        return static_cast<int>(daftarProduk.size());
    }

    // Menampilkan katalog toko menggunakan polimorfisme murni
    void tampilkanKatalog(const string& label) const {
        cout << "================================================================================" << endl;
        cout << "                   " << namaToko << endl;
        cout << "             " << alamat << endl;
        cout << "================================================================================" << endl;
        cout << " KATALOG PRODUK [" << label << "] (Jumlah: " << daftarProduk.size() << " Produk)" << endl;
        cout << "================================================================================" << endl;

        for (size_t i = 0; i < daftarProduk.size(); ++i) {
            cout << "[" << (i + 1) << "]" << endl;
            // Pemanggilan method virtual secara polimorfik tanpa if-else tipe
            daftarProduk[i]->displayInfo();
            if (i < daftarProduk.size() - 1) {
                cout << "--------------------------------------------------------------------------------" << endl;
            }
        }
        cout << "================================================================================" << endl;
        cout << endl;
    }
};

#endif
