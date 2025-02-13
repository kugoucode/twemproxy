MAINTAINERCLEANFILES = Makefile.in

AM_CPPFLAGS = -I $(top_srcdir)/src

AM_CFLAGS = -Wall -Wshadow
AM_CFLAGS += -Wno-unused-parameter -Wno-unused-value

noinst_LIBRARIES = libhashkit.a

noinst_HEADERS = nc_hashkit.h

# 添加测试程序
check_PROGRAMS = nc_fnv_test
TESTS = nc_fnv_test

# 修改测试程序配置，确保启用 C++11
nc_fnv_test_SOURCES = nc_fnv_test.cpp
nc_fnv_test_CXXFLAGS = -std=c++14  # 改用 C++14
nc_fnv_test_CPPFLAGS = $(AM_CPPFLAGS) `pkg-config --cflags gtest`
nc_fnv_test_LDFLAGS = `pkg-config --libs gtest`
nc_fnv_test_LDADD = libhashkit.a -lpthread

libhashkit_a_SOURCES =		\
	nc_crc16.c		\
	nc_crc32.c		\
	nc_fnv.c		\
	nc_hsieh.c		\
	nc_jenkins.c		\
	nc_ketama.c		\
	nc_md5.c		\
	nc_modula.c		\
	nc_murmur.c		\
	nc_one_at_a_time.c	\
	nc_random.c
