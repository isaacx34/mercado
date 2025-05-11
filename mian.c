#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int *total)
{
    printf("Ingrese la cantidad de productos (max %d): ", MAX_PRODUCTOS);
    scanf("%d", total);
    if (*total > MAX_PRODUCTOS)
        *total = MAX_PRODUCTOS;

    for (int i = 0; i < *total; i++)
    {
        printf("Producto #%d:\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", nombres[i]);
        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
}

float calcularPrecioTotal(float precios[], int total)
{
    float suma = 0;
    for (int i = 0; i < total; i++)
    {
        suma += precios[i];
    }
    return suma;
}

float calcularPromedio(float precios[], int total)
{
    if (total == 0)
        return 0;
    return calcularPrecioTotal(precios, total) / total;
}

int encontrarMasCaro(float precios[], int total)
{
    int indice = 0;
    for (int i = 1; i < total; i++)
    {
        if (precios[i] > precios[indice])
        {
            indice = i;
        }
    }
    return indice;
}

int encontrarMasBarato(float precios[], int total)
{
    int indice = 0;
    for (int i = 1; i < total; i++)
    {
        if (precios[i] < precios[indice])
        {
            indice = i;
        }
    }
    return indice;
}

int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int total, const char nombreBuscado[])
{
    for (int i = 0; i < total; i++)
    {
        if (strcmp(nombres[i], nombreBuscado) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int totalProductos;

    ingresarDatos(nombres, precios, &totalProductos);

    printf("\nPrecio total del inventario: $%.2f\n", calcularPrecioTotal(precios, totalProductos));
    printf("Precio promedio: $%.2f\n", calcularPromedio(precios, totalProductos));

    int indiceCaro = encontrarMasCaro(precios, totalProductos);
    int indiceBarato = encontrarMasBarato(precios, totalProductos);

    printf("Producto más caro: %s ($%.2f)\n", nombres[indiceCaro], precios[indiceCaro]);
    printf("Producto más barato: %s ($%.2f)\n", nombres[indiceBarato], precios[indiceBarato]);

    char nombreBusqueda[MAX_NOMBRE];
    printf("\nIngrese el nombre del producto a buscar: ");
    scanf(" %[^\n]", nombreBusqueda);

    int encontrado = buscarProducto(nombres, precios, totalProductos, nombreBusqueda);
    if (encontrado != -1)
    {
        printf("Producto encontrado: %s, Precio: $%.2f\n", nombres[encontrado], precios[encontrado]);
    }
    else
    {
        printf("Producto no encontrado.\n");
    }

    return 0;
}