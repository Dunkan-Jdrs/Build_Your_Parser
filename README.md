# Build your own CLI_Parser !

## Presentation

This is **a guided project** where you learn how to create a CLI_Parser from **scratch** using C++ and STL. Through 5 stages you will learn how to structure a project, separate responsibilities and discover multiples concepts like `argc & argv handling`, `move semantics`, `builder pattern` 

## Why doing this project

In addition to the concepts that you will learn, you will have a project to put in your portfolio and a reusable project for any application. Moreover this project is an entry point to bigger projects such as a Git-like.
## Stages

| Stage                                                                                 | What you implement                                                                                                                                                                 | Key concept                                                |
| ------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- |
| [Token](src/stage1/README.md)                                                          | A data structure that stores a group of raw arguments and determines which kind it is. ( [Subcommand](src/stage3/README.md), [Option](src/stage3/README.md) and their values ) | Enums, string parsing                                      |
| [Parser](src/stage2/README.md)                                                        | The system that iterates through `argv`, splits it into groups, and produces a `std::vector<Token>`                                                                                | `argc`/`argv` handling, sequential parsing, error handling |
| [Subcommand](src/stage3/Subcommand.md) & [Option](src/stage3/README.md)               | Define subcommands (e.g: `commit`, `log`...) and their associated options (`--port`, `-v`) with arity constraints ( number of arguments supported )                                | OOP design, registration pattern, unordered_map            |
| [Context](src/stage4/Context.md) & [Context Builder](src/stage4/README.md) | Building a read-only context from parsed results, it checks if each token complies with its option or subcommand                                                                   | Builder pattern, move semantics                            |
| [App](src/stage5/App.md)                                                              | Expose a high-level API that developers use to declare commands/options, parse `argv`, and execute handlers.                                                                       | API design, orchestration, architecture                    |

## Getting started

### Create repository
On this project you can find at the top-right a button `Use this template`, use it and create your own repository.

#### Steps

| Step             | Description                                                                                                                                      |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| Clone repository | Open a cmd in your project folder and clone your git project with `https://github.com/{yourUsername}/{Project_Name}.git`                         |
| Setup            | You can find at the root of your repository `setup.bat`, you can use it to initialize the project (It uses [Cmake](https://cmake.org/download/)) |
| Start            | You can either open the solution in `build` folder, or work with .cpp that you can find in src                                                   |
| Test             | You think that you completed a stage ? Go to `Root/src/stageX/validate.bat`                                                                      |
