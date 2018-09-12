CXX = g++
CFLAGES = -Wall -g -std=c++11

INCLUDES = -I./ -I/user/include

LDFLAGES = -L./user/lib64/x86_64-linux-gnu

EXE = call_testpy

EXE_SRC = call_testpy.cpp

EXE_OBJ = call_testpy.o

SRCS = call_py.cpp

OBJ = $(patsubst %.cpp,%.o,$(SRCS))

LIBS = -lpython2.7

all : $(EXE)
		@echo "------done-------"

$(EXE) : $(EXE_OBJ) $(OBJ)
	$(CXX) $(CFLAGES) -o $(EXE) $(OBJ) $(EXE_OBJ) $(INCLUDES) $(LDFLAGES) $(LIBS)

$(EXE_OBJ) : $(EXE_SRC)
	$(CXX) $(CFLAGES) -c $(EXE_SRC) -o $(EXE_OBJ) $(INCLUDES)

$(OBJ) : $(SRCS)
	$(CXX) $(CFLAGES) -c $(SRCS) -o $(OBJ) $(INCLUDES)

.PYTHON : clean

clean: 
	rm -r $(OBJS) $(EXE)