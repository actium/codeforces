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

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::map<unsigned, unsigned> q;
    for (size_t i = 0; i < n; ++i) {
        const auto it = q.emplace(a[i], 1).first, jt = q.find(a[i] - 1);
        if (jt != q.end())
            it->second = std::max(it->second, jt->second + 1);
    }

    std::pair<unsigned, unsigned> x = *q.begin();
    for (const auto& e : q) {
        if (e.second > x.second)
            x = e;
    }

    std::vector<size_t> v;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == x.first - x.second + 1) {
            v.push_back(i);
            --x.second;
        }
    }

    answer(v);
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
