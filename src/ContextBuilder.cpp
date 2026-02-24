#include "ContextBuilder.h"
#include "Token.h"
#include "Subcommand.h"
#include "Option.h"
#include <stdexcept>

/* Stage 4 : ContextBuilder

 ContextBuilder validates tokens against the declared options of a Subcommand and produces a Context.
*/

Context ContextBuilder::BuildContext(const Subcommand& subcommand, const std::vector<Token>& tokens)
{
	/*
	For each option token :
		- Find the matching Option in the Subcommand
		- Check that argument count matches the option arity (throw if not)
		- Store values in the ValuesMap indexed by the option long name
		
		Special case - ConcatOption (ex: "-rf") :
			- Every letter except the last must be a flag (arity 0)
			- The last letter can have any arity and receives the token arguments
	
	Error to throw:
		- Throw if the option arity does not match the token arguments size.
		- Throw if any letter except the last one in concatened option as an arity > 0
*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void ContextBuilder::ConvertBasicOption(const Subcommand& subcommand, const Token& token, ValuesMap& map)
{
	/* This is the function which handles the conversion of a Long or Short Token */
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void ContextBuilder::ConvertConcatOption(const Subcommand& subcommand, const Token& token, ValuesMap& map)
{
	/* This is the function which handle the conversion of a Concat Token */
    throw std::logic_error(__FUNCTION__ " not implemented");
}