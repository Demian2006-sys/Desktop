#include <stdio.h>

int main()
{
    int stock, cantidad, opcion, valid = 0;
    float precio, total_ganancias = 0, venta = 0;
    char nombre[30], id [30];

    do
    {
        printf("\nMenú de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            // Registro del producto
            printf("Ingrese el ID del producto: ");
            fflush (stdin);
            fgets(id, 30, stdin);

            printf("Ingrese el nombre del producto: ");
            fflush (stdin);
            fgets(nombre, 30, stdin);
            do{
            printf("Ingrese la cantidad inicial en stock: ");
            scanf("%d", &stock);
            if (stock<=0){
                printf("Cantidad no valida, no se acepta el 0 o un numero menor\n");
            }
            }while (stock<=0);
            do{
            printf("Ingrese el precio unitario del producto: ");
            scanf("%f", &precio);
            valid+=1;
            if (stock<=0){
                printf("Precio no valido, no se acepta el 0 o un numero menor\n");
            }
            }while (precio<=0);
            break;

        case 2:
        if (valid==0) {
				printf ("No se ha registrado ningun producto, tiene que ingresar primero en la opcion 1\n");
			}else{
        do{
            printf("Ingrese la cantidad a vender: ");
            scanf("%d", &cantidad);
        if (cantidad<1){
        printf ("La cantidad debe ser mayor a 0, vuelva a ingresar\n");
        }
        if (cantidad>stock){
            printf ("No existe la cantidad necesaria para esta venta\n");
        }
        }while (cantidad<1 || cantidad>stock);
         
        venta = cantidad*precio;
        printf ("El precio de la venta es %.2f\n",venta);
        total_ganancias+=venta;
        stock-=cantidad;
			}
        break;

        case 3:
        if (valid==0) {
				printf ("No se ha registrado ningun producto, tiene que ingresar primero en la opcion 1\n");
			}else{
        do{
            printf("Ingrese la cantidad a agregar al stock: ");
            scanf("%d", &cantidad);
            if (cantidad<=0){
                printf ("Cantidad no valida");
            }
        }while (cantidad<=0);
            stock+=cantidad;
			}
            break;

        case 4:
        if (valid==0) {
				printf ("No se ha registrado ningun producto, tiene que ingresar primero en la opcion 1\n");
			}else{
            printf("\nInformación del producto:\n");
            printf("ID: %s\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: %.2f\n", precio);
			}
            break;

        case 5:
        if (valid==0) {
				printf ("No se ha registrado ningun producto, tiene que ingresar primero en la opcion 1\n");
			}else{
            printf("Total de ganancias: $%.2f\n", total_ganancias);
			}
            break;

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}