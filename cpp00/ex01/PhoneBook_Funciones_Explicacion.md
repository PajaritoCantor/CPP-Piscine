# PhoneBook ex01: Explicación Función por Función

Esta guía explica **cada función** de nuestro proyecto PhoneBook como si estuvieras leyendo el código por primera vez. Si vienes de C, cada sección incluye comparaciones para que entiendas la transición a C++98.

---

## Índice de Archivos y Funciones

| Archivo | Función | Propósito |
| :--- | :--- | :--- |
| `Contact.cpp` | `Contact::Contact()` | Constructor: inicializa un contacto vacío |
| `Contact.cpp` | `Contact::~Contact()` | Destructor: limpieza al destruir el contacto |
| `Contact.cpp` | `Contact::setFirstName()` y demás Setters | Escribir datos en los atributos privados |
| `Contact.cpp` | `Contact::getFirstName()` y demás Getters | Leer datos de los atributos privados |
| `PhoneBook.cpp` | `PhoneBook::PhoneBook()` | Constructor: inicializa la agenda vacía |
| `PhoneBook.cpp` | `PhoneBook::~PhoneBook()` | Destructor: limpieza al destruir la agenda |
| `PhoneBook.cpp` | `PhoneBook::_formatColumn()` | Truncar strings a 10 caracteres para la tabla |
| `PhoneBook.cpp` | `getInput()` | Leer texto del usuario sin aceptar campos vacíos |
| `PhoneBook.cpp` | `PhoneBook::addContact()` | Añadir un contacto a la agenda (circular) |
| `PhoneBook.cpp` | `PhoneBook::searchContact()` | Mostrar la tabla y el detalle de un contacto |
| `main.cpp` | `main()` | Bucle principal del programa (menú de comandos) |

---

## Archivo 1: `Contact.cpp` — La Clase Contacto

### 1.1 Constructor: `Contact::Contact(void)`
```cpp
Contact::Contact(void) {}
```

**¿Qué es un Constructor?**
Es una función especial que se ejecuta **automáticamente** cada vez que creas un nuevo objeto de la clase `Contact`. En C no existe este concepto: si declarabas una `struct`, sus campos quedaban con "basura" en memoria y tú tenías que inicializarlos manualmente con `memset` o asignaciones explícitas.

En C++, el constructor te garantiza que el objeto nace en un estado válido. En nuestro caso, el cuerpo está vacío (`{}`) porque `std::string` ya se inicializa como cadena vacía por defecto, lo que significa que cada contacto nuevo empieza con todos sus campos en blanco.

**Sintaxis importante:** El nombre del constructor es **idéntico** al de la clase (`Contact::Contact`). No tiene tipo de retorno (ni `void`, ni `int`, nada).

---

### 1.2 Destructor: `Contact::~Contact(void)`
```cpp
Contact::~Contact(void) {}
```

**¿Qué es un Destructor?**
Es la función opuesta al constructor: se ejecuta **automáticamente** cuando el objeto deja de existir (por ejemplo, cuando el programa termina o cuando la variable sale de su ámbito). Se reconoce por la **virgulilla (`~`)** delante del nombre de la clase.

En C, si habías usado `malloc`, tenías que acordarte de llamar a `free` para liberar la memoria. En C++, los destructores se encargan de esa limpieza de forma automática. En nuestro caso, como usamos `std::string` (que gestiona su propia memoria internamente), no necesitamos hacer nada extra, pero lo declaramos igualmente porque es **buena práctica** y algunos evaluadores de 42 lo exigen.

---

### 1.3 Los Setters (Modificadores)
```cpp
void Contact::setFirstName(std::string str) { _firstName = str; }
void Contact::setLastName(std::string str) { _lastName = str; }
void Contact::setNickname(std::string str) { _nickname = str; }
void Contact::setPhoneNumber(std::string str) { _phoneNumber = str; }
void Contact::setDarkestSecret(std::string str) { _darkestSecret = str; }
```

**¿Qué hacen los Setters?**
Son funciones públicas que permiten **escribir** un valor en un atributo privado desde fuera de la clase.

**¿Por qué no escribimos directamente en la variable?**
Porque las variables `_firstName`, `_lastName`, etc. son **privadas** (`private`). Esto significa que el compilador impide que cualquier código fuera de la clase las toque. Eso es el **encapsulamiento**: proteger el estado interno del objeto.

