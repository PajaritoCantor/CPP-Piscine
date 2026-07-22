# C++ - Módulo 00

**Namespaces, clases, funciones miembro, flujos de stdio, listas de inicialización, static, const, y otros conceptos básicos**

**Resumen:**
Este documento contiene los ejercicios del Módulo 00 de los módulos de C++.

**Versión:** 11.2

---

## Contenido

- [I. Introducción](#i-introducción)
- [II. Reglas generales](#ii-reglas-generales)
- [III. Instrucciones sobre IA](#iii-instrucciones-sobre-ia)
- [IV. Ejercicio 00: Megaphone](#iv-ejercicio-00-megaphone)
- [V. Ejercicio 01: My Awesome PhoneBook](#v-ejercicio-01-my-awesome-phonebook)
- [VI. Ejercicio 02: The Job Of Your Dreams](#vi-ejercicio-02-the-job-of-your-dreams)
- [VII. Entrega y evaluación entre pares](#vii-entrega-y-evaluación-entre-pares)

---

## Capítulo I — Introducción

C++ es un lenguaje de programación de propósito general creado por Bjarne Stroustrup como una extensión del lenguaje de programación C, o "C con Clases" (fuente: Wikipedia).

El objetivo de estos módulos es introducirte a la **Programación Orientada a Objetos**.

Este será el punto de partida de tu viaje en C++. Muchos lenguajes son recomendados para aprender POO. Decidimos elegir C++ ya que deriva de tu viejo amigo C.

Dado que C++ es un lenguaje complejo, y para mantener las cosas simples, tu código seguirá el estándar **C++98**.

Somos conscientes de que el C++ moderno es muy diferente en muchos aspectos. Así que si quieres convertirte en un desarrollador C++ competente, ¡depende de ti ir más allá después del 42 Common Core!

Descubrirás nuevos conceptos paso a paso. Los ejercicios aumentarán progresivamente en complejidad.

---

## Capítulo II — Reglas Generales

### Compilación

- Compila tu código con `c++` y las flags `-Wall -Wextra -Werror`
- Tu código debe seguir compilando si añades la flag `-std=c++98`

### Convenciones de formato y nomenclatura

- Los directorios de ejercicios se nombrarán así: `ex00`, `ex01`, ..., `exn`
- Nombra tus archivos, clases, funciones, funciones miembro y atributos según lo requerido en las directrices.
- Escribe los nombres de clase en formato **UpperCamelCase**. Los archivos que contienen código de clase siempre se nombrarán según el nombre de la clase. Por ejemplo:
  `ClassName.hpp/ClassName.h`, `ClassName.cpp`, o `ClassName.tpp`. Entonces, si tienes un archivo de cabecera con la definición de una clase "BrickWall" que representa un muro de ladrillos, su nombre será `BrickWall.hpp`.
- A menos que se especifique lo contrario, cada mensaje de salida debe terminar con un carácter de nueva línea y mostrarse en la **salida estándar**.
- ¡**Adiós Norminette!** No se impone ningún estilo de código en los módulos de C++. Puedes seguir tu estilo favorito. Pero ten en cuenta que el código que tus evaluadores pares no puedan entender es código que no pueden calificar. Haz tu mejor esfuerzo por escribir código limpio y legible.

### Permitido/Prohibido

Ya no estás programando en C. ¡Es hora de C++! Por lo tanto:

- Tienes permitido usar casi todo de la **biblioteca estándar**. Por lo tanto, en lugar de limitarte a lo que ya conoces, sería inteligente usar las versiones C++ de las funciones de C que conoces tanto como sea posible.
- Sin embargo, **no puedes usar ninguna otra biblioteca externa**. Esto significa que C++11 (y formas derivadas) y las bibliotecas **Boost** están prohibidas. Las siguientes funciones también están prohibidas: `*printf()`, `*alloc()` y `free()`. Si las usas, tu nota será **0** y punto.
- Ten en cuenta que, a menos que se indique explícitamente lo contrario, las palabras clave `using namespace <ns_name>` y `friend` están **prohibidas**. De lo contrario, tu nota será **-42**.
- Solo tienes permitido usar la **STL en los Módulos 08 y 09**. Eso significa: sin **Contenedores** (vector/list/map, etc.) y sin **Algoritmos** (nada que requiera incluir la cabecera `<algorithm>`) hasta entonces. De lo contrario, tu nota será **-42**.

### Algunos requisitos de diseño

- Las **fugas de memoria** también ocurren en C++. Cuando asignas memoria (usando la palabra clave `new`), debes evitar fugas de memoria.
- Del **Módulo 02 al Módulo 09**, tus clases deben diseñarse en la **Forma Canónica Ortodoxa** (Orthodox Canonical Form), excepto cuando se indique explícitamente lo contrario.
- Cualquier implementación de función puesta en un archivo de cabecera (excepto para plantillas de funciones) significa **0** en el ejercicio.
- Deberías poder usar cada una de tus cabeceras independientemente de las demás. Por lo tanto, deben incluir todas las dependencias que necesiten. Sin embargo, debes evitar el problema de la **doble inclusión** añadiendo **include guards**. De lo contrario, tu nota será **0**.

### Léeme

- Puedes añadir archivos adicionales si lo necesitas (por ejemplo, para dividir tu código). Como estas tareas no son verificadas por un programa, siéntete libre de hacerlo siempre y cuando entregues los archivos obligatorios.
- A veces, las directrices de un ejercicio parecen cortas pero los ejemplos pueden mostrar requisitos que no están escritos explícitamente en las instrucciones.
- ¡Lee cada módulo completamente antes de empezar! En serio, hazlo.
- **¡Por Odín, por Thor! ¡¡¡Usa tu cerebro!!!**

> Respecto al Makefile para proyectos de C++, aplican las mismas reglas que en C (ver el capítulo de la Norma sobre el Makefile).

> Tendrás que implementar muchas clases. Esto puede parecer tedioso, a menos que seas capaz de programar scripts en tu editor de texto favorito.

> Se te da cierta cantidad de libertad para completar los ejercicios. Sin embargo, sigue las reglas obligatorias y no seas perezoso. ¡Te perderías mucha información útil! No dudes en leer sobre conceptos teóricos.

---

## Capítulo III — Instrucciones sobre IA

### ● Contexto

Este proyecto está diseñado para ayudarte a descubrir los bloques de construcción fundamentales de tu formación en 42.

Para anclar correctamente conocimientos y habilidades clave, es esencial adoptar un enfoque reflexivo al usar herramientas de IA y soporte.

El verdadero aprendizaje fundamental requiere un esfuerzo intelectual genuino — a través del desafío, la repetición y los intercambios de aprendizaje entre pares.

Para una visión más completa de nuestra postura sobre la IA — como herramienta de aprendizaje, como parte de la formación de 42, y como expectativa en el mercado laboral — por favor consulta la FAQ dedicada en la intranet.

### ● Mensaje principal

- ☛ Construye bases sólidas sin atajos.
- ☛ Desarrolla realmente habilidades técnicas y de poder.
- ☛ Experimenta el verdadero aprendizaje entre pares, comienza a aprender cómo aprender y resolver nuevos problemas.
- ☛ El viaje de aprendizaje es más importante que el resultado.
- ☛ Aprende sobre los riesgos asociados con la IA, y desarrolla prácticas de control efectivas y contramedidas para evitar errores comunes.

### ● Reglas del aprendiz:

- Debes aplicar razonamiento a tus tareas asignadas, especialmente antes de recurrir a la IA.
- No debes pedir respuestas directas a la IA.
- Debes aprender sobre el enfoque global de 42 respecto a la IA.

### ● Resultados de la fase:

Dentro de esta fase fundamental, obtendrás los siguientes resultados:

- Obtener bases técnicas y de programación adecuadas.
- Saber por qué y cómo la IA puede ser peligrosa durante esta fase.

### ● Comentarios y ejemplo:

- Sí, sabemos que la IA existe — y sí, puede resolver tus proyectos. Pero estás aquí para aprender, no para demostrar que la IA ha aprendido. No pierdas tu tiempo (ni el nuestro) solo para demostrar que la IA puede resolver el problema dado.
- Aprender en 42 no se trata de saber la respuesta — se trata de desarrollar la habilidad de encontrar una. La IA te da la respuesta directamente, pero eso te impide construir tu propio razonamiento. Y el razonamiento toma tiempo, esfuerzo e implica fracaso. El camino al éxito no debe ser fácil.
- Ten en cuenta que durante los exámenes, la IA no está disponible — sin internet, sin smartphones, etc. Te darás cuenta rápidamente si has dependido demasiado de la IA en tu proceso de aprendizaje.
- El aprendizaje entre pares te expone a diferentes ideas y enfoques, mejorando tus habilidades interpersonales y tu capacidad de pensar de forma divergente. Eso es mucho más valioso que simplemente chatear con un bot. ¡Así que no seas tímido — habla, haz preguntas y aprendan juntos!
- Sí, la IA será parte del currículum — tanto como herramienta de aprendizaje como tema en sí mismo. Incluso tendrás la oportunidad de construir tu propio software de IA. Para aprender más sobre nuestro enfoque crescendo, revisa la documentación disponible en la intranet.

> ✅ **Buena práctica:**
> Estoy atascado en un concepto nuevo. Le pregunto a alguien cercano cómo lo abordó. Hablamos 10 minutos — y de repente hace clic. Lo entiendo.

> ❌ **Mala práctica:**
> Uso la IA en secreto, copio algo de código que parece correcto. Durante la evaluación entre pares, no puedo explicar nada. Fallo. Durante el examen — sin IA — estoy atascado de nuevo. Fallo.

---

## Capítulo IV — Ejercicio 00: Megaphone

| Campo | Detalle |
|---|---|
| **Ejercicio** | 00 |
| **Nombre** | Megaphone |
| **Directorio** | `ex00/` |
| **Archivos a entregar** | `Makefile`, `megaphone.cpp` |
| **Funciones prohibidas** | Ninguna |

Solo para asegurarse de que todos estén despiertos, escribe un programa que produzca la siguiente salida:

```
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

Resuelve los ejercicios de manera C++ (a la manera de C++).

---

## Capítulo V — Ejercicio 01: My Awesome PhoneBook

| Campo | Detalle |
|---|---|
| **Ejercicio** | 01 |
| **Nombre** | My Awesome PhoneBook |
| **Directorio** | `ex01/` |
| **Archivos a entregar** | `Makefile`, `*.cpp`, `*.{h, hpp}` |
| **Funciones prohibidas** | Ninguna |

¡Bienvenido a los años 80 y su increíble tecnología! Escribe un programa que se comporte como un software de agenda telefónica cutre increíble.

Tienes que implementar dos clases:

### PhoneBook
- Tiene un array de contactos.
- Puede almacenar un **máximo de 8 contactos**. Si el usuario intenta añadir un 9º contacto, reemplaza el más antiguo por el nuevo.
- Ten en cuenta que la **asignación dinámica está prohibida**.

### Contact
- Representa un contacto de la agenda telefónica.

En tu código, la agenda debe instanciarse como una instancia de la clase **PhoneBook**. Lo mismo para los contactos. Cada uno debe instanciarse como una instancia de la clase **Contact**. Eres libre de diseñar las clases como quieras, pero ten en cuenta que **todo lo que siempre se use dentro de una clase es privado**, y **todo lo que pueda usarse fuera de una clase es público**.

> No olvides ver los videos de la intranet.

Al iniciar el programa, la agenda está vacía y se le pide al usuario que ingrese uno de tres comandos. El programa solo acepta **ADD**, **SEARCH** y **EXIT**.

### ADD: guardar un nuevo contacto
- Si el usuario ingresa este comando, se le solicita la información del nuevo contacto campo por campo. Una vez que todos los campos se hayan completado, añade el contacto a la agenda.
- Los campos del contacto son: **nombre** (first name), **apellido** (last name), **apodo** (nickname), **número de teléfono** (phone number) y **secreto más oscuro** (darkest secret). Un contacto guardado **no puede tener campos vacíos**.

### SEARCH: mostrar un contacto específico
- Muestra los contactos guardados como una lista de **4 columnas**: índice, nombre, apellido y apodo.
- Cada columna debe tener **10 caracteres de ancho**. Un carácter de barra vertical (`|`) las separa. El texto debe estar **alineado a la derecha**. Si el texto es más largo que la columna, debe **truncarse** y el último carácter mostrable debe reemplazarse por un punto (`.`).
- Luego, solicita al usuario nuevamente el **índice de la entrada** a mostrar. Si el índice está fuera de rango o es incorrecto, define un comportamiento relevante. De lo contrario, muestra la información del contacto, **un campo por línea**.
- Se espera que uses **iomanip** para reproducir la visualización esperada.

### EXIT
- El programa se cierra y ¡los contactos se pierden para siempre!

### Otro input
- Cualquier otra entrada es ignorada.

Una vez que un comando se ha ejecutado correctamente, el programa espera otro. Se detiene cuando el usuario ingresa **EXIT**.

Dale un nombre relevante a tu ejecutable.

> Referencias útiles:
> - http://www.cplusplus.com/reference/string/string/
> - http://www.cplusplus.com/reference/iomanip/

---

## Capítulo VI — Ejercicio 02: The Job Of Your Dreams

| Campo | Detalle |
|---|---|
| **Ejercicio** | 02 |
| **Nombre** | The Job Of Your Dreams |
| **Directorio** | `ex02/` |
| **Archivos a entregar** | `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp` |
| **Funciones prohibidas** | Ninguna |

> `Account.hpp`, `tests.cpp`, y el archivo de log están disponibles para descargar en la página de la intranet del módulo.

Hoy es tu primer día en **GlobalBanksters United**. Después de pasar exitosamente las pruebas de contratación (gracias a unos cuantos trucos de **Microsoft Office** que un amigo te enseñó), te uniste al equipo de desarrollo. También sabes que el reclutador quedó impresionado por lo rápido que instalaste **Adobe Reader**. Ese pequeño extra marcó toda la diferencia y te ayudó a vencer a todos tus oponentes (también conocidos como los otros candidatos): ¡lo lograste!

En fin, tu jefe acaba de darte algo de trabajo. Tu primera tarea es recrear un archivo perdido. Algo salió mal y un archivo fuente fue eliminado por error. Desafortunadamente, tus colegas no saben qué es **Git** y usan memorias USB para compartir código. En este punto, tendría sentido irse de este lugar ahora mismo. Sin embargo, decides quedarte. ¡Desafío aceptado!

Tus compañeros desarrolladores te dan un montón de archivos. Compilar `tests.cpp` revela que el archivo perdido es `Account.cpp`. Por suerte, el archivo de cabecera `Account.hpp` se guardó. También hay un archivo de log. Quizás podrías usarlo para entender cómo se implementó la clase **Account**.

Comienzas a recrear el archivo `Account.cpp`. En solo unos minutos, codificas unas líneas de puro C++ increíble. Después de un par de compilaciones fallidas, tu programa pasa las pruebas. Su salida coincide perfectamente con la guardada en el archivo de log (excepto por las **marcas de tiempo** que obviamente diferirán ya que las pruebas guardadas en el archivo de log se ejecutaron antes de que te contrataran).

¡Caramba, eres impresionante!

> El orden en que se llaman los destructores puede diferir dependiendo de tu compilador/sistema operativo. Así que tus destructores pueden llamarse en orden inverso.

> **Completar el ejercicio 02 no es obligatorio para aprobar este módulo.**

---

## Capítulo VII — Entrega y evaluación entre pares

Entrega tu tarea a tu repositorio **Git** como de costumbre. Solo el trabajo dentro de tu repositorio será evaluado durante la defensa. No dudes en verificar dos veces los nombres de tus archivos para asegurarte de que sean correctos.

Durante la evaluación, puede solicitarse ocasionalmente una breve **modificación del proyecto**. Esto podría implicar un cambio menor de comportamiento, unas pocas líneas de código por escribir o reescribir, o una característica fácil de añadir.

Aunque este paso **puede no aplicarse a todos los proyectos**, debes estar preparado para ello si se menciona en las directrices de evaluación.

Este paso está destinado a verificar tu comprensión real de una parte específica del proyecto. La modificación puede realizarse en cualquier entorno de desarrollo que elijas (por ejemplo, tu configuración habitual), y debería ser factible en unos pocos minutos — a menos que se defina un plazo específico como parte de la evaluación.

Se te puede pedir, por ejemplo, hacer una pequeña actualización a una función o script, modificar una visualización, o ajustar una estructura de datos para almacenar nueva información, etc.

Los detalles (alcance, objetivo, etc.) se especificarán en las **directrices de evaluación** y pueden variar de una evaluación a otra para el mismo proyecto.
