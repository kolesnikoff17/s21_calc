CC = gcc

#  УБРАТЬ САНИТАЙЗ ПЕРЕД СДАЧЕЙ

CFLAGS = -g
GCOV_FLAGS := -fprofile-arcs -ftest-coverage
LDFLAGS := -fprofile-arcs --coverage
LCHECK = -lcheck -lgmp
LIN_FLAGS := -lpthread -pthread -lrt -lm -lsubunit
ifeq ($(shell uname), Linux)
LCHECK += $(LIN_FLAGS)
endif

SOURCES:= $(wildcard calculating/*.c)

OBJ_DIR := obj
OBJ_GCOV_DIR := obj_gcov
OBJECTS := $(addprefix obj/,$(SOURCES:.c=.o))
OBJECTS_GCOV := $(addprefix obj_gcov/,$(SOURCES:.c=.o))
HEADER = calc_c.h

TARGET_EXEC := calc.a

RM := rm -rf


all: $(TARGET_EXEC)

$(TARGET_EXEC): create_dir $(OBJECTS)
	ar rcs $@ $(OBJ_DIR)/*.o

lib_gcov.a: create_dir $(OBJECTS_GCOV)
	ar rcs $@ $(OBJ_GCOV_DIR)/*.o

create_dir:
	mkdir -p $(OBJ_DIR) $(OBJ_GCOV_DIR)

test: tests/test_calc.c $(HEADER) lib_gcov.a
	$(CC) $(CFLAGS) $^ -o $@ $(LCHECK) $(LDFLAGS) $(GCOV_FLAGS)
	./$@
	@mv *gcda *gcno $(OBJ_GCOV_DIR)/

gcov_report: test
	@rm -f $(OBJ_GCOV_DIR)/*tests*
	@lcov/bin/./lcov -c -d $(OBJ_GCOV_DIR)/. -o $(OBJ_GCOV_DIR)/coverage.info
	@lcov/bin/./genhtml $(OBJ_GCOV_DIR)/coverage.info --output-directory out

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $(subst /,_,$@) $(LIN_FLAGS)
	@mv *.o $(OBJ_DIR)/

$(OBJ_GCOV_DIR)/%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $(subst /,_,$@) $(LIN_FLAGS)
	@mv *.o *gcno $(OBJ_GCOV_DIR)/

clean:
	$(RM) $(OBJ_DIR) $(OBJ_GCOV_DIR)
	$(RM) $(TARGET_EXEC) *.a
	$(RM) *.gc* test .vscode test.dSYM


lint:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.h *.c
	python3 ../materials/linters/cpplint.py --extensions=c \
	./core/*.h ./core/*.c ./another/*.h ./another/*.c \
	./comparison/*.h ./comparison/*.c ./convertion/*.h ./convertion/*.c \
	./arithmetic/*.h ./arithmetic/*.c
	$(RM) CPPLINT.cfg

rebuild: clean all

.PHONY: all clean rebuild test lint create_dir gcov_report
	
