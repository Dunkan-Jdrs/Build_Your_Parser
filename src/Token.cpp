#include "Token.h"
#include <stdexcept>

/*
* Stage 1: Token
* 
* A Token represent an element of the command line by its name and its arguments
*/

Token::Token(const std::string& name, const std::vector<std::string>& arguments)
{
	/*
		In this function you have to determine the TokenType base on the name's prefix:
			- No prefix -> Subcommand ( ex: "commit" )
		
			- Single dash (-) -> Short Option (ex: "-m")
				-> Concat Option, if there is more than 1 char (ex: "-rf")
					  
			- Double dash (--) -> LongOption (ex: "--verbose")
		
			- Only dashes or more than 2 dashes -> std::runtime_error
		
			Then you should register both name and arguments in m_name & m_arguments :
				- name needs to be stripped of its dashes ( ex: name = --verbose, m_name = verbose)
	*/
	throw std::exception(__FUNCTION__ " not implemented");
}

const std::string& Token::GetName() const
{
	/*
		Return the token's name
		Reminder: token's name shouldn't contain any dash (-)
	*/
	throw std::exception(__FUNCTION__ " not implemented");
}

const std::vector<std::string>& Token::GetArguments() const
{
	/*
		Return the token's arguments list
	*/
	throw std::exception(__FUNCTION__ " not implemented");
}

TokenType Token::GetType() const
{
	/*
		Return the token's type
	*/
	throw std::exception(__FUNCTION__ " not implemented");
}
