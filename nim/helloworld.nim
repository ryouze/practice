echo "Hello World"

# To compile this, run the following:
# nim c -r --verbosity:0 helloworld.nim

# The command above has several elements:
# c is an alias for compile, which compiles the Nim sources into C and then invokes the C compiler on it.
# -r is an alias for --run, which runs the program.
# --verbosity:0 makes the compiler only output essential messages, since by default it also outputs some debugging messages. From now on, we assume that --verbosity:0 is set.
# ./helloworld.nim is the path to the source you want to compile.

