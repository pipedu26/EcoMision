#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Zona;

class Explorador {
private:
    string nombre;
    int energia;
    int puntajeAmbiental;
    Zona* zonaActual;
    vector<string> inventario;

public:
    Explorador(string nombre, int energia);

    void perderEnergia(int cantidad);
    void recuperarEnergia(int cantidad);
    void aumentarPuntaje(int puntos);
    void recolectar(string item);
    void cambiarZona(Zona* zona);

    Zona* getZonaActual();
    string getNombre();
    int getEnergia();
    int getPuntaje();

    void mostrarEstado();
};
