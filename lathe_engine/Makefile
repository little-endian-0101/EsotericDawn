CC := clang

CFLAGS := -Icore/include \
		  -std=c23 \
		  -DLATHE_ARENA_POISON \

SRC :=	test.c \
		core/source/math/lathe_mat3.c \
		core/source/math/lathe_vec3.c \
		core/source/memory/lathe_memory.c \
		core/source/system/lathe_logger.c \
		core/source/system/lathe_controller.m

#https://stackoverflow.com/a/12099167
# UNAME_S :=
# ifeq ($(OS),Windows_NT)
# 	CFLAGS += -D LATHE_WINDOWS
# else
# 	UNAME_S := $(shell uname -s)
# 	ifeq ($(UNAME_S),Linux)
#         CFLAGS += -D LATHE_LINUX
#     endif
#     ifeq ($(UNAME_S),Darwin)
#         CFLAGS += -D LATHE_OSX -framework AppKit
#         SRC += core/source/platform_mac.m
#     endif
# endif
#fix appkit later,just want it to work
#probably should handle if none of the above, but I just want to release on Mac,Windows, and Linux rn

TARGET := build/test
OBJ :=	$(SRC:.c=.o)
OBJ := $(OBJ:.m=.o)
# Specify the frameworks to link
LIBS = -framework GameController -framework Foundation -lobjc


all : $(TARGET)

$(TARGET):	$(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.m
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
