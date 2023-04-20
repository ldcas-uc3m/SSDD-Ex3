#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "lib/claves.h"

#define MAX_VALUE1 256
// #define DEBUG_MODE 1  // uncomment for debug mode


int std_run() {
    if (init() != 0) {
        printf("Error in init\n");
        return -1;
    }

    int key = 0;
    char* value1 = "Prueba";
    int value2 = 1;
    double value3 = 2.4;  
    int err;

    err = set_value(key, value1, value2, value3);
    if (err!=0){
        printf("Error while inserting the value\n");
        return -1;
    }

    int key1 = 0;
    err = exist(key1);
    if (err==-1){
        printf("Error in exist\n");
        return -1;
    }


    int newKey = 1;
    err=copy_key(key1, newKey);
    if (err!=0){
        printf("Error in copy_key\n");
        return -1;
    }

    int value2Modified = 2;
    err = modify_value(newKey, value1, value2Modified, value3);
    if (err!=0){
        printf("Error in modify_value\n");

        return -1;
    }
    
    char* value1Get = malloc(MAX_VALUE1 * sizeof(char));
    int value2Get;
    double value3Get;
    err = get_value(newKey, value1Get, &value2Get, &value3Get);
    if (err==0){
        printf("The obtained values are %s , %d, %f\n", value1Get, value2Get, value3Get);
    }else{
        free(value1Get);
        printf("Error in get_value\n");
        return -1;
    }

    return 0;
}


void debug_run() {
    int opcode;
    int key;
    int key1;
    int key2;
    char value1[MAX_VALUE1];
    int value2;
    double value3;
    int result;

    char tmp[1];

    // menu
    while (true) {
        printf("\n\n-------------\n\n");
        printf("Bienvenido al debugger.\n\n");

        printf("(0) init()\n");
        printf("(1) set_value(int key, char value1[], int value2, double value3)\n");
        printf("(2) get_value(int key)\n");
        printf("(3) modify_value(int key, char value1[], int value2, double value3)\n");
        printf("(4) exist(int key)\n");
        printf("(5) copy_key(int key1, int key2)\n");
        printf("(6) delete_key(int key)\n");

        printf("\nElige el mensaje que enviar: ");
        scanf("%i", &opcode);


        switch (opcode) {
            case 0:  // init
                
                printf("Enviando init()...\n");

                result = init();

                printf("Respuesta: {result: %i}\n", result);
                printf("Pulse ENTER para continuar...\n");
                scanf("%s", tmp);

                break;

            case 1:  // set
                printf("int key: ");
                scanf("%i", &key);
                printf("char value1[]: ");
                scanf("%s", value1);
                printf("int value2: ");
                scanf("%i", &value2);
                printf("double value3: ");
                scanf("%lf", &value3);

                printf("Enviando set_value...\n");

                result = set_value(key, value1, value2, value3);

                printf("\nRespuesta: {result: %i}\n", result);
                printf("Pulse ENTER para continuar...\n");
                scanf("%s", tmp);

                break;
                
            case 2:  // get
                printf("int key: ");
                scanf("%i", &key);

                printf("Enviando get...\n");

                result = get_value(key, value1, &value2, &value3);

                printf("\nRespuesta: {result: %i, value1: %s, value2: %i, value3: %f}\n", result, value1, value2, value3);
                printf("Pulse ENTER para continuar...\n");
                scanf("%s", tmp);

                break;

            case 3:  // modify
                printf("int key: ");
                scanf("%i", &key);
                printf("char value1[]: ");
                scanf("%s", value1);
                printf("int value2: ");
                scanf("%i", &value2);
                printf("double value3: ");
                scanf("%lf", &value3);

                printf("Enviando modify_value...\n");

                result = modify_value(key, value1, value2, value3);

                printf("\nRespuesta: {result: %i}\n", result);
                printf("Pulse ENTER para continuar...\n");
                scanf("%s", tmp);

                break;
            
            case 4:  // exist
                printf("int key: ");
                scanf("%i", &key);

                printf("Enviando exist...\n");

                result = exist(key);

                printf("\nRespuesta: {result: %i}\n", result);
                printf("Pulse ENTER para continuar...\n");
                scanf("%s", tmp);

                break;

            case 5:  // copyKey
                printf("int key1: ");
                scanf("%i", &key1);
                printf("int key2: ");
                scanf("%i", &key2);

                printf("Enviando copy_key...\n");

                result = copy_key(key1,key2);

                printf("\nRespuesta: {result: %i}\n", result);
                printf("Pulse ENTER para continuar...\n");
                scanf("%s", tmp);

                break;

            case 6: //deleteKey
                printf("int key: ");
                scanf("%i", &key);

                printf("Enviando delete_key...\n");

                result = delete_key(key);

                printf("\nRespuesta: {result: %i}\n", result);

                printf("Pulse ENTER para continuar...\n");
                break;

            default:
                printf("opcode no válido\n");

                break;
        }

        // sleep(1);
    }
}


int main() {
    #ifdef DEBUG_MODE
        debug_run();
    #else
        return std_run();
    #endif
}