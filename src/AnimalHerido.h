#pragma once
#include "ElementoInteractivo.h"

class AnimalHerido : public ElementoInteractivo {
private:
    string especie;
    bool curado;

public:
    AnimalHerido(string especie);

    void interactuar(Explorador* explorador);
    void mostrarInfo();
};
