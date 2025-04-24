
SYSTEMC_TOOL     ?= $(HOME)/Tools/Accellera/SystemC/systemc
SYSTEMC_HOME     ?= $(SYSTEMC_TOOL)/2.3.3

TARGET_ARCH      ?= linux64
ifneq (,$(strip $(TARGET_ARCH)))
ARCH_SUFFIX      ?= -$(TARGET_ARCH)
endif
LDFLAG_RPATH     ?= -Wl,-rpath=

SYSTEMC_INC_DIR  ?= $(SYSTEMC_HOME)/include
SYSTEMC_LIB_DIR  ?= $(SYSTEMC_HOME)/lib$(ARCH_SUFFIX)

SYSTEMC_DEFINES  ?=
SYSTEMC_CXXFLAGS ?= $(FLAGS_COMMON) $(FLAGS_STRICT) $(FLAGS_WERROR)
SYSTEMC_LDFLAGS  ?= -L$(SYSTEMC_LIB_DIR) \
                    $(LDFLAG_RPATH)$(SYSTEMC_LIB_DIR)
SYSTEMC_LIBS     ?= -lsystemc -lm

INCDIR   += -I. -I$(SYSTEMC_INC_DIR)
LIBDIR   += -L. 

CXXFLAGS += $(CFLAGS) $(SYSTEMC_CXXFLAGS) $(INCDIR) $(SYSTEMC_DEFINES)
LDFLAGS  += $(CFLAGS) $(SYSTEMC_CXXFLAGS) $(LIBDIR) $(SYSTEMC_LDFLAGS)
LIBS     += $(SYSTEMC_LIBS) $(EXTRA_LIBS)

# basic check for SystemC directory
ifeq (,$(wildcard $(SYSTEMC_HOME)/.))
$(error SYSTEMC_HOME [$(SYSTEMC_HOME)] is not present. \
        Please update Makefile.config)
endif
ifeq (,$(wildcard $(SYSTEMC_INC_DIR)/systemc.h))
$(error systemc.h [$(SYSTEMC_INC_DIR)] not found. \
        Please update Makefile.config)
endif
ifeq (,$(wildcard $(SYSTEMC_LIB_DIR)/libsystemc*))
$(error SystemC library [$(SYSTEMC_LIB_DIR)] not found. \
        Please update Makefile.config)
endif

## ***************************************************************************
## build rules

all: clean simple

simple: simple.cpp
	g++ $(CXXFLAGS) $(LDFLAGS) $(LIBS) -o $@ $<

clean:
	rm -f simple
