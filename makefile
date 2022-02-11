libs = -lstdc++ -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
prms = -O0 -Wall -Wextra -g -m64
SUBDIR = entities managers physics
SRCS = $(wildcard src/*.cpp $(foreach fd, $(SUBDIR), src/$(fd)/*.cpp))
INCS = ./include/ $(foreach fd, $(SUBDIR), ./include/$(fd)/)

CC = clang++

all: compile run

compile:
	@${CC} ${SRCS} -I./include/ ${prms} ${libs} -o ./bin/debug/main.exe

run:
	@bin/debug/main.exe

echoes:
	@echo "Files: $(INCS)"