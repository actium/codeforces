#include <algorithm>
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
    std::cout << v.size();

    for (const unsigned x : v)
        std::cout << ' ' << x;

    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, size_t k)
{
    std::map<unsigned, std::vector<unsigned>> v;
    v[0] = {};
    for (size_t i = 0; v.size() <= k; ++i) {
        std::map<unsigned, std::vector<unsigned>> q;
        for (auto e : v) {
            e.second.push_back(a[i]);
            q.emplace(e.first + a[i], e.second);
        }

        for (const auto& e : q)
            v.insert(e);
    }

    for (const auto& e : v) {
        if (e.first == 0)
            continue;

        answer(e.second);

        if (--k == 0)
            break;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
