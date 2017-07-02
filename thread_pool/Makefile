CC := g++  
TARGET := threadpool  
INCLUDE := -I./  
LIBS := -lpthread   
  
# C++语言编译参数   
CXXFLAGS := -g -Wall -D_REENTRANT -std=c++11  
  
# C预处理参数   
# CPPFLAGS :=    

SRC=$(wildcard *.cpp)
  
OBJECTS=$(patsubst %.cpp, %.o, $(SRC)) 
  
  
# $@表示所有目标集   
%.o : %.cpp   
	$(CC) $(CXXFLAGS) $(INCLUDE) $< -c 


$(TARGET): $(OBJECTS)   
	$(CC) $^ -o $(TARGET) $(LIBS)   
  
.PHONY : clean  
clean:   
	-rm -f $(OBJECTS) $(TARGET)  
