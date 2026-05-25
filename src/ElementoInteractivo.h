#pragma once
#include <string>
#include <iostream>

using namespace std;

class Explorador;

class ElementoInteractivo {
protected:
    string nombre;
    bool usado;

public:
    ElementoInteractivo();
    ElementoInteractivo(string nombre);

    string getNombre();
    bool isUsado();

    virtual void interactuar(Explorador* explorador) = 0;
    virtual void mostrarInfo() = 0;
};
