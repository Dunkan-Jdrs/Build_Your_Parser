# Build your own CLI Parser!

## Presentation

This is **a guided project** where you learn how to create a CLI Parser from **scratch** using C++ and STL. Through 5 stages (~10 to 15 hours) you will learn how to structure a project, separate responsibilities and discover multiple concepts like `argc & argv handling`, `move semantics`, `builder pattern`.

## Why do this project?

In addition to the concepts that you will learn, you will have a project to put in your portfolio and a reusable library for any application. Moreover this project is an entry point to bigger projects such as a Git-like.

## What you'll end up with

By the end of this project, you'll have built a reusable C++ library that lets you define a CLI like this:

```cpp
App app;

Subcommand commit("commit", [](const Context& ctx) {
    std::string msg = ctx.GetRaw("message");
    std::cout << "Committing: " << msg << "\n";
});
commit.AddOption(Option("m", "message", 1));
app.AddSubcommand(commit);

Subcommand log("log", [](const Context& ctx) {
    if (ctx.Has("verbose"))
        std::cout << "[verbose] Showing full log...\n";
    else
        std::cout << "Showing log...\n";
});
log.AddOption(Option("v", "verbose", 0));
app.AddSubcommand(log);

app.Run(argc, argv);
```

```
$ ./myapp commit --message "first commit"
Committing: first commit

$ ./myapp log -v
[verbose] Showing full log...
```

Every stage builds on the previous one, and by stage 5 you plug everything together into this clean API.

## Stages

| Stage                                                                         | What you implement                                                                                                                                                              | Key concept                                                |
| ----------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- |
| [Token](src/stage1/README.md)                                                 | A data structure that stores a group of raw arguments and determines which kind it is. ([Subcommand](src/stage3/README.md), [Option](src/stage3/README.md) and their values)    | Enums, string parsing                                      |
| [Parser](src/stage2/README.md)                                                | The system that iterates through `argv`, splits it into groups, and produces a `std::vector<Token>`                                                                             | `argc`/`argv` handling, sequential parsing, error handling |
| [Subcommand](src/stage3/README.md) & [Option](src/stage3/README.md)          | Define subcommands (e.g: `commit`, `log`...) and their associated options (`--port`, `-v`) with arity constraints (number of arguments supported)                               | OOP design, registration pattern, unordered_map            |
| [Context](src/stage4/README.md) & [ContextBuilder](src/stage4/README.md)     | Build a read-only context from parsed results, checking if each token complies with its option or subcommand                                                                    | Builder pattern, move semantics                            |
| [App](src/stage5/README.md)                                                   | Expose a high-level API that developers use to declare commands/options, parse `argv`, and execute handlers                                                                     | API design, orchestration, architecture                    |

## Getting started

### Create repository

On this project you can find at the top-right a button `Use this template`, use it and create your own repository.

### Steps

| Step             | Description                                                                                                                                       |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| Clone repository | Open a cmd in your project folder and clone your git project with `https://github.com/{yourUsername}/{Project_Name}.git`                          |
| Setup            | You can find at the root of your repository `setup.bat`, you can use it to initialize the project (It uses [CMake](https://cmake.org/download/))  |
| Start            | You can either open the solution in the `build` folder, or work directly with the `.cpp` files found in `src`                                     |
| Test             | You think you completed a stage? Go to `Root/src/stageX/validate.bat`                                                                            |