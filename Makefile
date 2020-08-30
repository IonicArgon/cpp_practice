# compiler goes here
CC = g++-10

# compiler flags
CFLAGS = -std=c++20 -Iinclude

# source file locations
CHAPT1SRC = ./src/1-basics/
CHAPT2SRC = ./src/2-funcs_and_files/
CHAPT5SRC = ./src/5-operators/
CHAPTOSRC = ./src/O-bit_manipulation/
CHAPT6SRC = ./src/6-object_scope/
CHAPTSSRC = ./src/S-compound_types/
CHAPTLSRC = ./src/L-control_flow/
CHAPTPSRC = ./src/P-pointers_memory/

.PHONY : clean all chapter1 chapter2 chapter5 chapterO chapter6 chapterS \
		 chapterL chapterP

all : chapter1 chapter2 chapter5 chapterO chapter6 chapterS \
	  chapterL chapterP

chapter1 : ./bin/var-init
chapter2 : ./bin/fwrd-declr ./bin/fwrd-declr-2 ./bin/headers
chapter5 : ./bin/float-comp
chapterO : ./bin/bitset ./bin/bitop ./bin/bitmasks
chapter6 : ./bin/namespaces ./bin/global-vari ./bin/typedefs ./bin/auto
chapterS : ./bin/enums ./bin/structs
chapterL : ./bin/tidbits
chapterP : ./bin/pointers ./bin/ptr-arr ./bin/dyn-malloc ./bin/reference \
		   ./bin/const_ref ./bin/mem_sel ./bin/tidbits2

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


# chapter S
./bin/enums : ${CHAPTSSRC}enums.cpp
	@${CC} ${CFLAGS} ${CHAPTSSRC}enums.cpp \
	-o $@
	@echo "Built: $@"

./bin/structs : ${CHAPTSSRC}structs.cpp
	@${CC} ${CFLAGS} ${CHAPTSSRC}structs.cpp \
	-o $@
	@echo "Built: $@"

# chapter L
./bin/tidbits : ${CHAPTLSRC}tidbits.cpp
	@${CC} ${CFLAGS} ${CHAPTLSRC}tidbits.cpp \
	-o $@
	@echo "Built: $@"


# chapter P
./bin/pointers : ${CHAPTPSRC}pointers.cpp
	@${CC} ${CFLAGS} ${CHAPTPSRC}pointers.cpp \
	-o $@
	@echo "Built: $@"

./bin/ptr-arr : ${CHAPTPSRC}ptr-arr.cpp
	@${CC} ${CFLAGS} ${CHAPTPSRC}ptr-arr.cpp \
	-o $@
	@echo "Built: $@"

./bin/dyn-malloc : ${CHAPTPSRC}dyn-malloc.cpp
	@${CC} ${CFLAGS} ${CHAPTPSRC}dyn-malloc.cpp \
	-o $@
	@echo "Built: $@"

./bin/reference : ${CHAPTPSRC}reference.cpp
	@${CC} ${CFLAGS} ${CHAPTPSRC}reference.cpp \
	-o $@
	@echo "Built: $@"

./bin/const_ref : ${CHAPTPSRC}const_ref.cpp
	@${CC} ${CFLAGS} ${CHAPTPSRC}const_ref.cpp \
	-o $@
	@echo "Built: $@"

./bin/mem_sel : ${CHAPTPSRC}mem_sel.cpp
	@${CC} ${CFLAGS} ${CHAPTPSRC}mem_sel.cpp \
	-o $@
	@echo "Built: $@"

./bin/tidbits2 : ${CHAPTPSRC}tidbits2.cpp
	@${CC} ${CFLAGS} ${CHAPTPSRC}tidbits2.cpp \
	-o $@
	@echo "Built: $@"

# clean 
clean :
	@rm -f ./bin/*
	@echo "Cleanup complete."