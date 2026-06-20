# cpp_learn

A small C++ learning project collection with a structured layout and a simple `make`-based build setup.

## Structure

- `examples/`: organized examples grouped by topic
- `experiments/`: quick tests, scratch code, and temporary experiments
- `bin/`: output directory for compiled executables

## Build

Build all examples:

```sh
make
```

Build only one specific example:

```sh
make single FILE=examples/object_lifecycle/parent_child_lifetest.cpp
```

List available examples:

```sh
make list
```

Run a specific example after building everything:

```sh
make run FILE=examples/object_lifecycle/parent_child_lifetest.cpp
```

Build and run only one specific example:

```sh
make run-single FILE=examples/object_lifecycle/parent_child_lifetest.cpp
```

Clean generated files:

```sh
make clean
```

## Naming

Each `.cpp` file is built as a separate executable.

Example:

- `examples/basics/hello_world.cpp` -> `bin/examples/basics/hello_world`
- `examples/object_lifecycle/parent_child_lifetest.cpp` -> `bin/examples/object_lifecycle/parent_child_lifetest`

## Recommended Usage

If an example becomes larger or more complex, it is worth giving it its own subdirectory under `examples/`.

The `experiments/` directory is the right place for quick exploratory code that you do not want to move into the organized examples yet.

Use `make` when you want to build the full collection, and use `make single FILE=...` or `make run-single FILE=...` when you only want to work with one example.