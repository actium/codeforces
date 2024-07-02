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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<std::string>& s, size_t k)
{
    const size_t n = s.size();

    std::string t = "aaaa";

    const auto check = [&](const std::string& q) {
        if (t == "aaaa")
            t = q;

        return t == q;
    };

    for (size_t i = 0; i < n; i += 4) {
        std::string p[4];
        for (size_t j = 0; j < 4; ++j) {
            auto it = s[i+j].rbegin();
            for (size_t q = 0; q < k; ) {
                if (it == s[i+j].rend())
                    return no_answer();

                q += (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u');

                p[j].push_back(*it++);
            }
        }

        if (p[0] == p[1] && p[1] == p[2] && p[2] == p[3])
            continue;

        if (p[0] == p[1] && p[2] == p[3] && check("aabb"))
            continue;

        if (p[0] == p[2] && p[1] == p[3] && check("abab"))
            continue;

        if (p[0] == p[3] && p[1] == p[2] && check("abba"))
            continue;

        return no_answer();
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(4 * n);
    std::cin >> s;

    solve(s, k);

    return 0;
}
