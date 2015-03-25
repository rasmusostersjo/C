# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -std=c99

# Src files
SRC = memChr.c  memCmp.c  memCpy.c   memMove.c memSet.c  stpCpy.c strCat.c \
	  strChr.c  strCmp.c  strCpy.c   strcSpn.c strDup.c  strFry.c strLen.c \
	  strnCat.c strnCmp.c strnCpy.c  strpBrk.c strrChr.c strSep.c strSpn.c \
	  strStr.c  strTok.c  strTok_r.c

# Source object files
OBJS = $(SRC:.c=.o)

# Library header file
HEADER = String.h

# Library name
LIB_NAME = libString.a

# Build library
$(LIB_NAME): $(OBJS) $(HEADER)
	ar rsv $@ $(OBJS)

# Compile objects
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

# Clean up options
.PHONY:
clean:
	rm -rf *.o *.exe
cleanAll:
	rm -rf *.o *.exe $(LIB_NAME) test
