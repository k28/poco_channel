#
# 再帰的にsrcフォルダを掘ってMakeするMakefile
#

CXX		= g++
CFLAGS	= -ggdb3 -Wall -Werror
INCS	= 
LIBS	= -lPocoFoundation
TARGET	= channel_sample

SRCROOT	= src
OBJROOT	= obj
ifeq "$(strip $(OBJROOT))" ""
	OBJROOT=.
endif

# SECROOTから再帰的にソースファイルを検索する
SRCDIRS = $(shell find $(SRCROOT) -type d)
SOURCES	= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cc))
# SRCROOTを各SOURCESから削除する
OBJSRCS = $(SOURCES:$(SRCROOT)/%=%)
OBJECTS	= $(addprefix $(OBJROOT)/, $(OBJSRCS:.cc=.o))

DEPENDS	= $(OBJECTS:.o=.d)

# for debug
#$(warning SOURCES = $(SOURCES))
#$(warning OBJECTS = $(OBJECTS))

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

$(OBJROOT)/%.o : $(SRCROOT)/%.cc
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CXX) $(CFLAGS) $(INCS) -o $@ -c $<

all: clean $(TARGET)

run :
	./$(TARGET)

clean:
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGET)

-include $(DEPENDS)

