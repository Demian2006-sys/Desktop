#include <stdio.h>

int main() {
    int stock, cantidad, opcion, valid = 0;
    float precio, descuento, total_ganancias = 0, venta = 0;
    char nombre[30], id[30], opc;

    do {
        printf("==========================================\n");
        printf("_Menu de opciones_\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("==========================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); 
        
        if (opcion >= 2 && opcion <= 5 && valid == 0) {
            printf("No se ha registrado ningún producto. Ingrese primero en la opcion 1.\n");
            continue;
        }

        switch (opcion) {
        case 1:
            printf("Ingrese el ID del producto: ");
            fflush (stdin);
            fgets(id, 30, stdin);
          

            printf("Ingrese el nombre del producto: ");
            fflush (stdin);
            fgets(nombre, 30, stdin);

            do {
                printf("Ingrese la cantidad inicial en stock: ");
                if (scanf("%d", &stock) != EOF)
                {
                if (stock <= 0) {
                    printf("Cantidad no válida, no se acepta el 0 o un número menor\n");
                }
            }
            } while (stock <= 0);

            do {
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);
                if (precio <= 0) {
                    printf("Precio no válido, no se acepta el 0 o un número menor\n");
                }
            } while (precio <= 0);

            valid = 1; 
            break;
            
        if (valid == 0){
            printf("No se ha registrado ningún producto, tiene que ingresar primero en la opción 1\n");
        }else{
        case 2:
            
            do {
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                if (cantidad < 1) {
                    printf("La cantidad debe ser mayor a 0, vuelva a ingresar\n");
                }
                if (cantidad > stock) {
                    printf("No existe la cantidad necesaria para esta venta\n");
                }
            } while (cantidad < 1 || cantidad > stock);

            printf("Desea ingresar un descuento? (S/N): ");
            scanf(" %c", &opc); 

            venta = cantidad * precio; 

            if (opc == 'S' || opc == 's') {
                do {
                    printf("Ingrese el porcentaje de descuento: ");
                    scanf("%f", &descuento);
                    if (descuento < 0 || descuento > 100) {
                        printf("Descuento no válido, debe ser un valor entre 0 y 100.\n");
                    }
                } while (descuento < 0 || descuento > 100);
            venta *= (1 - descuento / 100);
            }

            printf("El precio final de la venta es: %.2f\n", venta);
            total_ganancias += venta;
            stock -= cantidad;
            
            break;

        case 3:
            
            do {
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                if (cantidad <= 0) {
                    printf("Cantidad no válida\n");
                }
            } while (cantidad <= 0);
            stock += cantidad;
            
            break;

        case 4:
            
            printf("\nInformación del producto:\n");
            printf("ID: %s\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: %.2f\n", precio);
            
            break;

        case 5:
         printf("Total de ganancias: $%.2f\n", total_ganancias);
        
        break;
        }

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}