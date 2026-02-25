#include "App.h"
#include "Parser.h"
#include "Token.h"
#include "Context.h"
#include "ContextBuilder.h"
#include <stdexcept>

// Stage 5 : App
//
// App is the entry point of the CLI. It ties everything together.
// It registers Subcommands and runs the full parsing pipeline.
//
// Internal structure :
//   - m_subcommands : an unordered_map that stores registered Subcommands by name

int App::Run(int argc, const char** argv)
{
    /*
    This function runs the full pipeline and handles all errors.
    It should never throw to the caller.
    Return 0 on success, 1 on error.

    Tip: call Execute() inside a try/catch block.
    Catch any std::runtime_error, print the error message to std::cerr, and return 1.
    */
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void App::Execute(int argc, const char** argv)
{
    /*
    This function contains the full parsing pipeline.
    It can throw — errors are handled by Run().

    Pipeline to implement :
        1. Use Parser to parse argv into a vector of tokens
        2. If the token vector is empty, throw std::runtime_error
        3. If the first token is not a Subcommand, throw std::runtime_error
        4. Get the subcommand name from the first token
        5. If the subcommand is not registered, throw std::runtime_error
        6. Use ContextBuilder to build a Context from the subcommand and tokens
        7. Execute the subcommand with the Context
    */
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void App::AddSubcommand(const Subcommand& subcommand)
{
    /*
    Register a Subcommand in m_subcommands.
    
    Error to handle :
        - If a Subcommand with the same name is already registered, throw std::runtime_error.
    
    Tip: use IsSubcommandRegistred to check before inserting.
    */
    throw std::logic_error(__FUNCTION__ " not implemented");
}

bool App::IsSubcommandRegistred(const std::string& name)
{
    /*
    Check if a Subcommand with the given name is already registered.
    
    Tip: unordered_map has a find() method that returns end() if the key is not found.
    */
    throw std::logic_error(__FUNCTION__ " not implemented");
}