all: install clean

install:
	@cp src/main.c src/checkerrors.c src/direction.c src/functions.c src/go.c src/tofile.c src/toint.c src/tostr.c inc/header.h .
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o race04 main.c checkerrors.c direction.c functions.c go.c tofile.c toint.c tostr.c

uninstall: clean
	@rm -rf race04

clean:
	@rm -rf main.c checkerrors.c direction.c functions.c go.c tofile.c toint.c tostr.c header.h path.txt

reinstall: uninstall all