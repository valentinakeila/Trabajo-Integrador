/*LC1 – Trabajo Práctico Cajero automático
El siguiente enunciado deberá ser resuelto en grupo de entre 3 y 4 integrantes.
Parte 1
Debemos desarrollar un programa de simulación del funcionamiento de un cajero automático de un
banco.
Considerar en principio que el banco tiene 10 clientes. Los datos de los mismos son: Numero de
cuenta, contraseña, nombre, saldo y estado (Activo/Bloqueado).
El programa permitirá entonces que un cliente inicie sesión, realice operaciones y finalice sesión,
quedando el cajero disponible para la consulta de otro cliente.
Las acciones que podrá realizar un cliente que ha iniciado sesión, son las siguientes:
1) Depósito.
2) Extracción.
3) Consultar saldo.
4) Mostrar la cantidad de operaciones realizadas y el saldo actual.
Para el inicio de sesión se le pedirá al cliente que ingrese su número de cuenta y su contraseña. Si
ambos datos son correctos y el estado del cliente es "Activo", se le muestra un menú al cliente con
las 4 opciones ante.riormente detalladas y una opción número 5 para salir de su sesión. De lo
contrario, si alguno de los datos ingresados es incorrecto, mostrar el mensaje “Número de cuenta o
contraseña incorrecta”. O si el cliente está bloqueado, el mensaje "Su cuenta se encuentra
bloqueada, comuníquese con la entidad bancaria para su restablecimiento”.
Permitir sólo ingresar 3 veces los datos de inicio de manera incorrecta, a la 3ra vez mostrar el
mensaje “No se permiten más intentos. Su cuenta ha sido bloqueada, comuníquese con la entidad
bancaria para su restablecimiento”. Además esta situación deberá cambiar el estado del cliente a
“Bloqueado”.
Las acciones de depositar y extraer deberán modificar el saldo del cliente.
Validar que el monto de la extracción no supere el saldo del cliente y de ser así inrmarlo con un
mensaje.
No se permitirá registrar más de 10 movimientos del tipo 1, 2 y 3. Cuando se llegue a los 10
movimientos el sistema deberá mostrar un cartel informando “Llegó al límite de operaciones. Fin.
Gracias!”. En caso de que el cliente quiera continuar efectuando operaciones deberá ingresar su
número de cuenta y contraseña nuevamente*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int tam = 10;
const int maxMovimientos = 5;

void usuarioCargado(int arrayNroCuenta[], int arrayContrasenia[], char arrayNombre[][20], double arraySaldo[], char arrayEstado[][10]);
void usuarioValidacion2(int arrayNroCuenta[], int arrayContrasenia[], char arrayEstado[][10], int opcion, int numOperaciones, double arraySaldo[]);
void deposito(int indiceCuenta, double arraySaldo[]);
void menu(int opcion, int numOperaciones, int indiceCuenta, double arraySaldo[]);
void main()
{
    int nroCuenta[10];   // [tam] Cambie los corchetes a "10" porque mi visual studio me marca error, iba "tam"
    int contrasenia[10]; // [tam]
    char nombre[10][20]; // [tam][20]
    double saldo[10];    // [tam] Se cambio a double porque float no admitia el saldo de Nico
    char estado[10][10]; // [tam][10]
    int opcion;
    int numOperaciones = 0;

    usuarioCargado(nroCuenta, contrasenia, nombre, saldo, estado);
    usuarioValidacion2(nroCuenta, contrasenia, estado, opcion, numOperaciones, saldo);

    system("pause");
}

void usuarioCargado(int arrayNroCuenta[], int arrayContrasenia[], char arrayNombre[][20], double arraySaldo[], char arrayEstado[][10])
{
    arrayNroCuenta[0] = 1000;
    arrayContrasenia[0] = 6666;
    strcpy(arrayNombre[0], "Nicolas Cataldi");
    arraySaldo[0] = 99999999;
    strcpy(arrayEstado[0], "Bloqueado");

    arrayNroCuenta[1] = 2000;
    arrayContrasenia[1] = 9999;
    strcpy(arrayNombre[1], "Manuel Cecarelli");
    arraySaldo[1] = 5000;
    strcpy(arrayEstado[1], "Activo");

    arrayNroCuenta[2] = 3000;
    arrayContrasenia[2] = 5264;
    strcpy(arrayNombre[2], "Geraldine Corvalan");
    arraySaldo[2] = 1000000000;
    strcpy(arrayEstado[2], "Activo");

    arrayNroCuenta[3] = 4000;
    arrayContrasenia[3] = 2023;
    strcpy(arrayNombre[3], "Valentina Garrido");
    arraySaldo[3] = 500000;
    strcpy(arrayEstado[3], "Bloqueado");

    arrayNroCuenta[4] = 5000;
    arrayContrasenia[4] = 1557234560;
    strcpy(arrayNombre[4], "Jeremias Zagaglia");
    arraySaldo[4] = 30;
    strcpy(arrayEstado[4], "Activo");

    arrayNroCuenta[5] = 6000;
    arrayContrasenia[5] = 1989;
    strcpy(arrayNombre[5], "Taylor Swift");
    arraySaldo[5] = 10000000000;
    strcpy(arrayEstado[5], "Activo");

    arrayNroCuenta[6] = 7000;
    arrayContrasenia[6] = 3336;
    strcpy(arrayNombre[6], "Tini Stoessel");
    arraySaldo[6] = 999999999;
    strcpy(arrayEstado[6], "Activo");

    arrayNroCuenta[7] = 8000;
    arrayContrasenia[7] = 696;
    strcpy(arrayNombre[7], "Los palmeras");
    arraySaldo[7] = 9090909090;
    strcpy(arrayEstado[7], "Activo");

    arrayNroCuenta[8] = 9000;
    arrayContrasenia[8] = 9999;
    strcpy(arrayNombre[8], "Alejandro Sanz");
    arraySaldo[8] = 111000000;
    strcpy(arrayEstado[8], "Activo");

    arrayNroCuenta[9] = 1001;
    arrayContrasenia[9] = 5432;
    strcpy(arrayNombre[9], "Chayanne");
    arraySaldo[9] = 999999999;
    strcpy(arrayEstado[9], "Activo");
}

void usuarioValidacion2(int arrayNroCuenta[], int arrayContrasenia[], char arrayEstado[][10], int opcion, int numOperaciones, double arraySaldo[])
{
    int intentos = 1;
    int nroIngresado;
    int passIngresado;
    int indiceCuentaBloqueada = -1; /*nueva variable para almacenar el índice del usuario que tiene que ser bloqueado cuando se termina while busco el índice utilizando el número de cuenta ingresado y se pone estado bloqueado al usuario*/
    int indiceCuenta = -1;
    int banderaNro = 0;
    int banderaNroCon = 0;

    do
    {
        int indiceCuenta = -1;
        banderaNro = 0;
        banderaNroCon = 0;

        printf("Ingrese su usuario (intento %d/3)\n", intentos);
        scanf("%d", &nroIngresado);
        printf("Ingrese su contrase%ca (intento %d/3)\n", 164, intentos);
        scanf("%d", &passIngresado);

        for (int i = 0; i < tam; i++)
        {
            if (nroIngresado == arrayNroCuenta[i])
            {

                banderaNro = 1;

                if (passIngresado == arrayContrasenia[i])
                {
                    banderaNroCon = 1;
                    indiceCuenta = i;
                }
            }
        }

        if (banderaNroCon == 1)
        {
            if (strcmp(arrayEstado[indiceCuenta], "Bloqueado") != 0)
            {
                printf("Bienvenido\n");
                menu(opcion, numOperaciones, indiceCuenta, arraySaldo);
            }
            else
            {
                printf("Su cuenta se encuentra bloqueada, comun%cquese con la entidad bancaria para su restablecimiento\n", 161);
            }
        }
        else
        {
            printf("N%cmero de cuenta o contrase%ca incorrectos\n", 163, 164);
            intentos++;
        }

        if (intentos > 3)
        {
            printf("No se permiten m%cs intentos. Su cuenta ha sido bloqueada, comun%cquese con la entidad bancaria para su restablecimiento.\n", 160, 163);
            if (banderaNro == 1)
            {
                    for (int i = 0; i < tam; i++)
                    {
                        if (nroIngresado == arrayNroCuenta[i])
                        {
                            indiceCuentaBloqueada = i;
                            strcpy(arrayEstado[i], "Bloqueado");
                            printf("La cuenta con n%cmero %d ha sido bloqueada.\n", 163, arrayNroCuenta[i]);
                        }
                    }
            }
        }

    } while (intentos <= 3);
}

