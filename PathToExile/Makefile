CXXFLAGS =-lboost_regex -Wall -g -std=c++11 -lcurl

APP = main
OBJS = Class.o  Shortest.o DataPopulater.o Charater.o

.PHONY: all
all: $(APP)

$(APP): $(OBJS)
Class.o: Class.h
Shortest.o: Shortest.h
DataPopulater.o:    DataPopulater.h
Charater.o: Charater.h
.PHONY: clean
clean:
	$(RM) *.o *~ a.out core $(APP)
