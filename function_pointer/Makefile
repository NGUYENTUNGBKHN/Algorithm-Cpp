BUILD_DIR:=build

LAB1_NAME:=lab1
LAB1_TARGET:=$(BUILD_DIR)/lab1

CXX:=g++
CC:=gcc


.PHONY: clean all lab1

lab1: $(LAB1_TARGET)

$(LAB1_TARGET): $(LAB1_NAME).cpp
	@echo "compile $<"
	@mkdir -p $(shell dirname $@)
	@$(CXX) $< -o $(LAB1_TARGET)
	@echo "Done."