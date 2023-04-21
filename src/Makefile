BIN_FILES  = cliente servidor
TEST_FILES = testing
VPATH = lib rpc  # path with source files not found in current dir
CC = gcc

CFLAGS = -g -I$(INSTALL_PATH)/include -I/usr/include/tirpc -Wall -fPIC
LDFLAGS = -L$(INSTALL_PATH)/lib/ -Wl,-R$(DIR)/lib/linux '-Wl,-R$$ORIGIN'
LDLIBS =  -lnsl -lpthread -ldl -ltirpc -lm


all: $(BIN_FILES)
.PHONY : all

cliente: cliente.o libclaves.so
	$(CC) $(CFLAGS) $(LDFLAGS) -L$(INSTALL_PATH) -lclaves $^ $(LDLIBS) -o $@
	
servidor: tuplas_xdr.o servidor.o server_impl.o linked_list.o tuplas_svc.o log.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	
libclaves.so: claves.o tuplas_xdr.o tuplas_clnt.o
	$(CC) -shared $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

testing: testing.o libclaves.so
	$(CC) $(CFLAGS) $(LDFLAGS) -L$(INSTALL_PATH) -lclaves $^ $(LDLIBS) -o $@


%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<


test: $(TEST_FILES)
.SUFFIXES:
.PHONY : test


clean:
	rm -f $(BIN_FILES) $(TEST_FILES) *.o *.so

.SUFFIXES:
.PHONY : clean