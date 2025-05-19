#include <iostream>
#include <string>

class PembalapF1 {
private:
    std::string nama;
    int posisi;
    float point;

public:
    PembalapF1(std::string n, int p) {
        nama = n;
        posisi = p;
        point = hitungPoint(posisi);
    }

    //untuk menghitung poin berdasarkan posisi pembalap
    float hitungPoint(int posisi) {
        if (posisi == 1){
            return 25;
        } else if (posisi == 2){
            return 18;
        } else if (posisi == 3){
            return 15;
        } else if (posisi == 4){
            return 12;
        } else if (posisi == 5){
            return 10;
        } else if (posisi == 6){
            return 8;
        } else if (posisi == 7){
            return 6;
        } else if (posisi == 8){
            return 4;
        } else if (posisi == 9){
            return 2;
        } else if (posisi == 10){
            return 1;
        } else {
            return 0;
        }
    }

    //untuk menampilkan info pembalap
    void printInfo() {
        std::cout << "Point yang diperoleh " << nama << "adalah +" << point << std::endl;
    }
};

int main() {
    int jumlahPembalap;
    std::cout << "Masukkan jumlah pembalap: ";
    std::cin >> jumlahPembalap;

    PembalapF1** pembalap = new PembalapF1*[jumlahPembalap];

    std::string nama;
    int posisi;

    for (int i = 0; i < jumlahPembalap; i++) {
        std::cin >> nama >> posisi;
        pembalap[i] = new PembalapF1(nama, posisi);
    }

    for (int i = 0; i < jumlahPembalap; i++) {
        pembalap[i]->printInfo();
        delete pembalap[i];
    }
    return 0;
}
