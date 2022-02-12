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

struct Message {
    std::string s;
    std::string r;
    unsigned t;
};

std::istream& operator >>(std::istream& input, Message& v)
{
    return input >> v.s >> v.r >> v.t;
}

void answer(const std::set<std::pair<std::string, std::string>>& x)
{
    std::cout << x.size() << '\n';

    for (const std::pair<std::string, std::string>& e : x)
        std::cout << e.first << ' ' << e.second << '\n';
}

void solve(const std::vector<Message>& m, unsigned d)
{
    const size_t n = m.size();

    std::set<std::pair<std::string, std::string>> f;
    for (size_t i = 0; i < n; ++i) {
        const Message& s = m[i];

        for (size_t j = 0; j < i; ++j) {
            const Message& r = m[j];

            if (r.s == s.r && r.r == s.s && s.t > r.t && s.t - r.t <= d)
                f.emplace(std::min(s.s, s.r), std::max(s.s, s.r));
        }
    }

    answer(f);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<Message> m(n);
    std::cin >> m;

    solve(m, d);

    return 0;
}