void extraccion(int indiceCuenta, double arraySaldo[])
{

    int montoExtraccion = 0;
    int banderaCancelar = 0;

    do
    {
        do
        {
            printf("Saldo: $%.2lf\n", arraySaldo[indiceCuenta]);
            printf("Ingrese el monto a extraer\n");
            scanf("%d", &montoExtraccion);

            if (montoExtraccion < 1)
            {
                    printf("Monto no v%clido, ingreselo nuevamente\n", 160);
            }

        } while (montoExtraccion < 1);

        if (montoExtraccion > arraySaldo[indiceCuenta])
        {

            do
            {
                    printf("No posee suficiente saldo, desea cancelar la operaci%cn?\n", 162);
                    printf("1- No\n");
                    printf("2- Si\n");
                    scanf("%d", &banderaCancelar);
            } while (banderaCancelar != 1 && banderaCancelar != 2);
        }
        else if (montoExtraccion % 100 != 0)
        {
            do
            {
                    printf("El monto a retirar debe ser m%cltiplo de 100, desea cancelar la operaci%cn?\n", 163, 162);
                    printf("1- No\n");
                    printf("2- Si\n");
                    montoExtraccion = 0;
                    scanf("%d", &banderaCancelar);
            } while (banderaCancelar != 1 && banderaCancelar != 2);
        }
        else
        {
            arraySaldo[indiceCuenta] = arraySaldo[indiceCuenta] - montoExtraccion;
            printf("Extraido con %cxito, Saldo Actual: $%.2lf\n", 130, arraySaldo[indiceCuenta]);
            banderaCancelar = 2;
        }

    } while (banderaCancelar == 1);
}

