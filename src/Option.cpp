#include "Option.h"
#include <stdexcept>

/*
* Stage 2 : Option
* 
* An Option describes an accepted option for a Subcommand.
* It has a short name (ex: "v"), a long name (ex: "verbose"),
* and an arity : the number of values it expects after it.
* Arity 0 means it's a flag (no value expected).
*/

Option::Option(const std::string& shortName, const std::string& longName, const int arity)
{
	/*
	Assign every parameter to the right member
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
