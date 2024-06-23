CPP_DIR = Cpp
C_ARRAY_DIR = C_array
C_LINTEDLIST_DIR = C_linkedlist

CPP_OUTPUT = minstack_cpp
C_ARRAY_OUTPUT = minstack_c_array
C_LINTEDLIST_OUTPUT = minstack_c_linkedlist

all:                                                                                                                                                                                                        
	g++ ./$(CPP_DIR)/main.cpp ./$(CPP_DIR)/minstack.cpp -o $(CPP_OUTPUT)
	gcc ./$(C_ARRAY_DIR)/main.c ./$(C_ARRAY_DIR)/minstack.c -o $(C_ARRAY_OUTPUT)
	gcc ./$(C_LINTEDLIST_DIR)/main.c ./$(C_LINTEDLIST_DIR)/minstack.c -o $(C_LINTEDLIST_OUTPUT)

clean:
	@rm $(CPP_OUTPUT)
	@rm $(C_ARRAY_OUTPUT)
	@rm $(C_LINTEDLIST_OUTPUT)