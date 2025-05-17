#include <iostream>
#include <string>
using namespace std;

class dosen;
class staff;
class universitas;

class mahasiswa
{
    private:
    string nama;
    int nim;
    float nilai; //dapat diubah dengan dosen

    public:
    mahasiswa(string nama, int nim):nama(nama), nim(nim), nilai(0){}
    
    friend class dosen; //agar dosen bisa mengakses mahasiswa
};

class dosen
{
    private:
    string nama;
    int nidn;
    string pangkat;
    float gaji;

    public:
    dosen(string nama, int nidn):nama(nama), nidn(nidn), pangkat("Asisten ahli"), gaji(2000000){}

    void berNilai(mahasiswa* m, float n)
    {
        m->nilai = n;
    }
    friend class staff; //agar staff bisa gaji dosen
    friend class universitas; //universitas bisa akses gaji dosen
    friend float melihatGajidosen(dosen* d);
};