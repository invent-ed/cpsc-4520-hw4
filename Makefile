# Parameters

CLIENT = client
PLACES = places
AIRPORTS = airports


# Places server parameters

PLACES_SOURCES_CLNT.c = 
PLACES_SOURCES_CLNT.h = 
PLACES_SOURCES_SVC.c = 
PLACES_SOURCES_SVC.h = 

PLACES_TARGETS_CLNT.c = places_clnt.c places_client.c places_xdr.c 
PLACES_TARGETS_SVC.c = places_svc.c places_server.c places_xdr.c 

PLACES_OBJECTS_CLNT = $(PLACES_SOURCES_CLNT.c:%.c=%.o) $(PLACES_TARGETS_CLNT.c:%.c=%.o)
PLACES_OBJECTS_SVC = $(PLACES_SOURCES_SVC.c:%.c=%.o) $(PLACES_TARGETS_SVC.c:%.c=%.o)


# Airports server parameters

AIRPORTS_SOURCES_CLNT.c = 
AIRPORTS_SOURCES_CLNT.h = 
AIRPORTS_SOURCES_SVC.c = 
AIRPORTS_SOURCES_SVC.h = 

AIRPORTS_TARGETS_CLNT.c = airports_clnt.c airports_client.c airports_xdr.c 
AIRPORTS_TARGETS_SVC.c = airports_svc.c airports_server.c airports_xdr.c 

AIRPORTS_OBJECTS_CLNT = $(AIRPORTS_SOURCES_CLNT.c:%.c=%.o) $(AIRPORTS_TARGETS_CLNT.c:%.c=%.o)
AIRPORTS_OBJECTS_SVC = $(AIRPORTS_SOURCES_SVC.c:%.c=%.o) $(AIRPORTS_TARGETS_SVC.c:%.c=%.o)


# Compiler flags

CFLAGS += -g -I /usr/include/tirpc
LDLIBS += -ltirpc
RPCGENFLAGS = 


# Targets

all : $(CLIENT) $(PLACES) $(AIRPORTS)

$(PLACES_OBJECTS_CLNT) : $(PLACES_SOURCES_CLNT.c) $(PLACES_SOURCES_CLNT.h) $(PLACES_TARGETS_CLNT.c) 
$(PLACES_OBJECTS_SVC) : $(PLACES_SOURCES_SVC.c) $(PLACES_SOURCES_SVC.h) $(PLACES_TARGETS_SVC.c)

$(AIRPORTS_OBJECTS_CLNT) : $(AIRPORTS_SOURCES_CLNT.c) $(AIRPORTS_SOURCES_CLNT.h) $(AIRPORTS_TARGETS_CLNT.c) 
$(AIRPORTS_OBJECTS_SVC) : $(AIRPORTS_SOURCES_SVC.c) $(AIRPORTS_SOURCES_SVC.h) $(AIRPORTS_TARGETS_SVC.c)

CLIENT_OBJECTS = $(PLACES_OBJECTS_CLNT)
PLACES_OBJECTS = $(PLACES_OBJECTS_SVC) $(AIRPORTS_OBJECTS_CLNT)
AIRPORTS_OBJECTS = $(AIRPORTS_OBJECTS_SVC)

$(CLIENT) : $(CLIENT_OBJECTS) 
	$(LINK.c) -o $(CLIENT) $(CLIENT_OBJECTS) $(LDLIBS) 

$(PLACES) : $(PLACES_OBJECTS)
	$(LINK.c) -o $(PLACES) $(PLACES_OBJECTS) $(LDLIBS) 

$(AIRPORTS) : $(AIRPORTS_OBJECTS)
	$(LINK.c) -o $(AIRPORTS) $(AIRPORTS_OBJECTS) $(LDLIBS) 

clean:
	$(RM) core $(CLIENT_OBJECTS) $(PLACES_OBJECTS) $(AIRPORTS_OBJECTS) $(CLIENT) $(PLACES) $(AIRPORTS)
