#pragma once
#include "Reserva.h"
#include "Explorador.h"

class EcoMision {
private:
    Reserva* reserva;
    Explorador* explorador;

public:
    EcoMision();

    void iniciar();
    void ejecutarDemostracion();
    void mostrarEstado();
};
