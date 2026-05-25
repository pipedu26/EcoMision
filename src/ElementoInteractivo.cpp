#include "ElementoInteractivo.h"

ElementoInteractivo::ElementoInteractivo() {
    this->nombre = "";
    this->usado = false;
}

ElementoInteractivo::ElementoInteractivo(string nombre) {
    this->nombre = nombre;
    this->usado = false;
}

string ElementoInteractivo::getNombre() {
    return nombre;
}

bool ElementoInteractivo::isUsado() {
    return usado;
}
