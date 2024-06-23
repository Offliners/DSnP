CPP_DIR = Cpp
C_ARRAY_DIR = C_array

CPP_OUTPUT = minstack_cpp
C_ARRAY_OUTPUT = minstack_c_array

all:                                                                                                                                                                                                        
	g++ ./$(CPP_DIR)/main.cpp ./$(CPP_DIR)/minstack.cpp -o $(CPP_OUTPUT)
	gcc ./$(C_ARRAY_DIR)/main.c ./$(C_ARRAY_DIR)/minstack.c -o $(C_ARRAY_OUTPUT)

clean:
	@rm $(CPP_OUTPUT)
	@rm $(C_ARRAY_OUTPUT)