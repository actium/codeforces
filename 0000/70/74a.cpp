#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Participant {
    std::string nick;
    unsigned s, f;
    unsigned a, b, c, d, e;
};

std::istream& operator >>(std::istream& input, Participant& v)
{
    return input >> v.nick >> v.s >> v.f >> v.a >> v.b >> v.c >> v.d >> v.e;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<Participant>& p)
{
    const auto comparator = [](const Participant& lhs, const Participant& rhs) {
        const unsigned a = lhs.a + lhs.b + lhs.c + lhs.d + lhs.e + lhs.s * 100;
        const unsigned b = rhs.a + rhs.b + rhs.c + rhs.d + rhs.e + rhs.s * 100;
        return a + rhs.f * 50 < b + lhs.f * 50;
    };
    answer(std::max_element(p.cbegin(), p.cend(), comparator)->nick);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<Participant> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

