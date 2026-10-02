# TP3 DPBO 2026 – Inventori Toko "Gadget & Gaming Rig Hub"

## Janji

Saya **Riza Wahyu Nugraha** dengan **NIM 2511421** mengerjakan **Tugas Praktikum 3** dalam mata kuliah **Desain dan Pemrograman Berorientasi Objek** untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

---

## Deskripsi Program

Program ini adalah sistem inventori katalog untuk toko **"Gadget & Gaming Rig Hub"** yang berlokasi di **Jl. Merdeka No. 45, Bandung**. Toko ini mengelola berbagai perlengkapan komputer dan ekosistem gaming yang terbagi ke dalam empat kategori utama:
1. **Sparepart PC Desktop** (Komponen seperti GPU, Processor, PSU).
2. **Sparepart Laptop** (Komponen khusus notebook seperti RAM SODIMM, Baterai).
3. **Periferal Desktop** (Peralatan input/output seperti Keyboard Mechanical, Mouse Gaming, Headset).
4. **Gaming Furniture** (Perabot setup gaming seperti Kursi Gaming Ergonomis, Meja Gaming Elektrik, Monitor Stand).

Sistem diimplementasikan secara identik pada tiga bahasa pemrograman berorientasi objek:
- **C++** (Menggunakan header `.h` dan implementasi `.cpp` modular, serta pointer polimorfik)
- **Python** (Menggunakan class modular dengan enkapsulasi private `__` dan `super()`)
- **Java** (Menggunakan *abstract class*, *inheritance*, dan *ArrayList*)

---

## Konsep OOP yang Diterapkan

1. **Hierarchical Inheritance (Pewarisan Hirarkis):**  
   Terdapat satu kelas induk (*superclass*), yaitu `Produk`, yang mewariskan atribut umum (`id`, `nama`, `brand`, `harga`, `stok`) serta perilaku `displayInfo()` kepada **empat kelas anak (*subclasses*)**:
   - `Produk` $\rightarrow$ `SparepartPc`
   - `Produk` $\rightarrow$ `SparepartLaptop`
   - `Produk` $\rightarrow$ `Periferal`
   - `Produk` $\rightarrow$ `GamingFurniture`

2. **Composition (Komposisi - Hubungan *Has-A*):**  
   Kelas `TokoGadget` memiliki (*has-a*) relasi kepemilikan kuat terhadap kumpulan `Produk`. Toko mengelola siklus hidup objek-objek produk di dalamnya. Pada C++, destructor `TokoGadget` secara bertanggung jawab membebaskan alokasi memori (*heap memory*) dari seluruh produk saat objek toko dihancurkan.

3. **Array of Objects:**  
   Katalog inventaris disimpan dalam bentuk struktur data dinamis kumpulan objek:
   - **C++:** `std::vector<Produk*>`
   - **Python:** `list` of `Produk`
   - **Java:** `ArrayList<Produk>`

4. **Pure Polymorphism (Polimorfisme Murni):**  
   Method `displayInfo()` dideklarasikan virtual/abstrak pada kelas `Produk` dan dioverride secara spesifik oleh masing-masing kelas turunan. Saat menampilkan katalog di dalam `TokoGadget`, iterasi hanya memanggil `produk->displayInfo()` tanpa adanya pengecekan tipe kondisi `if-else` atau `instanceof/type()`. Sistem runtime secara dinamis menentukan implementasi method yang sesuai (*dynamic dispatch*).

---

## Diagram Class

### Visualisasi Diagram (Mermaid)

```mermaid
classDiagram
    class Produk {
        <<abstract>>
        #String id
        #String nama
        #String brand
        #double harga
        #int stok
        +formatRupiah(nilai: double) String
        +displayInfo()* void
    }

    class SparepartPc {
        -int dayaWatt
        -String formFactor
        +displayInfo() void
    }

    class SparepartLaptop {
        -String tipeKompatibel
        -int garansiBulan
        +displayInfo() void
    }

    class Periferal {
        -String koneksi
        -String tipeFitur
        +displayInfo() void
    }

    class GamingFurniture {
        -String material
        -double bebanMaksKg
        +displayInfo() void
    }

    class TokoGadget {
        -String namaToko
        -String alamat
        -List~Produk~ daftarProduk
        +tambahProduk(produk: Produk) void
        +tampilkanKatalog(label: String) void
        +getJumlahProduk() int
    }

    Produk <|-- SparepartPc : Hierarchical Inheritance
    Produk <|-- SparepartLaptop : Hierarchical Inheritance
    Produk <|-- Periferal : Hierarchical Inheritance
    Produk <|-- GamingFurniture : Hierarchical Inheritance
    TokoGadget *-- Produk : Composition (1 to *)
```

### Representasi Teks (ASCII)

