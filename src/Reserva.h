#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include "Zona.h"

using namespace std;

class Reserva {
private:
    unordered_map<string, Zona*> zonas;
    string codigoInicial;

public:
    Reserva(string codigoInicial);

    void agregarZona(string codigo, Zona* zona);
    Zona* buscarZona(string codigo);
    string getCodigoInicial();
    void mostrarZonas();
};
