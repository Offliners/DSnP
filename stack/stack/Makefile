CPP_DIR = Cpp
C_ARRAY_DIR = C_array
C_LINTEDLIST_DIR = C_linkedlist

CPP_OUTPUT = stack_cpp
C_ARRAY_OUTPUT = stack_c_array
C_LINTEDLIST_OUTPUT = stack_c_linkedlist

all:                                                                                                                                                                                                        
	g++ ./$(CPP_DIR)/main.cpp -o $(CPP_OUTPUT)
	gcc ./$(C_ARRAY_DIR)/main.c ./$(C_ARRAY_DIR)/stack.c -o $(C_ARRAY_OUTPUT)
	gcc ./$(C_LINTEDLIST_DIR)/main.c ./$(C_LINTEDLIST_DIR)/stack.c -o $(C_LINTEDLIST_OUTPUT)

clean:
	@rm $(CPP_OUTPUT)
	@rm $(C_ARRAY_OUTPUT)
	@rm $(C_LINTEDLIST_OUTPUT)