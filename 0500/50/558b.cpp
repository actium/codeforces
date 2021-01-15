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

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    struct Element {
        unsigned f;
        size_t l, r;
    };

    std::map<unsigned, Element> x;
    for (size_t i = 0; i < n; ++i) {
        const auto it = x.find(a[i]);
        if (it == x.end()) {
            x.emplace(a[i], Element{ 1, i, i });
        } else {
            ++it->second.f;
            it->second.r = i;
        }
    }

    const Element* p = &x.begin()->second;
    for (const auto& q : x) {
        if (q.second.f < p->f)
            continue;

        if (q.second.f > p->f || q.second.r - q.second.l < p->r - p->l)
            p = &q.second;
    }

    answer(p->l, p->r);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

