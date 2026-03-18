#include "Context.h"

Context::Context(ValuesMap&& values)
{
	/*
    values is a rvalue reference, use std::move to transfer ownership into m_values.
    See the README for a detailed explanation of move semantics.
    */
    throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::string& Context::GetRaw(const std::string& valueName) const
{
	/*
    Return the first argument of the requested option as a std::string.

	Throw std::runtime_error if valueName does not exist in the context.
	Throw std::runtime_error if the option is a flag (no value associated).
    */
    throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::vector<std::string>& Context::GetAllRaw(const std::string& valueName) const
{
	/*
	Return all arguments of the requested option as a list of std::string.

	Throw std::runtime_error if valueName does not exist in the context.
	Throw std::runtime_error if the option is a flag (no value associated).
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}

bool Context::Has(const std::string& valueName) const
{
	/*
	Check if the asked option exists in the Context.
	Return true if the option exists, false otherwise.
	*/
    throw std::logic_error(__FUNCTION__ " not implemented");
}