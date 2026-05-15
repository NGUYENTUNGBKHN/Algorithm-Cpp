BUILD_DIR:=build

LAB0_NAME:=lab0
LAB0_TARGET:=$(BUILD_DIR)/$(LAB0_NAME)


CC:=g++


.PHONY: clean all lab0

lab0: $(LAB0_TARGET)


$(LAB0_TARGET): $(LAB0_NAME).cpp
	@echo "compile $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $< -o $(LAB0_TARGET)
	@echo "Done."
