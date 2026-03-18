#include "Token.h"
#include <stdexcept>

Token::Token(const std::string& name, const std::vector<std::string>& arguments)
{
	/*
	In this function you have to determine the TokenType base on the name's prefix:
		- No prefix          								-> Subcommand     (ex: "commit")
		- Single dash (-)    								-> ShortOption    (ex: "-m")
																-> ConcatOption   if more than 1 char after dash (ex: "-rf")
		- Double dash (--)   							-> LongOption     (ex: "--verbose")
		- Empty or whitespace-only name       -> throw std::runtime_error
		- Only dashes or more than 2 dashes   -> throw std::runtime_error

		Then you have to register both name and arguments in m_name & m_arguments :
		Note: m_name must to be stripped of its dashes (ex: name = --verbose, m_name = verbose)
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::string& Token::GetName() const
{
	/*
	Return the token's name
	Reminder: token's name shouldn't contain any dashes (-)
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}

const std::vector<std::string>& Token::GetArguments() const
{
	/*
	Return the token's arguments list
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}

TokenType Token::GetType() const
{
	/*
	Return the token's type
	*/
	throw std::logic_error(__FUNCTION__ " not implemented");
}
