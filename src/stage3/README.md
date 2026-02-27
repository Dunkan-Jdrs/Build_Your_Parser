## What is a Subcommand & an option

### Subcommand

Subcommand is an object that stores a function and registers options that can be used in this function. It has a name which will be used later in [App](../stage5/App.md).

### Option

An option is a data structure that stores two strings (a short name and a long name), and an arity which represents how many argument the option supports.

## What to implement?

### Subcommand

In this third stage you will have to implement 6 short functions for the Subcommand:

| Function            | Description                                                                                                                  |
| ------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| Subcommand          | This is the class constructor and simply assign parameters to their member.                                                  |
| GetName             | This is the getter for `m_name`.                                                                                             |
| Exec                | It takes a Context to invoke the registered callback with it.                                                                           |
| GetOption           | Get the `Option` from its short or long name.                                                                      |
| AddOption           | Add accepted `Option` to an option list, then reference it by its short and long name in a map. |
| HasRegisteredOption | Check by the short or long name of an option if it is accepted by the subcommand.                                             |

### Option

you will have to implement 4 short functions for the Option:

| Function     | Description                                                                 |
| ------------ | --------------------------------------------------------------------------- |
| Option       | This is the class constructor and simply assign parameters to their member. |
| GetShortName | This is the getter for `m_shortName`.                                       |
| GetLongName  | This is the getter for `m_longName`.                                        |
| GetArity     | This is the getter for `m_arity`.                                           |

## Exceptions to handle

We want to throw error if the user try to use an option that is not supported by the subcommand.
You have to handle:
- Throw runtime error if trying to get an option that is not registered.

## Resources

For this stage you may look at:
- [`std::unordered_map`](https://cplusplus.com/reference/unordered_map/unordered_map/)

If you want to go further, you might look at:
- [`std::function`](https://cplusplus.com/reference/functional/function/function/)