#include <iostream>
using namespace std;
class buku
{
    string judul;

    public:
    buku setJudul(string buku)
    {
        this->judul = judul;
        return *this;  //chain function
    }
    string getJudul()
    {
        return this->judul;
    }

}bukunya;