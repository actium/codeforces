#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, std::string_view>>& v)
{
    for (const std::pair<unsigned, std::string_view>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<std::string>& f, const std::vector<std::string>& s)
{
    const size_t q = s.size();

    std::map<std::string_view, std::pair<unsigned, std::string_view>> x;
    for (const std::string& t : f) {
        const size_t k = t.length();

        std::set<std::string_view> p;
        for (size_t i = 1; i <= k; ++i) {
            for (size_t j = 0; j < i; ++j)
                p.emplace(t.data() + j, i - j);
        }

        for (const std::string_view& u : p) {
            ++x[u].first;
            x[u].second = t;
        }
    }

    std::vector<std::pair<unsigned, std::string_view>> a(q, std::make_pair(0, "-"));
    for (size_t i = 0; i < q; ++i) {
        const auto it = x.find(s[i]);
        if (it != x.end())
            a[i] = it->second;
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> f(n);
    std::cin >> f;

    size_t q;
    std::cin >> q;

    std::vector<std::string> s(q);
    std::cin >> s;

    solve(f, s);

    return 0;
}
