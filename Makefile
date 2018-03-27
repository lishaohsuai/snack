LOCAL_LIBRARY +=  -L./lib -lcurses -std=c++11
LOCAL_LDFLAGS +=  -lpthread -ldl
LOCAL_CFLAGS += -I./include -g

CC=g++

TARGETS1 = Even_Snack
SRCS1 = ./src/main.cc ./src/jsoncpp.cc ./src/windows/windows.cc ./src/snack/snack.cc
OBJS1 = $(patsubst %.cc, %.o, $(SRCS1))

TARGETS2 = ./test/



CFLAGS += $(LOCAL_CFLAGS)
LDFLAGS += $(LOCAL_LIBRARY) $(LOCAL_LDFLAGS)

$(info $(TARGETS))

all: $(TARGETS1) $(TARGETS2)


$(TARGETS1):$(OBJS1)
	$(CC)  -o $@ $^  $(LDFLAGS) $(CFLAGS)

$(OBJS1): %.o:%.cc
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	rm  $(TARGETS1) $(OBJS1)

#.SUFFIXES:
.PHONY : all clean
