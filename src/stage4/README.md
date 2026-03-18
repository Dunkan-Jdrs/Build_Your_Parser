## What is a Context & ContextBuilder

### Context

Context is a read-only object that gives access to values that are bound to an option. It is passed to a [Subcommand](../stage3/README.md) callback which can use the context to get informations.

### ContextBuilder

ContextBuilder is the only class that has access to the Context constructor. It takes a [Subcommand](../stage3/README.md) and a list of [Token](../stage1/README.md), validates them, and builds an immutable Context whose only goal is to provide information.

## What to implement?

### Context

In this fourth stage you will have to implement 4 functions:

| Function  | Description                                                                                                                                                                   |
| --------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Context   | This is the class constructor, the parameter is a rvalue (&&), it's a new concept that is detailed below.                                                                     |
| GetRaw    | This is to get the first arguments of an option as a std::string (e.g. `-m "message"` => `message`).                                                                          |
| GetAllRaw | This is to get all arguments of an option as a list of std::string (e.g. `--file "C:/FirstFile.txt" "C:/SecondFile.txt"` => { `"C:/FirstFile.txt"`, `"C:/SecondFile.txt"` }). |
| Has       | This checks if an option exists in the context.                                                                                                                               |

### ContextBuilder

In this fourth stage you will have to implement 3 functions:

| Function            | Description                                                                                                                                                                    |
| ------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| BuildContext        | This is the function that creates a Context. For every token it checks its type and calls the appropriate conversion function.                                                  |
| ConvertBasicOption  | It checks if the current token arguments count matches with the option arity. If it does, it pushes every argument into the ValuesMap.                                          |
| ConvertConcatOption | It checks if any option, except the last one, does not require a parameter, then adds it to the ValuesMap without parameters. For the last option, it calls ConvertBasicOption. |

## Why using && parameter (The move semantics)?

### Analogy

Imagine that you want to relocate from **House A** to **House B**, you want to bring every object from A to B. You may either:
- List all the objects from **House A**, take their reference and ask to create a new version of each to put them in **House B**. After that, **House A** exists with its own objects, and **House B** exists with a copy of each.
- Take all objects from **House A** and transfer them to **House B**. Now, **House A** still exists, but it is empty because all objects belong to **House B**.

The move semantics works like the second option. You transfer the data of an object to another, leaving the first object empty.

### Concrete

Our parameter is an `unordered_map`, which is a container from the STL (standard library). The `unordered_map` manages its memory internally by allocating memory with the **new** operator. When you decide to copy such an object, you allocate a big memory space then copy all values to the new one. But sometimes, you know that the original object won't be needed anymore after the transfer. Then, why copy it? Instead, you should move it — the first object transfers its internal pointers to the new one, then loses ownership by setting every pointer to `nullptr`.

So why `&&`? It means rvalue reference. It references an object that the owner *promises* won't be used anymore after the move. That is what we want — an object whose resources we can steal to put into the new object.
```cpp
std::unordered_map<std::string, int> myFirstMap {
    {"1", 1},
    {"2", 2},
    {"3", 3},
};

// Using copy
std::unordered_map<std::string, int> mySecondMap = myFirstMap;
// myFirstMap still has its data and you can still work with it.

// Using move semantics
std::unordered_map<std::string, int> myThirdMap = std::move(myFirstMap);
// myFirstMap no longer owns the data. The object still exists but is in an
// unspecified state. You should not use it after the move.
```

## Exceptions to throw

### Context
- Throw runtime error if the Context does not have the requested value.
- Throw runtime error if the value is a flag (does not contain any value).

### ContextBuilder
- Throw runtime error if token argument count is greater than option arity.
- Throw runtime error if token argument count is less than option arity.
- Throw runtime error if any option except the last in a concatenated option requires a parameter.

## Resources

For this stage you may look at:
- [`std::unordered_map`](https://cplusplus.com/reference/unordered_map/unordered_map/)
- [`std::move`](https://en.cppreference.com/w/cpp/utility/move)
- [Stage 3 — Subcommand & Option](../stage3/README.md)