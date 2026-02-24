#include "App.h"
#include "Parser.h"
#include "Token.h"
#include "Context.h"
#include "ContextBuilder.h"

// Stage 5 : App
//
// App is the entry point. It registers Subcommands and runs the full pipeline :
//   1. Parse argv into tokens
//   2. Identify the subcommand from the first token
//   3. Build a Context from the remaining tokens
//   4. Execute the subcommand callback
//
// Edge cases to handle :
//   - No arguments provided => throw std::runtime_error
//   - First token is not a Subcommand => throw std::runtime_error
//   - Subcommand not registered => do nothing (or throw, your choice)
//   - Adding the same subcommand twice => throw std::runtime_error

int App::Run(int argc, const char** argv)
{
    throw std::exception(__FUNCTION__ " not implemented");
}

void App::AddSubcommand(const Subcommand& subcommand)
{
    throw std::exception(__FUNCTION__ " not implemented");
}

bool App::IsSubcommandRegistred(const std::string& name)
{
    throw std::exception(__FUNCTION__ " not implemented");
}