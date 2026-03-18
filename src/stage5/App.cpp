#include "App.h"
#include "Parser.h"
#include "Token.h"
#include "Context.h"
#include "ContextBuilder.h"
#include <stdexcept>

int App::Run(int argc, const char** argv)
{
    /*
	Entry point of the CLI. Runs the full pipeline and handles all errors.
	This function must never throw to the caller.

	Call Execute() inside a try/catch block.
	Catch any std::exception, print the error message to std::cerr, and return 1.
	Return 0 on success.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void App::Execute(int argc, const char** argv)
{
    /*
    This function contains the full parsing pipeline.

    What to implement :
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
	Register a subcommand in m_subcommands.

	Throw std::runtime_error if a subcommand with the same name is already registered.
	Tip: use IsSubcommandRegistred() to check before inserting.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

bool App::IsSubcommandRegistred(const std::string& name)
{
    /*
	Return true if a subcommand with the given name is already registered.
	Tip: unordered_map has a find() method that returns end() if the key is not found.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}