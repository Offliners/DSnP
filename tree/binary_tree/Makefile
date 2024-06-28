CPP_DIR = Cpp
C_DIR = C

CPP_OUTPUT = binarytree_cpp
C_OUTPUT = binarytree_c

all:                                                                                                                                                                                                        
	g++ ./$(CPP_DIR)/main.cpp ./$(CPP_DIR)/binarytree.cpp -o $(CPP_OUTPUT)
	gcc ./$(C_DIR)/main.c ./$(C_DIR)/queue.c ./$(C_DIR)/binarytree.c -o $(C_OUTPUT)

clean:
	@rm $(CPP_OUTPUT)
	@rm $(C_OUTPUT)