**¿Cómo se leen?**

```
Código externo                          Clase Contact
─────────────                           ──────────────
contact.setFirstName("Juan");  ────►   _firstName = "Juan";  (PERMITIDO ✅)
contact._firstName = "Juan";  ────►    ERROR DE COMPILACIÓN  (PROHIBIDO ❌)
```

**¿Qué es `_firstName`?**
El guion bajo (`_`) al principio del nombre es una **convención de estilo** muy usada en 42 y en la industria para distinguir rápidamente las **variables miembro** (que pertenecen a la clase) de las **variables locales** (que solo existen dentro de una función). No es obligatorio del lenguaje, pero te ayuda a leer el código de un vistazo.

---

### 1.4 Los Getters (Accesores)
```cpp
std::string Contact::getFirstName(void) const { return (_firstName); }
std::string Contact::getLastName(void) const { return (_lastName); }
std::string Contact::getNickname(void) const { return (_nickname); }
std::string Contact::getPhoneNumber(void) const { return (_phoneNumber); }
std::string Contact::getDarkestSecret(void) const { return (_darkestSecret); }
```

**¿Qué hacen los Getters?**
Son funciones públicas que permiten **leer** el valor de un atributo privado sin poder modificarlo.

**¿Qué significa `const` al final de la firma?**
```cpp
std::string getFirstName(void) const;
//                               ^^^^^
```
Este `const` es una **promesa al compilador**: esta función **jamás modificará** ningún atributo del objeto. Si por accidente intentas hacer algo como `_firstName = "Hola"` dentro de un método `const`, el compilador te detendrá con un error. Es una red de seguridad.

**¿Por qué `return (_firstName);` con paréntesis?**
Los paréntesis alrededor del valor de retorno son una **convención de estilo de 42**. Funcionalmente son idénticos a `return _firstName;`, pero el estándar de la piscina pide que se escriban así para mantener coherencia visual.

---

## Archivo 2: `PhoneBook.cpp` — La Clase Agenda

### 2.1 Constructor: `PhoneBook::PhoneBook(void)`
```cpp
PhoneBook::PhoneBook(void) {
  _index = 0;
  _total = 0;
}
```

Cuando creamos una nueva agenda, necesitamos que:
*   **`_index`** (la posición donde se guardará el siguiente contacto) empiece en `0`.
*   **`_total`** (el número de contactos guardados hasta ahora) empiece en `0`.

El array `_contacts[8]` (los 8 contactos) se inicializa automáticamente porque cada elemento es un objeto `Contact`, y al crearse cada uno ejecuta su propio constructor (que acabamos de ver).

---

### 2.2 Destructor: `PhoneBook::~PhoneBook(void)`
```cpp
PhoneBook::~PhoneBook(void) {}
```
Igual que en `Contact`, no necesitamos hacer nada especial al destruir la agenda. Los 8 objetos `Contact` dentro del array serán destruidos automáticamente (cada uno llamará a su propio destructor `~Contact`).

---

### 2.3 Método Privado: `PhoneBook::_formatColumn()`
```cpp
std::string PhoneBook::_formatColumn(std::string str) const {
  if (str.length() > 10) {
    return (str.substr(0, 9) + ".");
  }
  return (str);
}
```

**¿Qué hace?**
Recibe un string y verifica si tiene más de 10 caracteres. Si es así, lo recorta a los **primeros 9 caracteres** y le añade un **punto (`.`)** al final, generando un string de exactamente 10 caracteres.

**Ejemplo paso a paso:**
```
Entrada: "Christopher"    (11 caracteres)
  ¿11 > 10?  → SÍ
  substr(0, 9) → "Christoph"  (9 caracteres)
  + "."       → "Christoph."  (10 caracteres) ← RESULTADO

Entrada: "Juan"           (4 caracteres)
  ¿4 > 10?   → NO
  Devuelve "Juan" tal cual ← RESULTADO
```

**¿Por qué es `private`?**
Este método es un **helper interno** (ayudante). Solo lo usa la propia clase `PhoneBook` dentro de `searchContact()`. Nadie fuera de la clase necesita llamarlo directamente, así que lo protegemos haciéndolo privado. Nota que su nombre empieza con `_` para indicar que es un miembro privado, siguiendo nuestra convención.

