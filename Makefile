CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g

SRC_DIRS := examples experiments
SRC := $(sort $(shell find $(SRC_DIRS) -name '*.cpp' 2>/dev/null))
BIN := $(patsubst %.cpp,bin/%,$(SRC))

all: $(BIN)

bin/%: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

single:
	@test -n "$(FILE)" || (echo "Usage: make single FILE=examples/basics/hello_world.cpp" && exit 1)
	@$(MAKE) bin/$(basename $(FILE))

run: all
	@test -n "$(FILE)" || (echo "Usage: make run FILE=examples/basics/hello_world.cpp" && exit 1)
	@./bin/$(basename $(FILE))

run-single:
	@test -n "$(FILE)" || (echo "Usage: make run-single FILE=examples/basics/hello_world.cpp" && exit 1)
	@$(MAKE) single FILE="$(FILE)"
	@printf "\n--------------PROGRAM RUN--------------\n\n"
	@./bin/$(basename $(FILE))
	@printf "\n\n--------------PROGRAM END--------------\n\n"

list:
	@printf '%s\n' $(SRC)

clean:
	rm -rf bin build

.PHONY: all single run run-single list clean