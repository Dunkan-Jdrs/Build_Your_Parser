#include "Subcommand.h"
#include "Context.h"
#include <stdexcept>

Subcommand::Subcommand(const std::string& name, std::function<void(const Context&)> callback)
{
	/*
	Assign parameters to their respective members.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void Subcommand::Exec(const Context& context)
{
	/* Execute the subcommand callback with the context */
    throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::string& Subcommand::GetName() const
{
	/*Returns subcommand's name*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

const Option& Subcommand::GetOption(const std::string& optionName) const
{
	/*
	Return the Option matching the given name.
	This must work with both the short name and the long name.

	Throw std::runtime_error if the option is not registered.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

void Subcommand::AddOption(const Option& option)
{
	/*
	Register the option in both the vector and the map.
		- Store the object in the vector.
		- Index it by short name and long name in the map, pointing to the vector entry.

	This avoids storing the object twice for two different keys.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

bool Subcommand::HasRegisteredOption(const std::string& name) const
{
	/*
	Return true if an option with the given name is registered.
	This must work with both the short name and the long name.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}