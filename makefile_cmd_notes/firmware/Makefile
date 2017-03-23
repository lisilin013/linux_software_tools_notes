VPATH = inc : src : .
# vpath %.cpp src 
# vpath %.h inc
# TARGET =  firmware

# method one 
# obj_cpp := $(wildcard *o)
# cpp_main : $(obj_cpp)
# 	g++ -o cpp_main $(obj_cpp)
# add.o  cpp_main.o :  add.h


# method two
# obj_cpp := $(patsubst %.cpp, %.o, $(wildcard *cpp))

# cpp_main : $(obj_cpp)
# 	g++ -o cpp_main $(obj_cpp)

# method three
obj_cpp = main.o add.o

cpp_main : $(obj_cpp)
	g++ -o cpp_main $(obj_cpp)




.PHONY : clean

clean:
	-rm cpp_main $(obj_cpp)

print :
	@echo 'hello world!'

