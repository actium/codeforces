#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Command {
    std::string t;
    int k;
};

std::istream& operator >>(std::istream& input, Command& c)
{
    std::cin >> c.t;
    return c.t != "defragment" ? input >> c.k : input;
}

class MemoryManager {
public:
    explicit MemoryManager(size_t m)
        : last_block_id_(0)
    {
        blocks_.emplace_back(0, m);
    }

    void allocate(size_t k)
    {
        for (auto it = blocks_.begin(); it != blocks_.end(); ++it) {
            if (it->first == 0 && it->second >= k) {
                if (it->second > k) {
                    blocks_.emplace(std::next(it), 0, it->second - k);
                    it->second = k;
                }

                it->first = ++last_block_id_;
                std::cout << last_block_id_ << '\n';
                return;
            }
        }

        std::cout << "NULL" << '\n';
    }

    void release(int x)
    {
        for (auto it = blocks_.begin(); it != blocks_.end(); ++it) {
            if (it->first != 0 && it->first == x) {
                it->first = 0;
                if (std::next(it) != blocks_.end() && std::next(it)->first == 0) {
                    it->second += std::next(it)->second;
                    blocks_.erase(std::next(it));
                }
                if (it != blocks_.begin() && std::prev(it)->first == 0) {
                    it->second += std::prev(it)->second;
                    blocks_.erase(std::prev(it));
                }
                return;
            }
        }

        std::cout << "ILLEGAL_ERASE_ARGUMENT" << '\n';
    }

    void defragment()
    {
        size_t m = 0;
        for (auto it = blocks_.begin(); it != blocks_.end(); ) {
            if (it->first == 0) {
                m += it->second;
                it = blocks_.erase(it);
            } else {
                ++it;
            }
        }

        if (m != 0)
            blocks_.emplace_back(0, m);
    }

private:
    std::list<std::pair<unsigned, size_t>> blocks_;

    unsigned last_block_id_;

}; // class MemoryManager

void solve(size_t m, const std::vector<Command>& c)
{
    MemoryManager mm(m);
    for (const Command& q : c) {
        if (q.t == "alloc")
            mm.allocate(q.k);

        if (q.t == "erase")
            mm.release(q.k);

        if (q.t == "defragment")
            mm.defragment();
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t, m;
    std::cin >> t >> m;

    std::vector<Command> c(t);
    std::cin >> c;

    solve(m, c);

    return 0;
}
