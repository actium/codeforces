#include <iostream>
#include <set>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    std::set<std::string> words;
    for (size_t i = 0; i < n; ++i)
        words.insert(s.substr(i) + s.substr(0, i));

    answer(words.size());
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

