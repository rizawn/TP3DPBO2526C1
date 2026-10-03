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

    // Helper untuk membuat teks rata tengah (80 kolom)
    string centerText(const string& text, int width = 80) const {
        if (static_cast<int>(text.length()) >= width) return text;
        int padding = (width - static_cast<int>(text.length())) / 2;
        string res = string(padding, ' ') + text;
        while (static_cast<int>(res.length()) < width) res += " ";
        return res;
    }

    // Menampilkan katalog toko menggunakan polimorfisme murni (2 kotak kesamping)
    void tampilkanKatalog(const string& label = "") const {
        cout << "================================================================================" << endl;
        cout << centerText(namaToko, 80) << endl;
        cout << centerText(alamat, 80) << endl;
        cout << "================================================================================" << endl;

        if (daftarProduk.empty()) {
            cout << centerText("KATALOG PRODUK (Katalog masih kosong!)", 80) << endl;
            cout << "================================================================================" << endl;
            cout << " [!] Katalog masih kosong! (Belum ada produk)." << endl;
            cout << "     Silakan gunakan menu [2] Tambah Produk atau [3] Muat Data Sampel Awal." << endl;
        } else {
            string headerCount = "KATALOG PRODUK (" + to_string(daftarProduk.size()) + " Produk)";
            if (daftarProduk.size() == 1) {
                headerCount = "KATALOG PRODUK (1 Produk)";
            }
            cout << centerText(headerCount, 80) << endl;
            cout << "================================================================================" << endl;

            for (size_t i = 0; i < daftarProduk.size(); i += 2) {
                vector<string> card1 = daftarProduk[i]->getCardLines(static_cast<int>(i + 1));
                bool hasSecond = (i + 1 < daftarProduk.size());
                vector<string> card2;
                if (hasSecond) {
                    card2 = daftarProduk[i + 1]->getCardLines(static_cast<int>(i + 2));
                }

                for (size_t lineIdx = 0; lineIdx < card1.size(); ++lineIdx) {
                    cout << card1[lineIdx];
                    if (hasSecond && lineIdx < card2.size()) {
                        cout << "  " << card2[lineIdx];
                    }
                    cout << endl;
                }
                if (i + 2 < daftarProduk.size()) {
                    cout << endl;
                }
            }
        }

        cout << "================================================================================" << endl;
        cout << endl;
    }
};

#endif
