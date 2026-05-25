#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ElementoInteractivo.h"

using namespace std;

class Explorador;

class Zona {
private:
    string codigo;
    string nombre;
    vector<ElementoInteractivo*> elementos;

public:
    Zona(string codigo, string nombre);

    string getCodigo();
    string getNombre();

    void agregarElemento(ElementoInteractivo* e);
    void mostrarElementos();

    // sobrecarga: se puede interactuar por indice o por nombre
    void interactuar(int indice, Explorador* exp);
    void interactuar(string nombreElemento, Explorador* exp);
};