```text
                       +---------------------------------------+
                       |           <<abstract>>                |
                       |              Produk                   |
                       +---------------------------------------+
                       | # id       : String                   |
                       | # nama     : String                   |
                       | # brand    : String                   |
                       | # harga    : double                   |
                       | # stok     : int                      |
                       +---------------------------------------+
                       | + displayInfo()*                      |
                       +---------------------------------------+
                                          ^
                                          | (Hierarchical Inheritance)
          +-------------------+-----------+-----------+--------------------+
          |                   |                       |                    |
+-------------------+ +---------------------+ +------------------+ +-----------------------+
|    SparepartPc    | |   SparepartLaptop   | |    Periferal     | |    GamingFurniture    |
+-------------------+ +---------------------+ +------------------+ +-----------------------+
| - dayaWatt: int   | | - tipeKompatibel:str| | - koneksi: str   | | - material: str       |
| - formFactor: str | | - garansiBulan: int | | - tipeFitur: str | | - bebanMaksKg: double |
+-------------------+ +---------------------+ +------------------+ +-----------------------+
| + displayInfo()   | | + displayInfo()     | | + displayInfo()  | | + displayInfo()       |
+-------------------+ +---------------------+ +------------------+ +-----------------------+
          ^                   ^                       ^                    ^
          |                   |                       |                    |
          +-------------------+-----------+-----------+--------------------+
                                          *
                                          | (Composition: has-a)
                       +---------------------------------------+
                       |              TokoGadget               |
                       +---------------------------------------+
                       | - namaToko     : String               |
                       | - alamat       : String               |
                       | - daftarProduk : List<Produk*>        |
                       +---------------------------------------+
                       | + tambahProduk(Produk) : void         |
                       | + tampilkanKatalog(String) : void     |
                       | + getJumlahProduk() : int             |
                       +---------------------------------------+
```

---

## Tabel Atribut dan Methods

### 1. Tabel Atribut

| Kelas Pemilik | Nama Atribut | Tipe Data | Akses | Keterangan |
| :--- | :--- | :--- | :--- | :--- |
| **Produk** | `id` | String | Protected / Private | Kode unik identifikasi produk (contoh: `PC-001`, `LP-001`) |
| **Produk** | `nama` | String | Protected / Private | Nama lengkap produk |
| **Produk** | `brand` | String | Protected / Private | Merk manufaktur / pabrikan |
| **Produk** | `harga` | Double | Protected / Private | Harga jual satuan (Rupiah) |
| **Produk** | `stok` | Integer | Protected / Private | Ketersediaan kuantitas unit barang |
| **SparepartPc** | `dayaWatt` | Integer | Private | Estimasi konsumsi daya dalam satuan Watt |
| **SparepartPc** | `formFactor` | String | Private | Ukuran/soket dudukan (misal: `PCIe x16`, `AM4`, `ATX`) |
| **SparepartLaptop** | `tipeKompatibel`| String | Private | Tipe soket/modul kompatibilitas laptop (misal: `DDR4 SODIMM`) |
| **SparepartLaptop** | `garansiBulan` | Integer | Private | Masa garansi perlindungan resmi dalam bulan |
| **Periferal** | `koneksi` | String | Private | Jenis sambungan (misal: `Wired`, `Wireless`) |
| **Periferal** | `tipeFitur` | String | Private | Fitur utama penunjang (misal: `RGB Switch`, `25.600 DPI`) |
| **GamingFurniture** | `material` | String | Private | Bahan dasar pembuatan perabot |
| **GamingFurniture** | `bebanMaksKg` | Double | Private | Kapasitas beban maksimal dalam kilogram |
| **TokoGadget** | `namaToko` | String | Private | Nama identitas toko retail |
| **TokoGadget** | `alamat` | String | Private | Lokasi operasional toko |
| **TokoGadget** | `daftarProduk` | Array of Objects | Private | Koleksi/wadah list produk yang dijual di toko |

---

### 2. Tabel Methods

