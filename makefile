convert: convert.c convert_to_base.c convert_to_base.h
	gcc -o convert convert.c convert_to_base.c

ctest: convert.c convert_to_base.c convert_to_base.h
	gcc --coverage -o ctest convert.c convert_to_base.c
