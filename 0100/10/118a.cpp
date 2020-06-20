#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& input)
{
    std::string output;
    for (char c : input) {
        c = tolower(c);
        if (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i')
            continue;

        output.push_back('.');
        output.push_back(c);
    }

    answer(output);
}

int main()
{
    std::string input;
    std::cin >> input;

    solve(input);

    return 0;
}

