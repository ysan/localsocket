#
#   Defines
#
BASEDIR		:=	../../

CFLAGS		:=	-std=c++11

INCLUDES	:= \
	-I./ \
	-I$(BASEDIR)/immsocketcommon \
	-I$(BASEDIR)/immsocket \
	-I$(BASEDIR)/immsocketservice \

LIBS		:= \
	-L$(BASEDIR)/immsocketservice -limmsocketservice \
	-L$(BASEDIR)/immsocket -limmsocket \
	-L$(BASEDIR)/immsocketcommon -limmsocketcommon \
	-lpthread \

LDFLAGS		:= \
#	-Wl,-rpath=`pwd`/$(BASEDIR)/immsocketcommon \
#	-Wl,-rpath=`pwd`/$(BASEDIR)/immsocket \
#	-Wl,-rpath=`pwd`/$(BASEDIR)/immsocketservice \

APPEND_OBJS	:=

USERDEFS	:=


#
#   Target object
#
TARGET_NAME	:=	server

#
#   Target type
#     (EXEC/SHARED/STATIC/OBJECT)
#
TARGET_TYPE	:=	EXEC

#
#   Compile sources
#
SRCS		:=

SRCS_CPP	:= \
	main.cpp \

#
#   Configurations
#
include $(BASEDIR)/Config.mak

