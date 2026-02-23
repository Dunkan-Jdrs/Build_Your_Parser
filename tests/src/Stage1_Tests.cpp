#pragma once
#include "Common.h"

#pragma region TOKEN
TEST(Stage1_Token, IsSubcommand)
{
	/*Init*/
	Token tokenOption = Token("subcommand", {});
	TokenType type;

	/*Execute*/
	type = tokenOption.GetType();

	/*Verify*/
	EXPECT_EQ(type, TokenType::Subcommand);
}

TEST(Stage1_Token, IsShortOption)
{
	/*Init*/
	const std::string optionName = "-m";
	Token tokenOption = Token(optionName, {});
	TokenType type;

	/*Execute*/
	type = tokenOption.GetType();

	/*Verify*/
	EXPECT_EQ(type, TokenType::ShortOption);
}

TEST(Stage1_Token, IsConcatOptionOption)
{
	/*Init*/
	const std::string optionName = "-abc";
	Token tokenOption = Token(optionName, {});
	TokenType type;

	/*Execute*/
	type = tokenOption.GetType();

	/*Verify*/
	EXPECT_EQ(type, TokenType::ConcatOption);
}

TEST(Stage1_Token, IsLongOptionOption)
{
	/*Init*/
	const std::string optionName = "--message";
	Token tokenOption = Token(optionName, {});
	TokenType type;

	/*Execute*/
	type = tokenOption.GetType();

	/*Verify*/
	EXPECT_EQ(type, TokenType::LongOption);
}

TEST(Stage1_Token, ShortOptionNameTrimmed)
{
	/*Init*/
	Token tokenOption = Token("-m", {});

	/*Execute*/

	/*Verify*/
	EXPECT_EQ(tokenOption.GetName(), "m");
}

TEST(Stage1_Token, LongOptionNameTrimmed)
{
	/*Init*/
	Token tokenOption = Token("-message", {});

	/*Execute*/

	/*Verify*/
	EXPECT_EQ(tokenOption.GetName(), "message");
}

TEST(Stage1_Token, ThrowsIfOnlyDash)
{
	/*Init*/

	/*Execute*/

	/*Verify*/
	EXPECT_THROW(Token("-", {}), std::runtime_error);
}

TEST(Stage1_Token, ThrowsIfTooManyDashes)
{
	/*Init*/

	/*Execute*/

	/*Verify*/
	EXPECT_THROW(Token("---Test", {}), std::runtime_error);
}

TEST(Stage1_Token, StoresArguments)
{
	/*Init*/
	Token tokenOption = Token("-m", { "Hello", "Bonjour" });
	/*Execute*/

	/*Verify*/
	EXPECT_EQ(tokenOption.GetArguments().size(), 2);
	EXPECT_EQ(tokenOption.GetArguments()[0], "Hello");
	EXPECT_EQ(tokenOption.GetArguments()[1], "Bonjour");
}
#pragma endregion