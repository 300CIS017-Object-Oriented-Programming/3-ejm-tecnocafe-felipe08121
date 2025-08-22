# Ejemplo – TecnoCafé (Funciones, Ciclos y Condicionales en C++)

Al finalizar esta práctica, podrás:

* Escribir, compilar y ejecutar programas en C++ con **entrada/salida**, **condicionales** y **ciclos**.
* **Modularizar** el código mediante **funciones** con parámetros y valores de retorno.
* Aplicar **convenciones de nombramiento** consistentes (camelCase para funciones y variables; constantes en
  MAYÚS\_CON\_GUIONES).
* Implementar **validaciones** de entradas y flujos de control.

## Introducción al proyecto

TecnoCafé es un sistema de gestión de pedidos para una cafetería universitaria. Permite:
- Registrar productos al pedido
- Ver resumen del pedido actual
- Finalizar el pedido aplicando descuentos según tipo de usuario
- Cargar productos de demostración

**Carta de productos (base):**

1. Tinto (\$1500)
2. Cappuccino (\$4500)
3. Pandebono (\$3000)
4. Sándwich (\$8500)

**Tipos de usuario y descuentos:**

* Estudiante: 10%
* Profesor: 5%
* Visitante: 0%


El proyecto ilustra conceptos  de C++ como: funciones, arreglos, paso por referencia, validación de datos y estructuras de control.

## Estructura del programa

### Convenciones de código (obligatorias)

* **Funciones y variables locales:** `camelCase` → `calcularSubtotal()`, `precioUnitario`, `cantidadSolicitada`.
* **Archivos:** `PascalCase` → `Producto`, `Pedido`, `TipoUsuario`.
* **Constantes y macros:** `MAYUS_CON_GUIONES` → `DESCUENTO_ESTUDIANTE`, `MAX_ITEMS`.
* Comentarios breves **encima** de cada función explicando su propósito.
* Nombres **en español**, claros y sin abreviaturas crípticas.

### Archivos principales

- **`Cafe.h`**: Contiene las declaraciones de funciones y constantes (interfaz)
- **`Cafe.cpp`**: Contiene la implementación de las funciones (lógica)
- **`main.cpp`**: Contiene la función principal que coordina todo el programa

### Componentes clave

1. **Constantes**: Valores fijos como precios y descuentos
   ```cpp
   const int PRECIO_TINTO = 1500;
   const double DESCUENTO_ESTUDIANTE = 0.10;
   ```

2. **Arreglos para almacenar datos**: A diferencia de las listas en Python, estos tienen tamaño fijo
   ```cpp
   int codigos[MAX_ITEMS] = {0};
   int cantidades[MAX_ITEMS] = {0};
   ```

3. **Menú interactivo**: Implementado mediante un bucle `do-while` y un `switch`
   ```cpp
   do {
       mostrarMenuPrincipal();
       opcion = leerOpcionMenu();
       switch (opcion) {
           // Casos para diferentes opciones
       }
   } while (opcion != -1);
   ```

## Conceptos clave de C++
### 2. Diferencias clave entre C++ y Python

#### Compilación vs. Interpretación
- **Python**: Interpretado, los errores se descubren durante la ejecución.
- **C++**: Compilado, muchos errores se detectan antes de ejecutar el programa.

#### Tipos de datos
- **Python**: Tipado dinámico (una variable puede cambiar de tipo).
- **C++**: Tipado estático (el tipo se define al declarar la variable).

```cpp
// En C++ debes declarar el tipo:
int cantidad = 5;
string nombre = "Tinto";

// En Python sería:
# cantidad = 5
# nombre = "Tinto"
```

#### Arreglos y colecciones
- **Python**: Listas dinámicas, flexibles y con muchos métodos incorporados.
- **C++**: En este programa. Arreglos estáticos con tamaño fijo definido en la declaración. Más adelante en el curso se aprenderá sobre contenedores dinámicos

```cpp
// En C++:
int codigos[MAX_ITEMS] = {0}; // Tamaño fijo

// En Python equivalente:
# codigos = [0] * MAX_ITEMS  # Pero es dinámico y puede crecer
```

