# Bitácora de uso de IA generativa — EcoMisión

## ¿Para qué usamos IA generativa?

Usamos IA principalmente en tres momentos del proyecto:

1. **Para entender el enunciado** al inicio. Teníamos dudas sobre qué significaba "agregación" vs "composición" en el contexto del diagrama UML. Le preguntamos a la IA que nos explicara la diferencia con un ejemplo parecido al proyecto.

2. **Para revisar el primer diagrama de clases** antes de empezar a codificar. Queríamos saber si las relaciones que habíamos dibujado tenían sentido o si había algo que no cuadraba.

3. **Para entender errores de compilación** que no sabíamos leer. Especialmente el error que salió cuando intentamos asignar `this->nombre` en el constructor de `AnimalHerido` sin haber llamado al constructor de la clase base.

---

## ¿Qué decisión de diseño revisamos con IA?

La decisión de cómo guardar los elementos interactivos en `Zona`. Teníamos duda entre usar un `vector<ElementoInteractivo>` (sin puntero) o `vector<ElementoInteractivo*>` (con puntero).

La IA nos explicó que si guardábamos objetos directamente (sin puntero), C++ haría "object slicing" y perdería la parte específica de cada subclase, con lo que el polimorfismo no funcionaría. Eso no lo habíamos visto en clase todavía y no lo entendíamos del todo, pero lo comprobamos haciendo una prueba pequeña y efectivamente sin el puntero todos los elementos se comportaban igual.

---

## ¿Qué sugerencia de IA aceptamos y por qué?

Aceptamos la sugerencia de centralizar el atributo `usado` en la clase base `ElementoInteractivo` en lugar de repetirlo en cada subclase.

Al principio cada subclase tenía su propio bool (`curado`, `recolectada`, `limpiado`) para saber si ya había sido usado, y ninguna tenía un atributo común. La IA sugirió agregar `usado` en la clase base para no repetir la misma lógica de verificación en cada `interactuar()`.

Lo aceptamos porque tenía sentido: todos los elementos comparten ese comportamiento (verificar si ya fueron usados antes de hacer algo), y moverlo a la clase base lo hace más limpio. Además mantuvimos los bools propios de cada subclase (`curado`, `recolectada`, etc.) para guardar el estado específico.

---

## ¿Qué sugerencia de IA corregimos o rechazamos y por qué?

La IA sugirió en un momento usar `PortalDeRuta` con un `codigoDestino` (string) en lugar de `Zona*`, y que el portal buscara la zona en la reserva al momento de interactuar. Para eso el portal necesitaría una referencia a `Reserva`.

Lo rechazamos porque nos pareció innecesariamente complicado para lo que necesitábamos. Si el portal ya sabe a qué zona apunta desde que se crea, guardar `Zona*` directo es más simple y funciona igual. Agregar una dependencia entre `PortalDeRuta` y `Reserva` solo para buscar algo que ya podemos pasar directamente no tenía justificación.

También rechazamos el uso de `override` en las subclases. La IA lo incluía en todas las firmas de los métodos heredados. Investigamos y vimos que `override` es opcional en C++, y como en clase no lo habíamos visto, preferimos no usarlo para no incluir cosas que no sabríamos explicar en la sustentación.

---

| [Nombre 1] | Clase `ElementoInteractivo` y las subclases: por qué es abstracta, qué es polimorfismo, cómo funciona `interactuar()` en cada subclase |
| [Nombre 2] | Clase `Reserva` y `Zona`: por qué se usó `unordered_map`, cómo funciona la sobrecarga, qué es agregación |
| [Nombre 3] | Clase `Explorador` y `EcoMision`: cómo se coordina la demostración, qué es asociación, cómo cambia el estado del explorador |

> Nota: independientemente de la división, cada integrante debe poder explicar cualquier parte del código en la sustentación individual.
