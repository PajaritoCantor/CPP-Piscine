# PhoneBook - Explicacion completa por partes

Este documento explica cada parte de tu proyecto `ex01` de forma practica.

## 1. Vista general del proyecto

El programa tiene 3 piezas principales:

1. `main.cpp`: controla el bucle de comandos (`ADD`, `SEARCH`, `EXIT`).
2. `Contact.hpp` + `Contact.cpp`: define que datos guarda un contacto y como leer/escribir esos datos.
3. `PhoneBook.hpp` + `PhoneBook.cpp`: guarda hasta 8 contactos y aplica la logica de agregar y buscar.

---

## 2. `Contact` (modelo de datos)

### `Contact.hpp`

La clase `Contact` encapsula 5 campos privados:

- `_firstName`
- `_lastName`
- `_nickname`
- `_phoneNumber`
- `_darkestSecret`

Tambien expone metodos publicos:

- Setters: `setFirstName`, `setLastName`, `setNickname`, `setPhoneNumber`, `setDarkestSecret`
- Getters: `getFirstName`, `getLastName`, `getNickname`, `getPhoneNumber`, `getDarkestSecret`

Punto importante:

- Los getters son `const`, por lo que pueden llamarse desde metodos `const` (como `searchContact`) sin modificar el objeto.

### `Contact.cpp`

Implementa cada setter y getter de forma directa:

- Un setter copia el valor recibido al atributo privado.
- Un getter devuelve el valor del atributo.

No hay validacion fuerte aqui; la validacion principal la haces antes de guardar (en `getInput` dentro de `PhoneBook.cpp`).

---

## 3. `PhoneBook` (logica principal)

### `PhoneBook.hpp`

La clase `PhoneBook` tiene estos atributos privados:

- `Contact _contacts[8]`: arreglo fijo de 8 contactos.
- `int _index`: posicion donde se escribira el proximo contacto.
- `int _total`: cuantos contactos validos hay para mostrar en `SEARCH` (maximo 8).

Metodos privados/publicos:

- Privado: `_formatColumn(std::string)` para recortar columnas a 10 caracteres.
- Publico: constructor/destructor, `addContact()`, `searchContact()`.

### Constructor `PhoneBook::PhoneBook()`

Inicializa estado interno:

- `_index = 0`
- `_total = 0`

Esto significa: la agenda empieza vacia y el primer `ADD` escribe en la posicion 0.

### `_formatColumn(std::string)`

Funcion de ayuda para la tabla de `SEARCH`:

- Si el texto tiene mas de 10 caracteres, recorta a 9 y agrega `.`
- Si no, lo devuelve igual.

Ejemplo:

- `Christopher` -> `Christoph.`

### `getInput(prompt)` (funcion `static` en el `.cpp`)

Lee un campo por terminal con estas reglas:

1. Muestra el prompt.
2. Usa `std::getline`.
3. Si hay EOF/error (`Ctrl+D`), devuelve cadena vacia para cortar limpio.
4. Si el usuario escribe vacio, muestra error y vuelve a pedir.

Esto evita que guardes campos vacios.

### `addContact()`

Flujo paso a paso:

1. Pide los 5 campos (`first`, `last`, `nick`, `phone`, `secret`).
2. Si detecta EOF durante la carga, sale sin guardar.
3. Guarda en `_contacts[_index]` usando setters.
4. Avanza el indice circular:

```cpp
_index = (_index + 1) % 8;
```

5. Actualiza `_total` solo hasta 8:

```cpp
if (_total < 8) {
  _total++;
}
```

Resultado:

- Contactos 1..8 llenan indices 0..7.
- A partir del contacto 9, se sobrescribe siempre el contacto en el índice 0.
- El comportamiento de búfer circular que implementamos antes (sobrescribir 0, 1, 2... en secuencia) es una interpretación común, pero la especificación del módulo es más simple.
- La lógica ahora asegura que, una vez lleno, solo el contacto más antiguo (índice 0) es reemplazado.
```


### `searchContact() const`

Flujo paso a paso:

1. Si `_total == 0`, informa que esta vacio.
2. Imprime cabecera de tabla con `std::setw(10)` y `std::right`.
3. Recorre `i = 0` hasta `i < _total` y muestra:
   - indice
   - first name
   - last name
   - nickname
   usando `_formatColumn` para ajustar a 10.
4. Pide un indice al usuario.
5. Valida entrada:
   - Debe ser 1 solo caracter
   - Debe estar entre `'0'` y `'7'`
   - Debe ser menor que `_total`
6. Si es valido, muestra los 5 campos completos del contacto.
7. Si no es valido, muestra error.

Nota:

- Aunque acepta `0..7`, la comprobacion `idx < _total` evita leer fuera de los contactos cargados.

---

## 4. `main.cpp` (control del programa)

`main` hace lo siguiente:

1. Crea una instancia `PhoneBook book`.
2. Muestra mensaje de bienvenida.
3. Entra en bucle infinito para leer comando.
4. Si comando es:
   - `ADD`: llama `book.addContact()`
   - `SEARCH`: llama `book.searchContact()`
   - `EXIT`: termina programa
5. Si recibe EOF (`Ctrl+D`) en lectura del comando, sale de forma limpia.
6. Si comando invalido no vacio, muestra mensaje de ayuda.

---

## 5. Resumen rapido de diseno

- Encapsulacion: los datos de `Contact` son privados.
- Estructura simple y C++98: sin STL avanzada ni contenedores dinamicos.
- Capacidad fija: exactamente 8 contactos.
- Sobrescritura circular correcta: controlada por `_index = (_index + 1) % 8`.
- Salida robusta ante EOF para evitar bloqueos o comportamientos raros.

---

## 6. Mini mapa mental de ejecucion

1. El usuario escribe un comando en `main`.
2. `ADD` llena un `Contact` y lo guarda en `PhoneBook`.
3. `SEARCH` lista resumen y luego muestra detalle por indice.
4. `EXIT` o EOF termina.
