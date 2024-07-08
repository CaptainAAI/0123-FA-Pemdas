/**
* @mainpage Sistem Manajemen Matkul dan Nilai
*
* @section intro_sec Pengantar
* Selamat datang di dokumentasi UAS PEMDAS.
* Sistem ini dirancang untuk menghitung nilai suatu mata kuliah.
*
* @section structure_sec Struktur Kode
* Kode ini terdiri dari tiga kelas utama:
* - \b MataKuliah: Menangani operasi yang terkait dengan nilai Matkul
* - \b Pemrograman: Menangani informasi tentang nilai Matkul Pemrogaman
* - \b Jaringan: Menangani informasi tentang nilai Matkul Jaringan
* - \b Databaseabd: Menangani informasi tentang nilai Matkul Databaseabd
*
* @section setup_sec Setup dan Konfigurasinya
* Untuk menjalankan sistem ini, pastikan Anda memiliki compiler yang mendukung C++.
*
* @section author_sec Tentang Pengembang
* Sistem ini dikembangkan oleh saya sendiri sebagai bagian dari UCP3 UAS.
*
* @section note_sec Catatan
* Dokumentasi ini dihasilkan menggunakan Doxygen.
*/

/**
 * @file UASPemdas.cpp
 * @brief Sistem penilaian.
 *
 * File ini berisi implementasi dari seluruh materi PemDas.
 */

#include <iostream>
using namespace std;

/**
 * @class MataKuliah
 * @brief Kelas untuk menangani variable penilaian
 */
class MataKuliah {
private:
    float presensi; /**< Nilai presensi */
    float activity; /**< Nilai aktivitas */
    float exercise; /**< Nilai latihan */
    float tugasAkhir; /**< Nilai tugas akhir */

public:
    /**
     * @brief Konstruktor default
     *
     * Menginisialisasi semua nilai penilaian dengan 0.0.
     */
    MataKuliah() {
        presensi = 0.0;
        activity = 0.0;
        exercise = 0.0;
        tugasAkhir = 0.0;
    }

    // Getter dan setter untuk presensi
    /**
     * @brief Mengatur nilai presensi
     * @param nilai Nilai presensi
     */
    void setPresensi(float nilai) {
        this->presensi = nilai;
    }

    /**
     * @brief Mendapatkan nilai presensi
     * @return Nilai presensi
     */
    float getPresensi() {
        return presensi;
    }

    // Getter dan setter untuk activity
    /**
     * @brief Mengatur nilai aktivitas
     * @param nilai Nilai aktivitas
     */
    void setActivity(float nilai) {
        activity = nilai;
    }

    /**
     * @brief Mendapatkan nilai aktivitas
     * @return Nilai aktivitas
     */
    float getActivity() {
        return activity;
    }

    // Getter dan setter untuk exercise
    /**
     * @brief Mengatur nilai latihan
     * @param nilai Nilai latihan
     */
    void setExercise(float nilai) {
        exercise = nilai;
    }

    /**
     * @brief Mendapatkan nilai latihan
     * @return Nilai latihan
     */
    float getExercise() {
        return exercise;
    }

    // Getter dan setter untuk tugasAkhir
    /**
     * @brief Mengatur nilai tugas akhir
     * @param nilai Nilai tugas akhir
     */
    void setTugasAkhir(float nilai) {
        tugasAkhir = nilai;
    }

    /**
     * @brief Mendapatkan nilai tugas akhir
     * @return Nilai tugas akhir
     */
    float getTugasAkhir() {
        return tugasAkhir;
    }

    /**
     * @brief Metode virtual untuk mendapatkan nama mata kuliah
     */
    virtual void namaMataKuliah() = 0;

    /**
     * @brief Metode virtual untuk memasukkan nilai
     * @param pres Nilai presensi
     * @param act Nilai aktivitas
     * @param ex Nilai latihan
     * @param ta Nilai tugas akhir
     */
    virtual void inputNilai(float pres, float act, float ex, float ta) = 0;

    /**
     * @brief Metode virtual untuk menghitung nilai akhir
     * @return Nilai akhir
     */
    virtual float hitungNilaiAkhir() = 0;

