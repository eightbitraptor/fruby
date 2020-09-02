# This is the main source file list we're building
SRC    = main.c
# This tells Make that our object filenames should be the same as the src
# filenames but with .c replaced with .o
OBJ    = $(SRC:.c=.o)
# Our final binary will be called fruby (fake ruby)
EXE    = fruby

# Use Clang instead of GCC
CC        = clang
# Compile flags, -O0 is no optimisations, -ggdb3 is extra debug info including macro defs
CFLAGS    = -O0 -ggdb3
# Lots of warnings turned on, these are copied from the main Ruby Makefile
WARNFLAGS = -Wall -Wextra -Werror=deprecated-declarations -Werror=division-by-zero -Werror=implicit-function-declaration -Werror=implicit-int -Werror=pointer-arith -Werror=shorten-64-to-32 -Werror=write-strings -Wmissing-noreturn -Wno-constant-logical-operand -Wno-long-long -Wno-missing-field-initializers -Wno-overlength-strings -Wno-parentheses-equality -Wno-self-assign -Wno-tautological-compare -Wno-unused-parameter -Wno-unused-value -Wunused-variable -Werror=extra-tokens -std=gnu99
# -o, linking options, use the exe name configured above for the final binary
# and link with all the library directories configured at the top of the file
LDFLAGS   = -o $(EXE)
RM        = /bin/rm -f

# Compile and Assemble C Source Files into Object Files -c tells clang to only
# compile the files, don't link. This creates *.o files instead of a.out
# executables
%.o: %.c
	$(CC) $(CFLAGS) $(WARNFLAGS) -c $*.c

# Link all Object Files with external Libraries into Binaries, actual linking
# options are controlled by LDFLAGS
$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	$(RM) -r $(OBJ) $(OBJ).dSYM $(EXE)