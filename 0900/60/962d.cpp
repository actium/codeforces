#include <algorithm>
#include <iostream>
#include <set>
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
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::set<std::pair<integer, size_t>> s;
    for (size_t i = 0; i < n; ++i)
        s.emplace(a[i], i);

    std::vector<std::pair<size_t, integer>> t;
    while (!s.empty()) {
        const auto it = s.begin(), jt = std::next(it);
        if (jt == s.end() || it->first != jt->first) {
            t.emplace_back(it->second, it->first);
        } else {
            s.emplace(2 * it->first, jt->second);
            s.erase(jt);
        }
        s.erase(it);
    }

    std::sort(t.begin(), t.end());

    std::vector<integer> b;
    for (const auto& e : t)
        b.push_back(e.second);

    answer(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
