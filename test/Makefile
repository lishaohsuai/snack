LOCAL_LIBRARY +=  -L./lib -lcurses -std=c++11 -g
LOCAL_LDFLAGS +=  -lpthread -ldl
LOCAL_CFLAGS += -I./include

CC=gcc

TARGETS1 = test_one
SRCS1 = ./test1/test.c
OBJS1 = $(patsubst %.c, %.o, $(SRCS1))




CFLAGS += $(LOCAL_CFLAGS)
LDFLAGS += $(LOCAL_LIBRARY) $(LOCAL_LDFLAGS)

$(info $(TARGETS))

all: $(TARGETS1) $(TARGETS2)


$(TARGETS1):$(OBJS1)
	$(CC)  -o $@ $^  $(LDFLAGS) $(CFLAGS)

$(OBJS1): %.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	#mv  $(TARGETS1) $(OBJS1)  $(OBJS2)

#.SUFFIXES:
.PHONY : all clean
