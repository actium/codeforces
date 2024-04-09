#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& s, size_t k)
{
    const size_t n = s.size();

    std::map<unsigned, unsigned> f;
    for (const unsigned x : s)
        ++f[x];

    const auto check = [&](size_t x) {
        size_t q = 0;
        for (const auto& e : f)
            q += e.second / x;

        return q >= k;
    };

    size_t lb = 1, ub = n;
    while (lb + 1 < ub) {
        const size_t mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    std::vector<unsigned> t;
    for (auto it = f.begin(); it != f.end() && t.size() < k; ) {
        if (it->second < lb) {
            ++it;
        } else {
            t.push_back(it->first);
            it->second -= lb;
        }
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s, k);

    return 0;
}
