BUILD_DIR:=build

LAB0_NAME:=generate_parentheses
LAB0_TARGET:=$(BUILD_DIR)/generate_parentheses

LAB1_NAME:=graph_coloring
LAB1_TARGET:=$(BUILD_DIR)/graph_coloring

CC:=g++


.PHONY: clean all lab0 lab1

lab0: $(LAB0_TARGET)

lab1: $(LAB1_TARGET)

$(LAB0_TARGET): $(LAB0_NAME).cpp
	@echo "compile $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $< -o $(LAB0_TARGET)
	@echo "Done."


$(LAB1_TARGET): $(LAB1_NAME).cpp
	@echo "compile $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $< -o $(LAB1_TARGET)
	@echo "Done."
