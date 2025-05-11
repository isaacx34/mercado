#ifndef FUNCION_H
#define FUNCION_H

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int *total);
float calcularPrecioTotal(float precios[], int total);
float calcularPromedio(float precios[], int total);
int encontrarMasCaro(float precios[], int total);
int encontrarMasBarato(float precios[], int total);
int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int total, const char nombreBuscado[]);

#endif