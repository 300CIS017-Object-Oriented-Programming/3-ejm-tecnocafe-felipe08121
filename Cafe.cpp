//
// Created by lenovo on 20/08/2025.
//
#include "Cafe.h"




void mostrarCartaProductos()
{
    cout << "\n--- Carta de productos ---\n";
    cout << "1. Tinto       $" << PRECIO_TINTO << "\n";
    cout << "2. Cappuccino  $" << PRECIO_CAPPUCCINO << "\n";
    cout << "3. Pandebono   $" << PRECIO_PANDEBONO << "\n";
    cout << "4. Sandwich    $" << PRECIO_SANDWICH << "\n";
    cout << "5. Pizza       $" << PRECIO_PIZZA    << "\n";
    cout << "6. Hamburguesa $" << PRECIO_HAMBUERGUESA << "\n";
}

int leerCodigoProducto()
{
    cout << "Ingrese el codigo del producto (1-6): ";
    int codigo;
    cin >> codigo;
    while (codigo < 1 || codigo > 6)
    {
        cout << "Codigo inválido. Intente de nuevo (1-6): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> codigo;
    }
    return codigo;
}

int leerCantidadProducto()
{
    cout << "Ingrese la cantidad (1-20): ";
    int cantidad;
    cin >> cantidad;
    while (cantidad < 1 || cantidad > 20)
    {
        cout << "Cantidad invalida. Intente de nuevo (1-20): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cantidad;
    }
    return cantidad;
}

int obtenerPrecioPorCodigo(int codigoProducto)
{
    switch (codigoProducto) {
        case 1: {
            if (PRECIO_TINTO < 0 ){
                return PRECIO_TINTO * -1; /* Validaciones de los precios, si identifica que el precio es menor a cero
                (negativo) lo multiplica por -1 para asegurar que mantenga el mismo valor, pere que el precio sea positivo.
            */
            }
            else {
                return PRECIO_TINTO;
            }
        }
        case 2: {
            if (PRECIO_CAPPUCCINO < 0 ) {
                return PRECIO_CAPPUCCINO * - 1;
            }
            else {
                return PRECIO_CAPPUCCINO;
            }
        }
        case 3: {
            if ( PRECIO_PANDEBONO < 0) {
                return PRECIO_PANDEBONO * -1;
            }
            else {
                return PRECIO_PANDEBONO;
            }
        }
        case 4: {
            if (PRECIO_SANDWICH < 0) {
                return PRECIO_SANDWICH * -1;
            }
            else {
                return PRECIO_SANDWICH;
            }
        }
        case 5: {
            if (PRECIO_PIZZA < 0) {
                return PRECIO_PIZZA * -1 ;
            }
            else {
                return PRECIO_PIZZA;
            }
        }
        case 6: {
            if (PRECIO_HAMBUERGUESA < 0) {
                return PRECIO_HAMBUERGUESA * -1;
            }
            else {
                return PRECIO_HAMBUERGUESA;
            }
        }
        default: {
            return 0;
        }
    }
}

string obtenerNombreProducto(int codigoProducto)
{
    switch (codigoProducto) {
        case 1: {
            return "Tinto";
        }
        case 2: {
            return "Cappuccino";
        }
        case 3: {
            return "Pandebono";
        }
        case 4: {
            return "Sandwich";
        }
        case 5: {
            return "Pizza";
        }
        case 6: {
            return "Hamburguesa";
        }

        default: {
            return "Desconocido";
        }
    }
}

void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
{
    if (cantidadItemsRegistrados >= MAX_ITEMS)
    {
        cout << "No es posible registrar más ítems en el pedido.\n";
        return;
    }
    mostrarCartaProductos();
    int codigo = leerCodigoProducto();
    int cantidad = leerCantidadProducto();

    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        if (codigos[i] == codigo)
        {
            cantidades[i] += cantidad;
            cout << "Producto actualizado: " << obtenerNombreProducto(codigo)
                << " x" << cantidades[i] << " (cantidad acumulada)\n\n";
            return;
        }
    }

    codigos[cantidadItemsRegistrados] = codigo;
    cantidades[cantidadItemsRegistrados] = cantidad;
    cantidadItemsRegistrados++;

    cout << "Producto agregado: " << obtenerNombreProducto(codigo)
        << " x" << cantidad << "\n\n";
}

double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados)
{
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        int precioUnitario = obtenerPrecioPorCodigo(codigos[i]);
        subtotal += precioUnitario * cantidades[i];
    }
    return subtotal;
}

int leerTipoUsuario()
{
    cout << "Tipo de usuario (1=Estudiante, 2=Profesor, 3=Visitante, 4=Perafan): ";
    int tipo;
    cin >> tipo;
    while (tipo < 1 || tipo > 4)
    {
        cout << "Opción inválida. Intente de nuevo (1-4): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> tipo;
    }
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoUsuario)
{
    if (tipoUsuario == 1 )
    {
        return DESCUENTO_ESTUDIANTE;
    }
    if (tipoUsuario == 2)
    {
        return DESCUENTO_PROFESOR;
    }

    if ( tipoUsuario == 4 )
    {
        return DESCUENTO_PERAFAN;
    }

    return DESCUENTO_VISITANTE;


}

