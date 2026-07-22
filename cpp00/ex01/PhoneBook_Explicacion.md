# PhoneBook: El Arte del Encapsulamiento y Flujos en C++98

El ejercicio **My Awesome PhoneBook** representa tu transición oficial de la programación imperativa en C a la **Programación Orientada a Objetos (POO)** en C++98. A través de este proyecto, aprendes a proteger el estado interno de tus objetos y a interactuar con la terminal mediante flujos tipados y seguros.

---

## 1. El Enigma del "Darkest Secret" (El Secreto más Oscuro)

### ¿Por qué no aparece en la tabla de `SEARCH` pero sí se almacena?

El diseño del comando `SEARCH` sigue un patrón clásico de interfaz de usuario: **Vista de Resumen vs. Vista de Detalle**.

1.  **La Vista de Resumen (La Tabla de 4 Columnas):**
    *   Muestra solo `Index`, `First Name`, `Last Name` y `Nickname`.
    *   **Propósito:** Proveer una lista compacta y rápida de los contactos disponibles. Mostrar campos confidenciales como el número de teléfono o datos personales comprometedores (el secreto más oscuro) en una lista pública violaría el principio de privacidad del diseño de software.
2.  **La Vista de Detalle (Búsqueda por Índice):**
    *   Cuando el usuario introduce el índice del contacto deseado, el programa imprime **todos y cada uno de los campos, uno por línea**, incluyendo el número de teléfono y el **secreto más oscuro**.
    *   **Propósito:** Revelar la información completa del contacto de forma segura y controlada solo a petición del usuario.

> **En resumen:** El "Darkest Secret" no se muestra en la tabla general por privacidad y diseño de pantalla, pero sí se revela cuando accedes al detalle del contacto.

---

## 2. Los Pilares de la Programación Orientada a Objetos

### A. Encapsulamiento Estricto
En C, las variables dentro de una estructura eran accesibles por cualquiera:
```c
// C - Inseguro por defecto
struct Contact {
    char first_name[50];
};
...
contact.first_name[0] = '\0'; // Cualquiera puede corromper el dato
```

En C++, el encapsulamiento protege el estado de un objeto declarando sus atributos como `private`. Nadie fuera de la clase puede leerlos o modificarlos directamente. En su lugar, usamos métodos `public` para interactuar con ellos:
*   **Setters (Modificadores):** Validan e introducen datos en el objeto.
*   **Getters (Accesores):** Devuelven el dato de forma segura. Nota el uso del calificador `const`:
    ```cpp
    std::string getFirstName(void) const;
    ```
    Este `const` le promete al compilador que la función **no modificará** ningún atributo del contacto. Si intentas alterar una variable miembro dentro de un método `const`, el código no compilará, lo que previene errores humanos en tiempo de desarrollo.

### B. Composición
La clase `PhoneBook` "tiene" un array de instancias de la clase `Contact`. Este diseño se llama **composición**. La clase contenedora gestiona la vida de los objetos que contiene.

---

## 3. Aritmética Modular para el Almacenamiento Circular

El enunciado exige que la agenda guarde un **máximo de 8 contactos**, y que al intentar añadir el 9º, este sobrescriba al más antiguo de forma circular.

En lugar de hacer costosos desplazamientos de array (lo cual consumiría procesador innecesariamente), utilizamos la **aritmética modular** con el operador módulo `%`:

```cpp
_contacts[_index].setFirstName(first);
...
_index = (_index + 1) % 8;
```

### ¿Cómo funciona matemáticamente?
El índice `_index` inicializa en `0` y progresa tras cada adición:
*   `0 + 1 = 1 % 8 = 1`
*   `1 + 1 = 2 % 8 = 2`
*   ...
*   `7 + 1 = 8 % 8 = 0` (¡El índice vuelve automáticamente a `0` sin condicionales!)

De esta manera, el noveno contacto se escribe de inmediato sobre `_contacts[0]`, reemplazando el contacto más antiguo tal y como exige la rúbrica.

---

## 4. Entrada y Formateo Profesional en C++98

### A. Flujos Robusto contra EOF (Ctrl+D)
Al leer texto de la terminal con `std::getline(std::cin, input)`, si el usuario interrumpe la entrada mediante un fin de archivo (EOF con `Ctrl+D`), el objeto `std::cin` entra en un estado de error (`failbit` o `eofbit`). 
Si no verificas el retorno de `std::getline` o el estado de `std::cin`, el programa intentará seguir leyendo infinitamente del flujo dañado, provocando un bucle infinito que consume el 100% de la CPU.
Nuestra implementación previene esto rompiendo el bucle de inmediato:
```cpp
if (!std::getline(std::cin, cmd)) {
  break; // Saliendo limpio y destruyendo el programa sin colgar la máquina
}
```

### B. Formateo y Alineación con `<iomanip>`
Para reproducir la visualización exacta exigida por el enunciado:
*   `std::setw(10)`: Ajusta el ancho de la columna a exactamente 10 caracteres. Si el dato es más pequeño, añade espacios.
*   `std::right`: Alinea el flujo a la derecha de los espacios creados por `setw`.
*   `.substr(0, 9) + "."`: Método de la clase `std::string` que devuelve una subcadena de longitud 9. Concatenarle el punto genera un string de exactamente 10 caracteres, que luego el formateador de ancho fijo acomoda sin problemas.

---

## 5. Tabla Comparativa: C vs C++98 en este Ejercicio

| Operación | Estilo Imperativo (C) | Estilo Orientado a Objetos (C++98) |
| :--- | :--- | :--- |
| **Entrada de texto** | `fgets(buf, 50, stdin)` (deja el salto de línea `\n` al final). | `std::getline(std::cin, str)` (limpia el salto de línea automáticamente). |
| **Gestión de Memoria** | Uso de arrays de char fijos (`char[50]`) o `malloc/free`. | Uso de objetos `std::string` dinámicos autoregulados (sin fugas). |
| **Formateo de salida** | Especificadores rígidos de `printf`: `printf("%10.10s", str)`. | Manipuladores de flujo tipados: `std::setw(10) << std::right`. |
| **Encapsulamiento** | Acceso global a estructuras de datos directas (`contact.name`). | Métodos de control internos seguros (`contact.getFirstName()`). |
