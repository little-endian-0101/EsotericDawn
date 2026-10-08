CC := clang

CFLAGS := -Icore/include \
		  -std=c23 \
		  -DLATHE_ARENA_POISON \
		  -Wall \
		  -Wextra \
		  -Wpedantic \
		  -Wconversion \
		  -Werror \
		  -DLATHE_DEBUG_ENABLED

SRC :=	test.c \
		core/source/math/lathe_mat3.c \
		core/source/math/lathe_vec3.c \
		core/source/memory/lathe_memory.c \
		core/source/system/lathe_logger.c 

LIBS :=

#https://stackoverflow.com/a/12099167
UNAME_S :=
ifeq ($(OS),Windows_NT)
	CFLAGS += -D LATHE_WINDOWS
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
        CFLAGS += -D LATHE_LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        CFLAGS += -D LATHE_OSX
        SRC += 	core/source/system/lathe_controller.m \
			core/source/platform/platform_mac.m  \
			core/source/render/mac_opengl_renderer.m
		LIBS += -framework GameController -framework Foundation -framework Cocoa -lobjc -framework OpenGL -framework QuartzCore
    endif
endif

#probably should handle if none of the above, but I just want to release on Mac,Windows, and Linux rn

TARGET := build/test
OBJ :=	$(SRC:.c=.o)
OBJ := $(OBJ:.m=.o)
# Specify the frameworks to link



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
