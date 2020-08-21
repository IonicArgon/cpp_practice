#include <iostream>
#include <vector>
#include <string>

// so sometimes you have wacky long complex types.
// an example would be something like
std::vector<std::pair<std::string, std::string>> long_ass_type{};

// you can get around having the long complex type using a typedef
typedef std::vector<std::pair<std::string, std::string>> long_typedef;

// which means you can now do
long_typedef short_type{};

// you can do the same thing with "using", making a type alias instead
using shortened_type = std::vector<std::pair<std::string, std::string>>;

// and it works the same way
shortened_type wow_much_short{};

// you could also use them to increase legibility like so
using test_score = int;
test_score gradeIBMayExam(std::string student)
{
    return 0;
}

// this gets rid of the ambiguous "int" and clarifies the return type a bit more
// you can also use them for easier code maintenance, like if you wanted to change
// the return value of a number of similar functions that return the same
// type value

int main()
{
    gradeIBMayExam("bob");
    return 0;
}