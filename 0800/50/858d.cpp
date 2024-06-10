#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::string_view>& v)
{
    for (const std::string_view& x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::map<std::string_view, size_t> x;
    for (size_t i = 0; i < n; ++i) {
        for (size_t k = 1; k < 10; ++k) {
            for (size_t j = 0; j + k < 10; ++j) {
                const auto r = x.emplace(std::string_view(s[i].data() + j, k), i);
                if (!r.second && r.first->second != i)
                    r.first->second = n;
            }
        }
    }

    std::vector<std::string_view> r(n);
    for (const auto& e : x) {
        if (e.second == n)
            continue;

        if (r[e.second].empty() || e.first.length() < r[e.second].length())
            r[e.second] = e.first;
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
