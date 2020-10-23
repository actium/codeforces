#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n; ++i) {
        if (s[i-1] > s[i]) {
            s.erase(s.begin() + i - 1);
            return answer(s);
        }
    }

    s.pop_back();
    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

