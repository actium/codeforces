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

void answer(unsigned u, const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << u << ' ' << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::map<unsigned, std::vector<size_t>> x;
    for (size_t i = 0; i < n; ++i)
        x[a[i]].push_back(i);

    const auto dequeue = [&x](const auto& it) {
        const std::pair<unsigned, size_t> p = { it->first, it->second.back() };
        it->second.pop_back();
        if (it->second.empty())
            x.erase(it);

        return p;
    };

    std::vector<std::pair<size_t, size_t>> p;
    while (k-- != 0 && x.size() > 1) {
        const std::pair<unsigned, size_t> b = dequeue(x.begin());
        const std::pair<unsigned, size_t> e = dequeue(std::prev(x.end()));

        p.emplace_back(e.second, b.second);

        x[b.first+1].push_back(b.second);
        x[e.first-1].push_back(e.second);
    }

    answer(x.rbegin()->first - x.begin()->first, p);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
