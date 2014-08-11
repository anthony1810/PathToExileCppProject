CXXFLAGS = -Wall -g -lcurl

APP = main
OBJS = Class.o

.PHONY: all
all: $(APP)

$(APP): $(OBJS)
Class.o: Class.h


.PHONY: clean
clean:
	$(RM) *.o *~ a.out core $(APP)
