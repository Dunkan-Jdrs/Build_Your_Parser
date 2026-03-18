#include "Common.h"
#pragma region PARSER

TEST(Stage2_Parser, Nothing) {

	/*Init*/
	Parser parser = Parser();

	const int argc = 1;
	const char* argv[argc] = { ".exe" };

	/*Execute*/
	std::vector<Token> tokens = parser.Parse(argc, argv);

	/*Verify*/
	EXPECT_TRUE(tokens.empty());
}

TEST(Stage2_Parser, SubcommandOnly) {

	/*Init*/
	Parser parser = Parser();

	const std::string subcommandName = "log";
	const int argc = 2;
	const char* argv[argc] = { ".exe", subcommandName.c_str() };

	/*Execute*/
	std::vector<Token> tokens = parser.Parse(argc, argv);

	/*Verify*/
	EXPECT_EQ(tokens[0].GetName(), subcommandName);
	EXPECT_EQ(tokens[0].GetType(), TokenType::Subcommand);
}

TEST(Stage2_Parser, FlagAndOption) {

	/*Init*/
	Parser parser = Parser();

	const std::string subcommandName = "subcommand";
	const std::string flagName = "--flag";
	const std::string optionName = "-o";

	const Option flag = Option("f", "flag", 0);
	const Option option = Option("o", "option", 1);

	const int argc = 5;
	const char* argv[argc] = { ".exe", subcommandName.c_str(), flagName.c_str(), optionName.c_str(), "foo" };

	/*Execute*/
	std::vector<Token> tokens = parser.Parse(argc, argv);

	/*Verify*/
	EXPECT_EQ(tokens[0].GetName(), subcommandName);
	EXPECT_EQ(tokens[0].GetType(), TokenType::Subcommand);
	EXPECT_EQ(tokens[0].GetArguments().size(), 0);

	EXPECT_EQ(tokens[1].GetName(), flagName.substr(2));
	EXPECT_EQ(tokens[1].GetType(), TokenType::LongOption);
	EXPECT_EQ(tokens[1].GetArguments().size(), 0);

	EXPECT_EQ(tokens[2].GetName(), optionName.substr(1));
	EXPECT_EQ(tokens[2].GetType(), TokenType::ShortOption);
	EXPECT_EQ(tokens[2].GetArguments().size(), 1);
}
#pragma endregion