    /**
     * @brief Metode virtual untuk mengecek kelulusan
     */
    virtual void cekKelulusan() = 0;
};

/**
 * @class Pemrograman
 * @brief Kelas untuk menangani variable penilaian Matkul Pemrogaman
 */
class Pemrograman : public MataKuliah {
public:
    /**
     * @brief Mendapatkan nama mata kuliah
     */
    void namaMataKuliah() {
        cout << "Mata Kuliah: Pemrograman\n";
    }

    /**
     * @brief Memasukkan nilai
     * @param pres Nilai presensi
     * @param act Nilai aktivitas
     * @param ex Nilai latihan
     * @param ta Nilai tugas akhir
     */
    void inputNilai(float pres, float act, float ex, float ta) {
        setPresensi(pres);
        setActivity(act);
        setExercise(ex);
        setTugasAkhir(ta);
    }

    /**
     * @brief Menghitung nilai akhir
     * @return Nilai akhir
     */
    float hitungNilaiAkhir() {
        return (0.1 * getPresensi()) + (0.3 * getActivity()) + (0.3 * getExercise()) + (0.3 * getTugasAkhir());
    }

    /**
     * @brief Mengecek kelulusan
     */
    void cekKelulusan() {
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
class Jaringan : public MataKuliah {
public:
    /**
     * @brief Mendapatkan nama mata kuliah
     */
    void namaMataKuliah() {
        cout << "Mata Kuliah: Jaringan\n";
    }

    /**
     * @brief Memasukkan nilai
     * @param pres Nilai presensi
     * @param act Nilai aktivitas
     * @param ex Nilai latihan
     * @param ta Nilai tugas akhir
     */
    void inputNilai(float pres, float act, float ex, float ta) {
        setPresensi(pres);
        setActivity(act);
        setExercise(ex);
        setTugasAkhir(ta);
    }

    /**
     * @brief Menghitung nilai akhir
     * @return Nilai akhir
     */
    float hitungNilaiAkhir() {
        return (0.1 * getPresensi()) + (0.3 * getActivity()) + (0.3 * getExercise()) + (0.3 * getTugasAkhir());
    }

    /**
     * @brief Mengecek kelulusan
     */
    void cekKelulusan() {
        if (hitungNilaiAkhir() >= 75) {
            cout << "Anda Lulus Jaringan dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
        else {
            cout << "Maaf, Anda Tidak Lulus Jaringan dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
    }
};

/**
 * @class Databaseabd
 * @brief Kelas untuk menangani variable penilaian Matkul Databaseabd
 */
class Databaseabd : public MataKuliah {
public:
    /**
     * @brief Mendapatkan nama mata kuliah
     */
    void namaMataKuliah() {
        cout << "Mata Kuliah: Databaseabd\n";
    }

    /**
     * @brief Memasukkan nilai
     * @param pres Nilai presensi
     * @param act Nilai aktivitas
     * @param ex Nilai latihan
     * @param ta Nilai tugas akhir
     */
    void inputNilai(float pres, float act, float ex, float ta) {
        setPresensi(pres);
        setActivity(act);
        setExercise(ex);
        setTugasAkhir(ta);
    }

    /**
     * @brief Menghitung nilai akhir
     * @return Nilai akhir
     */
    float hitungNilaiAkhir() {
        return (0.1 * getPresensi()) + (0.1 * getActivity()) + (0.1 * getExercise()) + (0.7 * getTugasAkhir());
    }

    /**
     * @brief Mengecek kelulusan
     */
    void cekKelulusan() {
        if (hitungNilaiAkhir() >= 75) {
            cout << "Anda Lulus Databaseabd dengan nilai akhir " << hitungNilaiAkhir() << endl;
        }
        else {
            cout << "Maaf, Anda Tidak Lulus Databaseabd dengan nilai akhir " << hitungNilaiAkhir() << endl;
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
    Databaseabd database1;

    cout << "Pilih mata kuliah yang ingin dihitung nilai akhirnya:\n";
    cout << "1. Pemrograman\n";
    cout << "2. Jaringan\n";
    cout << "3. Databaseabd\n";
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