double calcularTotal(double subtotal, double porcentajeDescuento)
{
    return subtotal * (1.0 - porcentajeDescuento);
}

void mostrarResumenPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados,
                          double porcentajeDescuento)
{
    cout << "\n===== Resumen del Pedido =====\n";
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        string nombre = obtenerNombreProducto(codigos[i]);
        int precio = obtenerPrecioPorCodigo(codigos[i]);
        double parcial = precio * cantidades[i];
        subtotal += parcial;
        cout << "- " << nombre << " x" << cantidades[i] << " = $" << parcial << "\n";
    }
    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento aplicado: " << (porcentajeDescuento * 100) << "%\n";
}

void productoMasCaro( const int codigos[], int cantidadItemsRegistrados )
{
    if ( cantidadItemsRegistrados == 0 ) {
        cout << "No hay ninguno Item registrado. \n";
        return;
    }
    int max = 0;
    int j; // Contador para los nombres.

    for (int i = 0 ; i < cantidadItemsRegistrados ; i++ ) {
        if ( obtenerPrecioPorCodigo(codigos[ i ]) > max )  {
            max = obtenerPrecioPorCodigo(codigos[ i ]);
            j = i;
        }
    }

    cout << "El producto mas caro es: " << obtenerNombreProducto(codigos[ j ]) << '\n';
    cout << "Y su precio es: " << max << "\n\n";
}

void productosRegistrados(int codigos[], int cantidades[], int cantidadItemsRegistrados ){
    cout << "Los siguientes productos : " << '\n';
    for ( int i = 0;  i < cantidadItemsRegistrados; i++ ) {

        cout <<obtenerNombreProducto( codigos [ i ] ) << "; Codigo de producto: " << codigos[ i ] << '\n';

    }

    double subtotal = calcularSubtotalPedido(codigos, cantidades, cantidadItemsRegistrados);
    cout << fixed << setprecision(2);
    cout << "\nSubtotal actual: $" << subtotal << "\n\n";
}

void eliminarProductos(int codigos[], int cantidades[], int &cantidadItemsRegistrados) {

    if ( cantidadItemsRegistrados == 0 ) {
        cout << "No hay ninguno Item registrado. \n";
    }
    productosRegistrados( codigos, cantidades, cantidadItemsRegistrados );

    int codigo;
    cout << "Ingrese el codigo del producto a eliminar: ";
    cin >> codigo;
    string nombre;

    if ( codigo < 1 && codigo > 6 ) {
        cout <<  "Codigo Invalido, Intente nuevamente. \n";
        return;
    }

    bool bandera = false;

    for (int i = 0 ; i < cantidadItemsRegistrados ; i++ ) {
        cout << codigos[i] << "- \n";
        if ( codigos[ i ] == codigo )  {
            nombre = obtenerNombreProducto(codigos[ i ]);
            cantidades[ i ]=0;
            codigos[ i ] = 0;
            bandera = true;
            cout << codigos[i] << " <--\n";
        }
        if ( bandera == true ) {
            codigos[ i ] = codigos[ i + 1 ];
            cantidades[ i ] = cantidades[ i + 1 ];
            codigos[ i + 1 ] = 0;
            cantidades[ i + 1 ] = 0;
            cout << codigos[i] << " --\n";
        }
    }
    cantidadItemsRegistrados--;
    productosRegistrados( codigos, cantidades, cantidadItemsRegistrados );

    cout << "El producto: " << nombre << " Fue eliminado" <<"\n\n";

}


void prediligenciarProductosDemo(int codigos[], int cantidades[], int & cantidadItemsRegistrados)
{
    // Limpiar pedido actual si existe
    cantidadItemsRegistrados = 0;

    // Añadir productos de ejemplo
    codigos[0] = 1;  // Tinto
    cantidades[0] = 2;

    codigos[1] = 3;  // Pandebono
    cantidades[1] = 3;

    codigos[2] = 4;  // Sandwich
    cantidades[2] = 1;

    codigos[ 3 ] = 5; // Pizza
    cantidades[ 3 ] = 4;

    codigos[ 4 ] = 6; // Hamburguesas
    cantidades[ 4 ] = 5;

    cantidadItemsRegistrados = 5;

    cout << "\nSe han cargado productos de ejemplo en el pedido:\n";
    cout << "- 2 Tintos\n";
    cout << "- 3 Pandebonos\n";
    cout << "- 1 Sandwich\n";
    cout << "- 4 Pizzas\n";
    cout << "- 5 Hamburguesas\n\n";
}