#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Entrada{
    private:
        string  mesprint,dia,hora,min,seg,ip,razon;
        struct tm fechastr;
        vector <string> mes = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        time_t date;

    public:
        Entrada(string mes, string dia, string hora, string min, string seg, string ip, string razon);
        void imprimeEntrada();
        string getMes();
        int getDia();
        int getHora();
        int getMin();
        int getSeg();
        string getDiastr();
        string getHorastr();
        string getMinstr();
        string getSegstr();
        string getIp();
        string getRazon();
        bool operator <=(const Entrada&);
        void ordenaMerge(vector<Entrada>& lista, int low, int high);
};

#endif