**¿Qué es `.substr()`?**
Es un **método** (función miembro) de la clase `std::string`. Recibe dos parámetros:
1.  La posición de inicio (empezando desde `0`).
2.  La cantidad de caracteres a extraer.

En C, habrías tenido que usar `strncpy` y preocuparte por el terminador nulo `\0`. En C++, `.substr()` te devuelve un nuevo `std::string` seguro y limpio.

---

### 2.4 Función Libre Estática: `getInput()`
```cpp
static std::string getInput(std::string prompt) {
  std::string input = "";

  while (true) {
    std::cout << prompt;
    if (!std::getline(std::cin, input)) {
      std::cout << std::endl;
      return ("");
    }
    if (!input.empty()) {
      break;
    }
    std::cout << "Error: Field cannot be empty." << std::endl;
  }
  return (input);
}
```

**¿Qué hace?**
Solicita texto al usuario y **no acepta cadenas vacías**. Si el usuario presiona Enter sin escribir nada, vuelve a pedir el dato.

**Desglose línea por línea:**

1.  **`static`**: Esta palabra clave aquí (fuera de una clase) significa que la función es **visible solo dentro de este archivo** (`PhoneBook.cpp`). Nadie desde `main.cpp` u otro archivo puede llamarla. Es como una función `static` en C.

2.  **`std::cout << prompt;`**: Imprime el texto del campo que se está pidiendo (ej: `"First name: "`).

3.  **`if (!std::getline(std::cin, input))`**: Lee una línea completa de la terminal. Si el usuario presiona **Ctrl+D** (señal de fin de archivo / EOF), `std::getline` falla y retorna `false`. El `!` lo invierte a `true`, entrando al `if` y devolviendo un string vacío para que la función que la llamó sepa que hubo un problema.

4.  **`if (!input.empty())`**: Si el string leído **no está vacío** (el usuario escribió algo), salimos del bucle con `break`.

5.  **Si está vacío**, imprimimos un error y el bucle `while (true)` vuelve a solicitar el mismo campo.

**En C habrías hecho:**
```c
char buf[256];
while (1) {
    printf("First name: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL)
        return (NULL);
    buf[strcspn(buf, "\n")] = '\0'; // Quitar el \n que fgets deja
    if (strlen(buf) > 0)
        break;
    printf("Error: Field cannot be empty.\n");
}
```
Nota cómo en C++ nos ahorramos el manejo manual del `\n` y del tamaño del buffer.

---

### 2.5 Método Público: `PhoneBook::addContact()`
```cpp
void PhoneBook::addContact(void) {
  std::string first, last, nick, phone, secret;

  first = getInput("First name: ");
  if (first.empty() && std::cin.eof())
    return;
  last = getInput("Last name: ");
  if (last.empty() && std::cin.eof())
    return;
  nick = getInput("Nickname: ");
  if (nick.empty() && std::cin.eof())
    return;
  phone = getInput("Phone number: ");
  if (phone.empty() && std::cin.eof())
    return;
  secret = getInput("Darkest secret: ");
  if (secret.empty() && std::cin.eof())
    return;

  _contacts[_index].setFirstName(first);
  _contacts[_index].setLastName(last);
  _contacts[_index].setNickname(nick);
  _contacts[_index].setPhoneNumber(phone);
  _contacts[_index].setDarkestSecret(secret);

  _index = (_index + 1) % 8;
  if (_total < 8) {
    _total++;
  }
  std::cout << "Contact added successfully." << std::endl;
}
```

**¿Qué hace?**
Solicita al usuario los 5 campos del contacto, los almacena en la posición actual del array y actualiza el índice circular.

**Desglose por bloques:**

**Bloque 1 — Recolección de datos:**
```cpp
first = getInput("First name: ");
if (first.empty() && std::cin.eof())
  return;
```
Llama a nuestra función `getInput` para solicitar cada campo. Después de cada solicitud, verifica si el string quedó vacío **Y** el flujo de entrada llegó a EOF (Ctrl+D). Si es así, aborta la operación de añadir sin guardar datos parciales.

