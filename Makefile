# Compiler
CC = gcc

# Flags
CFLAGS = -I. -ICommand -ICommands -IDirOps -IFileOps -ISearchOps -ITextOps -IMathOps -ISysOps -IUI -IUtil

# Sources
SRCS = main.c \
       Command/command.c \
       Commands/basic.c \
       DirOps/dirops.c \
       FileOps/fileops.c \
       SearchOps/searchops.c \
       TextOps/textops.c \
       MathOps/mathops.c \
       SysOps/sysops.c \
       UI/ui.c \
       Util/util.c

# Output
OUT = terminal

# Build
all: $(OUT)

$(OUT): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(OUT).exe

# Clean
clean:
	rm -f $(OUT).exe
