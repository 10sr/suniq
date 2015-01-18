AUTOMAKE_OPTIONS = subdir-objects

check_PROGRAMS = test_counter test_hash
EXTRA_DIST = $(check_PROGRAMS)
TESTS = $(check_PROGRAMS)
test_counter_SOURCES = test_counter.c \
	../src/counter.c ../src/counter.h \
	../src/hash.c ../src/hash.h
test_hash_SOURCES = test_hash.c ../src/hash.c ../src/hash.h
