#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned w, unsigned h, const std::vector<std::pair<char, unsigned>>& s)
{
    const size_t n = s.size();

    std::set<unsigned> x;
    x.insert(0);
    x.insert(w);

    std::set<unsigned> y;
    y.insert(0);
    y.insert(h);

    std::multiset<unsigned> hs;
    hs.insert(h);

    std::multiset<unsigned> vs;
    vs.insert(w);

    for (size_t i = 0; i < n; ++i) {
        if (s[i].first == 'H') {
            const auto it = y.lower_bound(s[i].second), jt = std::prev(it);
            hs.erase(hs.find(*it - *jt));
            hs.insert(*it - s[i].second);
            hs.insert(s[i].second - *jt);
            y.insert(s[i].second);
        } else {
            const auto it = x.lower_bound(s[i].second), jt = std::prev(it);
            vs.erase(vs.find(*it - *jt));
            vs.insert(*it - s[i].second);
            vs.insert(s[i].second - *jt);
            x.insert(s[i].second);
        }

        answer(1ull * *vs.rbegin() * *hs.rbegin());
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned w, h;
    std::cin >> w >> h;

    size_t n;
    std::cin >> n;

    std::vector<std::pair<char, unsigned>> s(n);
    std::cin >> s;

    solve(w, h, s);

    return 0;
}
