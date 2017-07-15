EXTRA_DIST = README.md
include_HEADERS =
lib_LIBRARIES =
TESTS =
check_PROGRAMS =

include_HEADERS += src/acur.h
lib_LIBRARIES += libacur.a
libacur_a_SOURCES = \
	src/acur.h \
	src/acur.c

TESTS += tests/init
check_PROGRAMS += tests/init
tests_init_SOURCES = src/tests/init.c
tests_init_LDADD = libacur.a

TESTS += tests/iter
check_PROGRAMS += tests/iter
tests_iter_SOURCES = src/tests/iter.c
tests_iter_LDADD = libacur.a
