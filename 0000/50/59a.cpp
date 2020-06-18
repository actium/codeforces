#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string word)
{
    const size_t c = std::count_if(word.cbegin(), word.cend(), isupper);
    if (c > word.length() - c) {
        std::transform(word.cbegin(), word.cend(), word.begin(), toupper);
    } else {
        std::transform(word.cbegin(), word.cend(), word.begin(), tolower);
    }

    answer(word);
}

int main()
{
    std::string word;
    std::cin >> word;

    solve(word);

    return 0;
}

