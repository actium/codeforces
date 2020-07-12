#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& p, const std::vector<std::string>& s)
{
    const size_t n = s.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            const std::string x = s[i] + s[j];
            if (x.find(p) != std::string::npos)
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    std::string p;
    std::cin >> p;

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(p, s);

    return 0;
}

