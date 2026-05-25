#include "Zona.h"
#include "Explorador.h"

Zona::Zona(string codigo, string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

string Zona::getCodigo() {
    return codigo;
}

string Zona::getNombre() {
    return nombre;
}

void Zona::agregarElemento(ElementoInteractivo* e) {
    elementos.push_back(e);
}

void Zona::mostrarElementos() {
    cout << "\nElementos en " << nombre << ":" << endl;
    if (elementos.empty()) {
        cout << "  (no hay elementos)" << endl;
        return;
    }
    for (int i = 0; i < elementos.size(); i++) {
        cout << "  [" << i << "] ";
        elementos[i]->mostrarInfo();
    }
}

// interactuar por indice
void Zona::interactuar(int indice, Explorador* exp) {
    if (indice < 0 || indice >= elementos.size()) {
        cout << "  Indice invalido." << endl;
        return;
    }
    elementos[indice]->interactuar(exp);
}

// interactuar por nombre del elemento
void Zona::interactuar(string nombreElemento, Explorador* exp) {
    for (int i = 0; i < elementos.size(); i++) {
        if (elementos[i]->getNombre() == nombreElemento) {
            elementos[i]->interactuar(exp);
            return;
        }
    }
    cout << "  No se encontro el elemento: " << nombreElemento << endl;
}
