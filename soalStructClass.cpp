#include <iostream>  // untuk input dan output
#include <vector> // untuk menyimpan banyak data secara dinamis
#include <string> // untuk menggunakan tipe data string 
#include <limits>  // untuk mengatur batas input 

using namespace std;

// ==========================================
// Bagian Moza
// ==========================================

// Class Mahasiswa untuk merepresentasikan setiap entitas mahasiswa
class Mahasiswa { // cetakan untuk membuat data mahasiswa 
private: // data disimpan di private agar tidak bisa diakses langsung dari luar class 
    string nama; // menyimpan nama mahasiswa
    string nim; // menyimpan NIM mahasiswa
    float ipk; // menyimpan nilai IPK mahasiswa 

public:
    // constructor untuk mengisi data awal mahasiswa
    Mahasiswa(string n, string m, float i) {
        nama = n; // isi variabel nama
        nim = m; // isi variabel nim
        ipk = i; // isi variabel ipk
    }

    // Getter untuk mengambil data pribadi (karena atribut bersifat private)
    string getNama() const { return nama; } // mengambil dan mengembalikan nama mahasiswa
    string getNim() const { return nim; } // mengambil dan mengembalikan NIM mahasiswa
    float getIpk() const { return ipk; } // mengambil dan mengembalikan IPK mahasiswa

    // Fungsi untuk menampilkan informasi mahasiswa ke layar
    void tampilkanData() const {
        cout << "NIM: " << nim << " | Nama: " << nama << " | IPK: " << ipk << endl;
    }
};

// ==========================================
// Bagian Kurnia
// ==========================================

// Fungsi pendukung untuk validasi input IPK agar tidak error jika user salah input text
float inputIPK() {
    float val; // variabel untuk meyimpan nilai IPK berupa desimal
    while (true) {//perulangan tanpa batas untuk terus meminta input sampai valid
        cin >> val; // proses membaca input angka dari user ke variabel val
        if (cin.fail() || val < 0.0 || val > 4.0) { // Kondisi jika input bukan angka, kurang dari 0, atau lebih dari 4.
            cin.clear(); //Memulihkan sistem input setelah mendeteksi adanya error/salah ketik.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Menghapus sisa teks salah yang tersisa di memori input buffer.
            cout << "Input tidak valid. Masukkan IPK antara 0.0 - 4.0: ";//Menampilkan pesan input tidak valid. Masukkan IPK antara 0.0 - 4.0 kepada user.
        } else { //Blok kode yang berjalan jika input dari pengguna sudah benar.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val; //menghapus sisa buffer lalu mengembalikan nilai IPK tersebut dan menghentikan perulangan.
        }
    }
}