void deposito(int indiceCuenta, double arraySaldo[])
{

    double montoDeposito = 0;

    do
    {

        printf("Ingrese el monto a depositar\n");
        scanf("%lf", &montoDeposito);

        if (montoDeposito < 1)
        {
            printf("Monto no v%clido\n", 160);
        }

    } while (montoDeposito < 1);

    arraySaldo[indiceCuenta] += montoDeposito;
    printf("Dep%csito con %cxito, Saldo Actual: $%.2lf\n", 162, 130, arraySaldo[indiceCuenta]);
}

void menu(int opcion, int numOperaciones, int indiceCuenta, double arraySaldo[])
{

    do
    {
        printf("Men%c de opciones\n", 163);
        printf("1- Dep%csito\n", 162);
        printf("2- Extracci%cn\n", 162);
        printf("3- Consultar saldo\n");
        printf("4- Mostrar operaciones y saldo actual\n");
        printf("5- Salir\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: // Deposito

            deposito(indiceCuenta, arraySaldo);

            numOperaciones = numOperaciones + 1;
            break;
        case 2: // Extraccion

            extraccion(indiceCuenta, arraySaldo);

            numOperaciones = numOperaciones + 1;
            break;
        case 3: // Consultar saldo

            printf("Saldo actual: %.2lf\n", arraySaldo[indiceCuenta]);

            numOperaciones = numOperaciones + 1;
            break;
        case 4: // Mostrar operaciones y saldo actual

            printf("Cantidad de operaciones: %d\n", numOperaciones);
            printf("Saldo actual: %.2lf\n", arraySaldo[indiceCuenta]);

            break;
        case 5: // Salir
            printf("Sesi%cn finalizada. Gracias!\n", 162);
            break;
        default: // Opcion incorrecta
            printf("Opci%cn inv%clida. Por favor, intente nuevamente.\n", 162, 160);
        }

        if (numOperaciones >= maxMovimientos)
        {
            printf("Lleg%c al l%cmite de operaciones. Fin. Gracias!\n", 162, 161);
        }

    } while (opcion != 5 && numOperaciones < maxMovimientos);
}