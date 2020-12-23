#include <iostream>
#include <set>
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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& t, size_t k, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    std::set<unsigned> w;
    for (const auto [type, id] : q) {
        if (type == 1) {
            w.insert(t[id-1]);

            if (w.size() > k)
                w.erase(w.begin());
        } else {
            answer(w.count(t[id-1]) != 0);
        }
    }
}

int main()
{
    size_t n, k, m;
    std::cin >> n >> k >> m;

    std::vector<unsigned> t(n);
    std::cin >> t;

    std::vector<std::pair<unsigned, unsigned>> q(m);
    std::cin >> q;

    solve(t, k, q);

    return 0;
}

