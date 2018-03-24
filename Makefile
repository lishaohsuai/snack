LOCAL_LIBRARY +=  -L./lib -lcurses -std=c++11
LOCAL_LDFLAGS +=  -lpthread -ldl
LOCAL_CFLAGS += -I./include

CC=g++

TARGETS1 = Even_Snack
SRCS1 = ./src/main.cc ./src/jsoncpp.cpp
OBJS1 = $(patsubst %.c, %.o, $(SRCS1))

TARGETS2 = ./test/



CFLAGS += $(LOCAL_CFLAGS)
LDFLAGS += $(LOCAL_LIBRARY) $(LOCAL_LDFLAGS)

$(info $(TARGETS))

all: $(TARGETS1) $(TARGETS2)


$(TARGETS1):$(OBJS1)
	$(CC)  -o $@ $^  $(LDFLAGS) $(CFLAGS)

$(OBJS1): %.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	@rm -rf $(TARGETS1) $(OBJS1) $(TARGETS2) $(OBJS2)

#.SUFFIXES:
.PHONY : all clean
