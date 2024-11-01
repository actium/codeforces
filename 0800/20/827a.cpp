#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::pair<std::string, std::vector<unsigned>>>& t)
{
    const size_t n = t.size();

    std::vector<std::pair<size_t, size_t>> events;
    for (size_t i = 0; i < n; ++i) {
        for (const unsigned x : t[i].second)
            events.emplace_back(x-1, i);
    }

    std::sort(events.begin(), events.end());

    std::string s;
    for (const auto& e : events) {
        if (e.first > s.length())
            s.append(e.first - s.length(), 'a');

        const std::string& v = t[e.second].first;
        if (e.first + v.length() > s.length())
            s.append(v.substr(s.length() - e.first));
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::vector<unsigned>>> t(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> t[i].first;

        size_t k;
        std::cin >> k;

        t[i].second.resize(k);
        std::cin >> t[i].second;
    }

    solve(t);

    return 0;
}
