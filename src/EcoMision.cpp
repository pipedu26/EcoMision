#include "EcoMision.h"
#include "AnimalHerido.h"
#include "PlantaMedicinal.h"
#include "ResiduoContaminante.h"
#include "PortalDeRuta.h"
#include "EstacionEnergia.h"

EcoMision::EcoMision() {
    this->reserva = nullptr;
    this->explorador = nullptr;
}

void EcoMision::iniciar() {
    cout << "================================" << endl;
    cout << "      Bienvenido a EcoMision    " << endl;
    cout << "================================" << endl;

    // creo la reserva con "bosque" como zona inicial
    reserva = new Reserva("bosque");

    // creo las zonas
    Zona* bosque = new Zona("bosque", "Bosque Humedo");
    Zona* rio    = new Zona("rio",    "Rio Contaminado");
    Zona* centro = new Zona("centro", "Centro de Recuperacion Animal");

    // agrego elementos al bosque
    bosque->agregarElemento(new AnimalHerido("venado"));
    bosque->agregarElemento(new PlantaMedicinal("curativa"));
    bosque->agregarElemento(new PortalDeRuta(rio));

    // agrego elementos al rio
    rio->agregarElemento(new ResiduoContaminante("plastico"));
    rio->agregarElemento(new ResiduoContaminante("quimico"));
    rio->agregarElemento(new EstacionEnergia(30));
    rio->agregarElemento(new PortalDeRuta(centro));

    // agrego elementos al centro
    centro->agregarElemento(new AnimalHerido("aguila"));
    centro->agregarElemento(new EstacionEnergia(50));

    // registro las zonas en la reserva con su codigo
    reserva->agregarZona("bosque", bosque);
    reserva->agregarZona("rio",    rio);
    reserva->agregarZona("centro", centro);

    // creo el explorador y lo ubico en la zona inicial
    explorador = new Explorador("Alex", 100);
    Zona* zonaInicial = reserva->buscarZona(reserva->getCodigoInicial());
    explorador->cambiarZona(zonaInicial);

    cout << "\nExplorador \"" << explorador->getNombre()
         << "\" listo en: " << zonaInicial->getNombre() << endl;
}

void EcoMision::ejecutarDemostracion() {
    cout << "\n======= INICIO DE DEMOSTRACION =======" << endl;

    // muestro todas las zonas registradas
    reserva->mostrarZonas();

    // --- Zona 1: Bosque Humedo ---
    Zona* zona = explorador->getZonaActual();
    cout << "\n>>> Zona actual: " << zona->getNombre() << endl;
    zona->mostrarElementos();

    cout << "\n> Interactuando con elemento [0] (por indice):" << endl;
    zona->interactuar(0, explorador);

    cout << "\n> Interactuando con \"Planta medicinal\" (por nombre):" << endl;
    zona->interactuar("Planta medicinal", explorador);

    explorador->mostrarEstado();

    // uso el portal para pasar al rio
    cout << "\n> Usando el portal [2] (por indice):" << endl;
    zona->interactuar(2, explorador);

    // --- Zona 2: Rio Contaminado ---
    zona = explorador->getZonaActual();
    cout << "\n>>> Zona actual: " << zona->getNombre() << endl;
    zona->mostrarElementos();

    cout << "\n> Limpiando residuo [0] (por indice):" << endl;
    zona->interactuar(0, explorador);

    cout << "\n> Usando \"Estacion de energia\" (por nombre):" << endl;
    zona->interactuar("Estacion de energia", explorador);

    explorador->mostrarEstado();

    // uso el portal para pasar al centro
    cout << "\n> Usando el portal [3] (por indice):" << endl;
    zona->interactuar(3, explorador);

    // --- Zona 3: Centro de Recuperacion ---
    zona = explorador->getZonaActual();
    cout << "\n>>> Zona actual: " << zona->getNombre() << endl;
    zona->mostrarElementos();

    cout << "\n> Curando al aguila [0] (por indice):" << endl;
    zona->interactuar(0, explorador);

    cout << "\n======= FIN DE DEMOSTRACION =======" << endl;
    explorador->mostrarEstado();
}

void EcoMision::mostrarEstado() {
    explorador->mostrarEstado();
}
