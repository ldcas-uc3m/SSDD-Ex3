/*
Implementación de las operaciones del cliente
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "claves.h"
#include "../rpc/tuplas.h"


#define INIT 0
#define SET_VALUE 1
#define GET_VALUE 2
#define MODIFY_VALUE 3
#define EXIST 4
#define COPY_KEY 5
#define DELETE_KEY 6


int init(void) {
    CLIENT *clnt;
    enum clnt_stat retval_1;
    int result_1;
    char *host = getenv("IP_TUPLAS");
    clnt = clnt_create (host, TUPLASPROG, TUPLASPROGVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
        printf("Error when setting up the client\n");
        return -1;
	}
    retval_1 = tuplas_init_1(&result_1, clnt);
	if (retval_1 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
        printf("Error when calling tuplas init\n");
        clnt_destroy (clnt);
        return -1;
	}else if(result_1){
        printf("Error performing init\n");
        return -1;
    }
    clnt_destroy (clnt);
    return 0;
}


int set_value(int key, char* value1, int value2, double value3) {
    CLIENT *clnt;
    enum clnt_stat retval_2;
    int result_2;
    char *host = getenv("IP_TUPLAS");
    clnt = clnt_create (host, TUPLASPROG, TUPLASPROGVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
        printf("Error when setting up the client\n");
        return -1;
	}
    retval_2 = tuplas_set_value_1(key, value1, value2, value3, &result_2, clnt);
	if (retval_2 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
        printf("Error when calling tuplas set_value\n");
        clnt_destroy (clnt);
        return -1;
	} else if (result_2 ==-1){
        printf("Error in set_value\n");
        clnt_destroy (clnt);
        return -1;
    }
    clnt_destroy (clnt);
    return 0;
}


int get_value(int key, char* value1, int* value2, double* value3) {
    CLIENT *clnt;
    enum clnt_stat retval_3;
    struct Respuesta result_3;
    char *host = getenv("IP_TUPLAS");
    clnt = clnt_create (host, TUPLASPROG, TUPLASPROGVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
        printf("Error when setting up the client\n");
        return -1;
	}
    retval_3 = tuplas_get_value_1(key, &result_3, clnt);
	if (retval_3 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
        printf("Error when calling tuplas get_value\n");
        clnt_destroy (clnt);
        return -1;
	} else if (result_3.result ==-1){
        printf("Error in get_value\n");
        clnt_destroy (clnt);
        return -1;
    }else{
        strcpy(value1,result_3.value1);
        *value2 = result_3.value2;
        *value3 = result_3.value3;
        clnt_destroy (clnt);
        return 0;
    }
}


int modify_value(int key, char* value1, int value2, double value3) {
    CLIENT *clnt;
    enum clnt_stat retval_4;
    int result_4;
    char *host = getenv("IP_TUPLAS");
    clnt = clnt_create (host, TUPLASPROG, TUPLASPROGVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
        printf("Error when setting up the client\n");
        return -1;
	}
    retval_4 = tuplas_modify_value_1(key, value1, value2, value3, &result_4, clnt);
	if (retval_4 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
        printf("Error when calling tuplas modify_value\n");
        clnt_destroy (clnt);
        return -1;
	} else if (result_4==-1){
        printf("Error in modify_key\n");
        clnt_destroy (clnt);
        return -1;
    }else{
        clnt_destroy (clnt);
        return 0;
    }
}


int exist(int key) {
    CLIENT *clnt;
    enum clnt_stat retval_5;
    int result_5;
    char *host = getenv("IP_TUPLAS");
    clnt = clnt_create (host, TUPLASPROG, TUPLASPROGVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
        printf("Error when setting up the client\n");
        return -1;
	}
    retval_5 = tuplas_exist_1(key, &result_5, clnt);
	if (retval_5 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
        printf("Error when calling tuplas exist\n");
        clnt_destroy (clnt);
        return -1;
	}else if (result_5==-1){
        printf("Error in exist\n");
        clnt_destroy (clnt);
        return -1;
    }else{
        clnt_destroy (clnt);
        return result_5;
    }
}


int copy_key(int key1, int key2) {
    CLIENT *clnt;
    enum clnt_stat retval_6;
    int result_6;
    char *host = getenv("IP_TUPLAS");
    clnt = clnt_create (host, TUPLASPROG, TUPLASPROGVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
        printf("Error when setting up the client\n");
        return -1;
	}
    retval_6 = tuplas_copy_key_1(key1, key2, &result_6, clnt);
	if (retval_6 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
        printf("Error when calling tuplas copy_key\n");
        clnt_destroy (clnt);
        return -1;
	}else if(result_6==-1){
        printf("Error in copy_key\n");
        clnt_destroy (clnt);
        return -1;
    }else{
        clnt_destroy (clnt);
        return 0;
    }
}


int delete_key(int key){
    CLIENT *clnt;
    enum clnt_stat retval_7;
    int result_7;
    char *host = getenv("IP_TUPLAS");
    clnt = clnt_create (host, TUPLASPROG, TUPLASPROGVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
        printf("Error when setting up the client\n");
        return -1;
	}
    retval_7 = tuplas_delete_key_1(key, &result_7, clnt);
	if (retval_7 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
        printf("Error when calling tuplas delete_key\n");
        clnt_destroy (clnt);
        return -1;
	}else if(result_7==-1){
        printf("Error in delete_key\n");
        clnt_destroy (clnt);
        return -1;
    }else{
        clnt_destroy (clnt);
        return 0;
    }
}