**Bloque 2 — Almacenamiento con Setters:**
```cpp
_contacts[_index].setFirstName(first);
_contacts[_index].setLastName(last);
// ...
```
Guarda cada campo en el contacto que ocupa la posición `_index` del array. Aquí se ve la **composición** en acción: `_contacts[_index]` es un objeto `Contact`, y le llamamos a sus métodos Setters para configurar sus datos.

**Bloque 3 — Indexación Circular (La Magia del Módulo):**
```cpp
_index = (_index + 1) % 8;
```
Esta es la línea más elegante del proyecto. El operador `%` (módulo) devuelve el **resto** de la división entera. Veamos cómo progresa:

```
Contacto añadido #1: _index = (0 + 1) % 8 = 1
Contacto añadido #2: _index = (1 + 1) % 8 = 2
Contacto añadido #3: _index = (2 + 1) % 8 = 3
...
Contacto añadido #7: _index = (6 + 1) % 8 = 7
Contacto añadido #8: _index = (7 + 1) % 8 = 0  ← ¡Vuelve al inicio!
Contacto añadido #9: _index = (0 + 1) % 8 = 1  ← Sobrescribe el 2º más antiguo
```

Sin esta aritmética, tendríamos que usar un condicional `if (_index >= 8) _index = 0;`. El módulo lo resuelve en una sola operación matemática.

**Bloque 4 — Contador de contactos válidos:**
```cpp
if (_total < 8) {
  _total++;
}
```
`_total` cuenta cuántos contactos reales existen en la agenda. Solo crece mientras no hayamos llenado las 8 posiciones. Una vez lleno, permanece en 8 aunque sigamos añadiendo contactos (porque estamos sobrescribiendo, no añadiendo nuevas posiciones).

---

### 2.6 Método Público: `PhoneBook::searchContact()`
```cpp
void PhoneBook::searchContact(void) const {
```

**Nota el `const`:** Esta función es de **solo lectura**. Solo muestra datos, nunca los modifica.

**Fase 1 — Verificación de agenda vacía:**
```cpp
if (_total == 0) {
  std::cout << "PhoneBook is empty." << std::endl;
  return;
}
```
Si no hay contactos, no tiene sentido mostrar una tabla vacía.

**Fase 2 — Impresión de la tabla de resumen:**
```cpp
  std::cout << "|" << std::setw(10) << std::right << "Index"
            << "|" << std::setw(10) << std::right << "First Name"
            << "|" << std::setw(10) << std::right << "Last Name"
            << "|" << std::setw(10) << std::right << "Nickname"
            << "|" << std::endl;
```

Aquí usamos los **manipuladores de flujo** de la librería `<iomanip>`:
*   **`std::setw(10)`**: "Set Width" → El siguiente dato que imprimas ocupará **exactamente 10 caracteres**. Si es más corto, se rellenará con espacios.
*   **`std::right`**: Alinea el texto a la **derecha** dentro de esos 10 caracteres.

**Resultado visual:**
```
|     Index|First Name| Last Name|  Nickname|
```

Luego, para cada contacto:
```cpp
  for (int i = 0; i < _total; i++) {
    std::cout << "|" << std::setw(10) << std::right << i << "|" << std::setw(10)
              << std::right << _formatColumn(_contacts[i].getFirstName()) << "|"
            // ... etc.
```
Aquí se combinan tres operaciones por cada celda de la tabla:
1.  `_contacts[i].getFirstName()` → Obtiene el nombre del contacto (Getter).
2.  `_formatColumn(...)` → Lo trunca a 10 caracteres si es necesario (Helper privado).
3.  `std::setw(10) << std::right << ...` → Lo alinea a la derecha en una celda de 10 caracteres.

**Fase 3 — Solicitud y validación del índice:**
```cpp
  if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
    int idx = input[0] - '0';
```
En lugar de usar funciones de conversión pesadas como `atoi()` o `std::stoi()` (que no existe en C++98), verificamos manualmente:
1.  Que el input sea **un solo carácter** (`length() == 1`).
2.  Que ese carácter esté entre `'0'` y `'7'` (los índices válidos).
3.  **`input[0] - '0'`**: Esta es la conversión clásica de carácter a número que ya conoces de C. El carácter `'0'` tiene valor ASCII 48, `'1'` tiene 49, etc. Al restar `'0'`, obtenemos el valor numérico real (ej: `'3' - '0' = 3`).

