#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(std::vector<unsigned>& v, size_t k)
{
    std::cout << std::min(v.size(), k) << '\n';

    const char* separator = "";
    while (k-- > 0 && !v.empty()) {
        std::cout << separator << v.back();
        v.pop_back();
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& id, size_t k)
{
    const size_t n = id.size();

    std::vector<unsigned> q;
    std::set<unsigned> p;
    for (size_t i = 0; i < n; ++i) {
        if (const auto it = p.find(id[i]); it != p.end())
            continue;

        if (q.size() >= k) {
            const unsigned x = q[q.size() - k];
            p.erase(x);
        }

        q.push_back(id[i]);
        p.insert(id[i]);
    }

    answer(q, k);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> id(n);
    std::cin >> id;

    solve(id, k);

    return 0;
}

