ctest: convert.c convert_to_base.c convert_to_base.h
	gcc -o ctest --coverage convert.c convert_to_base.c
convert: convert.c convert_to_base.c convert_to_base.h
	gcc -o convert convert.c convert_to_base.c
