#include "Common.h"
#pragma region APP
TEST(Stage4_App, RunNothing)
{
	/*Init*/
	App app = App();
	const int argc = 1;
	const char* argv[argc] = { ".exe" };

	/*Execute*/

	/*Verify*/
	EXPECT_EQ(app.Run(argc, argv), 1);
}

TEST(Stage4_App, RunWithoutSubcommand)
{
	/*Init*/
	App app = App();
	const int argc = 2;
	const char* argv[argc] = { ".exe", "-v" };

	/*Execute*/

	/*Verify*/

	// We don't verify with throw here because Run handle every throw of the application
	EXPECT_EQ(app.Run(argc, argv), 1);
}

TEST(Stage4_App, RunUnknownSubcommand)
{
	/*Init*/
	App app = App();
	const int argc = 2;
	const char* argv[argc] = { ".exe", "unknown" };

	/*Execute*/

	/*Verify*/

	// We don't verify with throw here because Run handle every throw of the application
	EXPECT_EQ(app.Run(argc, argv), 1);
}

TEST(Stage4_App, RunSubcommandWithUnknownOption)
{
	/*Init*/
	App app = App();

	const std::string subcommandName = "Foo";
	const int argc = 3;
	const char* argv[argc] = { ".exe", subcommandName.c_str(), "-h" };

	const int requiredValue = 10;
	int currentValue = 0;

	Subcommand foo = Subcommand(subcommandName, [requiredValue, &currentValue](const Context& ctx) {
		currentValue = requiredValue;
		});

	/*Execute*/
	app.AddSubcommand(foo);

	/*Verify*/
	// We don't verify with throw here because Run handle every throw of the application
	EXPECT_EQ(app.Run(argc, argv), 1);
}

TEST(Stage4_App, AddSubcommandTwice)
{
	/*Init*/
	App app = App();
	Subcommand foo = Subcommand("Foo", nullptr);
	Subcommand fooBis = Subcommand("Foo", nullptr);

	/*Execute*/
	app.AddSubcommand(foo);

	/*Verify*/
	EXPECT_THROW(app.AddSubcommand(foo), std::runtime_error);
	EXPECT_THROW(app.AddSubcommand(fooBis), std::runtime_error);
}

TEST(Stage4_App, RunSubcommandOnly)
{
	/*Init*/
	App app = App();

	const std::string subcommandName = "Foo";
	const int argc = 2;
	const char* argv[argc] = { ".exe", subcommandName.c_str() };

	const int requiredValue = 10;
	int currentValue = 0;

	Subcommand foo = Subcommand(subcommandName, [requiredValue, &currentValue](const Context& ctx) {
		currentValue = requiredValue;
		});

	/*Execute*/
	app.AddSubcommand(foo);
	app.Run(argc, argv);

	/*Verify*/
	EXPECT_EQ(requiredValue, currentValue);
}

TEST(Stage4_App, RunSubcommandWithOption)
{
	/*Init*/
	App app = App();

	const std::string subcommandName = "Foo";
	const std::string countOptionShortName = "c";
	const std::string countOptionLongName = "count";

	const int argc = 4;
	const char* argv[argc] = { ".exe", subcommandName.c_str(), "--count", "10" };

	const int requiredValue = 10;
	int currentValue = 0;

	Subcommand foo = Subcommand(subcommandName, [&currentValue, &countOptionLongName](const Context& ctx) {
		int count = std::stoi(ctx.GetRaw(countOptionLongName));
		currentValue = count;
		});

	foo.AddOption(countOptionShortName, countOptionLongName, 1);
	app.AddSubcommand(foo);

	/*Execute*/

	app.Run(argc, argv);

	/*Verify*/
	EXPECT_EQ(requiredValue, currentValue);
}
#pragma endregion