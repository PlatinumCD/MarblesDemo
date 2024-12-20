AM_CPPFLAGS += \
	-I$(top_srcdir)/src \
	$(MPI_CPPFLAGS)

compdir = $(pkglibdir)
comp_LTLIBRARIES = libMarblesDemo.la
libMarblesDemo_la_SOURCES = \
	marbles_demo.cc \
	marbles.h \
	marbles_bag.h

libMarblesDemo_la_LDFLAGS = -module -avoid-version

install-exec-hook:
	$(SST_REGISTER_TOOL) SST_ELEMENT_SOURCE     MarblesDemo=$(abs_srcdir)
