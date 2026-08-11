#include <iostream>
#include <map>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<integer>& b)
{
    const size_t n = b.size();

    std::map<integer, std::vector<size_t>> p;
    for (size_t i = 0; i < n; ++i)
        p[b[i]].push_back(i);

    if (p.begin()->first != 0)
        return no_answer();

    integer s = 0, x = 0;
    for (auto it = p.begin(); it != p.end(); ++it) {
        if (const auto jt = std::next(it); jt != p.end()) {
            if (jt->first <= s)
                return no_answer();

            const auto d = jt->first - s;
            if (d % it->second.size() != 0 || d / it->second.size() <= x)
                return no_answer();

            x = d / it->second.size();
        } else {
            ++x;
        }

        for (const size_t i : it->second) {
            b[i] = x;
            s += x;
        }
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> b(n);
    std::cin >> b;

    solve(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
