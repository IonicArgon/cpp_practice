# compiler goes here
CC = g++

# compiler flags
CFLAGS = -Wall -std=c++20

# source file locations
CHAPT1SRC = src/1-basics/
CHAPT2SRC = src/2-funcs_and_files/
CHAPT5SRC = src/5-operators/
CHAPTOSRC = src/O-bit_manipulation/
CHAPT6SRC = src/6-object_scope/

# bin locations
CHAPT1BIN = bin/1-basics/
CHAPT2BIN = bin/2-funcs_and_files/
CHAPT5BIN = bin/5-operators/
CHAPTOBIN = bin/O-bit_manipulation/
CHAPT6BIN = bin/6-object_scope/


all: chapter1 chapter2 chapter5 chapterO chapter6

chapter1 : vari-init
chapter2 : fwrd-declr fwrd-declr-2 header-files
chapter5 : float-comp
chapterO : flag-manip bitops bitmasks
chapter6 : namespaces global-constants typedefs


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


# chapter 6
namespaces : ${CHAPT6SRC}namespaces/namespaces.cpp \
			 ${CHAPT6SRC}namespaces/complex-math.cpp \
			 ${CHAPT6SRC}namespaces/simple-math.cpp
	${CC} ${CFLAGS} ${CHAPT6SRC}namespaces/namespaces.cpp \
					${CHAPT6SRC}namespaces/complex-math.cpp \
					${CHAPT6SRC}namespaces/simple-math.cpp \
	-Iinclude -o ${CHAPT6BIN}namespaces

global-constants: ${CHAPT6SRC}global-variables/global-vari.cpp \
				  ${CHAPT6SRC}global-variables/constants.cpp
	${CC} ${CFLAGS} ${CHAPT6SRC}global-variables/global-vari.cpp \
					${CHAPT6SRC}global-variables/constants.cpp \
	-Iinclude -o ${CHAPT6BIN}global-constants

typedefs : ${CHAPT6SRC}typedefs-alias.cpp
	${CC} ${CFLAGS} ${CHAPT6SRC}typedefs-alias.cpp \
	-o ${CHAPT6BIN}typedefs

# misc recipes
.PHONY : clean
clean:
	rm -f ${all} *.exe
	@echo "Cleanup complete."


