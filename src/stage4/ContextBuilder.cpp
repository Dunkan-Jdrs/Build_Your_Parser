#include "ContextBuilder.h"
#include "Token.h"
#include "Subcommand.h"
#include "Option.h"
#include <stdexcept>

Context ContextBuilder::BuildContext(const Subcommand& subcommand, const std::vector<Token>& tokens)
{
	/*
	Build a Context from the given subcommand and token list.

	For each option token:
		- Dispatch to ConvertBasicOption or ConvertConcatOption based on the token type
		- Each Convert function stores the result in ValuesMap indexed by the option's long name
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void ContextBuilder::ConvertBasicOption(const Subcommand& subcommand, const Token& token, ValuesMap& map)
{
	/*
	Handle conversion of a ShortOption or LongOption token.

	First, retrieve the Option from the subcommand using GetOption().

	Then check that the token's argument count matches the option's arity,
	and push all arguments into the ValuesMap under the option's long name.

	Throw std::runtime_error if argument count is greater than the option arity.
	Throw std::runtime_error if argument count is less than the option arity.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void ContextBuilder::ConvertConcatOption(const Subcommand& subcommand, const Token& token, ValuesMap& map)
{
	/*
	Handle conversion of a ConcatOption token (ex: "-rf").

	For each letter in the token name, retrieve the Option using GetOption().

	Each letter except the last must be a flag (arity == 0).
	The last letter can have any arity and receives the token arguments.
	Call ConvertBasicOption for the last letter.

	Throw std::runtime_error if any option except the last requires a parameter (arity > 0).
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}