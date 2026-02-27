## What is a Token?

Token is a data structure that represents a group of `std::string` from the command line. It stores the name, a list of arguments and define a `TokenType` depending on the name. 
- name : It is the first std::string of a Token
- arguments: This is a list that contains every arguments that follow `m_name`

Tokens are created from [Parser](../stage2/README.md) that you will discover in the next stage.

## What is `TokenType`?

`TokenType` is an `enum` that defines the kind of a token. The token can determine which type it is from its name:

| `TokenType`  | e.g         | Description                                                                                                                                                               |
| ------------ | ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Subcommand   | `commit`    | A subcommand is defined by a word without prefix. In our parser it doesn't have arguments.                                                                                |
| ShortOption  | `-m`        | A short option is defined by a single dash followed by a single letter. A short option can be followed by arguments.                                                      |
| LongOption   | `--message` | A long option is defined by a double dashes followed by a word. A long option can be followed by arguments.                                                               |
| ConcatOption | `-rf`       | A concatenate option is defined by a single dash followed by multiple letter. A concatenate option can have argument but they will be associated to the last letter only. |

## What to implement?

In this first stage you will have to implement 4 functions:

| Function     | Description                                                                                                                                                        |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Token        | This is the class constructor and the main function that you will develop. In this one your goal is do determine which type of Token correspond to the given name. |
| GetName      | This is the getter for `m_name`                                                                                                                                    |
| GetArguments | This is the getter for `m_arguments`                                                                                                                               |
| GetType      | This is the getter for `m_type`                                                                                                                                    |

## Exceptions to handle

We want to throw errors when there is invalid parameter for the Token.
You have to handle the following one:
- Throw runtime error if given name is empty or full whitespace.
- Throw runtime error if given name contains only dashes (-)
- Throw runtime error if given name contains more than 2 dashes

## Resources
---
For this stage you may look at:
[`std::string::find_first_not_of`](https://cplusplus.com/reference/string/string/find_first_not_of/)
[`std::runtime_error`](https://cplusplus.com/reference/stdexcept/runtime_error/)
