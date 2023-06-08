#include <stdio.h>
#include <string.h>

struct contacto
{
    char cedula[10];
    char nombre[50];
    char numero[10];
};

int main(int argc, char *argv[])
{
    int opcion;
    struct contacto ListaContactos[5];
    int cont = 0;
    do
    {

        printf("\tContactos\n");
        printf("1. Nuevo Contacto\n");
        printf("2. Busqueda del contacto por la cedula\n");
        printf("3. Salir\n");
        printf("Seleccione un opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            if (cont <= 4){
                char IngresoCedula[10];
                char IngresoNombre[50];
                char IngresoNumero[10];
                printf("Ingrese el nombre del contacto\n");
                fflush(stdin);
                scanf("%[^\n]", IngresoNombre);
                fflush(stdin);

                printf("Ingrese la cédula del contacto\n");
                scanf("%[^\n]", IngresoCedula);
                fflush(stdin);

                printf("Ingrese el numero de telefono\n");
                scanf("%[^\n]", IngresoNumero);
                fflush(stdin);

                strcpy(ListaContactos[cont].cedula, IngresoCedula);
                strcpy(ListaContactos[cont].nombre, IngresoNombre);
                strcpy(ListaContactos[cont].numero, IngresoNumero);
                cont = cont + 1;
            }else{
                printf("Lista de Contactos llena!!!");
            }
        }

        if (opcion == 2)
        {
            char BuscaCedula[10];
            fflush(stdin);
            printf("\nIngrese el número de cedula del contacto");
            scanf("%[^\n]", BuscaCedula);
            int busca=0;
            int resultado=1;
            do
            {
                resultado = strcmp (ListaContactos[busca].cedula,BuscaCedula);
                busca=busca + 1;
            } while (resultado!=0 && busca<5);

            busca=busca-1;
            printf("El contacto es \n%s, \n%s, \n%s\n", ListaContactos[busca].nombre, ListaContactos[busca].cedula, ListaContactos[busca].numero);
        }
    } while (opcion != 3);

    return 0;
}