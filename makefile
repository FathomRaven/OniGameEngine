libsprms = -lstdc++ -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
prms = -O0 -Wall -Wextra -g -m64

SUBDIR = entities managers physics
SRCS = $(foreach fd, $(SUBDIR), src/$(fd)/*.cpp) src/*.cpp
INCS = -I./include/ $(foreach fd, $(SUBDIR), -I./include/$(fd)/)
OUTDIR = ./bin/debug/main.exe

CC = clang++

.PHONY all: compile run

compile:
	@${CC} ${SRCS} ${INCS} ${prms} ${libsprms} -o ${OUTDIR}

run:
	@${OUTDIR}