####  Paso de parámetros
- **Python**: Paso por referencia para objetos mutables, valor para inmutables.
- **C++**: Paso explícito por valor o referencia (`&`).

```cpp
// Paso por referencia en C++:
void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
```

<details>
<summary>Ver más info sobre el paso de parámetros por valor y referencia</summary>

- **Python**: Paso por referencia para objetos mutables, valor para inmutables. Por ejemplo:
  ```python
  def modificar_lista(lista):
      lista.append(4)

  mi_lista = [1, 2, 3]
  modificar_lista(mi_lista)
  print(mi_lista)  # Salida: [1, 2, 3, 4]
  ```

  En este caso, la lista original se modifica porque es un objeto mutable.

- **C++**: Paso explícito por valor o referencia (`&`). Por ejemplo:
  ```cpp
  void modificarValor(int& numero) {
      numero += 10;
  }

  int valor = 5;
  modificarValor(valor);
  std::cout << valor;  // Salida: 15
  ```

  Aquí, el valor original de la variable `valor` se modifica porque se pasa por referencia.

  Si se pasa por valor, el original no se modifica:
  ```cpp
  void modificarValor(int numero) {
      numero += 10;
  }

  int valor = 5;
  modificarValor(valor);
  std::cout << valor;  // Salida: 5
  ```
</details>

#### Declaración vs. Implementación

En C++ es común separar lo que hace una función (declaración) de cómo lo hace (implementación):

- **Declaración** (en `Cafe.h`):
  ```cpp
  double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados);
  ```

- **Implementación** (en `Cafe.cpp`):
  ```cpp
  double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados) {
      double subtotal = 0.0;
      for (int i = 0; i < cantidadItemsRegistrados; i++) {
          // Código de la función
      }
      return subtotal;
  }
  ```

## Guía para explorar el código

Para entender el funcionamiento, se recomienda ejecutar el programa en este orden:

1. Inicia ejecutando el programa
2. Selecciona la opción 4 (Prediligenciar productos de demostración)
3. Usa la opción 2 para ver el resumen del pedido
4. Prueba la opción 3 para finalizar y pagar
5. Selecciona la opción 1 para agregar manualmente más productos
6. Vuelve a las opciones 2 y 3 para ver cómo cambia el resumen

### Funciones clave a estudiar:

- `prediligenciarProductosDemo()`: Muestra cómo se llenan los arreglos con datos
- `registrarProducto()`: Da ejemplos de  validaciones y actualización de arreglos
- `calcularSubtotalPedido()`: Muestra recorrido de arreglos y cálculos
- `mostrarResumenPedido()`: Muestra cómo presentar información al usuario

## Ejercicios sugeridos

1. **Modifica la función `prediligenciarProductosDemo(int codigos[], int cantidades[], int & cantidadItemsRegistrados)`** para incluir otros productos
2. **Modifica la función `prediligenciarProductosDemo(int codigos[], int cantidades[], int & cantidadItemsRegistrados)`** para quitar el & de la declaración e implementación, observa el resultado, intenta explicar por qué ahora el sistema indica que no tiene productos
3. **Agrega una nueva función** para mostrar el producto más caro del pedido
4. **Implementa una opción** para eliminar un producto del pedido
5. **Mejora la validación** para asegurar que los precios siempre sean positivos
6. **Añade una nueva categoría de usuario** con un descuento diferente

**Respuesta 2:** El & al lado de la variable significa que se está pasando una referencia a esa variable. Eso quiere decir que cualquier cambio que se haga sobre esa referencia dentro de la función se aplica directamente a la variable original que fue enviada como parámetro.

En cambio, si no usamos &, lo que se pasa es una copia por valor. Entonces, cualquier modificación dentro de la función solo afectará a esa copia local y no a la variable original del programa.

Por eso, cuando se quita el &, los cambios en cantidadItemsRegistrados ya no se reflejan fuera de la función, y el sistema sigue viendo el valor original (normalmente 0).

