CPP_OUTPUT = stack_cpp
C_ARRAY_OUTPUT = stack_c_array
C_LINTLIST_OUTPUT = stack_c_linklist

all:                                                                                                                                                                                                        
	g++ ./Cpp/main.cpp -o $(CPP_OUTPUT)
	gcc ./C_array/main.c ./C_array/stack.c -o $(C_ARRAY_OUTPUT)
	gcc ./C_linklist/main.c ./C_linklist/stack.c -o $(C_LINTLIST_OUTPUT)

clean:
	@rm $(CPP_OUTPUT)
	@rm $(C_ARRAY_OUTPUT)
	@rm $(C_LINTLIST_OUTPUT)