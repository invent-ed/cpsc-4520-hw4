/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "airports.h"

bool_t
xdr_kdTree (XDR *xdrs, kdTree *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->root, sizeof (struct kdNode), (xdrproc_t) xdr_kdNode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_kdNode (XDR *xdrs, kdNode *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->pos, sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->dir))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->data, sizeof (struct airport), (xdrproc_t) xdr_airport))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->left, sizeof (kdNode), (xdrproc_t) xdr_kdNode))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->right, sizeof (kdNode), (xdrproc_t) xdr_kdNode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_airport (XDR *xdrs, airport *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->code, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->latitude))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->longitude))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->distance))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_placesArg (XDR *xdrs, placesArg *objp)
{
	register int32_t *buf;

	 if (!xdr_double (xdrs, &objp->latitude))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->longitude))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_airportsLLNode (XDR *xdrs, airportsLLNode *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->airport, sizeof (airport), (xdrproc_t) xdr_airport))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->next, sizeof (airportsLLNode), (xdrproc_t) xdr_airportsLLNode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_airportsRet (XDR *xdrs, airportsRet *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->err))
		 return FALSE;
	switch (objp->err) {
	case 0:
		 if (!xdr_pointer (xdrs, (char **)&objp->airportsRet_u.airports, sizeof (airportsLLNode), (xdrproc_t) xdr_airportsLLNode))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}
