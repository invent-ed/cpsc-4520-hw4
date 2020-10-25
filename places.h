/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PLACES_H_RPCGEN
#define _PLACES_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct location {
	char *city;
	char *state;
	double latitude;
	double longitude;
};
typedef struct location location;

struct clientArg {
	char *city;
	char *state;
};
typedef struct clientArg clientArg;

struct airportInfo {
	char *code;
	char *name;
	double latitude;
	double longitude;
	double distance;
};
typedef struct airportInfo airportInfo;

struct placesLLNode {
	struct airportInfo *airport;
	struct placesLLNode *next;
};
typedef struct placesLLNode placesLLNode;

struct placesResults {
	struct location location;
	struct placesLLNode *airports;
};
typedef struct placesResults placesResults;

struct placesRet {
	int err;
	union {
		placesResults results;
	} placesRet_u;
};
typedef struct placesRet placesRet;

#define PLACES_PROG 0x34865249
#define PLACES_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define AIRPORTS_NEAR_CITY 1
extern  placesRet * airports_near_city_1(clientArg *, CLIENT *);
extern  placesRet * airports_near_city_1_svc(clientArg *, struct svc_req *);
extern int places_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define AIRPORTS_NEAR_CITY 1
extern  placesRet * airports_near_city_1();
extern  placesRet * airports_near_city_1_svc();
extern int places_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_location (XDR *, location*);
extern  bool_t xdr_clientArg (XDR *, clientArg*);
extern  bool_t xdr_airportInfo (XDR *, airportInfo*);
extern  bool_t xdr_placesLLNode (XDR *, placesLLNode*);
extern  bool_t xdr_placesResults (XDR *, placesResults*);
extern  bool_t xdr_placesRet (XDR *, placesRet*);

#else /* K&R C */
extern bool_t xdr_location ();
extern bool_t xdr_clientArg ();
extern bool_t xdr_airportInfo ();
extern bool_t xdr_placesLLNode ();
extern bool_t xdr_placesResults ();
extern bool_t xdr_placesRet ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PLACES_H_RPCGEN */