**Fase 4 — Impresión del detalle completo:**
```cpp
    if (idx < _total) {
      std::cout << "First name: " << _contacts[idx].getFirstName() << std::endl;
      std::cout << "Last name: " << _contacts[idx].getLastName() << std::endl;
      std::cout << "Nickname: " << _contacts[idx].getNickname() << std::endl;
      std::cout << "Phone number: " << _contacts[idx].getPhoneNumber() << std::endl;
      std::cout << "Darkest secret: " << _contacts[idx].getDarkestSecret() << std::endl;
    }
```
Aquí se muestra **toda la información** del contacto seleccionado, incluyendo el teléfono y el secreto más oscuro que no aparecían en la tabla resumen. Es la **vista de detalle**.

---

## Archivo 3: `main.cpp` — El Punto de Entrada

### 3.1 La Función `main()`
```cpp
int main(int ac, char **av) {
  (void)ac;
  (void)av;
```

**`(void)ac;` y `(void)av;`** — ¿Qué es esto?
Nuestro programa no usa argumentos de línea de comandos, pero declaramos `ac` y `av` por si un evaluador quiere probar con argumentos. El cast a `(void)` le dice explícitamente al compilador: "Sé que no estoy usando estas variables, no me des un warning". Sin esto, el flag `-Wextra` generaría un warning de "unused parameter" que, bajo `-Werror`, detendría la compilación.

**Instanciación del objeto:**
```cpp
  PhoneBook book;
```
Esta línea crea un objeto de la clase `PhoneBook`. En ese instante, el compilador ejecuta automáticamente `PhoneBook::PhoneBook()` (el constructor), que inicializa `_index = 0` y `_total = 0`. En C, habrías tenido que hacer:
```c
t_phonebook book;
memset(&book, 0, sizeof(book)); // O inicializar campo por campo
```

**El bucle principal:**
```cpp
  while (true) {
    std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
    if (!std::getline(std::cin, cmd)) {
      // EOF detectado (Ctrl+D)
      break;
    }
    if (cmd == "EXIT") {
      break;
    } else if (cmd == "ADD") {
      book.addContact();
    } else if (cmd == "SEARCH") {
      book.searchContact();
    }
  }
```

**Comparación de strings en C vs C++:**
*   **En C:** `if (strcmp(cmd, "EXIT") == 0)` → Necesitas una función específica y comparar con `0`.
*   **En C++:** `if (cmd == "EXIT")` → El operador `==` está **sobrecargado** para `std::string`, haciendo la comparación directa, limpia y legible.

**`book.addContact();`**: Llama al método `addContact` del objeto `book`. Es como si en C hubieras hecho `add_contact(&book);` pasando un puntero a la estructura. En C++, el objeto ya "sabe" sobre sí mismo (internamente usa un puntero invisible llamado `this`).

---

## Resumen Visual: Flujo Completo del Programa

```
╔══════════════════════════════════════════════════════════╗
║                  PROGRAMA INICIA                         ║
║  main() crea PhoneBook book (Constructor se ejecuta)     ║
╚═══════════════════════╦══════════════════════════════════╝
                        ▼
              ┌─────────────────┐
              │ Solicitar Comando│◄──────────────────────┐
              └────────┬────────┘                        │
                       ▼                                 │
              ┌─────────────────┐                        │
              │ ¿Qué comando?   │                        │
              └──┬──────┬──────┬┘                        │
                 │      │      │                         │
           "ADD" │  "SEARCH"  "EXIT"                     │
                 ▼      │      ▼                         │
          ┌──────────┐  │  ┌────────┐                    │
          │addContact│  │  │ break  │                    │
          │ Pide 5   │  │  │ (sale) │                    │
          │ campos   │  │  └────────┘                    │
          │ Guarda   │  │                                │
          │ en array │  ▼                                │
          │ _index++ │ ┌─────────────┐                   │
          │ % 8      │ │searchContact│                   │
          └──────┬───┘ │ Tabla       │                   │
                 │     │ + Detalle   │                   │
                 │     └──────┬──────┘                   │
                 │            │                          │
                 └────────────┴──────────────────────────┘
```
