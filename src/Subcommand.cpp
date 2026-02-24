#include "Subcommand.h"
#include "Context.h"

// Stage 3 : Subcommand
//
// A Subcommand has a name, a callback, and a list of accepted Options.
// Options are stored in a vector and indexed by both their short and long name
// in an unordered_map for fast lookup.
// 
// GetOption() must work with both the short name and the long name.

Subcommand::Subcommand(const std::string& name, std::function<void(const Context&)> callback)
{
    throw std::exception(__FUNCTION__ " not implemented");
}

void Subcommand::Exec(const Context& context)
{
    throw std::exception(__FUNCTION__ " not implemented");
}

const std::string& Subcommand::GetName() const
{
    throw std::exception(__FUNCTION__ " not implemented");
}

const Option& Subcommand::GetOption(const std::string& optionName) const
{
    throw std::exception(__FUNCTION__ " not implemented");
}

void Subcommand::AddOption(const Option& option)
{
    throw std::exception(__FUNCTION__ " not implemented");
}

void Subcommand::AddOption(const std::string& shortName, const std::string& longName, const int arity)
{
    throw std::exception(__FUNCTION__ " not implemented");
}

bool Subcommand::HasRegisteredOption(const std::string& name) const
{
    throw std::exception(__FUNCTION__ " not implemented");
}