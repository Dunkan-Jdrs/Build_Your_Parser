#include "Option.h"
#include <stdexcept>

Option::Option(const std::string& shortName, const std::string& longName, const int arity)
{
	/*
	Assign parameters to their respective members.
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::string& Option::GetShortName() const
{
	/*
	Get option short name
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::string& Option::GetLongName() const
{
	/*
	Get option long name
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}

size_t Option::GetArity() const
{
	/*
	Get option arity: the number of argument it needs to work
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}
