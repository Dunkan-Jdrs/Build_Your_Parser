## What is a Parser?

Parser is a system which transforms the command line arguments into a list of [Token](../stage1/README.md). Its job is to split the token name from its arguments (e.g: `commit -m "message"` => 2 Tokens, "commit" is a subcommand, and "-m" is an option with its argument "message" )

A command line is given through the entry point of your application by 2 parameters:
- `argc`: It is an `int` which means "arguments count", this is the number of arguments in the command line.
- `argv`: this is a `const char**`, you don't have to worry about the `*` for now, just know that it is a list of word and you can get each elements using argv\[i]. Note that argv\[0] is the executable path and should be ignored
## What to implement?

In this second stage you will have to implement a single function:

| Function | Description                                                                              |
| -------- | ---------------------------------------------------------------------------------------- |
| Parse    | It takes the list of arguments from command line, iterates through it and creates tokens |

## Exceptions to handle

You don't have to throw anything for the Parser.

## Resources

For this stage you may look at:
- [std::vector](https://cplusplus.com/reference/vector/vector/)
- [argc & argv](https://en.cppreference.com/w/cpp/language/main_function.html)