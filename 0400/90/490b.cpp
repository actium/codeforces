#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

unsigned first(const std::vector<std::pair<unsigned, unsigned>>& p)
{
    std::map<unsigned, int> b;
    for (const std::pair<unsigned, unsigned>& e : p) {
        ++b[e.first];
        --b[e.second];
    }

    auto it = b.begin();
    while (it->second != 1)
        ++it;

    return it->first;
}

void solve(std::vector<std::pair<unsigned, unsigned>>& p)
{
    std::sort(p.begin(), p.end());

    std::vector<unsigned> q;
    q.push_back(first(p));
    q.push_back(p[0].second);
    while (q.back() != 0) {
        const auto it = std::lower_bound(p.begin(), p.end(), q.end()[-2], [](const auto& p, unsigned x) {
            return p.first < x;
        });
        q.push_back(it->second);
    }
    q.pop_back();

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
