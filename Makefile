# compiler goes here
CC = g++

# compiler flags
CFLAGS = -Wall

# source file locations
CHAPT1SRC = src/1-basics/
CHAPT2SRC = src/2-funcs_and_files/
CHAPT5SRC = src/5-operators/
CHAPTOSRC = src/O-bit_manipulation/

# bin locations
CHAPT1BIN = bin/1-basics/
CHAPT2BIN = bin/2-funcs_and_files/
CHAPT5BIN = bin/5-operators/
CHAPTOBIN = bin/O-bit_manipulation/


all: chapter1 chapter2 chapter5 chapterO

chapter1 : vari-init
chapter2 : fwrd-declr fwrd-declr-2 header-files
chapter5 : float-comp
chapterO : flag-manip bitops bitmasks


# chapter one
vari-init : ${CHAPT1SRC}variable-initialization.cpp
	${CC} ${CFLAGS} ${CHAPT1SRC}variable-initialization.cpp \
	-o ${CHAPT1BIN}vari-init


# chapter 2
fwrd-declr : ${CHAPT2SRC}forward-declarations.cpp
	${CC} ${CFLAGS} ${CHAPT2SRC}forward-declarations.cpp \
	-o ${CHAPT2BIN}fwrd-declr

fwrd-declr-2 : ${CHAPT2SRC}fwrd-declr-2/fwrd-declr-2.cpp \
				${CHAPT2SRC}fwrd-declr-2/subtract.cpp
	${CC} ${CFLAGS} ${CHAPT2SRC}fwrd-declr-2/fwrd-declr-2.cpp \
	${CHAPT2SRC}fwrd-declr-2/subtract.cpp \
	-o ${CHAPT2BIN}fwrd-declr-2

header-files : ${CHAPT2SRC}header-files/header-files.cpp \
				${CHAPT2SRC}header-files/multiply.cpp
	${CC} ${CFLAGS} ${CHAPT2SRC}header-files/header-files.cpp \
	${CHAPT2SRC}header-files/multiply.cpp -Iinclude \
	-o ${CHAPT2BIN}header-files


# chapter 5
float-comp : ${CHAPT5SRC}floatpoint-comparisons.cpp
	${CC} ${CFLAGS} ${CHAPT5SRC}floatpoint-comparisons.cpp \
	-o ${CHAPT5BIN}float-comp


# chapter O
flag-manip : ${CHAPTOSRC}bitset-manip.cpp
	${CC} ${CFLAGS} ${CHAPTOSRC}bitset-manip.cpp \
	-o ${CHAPTOBIN}flag-manip

bitops : ${CHAPTOSRC}bitop.cpp
	${CC} ${CFLAGS} ${CHAPTOSRC}bitop.cpp \
	-o ${CHAPTOBIN}bitops

bitmasks : ${CHAPTOSRC}bitmasks.cpp
	${CC} ${CFLAGS} ${CHAPTOSRC}bitmasks.cpp \
	-o ${CHAPTOBIN}bitmasks


# misc recipes
.PHONY : clean
clean:
	rm -r ${CHAPT1BIN}${chapter1}
	rm -r ${CHAPT2BIN}${chapter2}
	rm -r ${CHAPT5BIN}${chapter5}
	mkdir ${CHAPT1BIN}
	mkdir ${CHAPT2BIN}
	mkdir ${CHAPT5BIN}
	@echo "Cleanup complete."


