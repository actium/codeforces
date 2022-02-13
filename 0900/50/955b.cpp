#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    std::unordered_map<char, unsigned> f;
    for (const char c : s)
        ++f[c];

    const auto q = [](const std::pair<char, unsigned>& x) {
        return x.second > 1;
    };

    switch (f.size()) {
        case 2:
            return answer(std::all_of(f.begin(), f.end(), q));
        case 3:
            return answer(std::any_of(f.begin(), f.end(), q));
        case 4:
            return answer(true);
    }

    answer(false);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
