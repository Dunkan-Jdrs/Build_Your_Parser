#include "Common.h"
TEST(Stage3_Subcommand, GetExistingOption)
{
	/*Init*/
	Subcommand subcommand = Subcommand("subcommand", nullptr);
	subcommand.AddOption(Option("m", "message", 0));

	/*Execute*/

	/*Verify*/
	EXPECT_NO_THROW(subcommand.GetOption("message"));
}

TEST(Stage3_Subcommand, GetNoneExistingOption)
{
	/*Init*/
	Subcommand subcommand = Subcommand("subcommand", nullptr);

	/*Execute*/

	/*Verify*/
	EXPECT_THROW(subcommand.GetOption("message"), std::runtime_error);
}