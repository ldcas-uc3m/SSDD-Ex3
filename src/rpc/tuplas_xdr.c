/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "tuplas.h"

bool_t
xdr_Respuesta (XDR *xdrs, Respuesta *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->result))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->value1, MAX_VALUE1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->value2))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->value3))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_tuplas_set_value_1_argument (XDR *xdrs, tuplas_set_value_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->value1, MAX_VALUE1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->value2))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->value3))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_tuplas_modify_value_1_argument (XDR *xdrs, tuplas_modify_value_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->value1, MAX_VALUE1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->value2))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->value3))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_tuplas_copy_key_1_argument (XDR *xdrs, tuplas_copy_key_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->key1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->key2))
		 return FALSE;
	return TRUE;
}
