#pragma once
#include "ElementoInteractivo.h"

class ResiduoContaminante : public ElementoInteractivo {
private:
    string tipo;
    bool limpiado;

public:
    ResiduoContaminante(string tipo);

    void interactuar(Explorador* explorador);
    void mostrarInfo();
};
