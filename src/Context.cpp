#include "Context.h"
#include <stdexcept>

// Stage 4 : Context
//
// Context is a read-only object passed to the Subcommand callback.
// It holds the parsed values indexed by the long name of each option.
//
// GetRaw() => returns the first value as a string (throws if flag or missing)
// GetAll() => returns all values (throws if flag or missing)
// Has()    => returns true if the option was present on the command line

Context::Context(ValuesMap&& values)
{
	/*
	This constructor has a rvalue parameter. Why?
	
	The ContextBuilder will locally create a ValuesMap, in the "Build" function, which is an unordered_map. 
	But after building the Context, at the end of the scope, the local map will be destroyed so we can't pass the ValuesMap as a reference.
	
	Indeed, we can give it as a value, but to avoid a copy of the map, we can pass it as a rvalue 
	which means that we move the object responsibility to this class.

	So the ValuesMap is now dependent on the Context life cycle.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::string& Context::GetRaw(const std::string& valueName) const
{
	/*
	Get a parameter as std::string from the asked option.
	Handle error:
		- You should throw a runtime_error if the valueName does not exist in the context
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::vector<std::string>& Context::GetAllRaw(const std::string& valueName) const
{
	/*
	Get all parameters as std::string from the asked option.
	Handle error:
		- You should throw a runtime_error if the valueName does not exist in the context
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

bool Context::Has(const std::string& valueName) const
{
	/*
	Check if the asked option exists in the Context.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}