| Kelas | Nama Method | Return Type | Parameter | Keterangan |
| :--- | :--- | :--- | :--- | :--- |
| **Produk** | `Produk()` | Constructor | - | Menginisialisasi nilai default |
| **Produk** | `Produk(...)` | Constructor | `id`, `nama`, `brand`, `harga`, `stok` | Mengisi nilai atribut kelas induk |
| **Produk** | `getId()`, `setId()` | String / void | `id` (pada setter) | Getter dan setter kode ID produk |
| **Produk** | `getNama()`, `setNama()` | String / void | `nama` (pada setter) | Getter dan setter nama produk |
| **Produk** | `getBrand()`, `setBrand()`| String / void | `brand` (pada setter) | Getter dan setter merk produk |
| **Produk** | `getHarga()`, `setHarga()`| double / void | `harga` (pada setter) | Getter dan setter harga |
| **Produk** | `getStok()`, `setStok()` | int / void | `stok` (pada setter) | Getter dan setter kuantitas stok |
| **Produk** | `formatRupiah()` | String | `nilai: double` | Helper pemformat nominal angka ke format Rupiah |
| **Produk** | `displayInfo()` | void (abstract) | - | Blueprint method penampilan data (wajib di-override) |
| **SparepartPc** | `displayInfo()` | void | - | Override: menampilkan identitas produk + daya & form factor |
| **SparepartLaptop**| `displayInfo()` | void | - | Override: menampilkan identitas produk + kompatibilitas & garansi |
| **Periferal** | `displayInfo()` | void | - | Override: menampilkan identitas produk + jenis koneksi & fitur |
| **GamingFurniture**| `displayInfo()` | void | - | Override: menampilkan identitas produk + bahan & beban maksimal |
| **TokoGadget** | `TokoGadget(...)` | Constructor | `namaToko`, `alamat` | Menginisialisasi toko dan alokasi array inventaris |
| **TokoGadget** | `tambahProduk()` | void | `Produk*` / `Produk` | Menambahkan item baru ke dalam koleksi inventaris |
| **TokoGadget** | `tampilkanKatalog()` | void | `label: String` | Mencetak header toko dan mendaftar seluruh produk via polimorfisme |
| **TokoGadget** | `getJumlahProduk()` | int | - | Mengembalikan banyaknya produk aktif yang terdata |

---

## Penjelasan Alur Program dan UX Interaktif

Program ini mengusung antarmuka terminal interaktif (*interactive CLI UX*) layaknya sistem kasir/manajemen toko retail sungguhan:

1. **Welcoming Entrance:**  
   Saat pertama kali dijalankan, program menampilkan banner selamat datang megah bertuliskan **GADGET & GAMING RIG HUB** beserta informasi alamat toko di Bandung.
2. **Menu Utama Interaktif:**  
   Pengguna disajikan 4 menu pilihan:
   - `[1] Lihat Katalog Produk Toko`: Menampilkan katalog produk secara polimorfik. Jika inventaris masih kosong (belum ada input), sistem menampilkan pesan informatif bahwa data masih kosong (0 produk).
   - `[2] Tambah Produk Baru (Pilih Kategori)`: Membuka sub-menu pemilihan kategori dengan form input yang disesuaikan (*customized layout*).
   - `[3] Muat Data Sampel Awal (8 Produk Default)`: Memuat 8 data sampel secara instan untuk kemudahan pengujian/demo.
   - `[4] Keluar dari Toko`: Menutup program dengan pesan terima kasih.
3. **Pemisahan Form Input Berdasarkan Kategori:**  
   Layout formulir dipisahkan secara dinamis sesuai kebutuhan atribut spesifik masing-masing kelas:
   - **Sparepart PC Desktop:** Input atribut umum + Konsumsi Daya (W) & Form Factor/Slot.
   - **Sparepart Laptop:** Input atribut umum + Kompatibilitas Soket/Tipe & Garansi Resmi (Bulan).
   - **Periferal Desktop:** Input atribut umum + Tipe Konektivitas & Fitur Unggulan.
   - **Gaming Furniture:** Input atribut umum + Bahan/Material & Beban Maksimal (Kg).
4. **Verifikasi Output Sebelum dan Sesudah Input:**  
   Pengguna dapat memeriksa katalog saat masih kosong (`[DATA KOSONG / SEBELUM INPUT]`), kemudian melakukan penambahan produk baru (baik manual maupun sampel), lalu melihat kembali daftar barang jualan yang telah terisi (`[LIVE STATUS]`) secara rapi dan polimorfik.

---

## Panduan Kompilasi dan Eksekusi

### 1. C++
Masuk ke direktori program C++:
```bash
cd tp3/CPP/Program
g++ main.cpp -o main.exe
./main.exe
```

### 2. Python
Masuk ke direktori program Python:
```bash
cd tp3/Python/Program
python main.py
```

### 3. Java
Masuk ke direktori program Java:
```bash
cd tp3/Java/Program
javac *.java
java Main
```

---

## Dokumentasi Output Program

### 1. C++
* **Sebelum Penambahan:**  
  ![C++ Sebelum Penambahan](CPP/Dokumentasi/cpp_sebelum.png)
* **Setelah Penambahan:**  
  ![C++ Setelah Penambahan](CPP/Dokumentasi/cpp_setelah.png)

### 2. Python
* **Sebelum Penambahan:**  
  ![Python Sebelum Penambahan](Python/Dokumentasi/python_sebelum.png)
* **Setelah Penambahan:**  
  ![Python Setelah Penambahan](Python/Dokumentasi/python_setelah.png)

### 3. Java
* **Sebelum Penambahan:**  
  ![Java Sebelum Penambahan](Java/Dokumentasi/java_sebelum.png)
* **Setelah Penambahan:**  
  ![Java Setelah Penambahan](Java/Dokumentasi/java_setelah.png)
