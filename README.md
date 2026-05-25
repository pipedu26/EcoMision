# EcoMisión

## Integrantes

> *(Completar con los nombres reales del equipo)*

- Juan Felipe Duran Chaparro
---

## Descripción

EcoMisión es un prototipo de experiencia interactiva en consola sobre cuidado ambiental, desarrollado como proyecto final de Programación Orientada a Objetos (2026-1) en la Pontificia Universidad Javeriana Cali.

Un explorador recorre una reserva natural compuesta por varias zonas. En cada zona encuentra elementos del entorno con los que puede interactuar: curar animales heridos, recolectar plantas medicinales, limpiar residuos contaminantes, usar estaciones de energía y moverse entre zonas a través de portales.

El proyecto aplica los cuatro pilares de POO: abstracción, encapsulamiento, herencia y polimorfismo.

---

## Cómo compilar y ejecutar

### Requisitos
- CLion (recomendado) o cualquier compilador con soporte C++17
- CMake 3.26 o superior

### En CLion
1. Descomprimir el proyecto
2. Abrir CLion → `File > Open` → seleccionar la carpeta `EcoMision`
3. CLion detecta el `CMakeLists.txt` automáticamente
4. Clic en el botón `Run` (triángulo verde)

### En terminal
```bash
cd EcoMision
mkdir build && cd build
cmake ..
make
./EcoMision
```

---

## Archivos principales

```
EcoMision/
├── CMakeLists.txt
├── .gitignore
├── README.md
├── src/
│   ├── main.cpp
│   ├── EcoMision.h / EcoMision.cpp        → coordina toda la experiencia
│   ├── Reserva.h / Reserva.cpp            → colección de zonas con unordered_map
│   ├── Zona.h / Zona.cpp                  → zona con sobrecarga en interactuar()
│   ├── Explorador.h / Explorador.cpp      → explorador con energía, puntaje e inventario
│   ├── ElementoInteractivo.h / .cpp       → clase abstracta base
│   ├── AnimalHerido.h / .cpp              → sube puntaje, baja energía
│   ├── PlantaMedicinal.h / .cpp           → agrega ítem al inventario
│   ├── ResiduoContaminante.h / .cpp       → baja energía, sube puntaje
│   ├── PortalDeRuta.h / .cpp              → cambia la zona del explorador
│   └── EstacionEnergia.h / .cpp           → recupera energía
└── docs/
    ├── diseno.md                           → diagramas UML y matriz de decisiones
    └── bitacora-ia.md                      → registro del uso de IA generativa
```

---

## Conceptos de POO aplicados

| Concepto | Dónde aparece |
|---|---|
| Clase abstracta | `ElementoInteractivo` con `interactuar()` y `mostrarInfo()` puros |
| Herencia | `AnimalHerido`, `PlantaMedicinal`, `ResiduoContaminante`, `PortalDeRuta`, `EstacionEnergia` heredan de `ElementoInteractivo` |
| Polimorfismo | `Zona` llama `interactuar()` sobre `ElementoInteractivo*` y cada subclase responde diferente |
| Sobrecarga | `Zona::interactuar(int, Explorador*)` y `Zona::interactuar(string, Explorador*)` |
| Encapsulamiento | Todos los atributos son privados o protegidos, acceso solo por métodos |
| Asociación | `Explorador` conoce su `Zona* zonaActual` pero no la posee |
| Agregación | `Zona` contiene `vector<ElementoInteractivo*>` y `Reserva` contiene `unordered_map<string, Zona*>` |
| Composición | `EcoMision` crea y posee `Reserva` y `Explorador` |
| `unordered_map` | `Reserva` administra las zonas usando el código como clave |

---

## Ejemplo de salida

```
================================
      Bienvenido a EcoMision
================================

Explorador "Alex" listo en: Bosque Humedo

======= INICIO DE DEMOSTRACION =======

=== Zonas de la reserva ===
  [bosque] Bosque Humedo
  [rio] Rio Contaminado
  [centro] Centro de Recuperacion Animal

>>> Zona actual: Bosque Humedo

Elementos en Bosque Humedo:
  [0] Animal herido (venado)
  [1] Planta medicinal - curativa
  [2] Portal de ruta -> Rio Contaminado

> Interactuando con elemento [0] (por indice):
  Curas al venado herido...
  Alex gano 15 puntos ambientales. Total: 15
  Alex perdio 10 de energia. Energia restante: 90
```
