#include <iostream>
#include <set>
#include <string>
#include <vector>

template <typename T = std::string_view>
std::vector<unsigned> Z(T&& s)
{
    const unsigned n = s.size();

    std::vector<unsigned> z(n);
    for (unsigned i = 1, j = 0; i < n; ++i) {
        if (i < j + z[j])
            z[i] = std::min(j + z[j] - i, z[i-j]);

        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];

        if (j + z[j] < i + z[i])
            j = i;
    }
    return z;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "Just a legend" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const std::vector<unsigned> z = Z(s);

    std::set<unsigned> t;
    t.insert(z[1]);
    for (size_t i = 2; i < n; ++i) {
        if (i + z[i] == n) {
            const auto it = t.lower_bound(z[i]);
            if (it != t.end())
                return answer(s.substr(0, z[i]));
        }

        t.insert(z[i]);
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
