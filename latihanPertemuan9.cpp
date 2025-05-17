#include <iostream>
#include <string>
using namespace std;

class dosen;
class universitas;

class mahasiswa
{
    private:
    string nama;
    int nim;
    float nilai; //dapat diubah dengan dosen

    public:
    mahasiswa(string nama, int nim):nama(nama), nim(nim), nilai(0){}
    
    void tampilkanData()
    {
        cout << "nim" << nim << endl;
        cout << "nilai" << nilai << endl;
    }
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
    dosen(string nama, int nidn):nama(nama), nidn(nidn), pangkat(pangkat), gaji(2000000){}

    void berNilai(mahasiswa* m, float n)
    {
        m->nilai = n;
    }
    void tampilkanData()
    {
        cout << "nama dosen" << nama << endl;
        cout << "nidn" << nidn << endl;
        cout << "pangkat dosen" << pangkat << endl;
    }
    friend class staff; //agar staff bisa gaji dosen
    friend class universitas; //universitas bisa akses gaji dosen
    friend float melihatGajidosen(dosen* d);
};

float melihatGajidosen(dosen* d)
{
    d->gaji;
    return;
}

class staff
{
    private:
    string nama;
    int idstaff;
    float gaji;

    public:
    staff(string nama, int idstaff):nama(nama), idstaff(idstaff), gaji(100000){}

    void ubahpangkat(dosen* d, string pangkatbaru)
    {
        d->pangkat = pangkatbaru;
    }
    void tampilkanData()
    {
        cout << "nama satff" << nama << endl;
        cout << "id staff" << idstaff << endl;
    }
    friend float melihatgajistaff(staff* s);
};

int main(){
    mahasiswa mhs1("Adi", 23456);
    dosen dsn("Budi", 5678, "Asisten Ahli", 10000000);
    staf stf("Tia", 2, 200000);

    dsn.beriNilai(&mhs1, 90);
    mhs1.tampilkanInfo();
    dsn.tampilkanInfo();
    LihatGajiDosen(&dsn);
    stf.ubahPangkat(&dsn, "Lektor");
    dsn.tampilkanInfo();
    stf.tampilkanInfo();
    LihatGajiStaf(&stf);

return 0;
}