int main() {
    vector<Mahasiswa> daftarMahasiswa;//Wadah dinamis untuk menyimpan kumpulan objek data dari class Mahasiswa.
    int pilihan;// Variabel untuk menyimpan angka menu pilihan dari user

    do { //Perulangan untuk terus menampilkan menu selama pengguna tidak memilih keluar.
        cout << "\n====================================\n";
        cout << "Menu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Seluruh Data Mahasiswa\n";
        cout << "3. Hitung Rata-rata IPK Mahasiswa\n";
        cout << "4. Mahasiswa dengan IPK Tertinggi\n";
        cout << "5. Mahasiswa dengan IPK Terendah\n";
        cout << "6. Keluar\n";
        cout << "====================================\n";
        cout << "Pilih menu (1-6): "; // Menampilkan teks menu pilihan 1 sampai 6 ke layar.
        
        if (!(cin >> pilihan)) { //Kondisi jika pengguna memasukkan input menu yang bukan angka.
            cin.clear();//Memulihkan sistem input setelah mendeteksi adanya error/salah ketik.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Menghapus sisa teks salah yang tersisa di memori input buffer.
            cout << "Pilihan tidak valid. Silakan coba lagi.\n"; // menampilkan pesan ke user yaitu Pilihan tidak valid. Silakan coba lagi. 
            continue;//Langsung melompat kembali ke awal perulangan untuk menampilkan menu lagi.
        }
        cin.ignore(); // Membersihkan satu karakter sisa (tombol enter) agar input teks berikutnya normal.

// ==========================================
// Bagian Bunga
// ==========================================

        switch (pilihan) { // menggunakan switch case untuk pilihan menu
            case 1: {
                 // menambahkan data mahasiswa baru
                string nama, nim;  // menyimpan nama dan NIM sementara
                float ipk; // menyimpan IPK sementara

                cout << "Masukkan Nama: ";
                getline(cin, nama); // menggunakan getline agar bisa input nama dengan spasi
                cout << "Masukkan NIM: ";
                getline(cin, nim); // menggunakan getline agar bisa input nim secara utuh dan dapat mengatasi jika user menggunakan spasi
                cout << "Masukkan IPK: ";
                ipk = inputIPK(); // menggunakan fungsi inputIPK untuk validasi input IPK

                // Membuat objek baru dan memasukkannya ke dalam vector
                daftarMahasiswa.push_back(Mahasiswa(nama, nim, ipk));
                cout << "Data mahasiswa berhasil ditambahkan!\n";
                break;
            }
            case 2: {
                // menampilkan seluruh data mahasiswa beserta informasi masing-masing
                if (daftarMahasiswa.empty()) { // cek apakah vector kosong
                    cout << "Belum ada data mahasiswa.\n"; // jika kosong, tampilkan pesan "Belum ada data mahasiswa."
                } else { //jika tidak kosong, tampilkan seluruh data mahasiswa
                    cout << "\n--- Data Seluruh Mahasiswa ---\n"; 
                    for (const auto& mhs : daftarMahasiswa) { // iterasi melalui vector dan menampilkan data setiap mahasiswa
                        mhs.tampilkanData();// memanggil metode tampilkanData untuk setiap mahasiswa
                    }
                }
                break;
            }
            case 3: {
                // menghitung rata-rata IPK dari seluruh mahasiswa
                if (daftarMahasiswa.empty()) {  // cek apakah vector kosong
                    cout << "Belum ada data mahasiswa untuk dihitung.\n"; // jika kosong, tampilkan pesan "Belum ada data mahasiswa untuk dihitung."
                } else { // jika tidak kosong, hitung rata-rata IPK
                    float totalIpk = 0; // menyimpan total IPK dan buat nilai awalnya 0
                    for (const auto& mhs : daftarMahasiswa) {  // iterasi melalui vector dan menjumlahkan IPK setiap mahasiswa
                        totalIpk += mhs.getIpk();  // menambahkan IPK setiap mahasiswa ke totalIpk
                    }
                    float rataRata = totalIpk / daftarMahasiswa.size();  // menghitung rata-rata IPK dengan membagi totalIpk dengan jumlah mahasiswa
                    cout << "Rata-rata IPK Mahasiswa: " << rataRata << endl;  // menampilkan hasil rata-rata IPK
                }
                break;
            }
            case 4: {
                // menampilkan mahasiswa dengan IPK tertinggi
                if (daftarMahasiswa.empty()) { // cek apakah vector kosong
                    cout << "Belum ada data mahasiswa.\n"; // jika kosong, tampilkan pesan "Belum ada data mahasiswa."
                } else { // jika tidak kosong, cari mahasiswa dengan IPK tertinggi
                    Mahasiswa tertinggi = daftarMahasiswa[0]; // inisialisasi mahasiswa tertinggi dengan mahasiswa pertama dalam vector
                    for (size_t i = 1; i < daftarMahasiswa.size(); ++i) {  // iterasi melalui vector mulai dari indeks 1 untuk mencari mahasiswa dengan IPK tertinggi
                        if (daftarMahasiswa[i].getIpk() > tertinggi.getIpk()) { 
                            tertinggi = daftarMahasiswa[i]; // jika IPK mahasiswa saat ini lebih tinggi dari IPK mahasiswa tertinggi, update mahasiswa tertinggi
                        }
                    }
                    cout << "\n--- Mahasiswa IPK Tertinggi ---\n"; // menampilkan mahasiswa dengan IPK tertinggi
                    tertinggi.tampilkanData();// ambil data mahasiswa di variabel tertinggi, lalu cetak seluruh datanya ke layar."
                }
                break;
            }
            case 5: {
                // menampilkan mahasiswa dengan IPK terendah
                if (daftarMahasiswa.empty()) { // cek apakah vector kosong
                    cout << "Belum ada data mahasiswa.\n";  // jika kosong, tampilkan pesan "Belum ada data mahasiswa."
                } else { // jika tidak kosong, cari mahasiswa dengan IPK terendah
                    Mahasiswa terendah = daftarMahasiswa[0];  // inisialisasi mahasiswa terendah dengan mahasiswa pertama dalam vector
                    for (size_t i = 1; i < daftarMahasiswa.size(); ++i) {  // iterasi melalui vector mulai dari indeks 1 untuk mencari mahasiswa dengan IPK terendah
                        if (daftarMahasiswa[i].getIpk() < terendah.getIpk()) {
                            terendah = daftarMahasiswa[i]; // jika IPK mahasiswa saat ini lebih rendah dari IPK mahasiswa terendah, update mahasiswa terendah
                        }
                    }
                    cout << "\n--- Mahasiswa IPK Terendah ---\n"; // menampilkan mahasiswa dengan IPK terendah
                    terendah.tampilkanData(); // ambil data mahasiswa di variabel terendah, lalu cetak seluruh datanya ke layar."
                }
                break;
            }
            case 6:
                // keluar dari program
                cout << "Terima kasih! Program selesai.\n"; // menampilkan pesan sebelum keluar
                break;
            default: // jika pilihan tidak valid, tampilkan pesan
                cout << "Menu tidak tersedia. Silakan pilih 1-6.\n";
        }
    } while (pilihan != 6); // loop terus berjalan sampai user memilih 6 untuk keluar

    return 0;
}
