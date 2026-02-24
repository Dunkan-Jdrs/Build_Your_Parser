#include "Common.h"

#pragma region Context
TEST(Stage3_Context, EmptyContext)
{
	/*Init*/
	Subcommand subcommand = Subcommand("subcommand", [](const Context& _ctx) {
		std::string x = _ctx.GetRaw("x");
		});

	ContextBuilder builder = ContextBuilder();
	Context ctx = builder.BuildContext(subcommand, {});

	/*Execute*/

	/*Verify*/
	EXPECT_THROW(subcommand.Exec(ctx), std::runtime_error);
}

TEST(Stage3_Context, ThrowsIfUnknownOption)
{
	/*Init*/
	Subcommand subcommand = Subcommand("subcommand", nullptr);
	ContextBuilder builder = ContextBuilder();

	/*Execute*/

	/*Verify*/
	EXPECT_THROW(builder.BuildContext(subcommand, { Token("-h", {}) }), std::runtime_error);
}

TEST(Stage3_Context, ThrowsIfMissmatchArity)
{
	/*Init*/
	Subcommand subcommand = Subcommand("subcommand", nullptr);
	ContextBuilder builder = ContextBuilder();

	Option option = Option("o", "option", 2);
	subcommand.AddOption(option);

	Token tokenTooManyArgs = Token("-o", { "test", "test2", "test3" });
	Token tokenTooLowArgs = Token("-o", { "test" });
	Token tokenGreatArgs = Token("-o", { "test", "test2" });
	/*Execute*/

	/*Verify*/
	EXPECT_THROW(builder.BuildContext(subcommand, { tokenTooManyArgs }), std::runtime_error);
	EXPECT_THROW(builder.BuildContext(subcommand, { tokenTooLowArgs }), std::runtime_error);
	EXPECT_NO_THROW(builder.BuildContext(subcommand, { tokenGreatArgs }));
}

TEST(Stage3_Context, ConcatToken)
{
	/*Init*/
	std::string concatFlag = "-abc";
	Token concatToken = Token(concatFlag, {});

	bool checkFlag = false;
	Subcommand subcommand = Subcommand("subcommand", [&checkFlag](const Context& _ctx) {
		checkFlag = _ctx.Has("a") && _ctx.Has("b") && _ctx.Has("c");
		});

	subcommand.AddOption(Option("a", "a", 0));
	subcommand.AddOption(Option("b", "b", 0));
	subcommand.AddOption(Option("c", "c", 0));

	ContextBuilder builder = ContextBuilder();
	Context ctx = builder.BuildContext(subcommand, { concatToken });

	/*Execute*/
	subcommand.Exec(ctx);

	/*Verify*/
	EXPECT_TRUE(checkFlag);
}

TEST(Stage3_Context, ConcatTokenWithLastOptionArgument)
{
	/*Init*/
	const std::string arg = "foo";
	const std::string concatFlag = "-abc";
	Token concatToken = Token(concatFlag, { arg });

	bool checkFlag = false;
	Subcommand subcommand = Subcommand("subcommand", [&checkFlag, &arg](const Context& _ctx) {
		checkFlag = _ctx.Has("a") && _ctx.Has("b") && _ctx.Has("c") && _ctx.GetRaw("c") == arg;
		});

	subcommand.AddOption(Option("a", "a", 0));
	subcommand.AddOption(Option("b", "b", 0));
	subcommand.AddOption(Option("c", "c", 1));

	ContextBuilder builder = ContextBuilder();
	Context ctx = builder.BuildContext(subcommand, { concatToken });

	/*Execute*/
	subcommand.Exec(ctx);

	/*Verify*/
	EXPECT_TRUE(checkFlag);
}

TEST(Stage3_Context, ThrowsIfConcatTokenHasMiddleOptionArgument)
{
	/*Init*/
	const std::string arg = "foo";
	const std::string concatFlag = "-abc";
	Token concatToken = Token(concatFlag, { arg });

	bool checkFlag = false;
	Subcommand subcommand = Subcommand("subcommand", nullptr);
	subcommand.AddOption(Option("a", "a", 0));
	subcommand.AddOption(Option("b", "b", 1));
	subcommand.AddOption(Option("c", "c", 0));

	ContextBuilder builder = ContextBuilder();

	/*Execute*/

	/*Verify*/
	EXPECT_THROW(builder.BuildContext(subcommand, { concatToken }), std::runtime_error);
}

TEST(Stage3_Context, ThrowsIfGetEmptyArg)
{
	/*Init*/
	std::string flag = "-a";
	Token token = Token(flag, {});

	bool checkFlag = false;
	Subcommand subcommand = Subcommand("subcommand", [](const Context& _ctx) {
		std::string getA = _ctx.GetRaw("a");
		});

	subcommand.AddOption(Option("a", "a", 0));

	ContextBuilder builder = ContextBuilder();
	Context ctx = builder.BuildContext(subcommand, { token });

	/*Execute*/

	/*Verify*/
	EXPECT_THROW(subcommand.Exec(ctx), std::runtime_error);
}

TEST(Stage3_Context, ThrowsIfGetAllEmptyArg)
{
	/*Init*/
	std::string flag = "-a";
	Token token = Token(flag, {});

	bool checkFlag = false;
	Subcommand subcommand = Subcommand("subcommand", [](const Context& _ctx) {
		std::vector<std::string> getAllA = _ctx.GetAllRaw("a");
		});

	subcommand.AddOption(Option("a", "a", 0));

	ContextBuilder builder = ContextBuilder();
	Context ctx = builder.BuildContext(subcommand, { token });

	/*Execute*/

	/*Verify*/
	EXPECT_THROW(subcommand.Exec(ctx), std::runtime_error);
}

TEST(Stage3_Context, GetTypedArg)
{
	/*Init*/
	const std::string flag = "--number";
	Token token = Token(flag, { "10" });

	bool checkFlag = false;
	int number = 0;
	Subcommand subcommand = Subcommand("subcommand", [&number](const Context& _ctx) {
		number = _ctx.Get<int>("number");
		});

	subcommand.AddOption(Option("n", "number", 1));

	ContextBuilder builder = ContextBuilder();
	Context ctx = builder.BuildContext(subcommand, { token });

	/*Execute*/
	subcommand.Exec(ctx);

	/*Verify*/
	EXPECT_EQ(number, 10);
}

TEST(Stage3_Context, GetAllTypedArg)
{
	/*Init*/
	const std::string flag = "--numbers";
	Token token = Token(flag, { "10", "15" });

	bool checkFlag = false;
	int number = 0;
	Subcommand subcommand = Subcommand("subcommand", [&number](const Context& _ctx) {
		std::vector<int> numbers = _ctx.GetAll<int>("numbers");
		for (int i = 0; i < numbers.size(); ++i) number += numbers[i];
		});

	subcommand.AddOption(Option("n", "numbers", 2));

	ContextBuilder builder = ContextBuilder();
	Context ctx = builder.BuildContext(subcommand, { token });

	/*Execute*/
	subcommand.Exec(ctx);

	/*Verify*/
	EXPECT_EQ(number, 25);
}
#pragma endregion