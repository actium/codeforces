#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string word)
{
    if (const size_t length = word.length(); length > 10)
        word.replace(1, length-2, std::to_string(length-2));

    answer(word);
}

int main()
{
    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;

        solve(word);
    }

    return 0;
}

