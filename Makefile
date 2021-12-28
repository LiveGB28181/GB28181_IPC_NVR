#####################################
# @file Makefile
# @author zhuguli
# @desc 
# SDK测试demo Makefile
# 芯片交叉编译平台请修改 BUILD_PLATFORM
#####################################
BUILD_PLATFORM = arm-hisiv300-linux
INCLUDE = include            
CFLAGS += -I$(INCLUDE) -O3 -DHAVE_CONFIG_H -Wall -Wcast-align -Wchar-subscripts -Wformat -Winline -Wmissing-declarations -Wmissing-prototypes -Wnested-externs -Wpointer-arith -DSRV_RECORD  -DENABLE_DEBUG -DENABLE_TRACE
LDFLAGS +=


TARGETS = gb28181_sdk_demo
          
OBJS = ./gb28181_sdk_demo.o 
LIBOTHER = lib/$(BUILD_PLATFORM)/libxml2.a lib/$(BUILD_PLATFORM)/libeXosip2.a \
           lib/$(BUILD_PLATFORM)/libosip2.a lib/$(BUILD_PLATFORM)/libosipparser2.a
             
LIB_GB28181 = lib/$(BUILD_PLATFORM)/libgb28181.a

EXTRALIBS := $(LIB_GB28181) $(LIBOTHER) 
LIBS = -lpthread -lnsl -lrt -lresolv -ldl  -lm  
							
CC = $(BUILD_PLATFORM)-gcc -DWITH_DOM 

all: $(TARGETS)		
.%o:%.c
	$(CC) $(CFLAGS) -c $^ 

install:
	cp -f $(TARGETS) $(EXEC_DIR)

$(TARGETS):$(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS) $(EXTRALIBS) 
	$(BUILD_PLATFORM)-strip $(TARGETS)
	
clean:
    
	rm -f *.o *~
	rm -f $(TARGETS)
