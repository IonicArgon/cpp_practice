# compiler goes here
CC = g++

# compiler flags
CFLAGS = -std=c++20 -Iinclude

# source file locations
CHAPT1SRC = ./src/1-basics/
CHAPT2SRC = ./src/2-funcs_and_files/
CHAPT5SRC = ./src/5-operators/
CHAPTOSRC = ./src/O-bit_manipulation/
CHAPT6SRC = ./src/6-object_scope/

.PHONY : clean all chapter1 chapter2 chapter5 chapterO chapter6

all : chapter1 chapter2 chapter5 chapterO chapter6

chapter1 : ./bin/var-init
chapter2 : ./bin/fwrd-declr ./bin/fwrd-declr-2 ./bin/headers
chapter5 : ./bin/float-comp
chapterO : ./bin/bitset ./bin/bitop ./bin/bitmasks
chapter6 : ./bin/namespaces ./bin/global-vari ./bin/typedefs ./bin/auto

# chapter 1
./bin/var-init : ${CHAPT1SRC}variable-initialization.cpp
	@${CC} ${CFLAGS} ${CHAPT1SRC}variable-initialization.cpp \
	-o $@
	@echo "Built: $@"


# chapter 2
./bin/fwrd-declr : ${CHAPT2SRC}forward-declarations.cpp
	@${CC} ${CFLAGS} ${CHAPT2SRC}forward-declarations.cpp \
	-o $@
	@echo "Built: $@"

./bin/fwrd-declr-2 : ${CHAPT2SRC}fwrd-declr-2/fwrd-declr-2.cpp \
					 ${CHAPT2SRC}fwrd-declr-2/subtract.cpp
	@${CC} ${CFLAGS} ${CHAPT2SRC}fwrd-declr-2/fwrd-declr-2.cpp \
					 ${CHAPT2SRC}fwrd-declr-2/subtract.cpp \
	-o $@
	@echo "Built: $@"

./bin/headers : ${CHAPT2SRC}header-files/header-files.cpp \
				${CHAPT2SRC}header-files/multiply.cpp
	@${CC} ${CFLAGS} ${CHAPT2SRC}header-files/header-files.cpp \
					 ${CHAPT2SRC}header-files/multiply.cpp \
	-o $@
	@echo "Built: $@"


# chapter 5
./bin/float-comp : ${CHAPT5SRC}floatpoint-comparisons.cpp
	@${CC} ${CFLAGS} ${CHAPT5SRC}floatpoint-comparisons.cpp \
	-o $@
	@echo "Built: $@"


# chapter O
./bin/bitset : ${CHAPTOSRC}bitset-manip.cpp
	@${CC} ${CFLAGS} ${CHAPTOSRC}bitset-manip.cpp \
	-o $@
	@echo "Built: $@"

./bin/bitop : ${CHAPTOSRC}bitop.cpp
	@${CC} ${CFLAGS} ${CHAPTOSRC}bitop.cpp \
	-o $@
	@echo "Built: $@"

./bin/bitmasks : ${CHAPTOSRC}bitmasks.cpp
	@${CC} ${CFLAGS} ${CHAPTOSRC}bitmasks.cpp \
	-o $@
	@echo "Built: $@"


# chapter 6
./bin/namespaces : ${CHAPT6SRC}namespaces/namespaces.cpp \
				   ${CHAPT6SRC}namespaces/simple-math.cpp \
				   ${CHAPT6SRC}namespaces/complex-math.cpp
	@${CC} ${CFLAGS} ${CHAPT6SRC}namespaces/namespaces.cpp \
				   	 ${CHAPT6SRC}namespaces/simple-math.cpp \
				     ${CHAPT6SRC}namespaces/complex-math.cpp \
	-o $@
	@echo "Built: $@"

./bin/global-vari : ${CHAPT6SRC}global-variables/global-vari.cpp \
					${CHAPT6SRC}global-variables/constants.cpp
	@${CC} ${CFLAGS} ${CHAPT6SRC}global-variables/global-vari.cpp \
					 ${CHAPT6SRC}global-variables/constants.cpp \
	-o $@
	@echo "Built: $@"

./bin/typedefs : ${CHAPT6SRC}typedefs-alias.cpp
	@${CC} ${CFLAGS} ${CHAPT6SRC}typedefs-alias.cpp \
	-o $@
	@echo "Built: $@"

./bin/auto : ${CHAPT6SRC}auto-keyword.cpp
	@${CC} ${CFLAGS} ${CHAPT6SRC}auto-keyword.cpp \
	-o $@
	@echo "Built: $@"


# clean
clean :
	@rm -f ./bin/*.exe
	@echo "Cleanup complete."