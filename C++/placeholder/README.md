### placeholder

This program takes two lines of text, the first are arguments with values and the second line reads the sentence.
From the provided arguments the program will replace the `[placeholders]` in the sentence with the arguments value.

For example:

    person=Paul,action=eat,what=strawberry icecream
    [person] likes to [action] [what].

    Paul likes to eat strawberry icecream.

I didn't use the `C++` libraries like `std::vector` or `std::string` nor classes to have an additional challenge and to write it as low-level as possible, also I tried to write the code as efficient (more in source code).
I could've used `C` for this but I simply wanted to experiment with `C++`.
