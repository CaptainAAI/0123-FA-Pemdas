/**
* @mainpage Sistem Manajemen matkul dan nilai
*
* @section intro_sec Pengantar
* Selamat datang di dokumentasi UAS PEMDAS
* Sistem ini dirancang untuk menghitung nilai suatu matkul
*
* @section structure_sec Struktur Kode
* Kode ini terdiri dari tiga kelas utama:
* - \b MataKuliah: Menangani operasi yang terkait dengan nilai Matkul
* - \b Pemrograman: Menangani informasi tentang dengan nilai Matkul Pemrogaman
* - \b Jaringan: Menangani informasi tentang dengan nilai Matkul Jaringan
*
* @section setup_sec Setup dan Konfigurasinya
* Untuk menjalankan sistem ini, pastikan Anda memiliki compiler yang mendukung C++.
*
* @section author_sec Tentang Pengembang
* Sistem ini dikembangkan oleh saya sendiri sebagai bagian dari UCP3 UAS.
* 
* 
* 
*
* @section note_sec Catatan
* Dokumentasi ini dihasilkan menggunakan Doxygen.
*/

/**
 * @file UASPemdas.cpp
 * @brief Sistem penilaian.
 *
 * File ini berisi implementasi dari Seluruh materi PemDas.
 */


#include <iostream>
using namespace std;

/**
 * @class Matakuliah
 * @brief Kelas untuk menangani variable penilaian
 */

// Kelas dasar MataKuliah
class MataKuliah { // isi dengan access modifier yang dibutuhkan
private:
    float presensi; /**< bagian penilaian */
    float activity; /**< bagian penilaian */
    float exercise; /**< bagian penilaian */
    float tugasAkhir; /**< bagian penilaian */

public:
    MataKuliah()
    {
        // isi dengan inisialisasi variabel yang dibutuhkan dibawah ini
        presensi = 0.0;
        activity = 0.0;
        exercise = 0.0;
        tugasAkhir = 0.0;

    }

    // Getter dan setter untuk presensi
    void setPresensi(float nilai)
    {
        this->presensi = nilai;
    }
    float getPresensi()
    {
        return presensi;
    }

    // Getter dan setter untuk activity
    void setActivity(float nilai)
    {
        activity = nilai;
    }
    float getActivity()
    {
        return activity;
    }

    // Getter dan setter untuk exercise
    void setExercise(float nilai)
    {
        exercise = nilai;
    }
    float getExercise()
    {
        return exercise;
    }

    // Getter dan setter untuk tugasAkhir
    void setTugasAkhir(float nilai)
    {
        tugasAkhir = nilai;
    }
    float getTugasAkhir()
    {
        return tugasAkhir;
    }

    // Metode virtual yang akan di- oleh kelas turunan
    virtual void namaMataKuliah() = 0;
    virtual void inputNilai(float pres, float act, float ex, float ta) = 0;
    virtual float hitungNilaiAkhir() = 0;
    virtual void cekKelulusan() = 0;
};

/**
 * @class Pemrogaman
 * @brief Kelas untuk menangani variable penilaian Matkul Pemrogaman
 */

// Kelas Pemrograman turunan dari MataKuliah
class Pemrograman : public MataKuliah {
public:
    void namaMataKuliah()  {
        cout << "Mata Kuliah: Pemrograman\n"; 
    }

    void inputNilai(float pres, float act, float ex, float ta)  {
        setPresensi(pres);
        setActivity(act);
        setExercise(ex);
        setTugasAkhir(ta);
    }

    float hitungNilaiAkhir()  {
        // Menghitung nilai akhir berdasarkan bobot tertentu
        return ( 0.1 * getPresensi() ) + ( 0.3 * getActivity() ) + ( 0.3 * getExercise() )  + ( 0.3 * getTugasAkhir() ) ;
    }

    void cekKelulusan()  {
        if (hitungNilaiAkhir() >= 75) {
            cout << "Anda Lulus Pemrograman dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
        else {
            cout << "Maaf, Anda Tidak Lulus Pemrograman dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
    }
};

/**
 * @class Jaringan
 * @brief Kelas untuk menangani variable penilaian Matkul Jaringan
 */

// Kelas Jaringan turunan dari MataKuliah
class Jaringan : public MataKuliah {
public:
    void namaMataKuliah()  { cout << "Mata Kuliah: Jaringan\n"; }

    void inputNilai(float pres, float act, float ex, float ta)  {
        setPresensi(pres);
        setActivity(act);
        setExercise(ex);
        setTugasAkhir(ta);
    }

    float hitungNilaiAkhir()  {
        // Menghitung nilai akhir berdasarkan bobot tertentu
        return (0.1 * getPresensi()) + (0.3 * getActivity()) + (0.3 * getExercise()) + (0.3 * getTugasAkhir());
    }

    void cekKelulusan()  {
        if (hitungNilaiAkhir() >= 75) {
            cout << "Anda Lulus Jaringan dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
        else {
            cout << "Maaf, Anda Tidak Lulus Jaringan dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
    }
};

/**
 * @class databaseabd
 * @brief Kelas untuk menangani variable penilaian Matkul databaseabd
 */

// Kelas databaseabd turunan dari MataKuliah
class databaseabd : public MataKuliah {
public:
    void namaMataKuliah()  { cout << "Mata Kuliah: databaseabd\n"; }

    void inputNilai(float pres, float act, float ex, float ta)  {
        setPresensi(pres);
        setActivity(act);
        setExercise(ex);
        setTugasAkhir(ta);
    }

    float hitungNilaiAkhir()  {
        // Menghitung nilai akhir berdasarkan bobot tertentu
        return (0.1 * getPresensi()) + (0.1 * getActivity()) + (0.1 * getExercise()) + (0.7 * getTugasAkhir());
    }

    void cekKelulusan()  {
        if (hitungNilaiAkhir() >= 75) {
            cout << "Anda Lulus databaseabd dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
        else {
            cout << "Maaf, Anda Tidak Lulus databaseabd dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
    }
};

/**
 * @brief Fungsi utama yang menjalankan program
 * @return 0 jika eksekusi berhasil
 */

int main() {

    char pilih;
    MataKuliah* mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;
    databaseabd database1;

    cout << "Pilih mata kuliah yang ingin dihitung nilai akhirnya:\n";
    cout << "1. Pemrograman\n";
    cout << "2. Jaringan\n";
    cout << "3. databaseabd\n";
    cout << "Pilihan Anda: ";
    cin >> pilih;

    
    switch (pilih) {
    case '1':
        mataKuliah = &pemrograman;
        break;
    case '2':
        mataKuliah = &jaringan;
        break;
    case '3':
        mataKuliah = &database1;
        break;
    default:
        cout << "Pilihan tidak valid.\n";
        return 0;
    }

    float pres, act, ex, ta;
    cout << "Masukkan nilai Presensi: ";
    cin >> pres;
    cout << "Masukkan nilai Activity: ";
    cin >> act;
    cout << "Masukkan nilai Exercise: ";
    cin >> ex;
    cout << "Masukkan nilai Tugas Akhir: ";
    cin >> ta;


    mataKuliah->inputNilai(pres, act, ex, ta);
    mataKuliah->namaMataKuliah();
    cout << "Nilai Akhir: " << mataKuliah->hitungNilaiAkhir() << endl;
    mataKuliah->cekKelulusan();

    return 0;

}
