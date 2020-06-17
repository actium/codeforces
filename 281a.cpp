#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string word)
{
    if (!word.empty())
        word[0] = toupper(word[0]);

    answer(word);
}

int main()
{
    std::string word;
    std::cin >> word;

    solve(word);

    return 0;
}

