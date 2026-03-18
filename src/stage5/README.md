## What is App
This is the final class of our library. It brings everything together and takes the user input to execute the right command.

## What to implement?
In this last stage you will have to implement 4 functions:

| Function              | Description                                                                                                                                                                        |
| --------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Run                   | Executes the command line and displays an error if a throw happens.                                                                                                                |
| Execute               | Creates a parser, collects the tokens, verifies if there is a subcommand to execute and that it exists, creates a context and executes the subcommand with the context.            |
| AddSubcommand         | Adds a valid subcommand to the unordered_map of subcommands.                                                                                                                       |
| IsSubcommandRegistred | Checks if a given subcommand (by name) is registered in the application.                                                                                                           |

## Exceptions to throw
- Throw runtime error if user tries to register a subcommand with the same name twice.
- Throw runtime error if application is called without any argument.
- Throw runtime error if application is called without a subcommand as first argument.
- Throw runtime error if the given subcommand does not exist in the app.

## Resources
This stage ties everything together. If you are stuck, go back to the relevant stage:
- [Stage 1 — Token](../stage1/README.md)
- [Stage 2 — Parser](../stage2/README.md)
- [Stage 3 — Subcommand & Option](../stage3/README.md)
- [Stage 4 — Context & ContextBuilder](../stage4/README.md)
- [`std::unordered_map`](https://cplusplus.com/reference/unordered_map/unordered_map/)
- [`std::runtime_error`](https://cplusplus.com/reference/stdexcept/runtime_error/)