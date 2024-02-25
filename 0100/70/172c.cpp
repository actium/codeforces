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

void solve(const std::vector<std::pair<unsigned, unsigned>>& s, size_t m)
{
    const size_t n = s.size();

    std::vector<unsigned> w(n);
    {
        unsigned t = 0;

        std::map<unsigned, std::vector<size_t>> p;

        const auto simulate = [&] {
            unsigned x = 0;
            for (const auto& e : p) {
                t += e.first - x;
                x = e.first;

                for (const size_t i : e.second)
                    w[i] = t;

                t += 1 + e.second.size() / 2;
            }
            p.clear();
            t += x;
        };

        for (size_t i = 0, k = 0; i < n; ++i) {
            t = std::max(t, s[i].first);

            p[s[i].second].push_back(i);

            if (++k == m || i + 1 == n) {
                simulate();
                k = 0;
            }
        }
    }

    answer(w);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s, m);

    return 0;
}
