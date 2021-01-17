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
    std::string name;
    unsigned region = 0;
    unsigned score;
};

std::istream& operator >>(std::istream& input, Participant& v)
{
    return input >> v.name >> v.region >> v.score;
}

void answer(const Participant& x, const Participant& y)
{
    std::cout << x.name << ' ' << y.name << '\n';
}

void no_answer()
{
    std::cout << '?' << '\n';
}

void solve(std::vector<Participant>& p, size_t m)
{
    std::sort(p.begin(), p.end(), [](const Participant& a, const Participant& b) { return a.score > b.score; });

    std::vector<std::vector<Participant>> t(m);
    for (const Participant& q : p)
        t[q.region-1].push_back(q);

    for (size_t i = 0; i < m; ++i) {
        if (t[i].size() == 2 || t[i][2].score < t[i][1].score)
            answer(t[i][0], t[i][1]);
        else
            no_answer();
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<Participant> p(n);
    std::cin >> p;

    solve(p, m);

    return 0;
}

