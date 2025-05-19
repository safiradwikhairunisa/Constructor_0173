#include <iostream>
using namespace std;

class mahasiswa{
    private:
        static int jmlmhs;
    public:
        string status;
        string nama;
        int nim;
        mahasiswa(string pnama, int pnim){
            status = "Mahasiswa baru ";
            nama = pnama;
            nim = pnim;
            cout << "Mahasiswa dibuat " << nama << endl;
            cout << "status " << status << endl;
            ++jmlmhs;
        };
        ~mahasiswa(){
            cout << "Mahasiswa dengan nama " << nama << " dihancurkan " << endl;
            -- jmlmhs;
        };
        static int gettotalmhs(){
            return jmlmhs;
        };
};

int mahasiswa::jmlmhs = 0;

int main(){
    cout << "Jumlah mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    mahasiswa mhs1("Rudi", 28);
    mahasiswa mhs2("Joko", 73);
    mhs2.status = "Mahasiswa uzur";
    cout << mhs2.status << endl;
    mahasiswa mhs3("Wowo", 63);
    cout << "Jumlah mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    {
        mahasiswa mhs4("pra", 98);
        cout << "Jumlah mahasiswa dalam bracket = " << mahasiswa::gettotalmhs() << endl;
    }
    cout << "Jumlah mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    return 0;
};