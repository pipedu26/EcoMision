#include "Explorador.h"
#include "Zona.h"

Explorador::Explorador(string nombre, int energia) {
    this->nombre = nombre;
    this->energia = energia;
    this->puntajeAmbiental = 0;
    this->zonaActual = nullptr;
}

void Explorador::perderEnergia(int cantidad) {
    this->energia = this->energia - cantidad;
    // que no quede en negativo
    if (this->energia < 0) {
        this->energia = 0;
    }
    cout << "  " << nombre << " perdio " << cantidad
         << " de energia. Energia restante: " << this->energia << endl;
}

void Explorador::recuperarEnergia(int cantidad) {
    this->energia = this->energia + cantidad;
    // que no pase de 100
    if (this->energia > 100) {
        this->energia = 100;
    }
    cout << "  " << nombre << " recupero " << cantidad
         << " de energia. Energia actual: " << this->energia << endl;
}

void Explorador::aumentarPuntaje(int puntos) {
    this->puntajeAmbiental = this->puntajeAmbiental + puntos;
    cout << "  " << nombre << " gano " << puntos
         << " puntos ambientales. Total: " << this->puntajeAmbiental << endl;
}

void Explorador::recolectar(string item) {
    inventario.push_back(item);
    cout << "  " << nombre << " recolecto: " << item << endl;
}

void Explorador::cambiarZona(Zona* zona) {
    this->zonaActual = zona;
}

Zona* Explorador::getZonaActual() {
    return zonaActual;
}

string Explorador::getNombre() {
    return nombre;
}

int Explorador::getEnergia() {
    return energia;
}

int Explorador::getPuntaje() {
    return puntajeAmbiental;
}

void Explorador::mostrarEstado() {
    cout << "\n--- Estado de " << nombre << " ---" << endl;
    cout << "  Energia:           " << energia << endl;
    cout << "  Puntaje ambiental: " << puntajeAmbiental << endl;
    if (zonaActual != nullptr) {
        cout << "  Zona actual:       " << zonaActual->getNombre() << endl;
    }
    cout << "  Inventario: ";
    if (inventario.empty()) {
        cout << "(vacio)" << endl;
    } else {
        for (int i = 0; i < inventario.size(); i++) {
            cout << inventario[i] << "  ";
        }
        cout << endl;
    }
}
