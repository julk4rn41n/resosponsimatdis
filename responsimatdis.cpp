#include <iostream>
using namespace std;

void kombinasi(int index, int mulai, int jumlah, int Perkelompok, string nama[], string kelompok[], int &total){
    if(index == Perkelompok){
    	//loop output kommbinasi orang
        cout<<"Kombinasi "<< (total + 1)<<": ";
        for(int i = 0; i < Perkelompok; i++){
        	cout<< kelompok[i]<<" ";
        }
        cout<< endl;
        total++;
        return;
    }
    //Loop kombinasi
    for(int i = mulai; i < jumlah; i++){
        kelompok[index] = nama[i];
        kombinasi(index + 1, i + 1, jumlah, Perkelompok, nama, kelompok, total);
    }
}
int main() {
    int jumlah, PerKelompok, total = 0;
    cout<<"=== PROGRAM UNTUK MENENTUKAN KOMBINASI PADA KELOMPOK ===\n";
    cout<<"Masukkan jumlah orang : "; cin>> jumlah;
	string nama[jumlah];
	//Menggecek apakah jumlah orang lebih dari 0
    if(jumlah < 0){
        cout<<"Jumlah mahasiswa harus lebih dari 0.\n";
        return 1;
    }
    for(int i = 0; i < jumlah; i++) {
        cout<<"Nama orang ke-"<< (i + 1)<<": "; cin>> nama[i];
    }
    cout<<"Masukkan jumlah anggota per kelompok: "; cin>> PerKelompok;
	string kelompok[PerKelompok];
	//menggecek apakah orang dalam setiap kelompok itu lebih dari 1 atau jumlah orang kurang dari jumlah banyak orang dalam setiap kelompok 
    if(PerKelompok < 1 || PerKelompok > jumlah){
        cout<<"Jumlah per kelompok tidak valid.\n";
        return 1;
    }
    int index = 0;
    cout<<"\n=== Semua Kombinasi Kelompok ===\n";
    kombinasi(index, 0, jumlah, PerKelompok, nama, kelompok, total);
    cout<<"\nJumlah kombinasi kelompok: "<< total<< endl;
    return 0;
}
