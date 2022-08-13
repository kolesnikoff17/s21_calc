CC = gcc

#  УБРАТЬ САНИТАЙЗ ПЕРЕД СДАЧЕЙ

CFLAGS = -g
GCOV_FLAGS := -fprofile-arcs -ftest-coverage
LDFLAGS := -fprofile-arcs --coverage
LCHECK = -lcheck
LIN_FLAGS := -lpthread -pthread -lrt -lm -lsubunit
ifeq ($(shell uname), Linux)
LCHECK += $(LIN_FLAGS)
endif

SOURCES:= $(wildcard calculating/*.c) $(wildcard bonus/*.c)

OBJ_DIR := obj
OBJ_GCOV_DIR := obj_gcov
OBJECTS := $(addprefix obj/,$(SOURCES:.c=.o))
OBJECTS_GCOV := $(addprefix obj_gcov/,$(SOURCES:.c=.o))
HEADER = calc_c.h

RM := rm -rf


all: test

create_dir:
	@mkdir -p $(OBJ_DIR) $(OBJ_GCOV_DIR)

test: tests/test_calc.c $(HEADER) $(OBJECTS_GCOV)
	$(CC) $(CFLAGS) $< $(OBJ_GCOV_DIR)/*.o -o $@ $(LCHECK) $(LDFLAGS) $(GCOV_FLAGS)
	./$@
	@mv *gcda *gcno $(OBJ_GCOV_DIR)/

gcov_report: test
	@rm -f $(OBJ_GCOV_DIR)/*tests*
	@lcov/bin/./lcov -c -d $(OBJ_GCOV_DIR)/. -o $(OBJ_GCOV_DIR)/coverage.info
	@lcov/bin/./genhtml $(OBJ_GCOV_DIR)/coverage.info --output-directory out

$(OBJ_DIR)/%.o: %.c $(HEADER) create_dir
	@$(CC) $(CFLAGS) -c $< -o $(subst /,_,$@)
	@mv *.o $(OBJ_DIR)/

$(OBJ_GCOV_DIR)/%.o: %.c $(HEADER) create_dir
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $(subst /,_,$@)
	@mv *.o *gcno $(OBJ_GCOV_DIR)/

clean:
	$(RM) $(OBJ_DIR) $(OBJ_GCOV_DIR)
	$(RM) $(TARGET_EXEC) *.a out
	$(RM) *.gc* test .vscode test.dSYM


lint:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.h *.c
	python3 ../materials/linters/cpplint.py --extensions=c \
	calculating/*.c calculating/*.c tests/*.c
	$(RM) CPPLINT.cfg

rebuild: clean all

.PHONY: all clean rebuild test lint create_dir gcov_report
	
