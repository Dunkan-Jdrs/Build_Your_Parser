#include "Parser.h"
#include <stdexcept>

std::vector<Token> Parser::Parse(int argc, const char** argv) const
{
	/*
	argc is the size of argv
	argv is the list of argument given by the user in his CLI.
	
	Iterate through argv to list the subcommand and the options with their argument
	A subcommand is only followed by options and never by an argument, this is the only token without '-' (in our version of CLI parser)
	An option begin with a '-', it is the entry of a new token, everything that follows without '-' is an argument in the token.
	
	Note: start at index 1 because argv[0] is the executable path.
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}
