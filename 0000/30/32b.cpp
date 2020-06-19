#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& input)
{
    std::string output;

    const size_t n = input.length();
    for (size_t i = 0; i < n; ++i) {
        if (input[i] == '.') {
            output.push_back('0');
        } else {
            //assert(i+1 < n);
            output.push_back(input[i+1] == '.' ? '1' : '2');
            ++i;
        }
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

