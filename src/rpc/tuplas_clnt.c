/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "tuplas.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
tuplas_init_1(int *clnt_res, CLIENT *clnt)
{
	 return (clnt_call (clnt, tuplas_init, (xdrproc_t) xdr_void, (caddr_t) NULL,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));

}

enum clnt_stat 
tuplas_set_value_1(int key, char *value1, int value2, double value3, int *clnt_res,  CLIENT *clnt)
{
	tuplas_set_value_1_argument arg;
	arg.key = key;
	arg.value1 = value1;
	arg.value2 = value2;
	arg.value3 = value3;
	return (clnt_call (clnt, tuplas_set_value, (xdrproc_t) xdr_tuplas_set_value_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
tuplas_get_value_1(int key, struct Respuesta *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, tuplas_get_value,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_Respuesta, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
tuplas_modify_value_1(int key, char *value1, int value2, double value3, int *clnt_res,  CLIENT *clnt)
{
	tuplas_modify_value_1_argument arg;
	arg.key = key;
	arg.value1 = value1;
	arg.value2 = value2;
	arg.value3 = value3;
	return (clnt_call (clnt, tuplas_modify_value, (xdrproc_t) xdr_tuplas_modify_value_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
tuplas_exist_1(int key, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, tuplas_exist,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
tuplas_copy_key_1(int key1, int key2, int *clnt_res,  CLIENT *clnt)
{
	tuplas_copy_key_1_argument arg;
	arg.key1 = key1;
	arg.key2 = key2;
	return (clnt_call (clnt, tuplas_copy_key, (xdrproc_t) xdr_tuplas_copy_key_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
tuplas_delete_key_1(int key, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, tuplas_delete_key,
		(xdrproc_t) xdr_int, (caddr_t) &key,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}
