/*
Server implementation, using sample code generated by rpcgen
*/

#include <stdbool.h>

#include "tuplas.h"
#include "../log.h"
#include "../lib/server_impl.h"



bool_t tuplas_init_1_svc(int* result, struct svc_req* rqstp) {
	bool_t retval = true;

	Log("Client %i: Received {opcode: 0 (init)}\n", local_sd);

	*result = init();

	return retval;
}


bool_t tuplas_set_value_1_svc(int key, char* value1, int value2, double value3, int* result, struct svc_req* rqstp) {
	bool_t retval = true;

	Log("Received {opcode: 1 (set), key: %i, value1: %s, value2: %i, value3: %f}\n", key, value1, value2, value3);

	*result = set(key, value1, value2, value3);

	return retval;
}


bool_t tuplas_get_value_1_svc(int key, struct Respuesta* result, struct svc_req* rqstp) {
	bool_t retval = true;

	Log("Received {opcode: 2 (get), key: %i}\n", key);
	
	result->value1 = malloc(MAX_VALUE1 * sizeof(char));

	result->result = get(key, result->value1, &(result->value2), &(result->value3));

	return retval;
}


bool_t tuplas_modify_value_1_svc(int key, char* value1, int value2, double value3, int* result,struct svc_req* rqstp) {
	bool_t retval = true;

	Log("Received {opcode: 3 (modify), key: %i, value1: %s, value2: %i, value3: %f}\n", key, value1, value2, value3);

	*result = modify(key, value1, value2, value3);

	return retval;
}


bool_t tuplas_exist_1_svc(int key, int* result, struct svc_req* rqstp) {
	bool_t retval = true;

	Log("Received {opcode: 4 (exist), key: %i}\n", key);

	*result = exist(key);

	return retval;
}


bool_t tuplas_copy_key_1_svc(int key1, int key2, int* result, struct svc_req* rqstp) {
	bool_t retval = true;

	Log("Client %i: Received {opcode: 5 (copy_key), key1: %i, key2: %i}\n", key1, key2);
	
	*result = copy_key(key1, key2);

	return retval;
}


bool_t tuplas_delete_key_1_svc(int key, int* result, struct svc_req* rqstp) {
	bool_t retval = true;

	Log("Received {opcode: 6 (delete_key), key: %i}\n", key);

	*result = delete_key(key);

	return retval;
}


int tuplasprog_1_freeresult(SVCXPRT* transp, xdrproc_t xdr_result, caddr_t result) {
	xdr_free (xdr_result, result);

	// Insert additional freeing code here, if needed

	return 1;
}
