#include "Subcommand.h"
#include "Context.h"
#include <stdexcept>

/* Stage 3 : Subcommand

	A Subcommand has a name, a callback, and a list of accepted Options.
	Options are stored in a vector and indexed by both their short and long name
	in an unordered_map.
	This avoids to have twice the object for 2 different keys in the map.

	GetOption() must work with both the short name and the long name.
*/

Subcommand::Subcommand(const std::string& name, std::function<void(const Context&)> callback)
{
	/*
	This constructor only assign parameters to members
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void Subcommand::Exec(const Context& context)
{
	/* This function execute the subcommand callback */
    throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::string& Subcommand::GetName() const
{
	/*This function returns subcommand name*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

const Option& Subcommand::GetOption(const std::string& optionName) const
{
	/*
		This function should work with short option name and long option name
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void Subcommand::AddOption(const Option& option)
{
	/*
		This function add option with both short and long name.
		Use the vector to store the objects, use the map to reference them.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

bool Subcommand::HasRegisteredOption(const std::string& name) const
{
	/*
		This function check if the option is registered ( both with short and long name ).
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}