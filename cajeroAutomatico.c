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

void usuarioCargado(int arrayNroCuenta[], int arrayContrasenia[], char arrayNombre[][20], float arraySaldo[], char arrayEstado[][10]);
void usuarioValidacion(int arrayNroCuenta[], int arrayContrasenia[], char arrayEstado[][10]);

void main()
{

    int nroCuenta[tam];
    int contrasenia[tam];
    char nombre[tam][20];
    float saldo[tam];
    char estado[tam][10];

    usuarioCargado(nroCuenta, contrasenia, nombre, saldo, estado);
    usuarioValidacion2(nroCuenta, contrasenia, estado[10]);

    system("pause");
}

void usuarioCargado(int arrayNroCuenta[], int arrayContrasenia[], char arrayNombre[][20], float arraySaldo[], char arrayEstado[][10])
{

    arrayNroCuenta[0] = 1000;
    arrayContrasenia[0] = 6666;
    arrayNombre[0][20] = "Nicolas Cataldi";
    arraySaldo[0] = 99999999999;
    arrayEstado[0][10] = "Activo";

    arrayNroCuenta[1] = 2000;
    arrayContrasenia[1] = 9999;
    arrayNombre[1][20] = "Manuel Cecarelli";
    arraySaldo[1] = 5000;
    arrayEstado[1][10] = "Activo";

    arrayNroCuenta[2] = 3000;
    arrayContrasenia[2] = 5264;
    arrayNombre[2][20] = "Geraldine Corvalan";
    arraySaldo[2] = 1000000000;
    arrayEstado[2][10] = "Activo";

    arrayNroCuenta[3] = 4000;
    arrayContrasenia[3] = 2023;
    arrayNombre[3][20] = "Valentina Garrido";
    arraySaldo[3] = 500000;
    arrayEstado[3][10] = "Activo";

    arrayNroCuenta[4] = 5000;
    arrayContrasenia[4] = 1557234560;
    arrayNombre[4][20] = "Jeremias Zagaglia";
    arraySaldo[4] = 30;
    arrayEstado[4][10] = "Activo";

    arrayNroCuenta[5] = 6000;
    arrayContrasenia[5] = 1989;
    arrayNombre[5][20] = "Taylor Swift";
    arraySaldo[5] = 10000000000;
    arrayEstado[5][10] = "Activo";

    arrayNroCuenta[6] = 7000;
    arrayContrasenia[6] = 3336;
    arrayNombre[6][20] = "Tini Stoessel";
    arraySaldo[6] = 999999999;
    arrayEstado[6][10] = "Activo";

    arrayNroCuenta[7] = 8000;
    arrayContrasenia[7] = 696;
    arrayNombre[7][20] = "Los palmeras";
    arraySaldo[7] = 9090909090;
    arrayEstado[7][10] = "Activo";

    arrayNroCuenta[8] = 9000;
    arrayContrasenia[8] = 9999;
    arrayNombre[8][20] = "Alejandro Sanz";
    arraySaldo[8] = 111000000;
    arrayEstado[8][10] = "Activo";

    arrayNroCuenta[9] = 1001;
    arrayContrasenia[9] = 5432;
    arrayNombre[9][20] = "Chayanne";
    arraySaldo[9] = 999999999;
    arrayEstado[9][10] = "Activo";
}

void usuarioValidacion(int arrayNroCuenta[], int arrayContrasenia[], char arrayEstado[][10])
{

    int intentos = 1;
    int nroIngresado;
    int passIngresado;
    int bandera = 0;//nuevo

    do
    {

        printf("Ingrese su usuario (intento %d/3)\n", intentos);
        scanf("%d", &nroIngresado);
        printf("Ingrese su contrase%ca (intento %d/3)\n", 164, intentos);
        scanf("%d", &passIngresado);
        for (int i = 0; i < tam; i++)
        {

            /*if (nroIngresado == arrayNroCuenta[i] && passIngresado == arrayContrasenia[i])
            {
                bandera = 1;
            }*/
            
        

            if (nroIngresado != arrayNroCuenta[i]) 
            {
                if (passIngresado != arrayContrasenia[i])
                {
                   printf("N%cmero de cuenta o contrase%ca incorrectos\n", 163, 164); 
                }
                
                
            }else if(nroIngresado == arrayNroCuenta[i] && passIngresado == arrayContrasenia[i])
            {
                intentos = intentos + 3;
                printf("Bienvenido\n");
            }
            /* if (intentos == 4)
             {

                 printf("No se permiten m%cs intentos. Su cuenta ha sido bloqueada, comun%cquese con la entidad bancaria para su restablecimiento\n", 160, 161);
                 if (nroIngresado == arrayNroCuenta[i])
                 {
                     arrayEstado[i] = "Bloqueado";
                 }
             }*/
        }
       // bandera = 0; nuevo
        intentos++;

    } while (intentos <= 3);
}



void usuarioValidacion2(int arrayNroCuenta[], int arrayContrasenia[], char arrayEstado[][10])
{
    int intentos = 1;
    int nroIngresado;
    int passIngresado;
    int bandera = 0;//nuevo
for (int i = 0; i < 3; i++)
{
    


    printf("Ingrese su usuario (intento %d/3)\n", intentos);
    scanf("%d", &nroIngresado);
    printf("Ingrese su contraseña (intento %d/3)\n", intentos);
    scanf("%d", &passIngresado);

    for (int j = 0; j < tam; j++)
    {
        if (nroIngresado == arrayNroCuenta[j] && passIngresado == arrayContrasenia[j])
        {
            bandera = 1;
            i = tam;
            break;
        }
    }

    if (bandera == 1)
    {
        intentos = intentos + 3;
        printf("Bienvenido\n");
    }
    else
    {
        printf("Número de cuenta o contraseña incorrectos\n");
    }

  
    if (intentos == 3)
{
    printf("No se permiten más intentos. Su cuenta ha sido bloqueada, comuníquese con la entidad bancaria para su restablecimiento.\n");
    if (bandera == 1)
    {
        strcpy(arrayEstado[i], "Bloqueado");
    }
}



    intentos++;
}

}

