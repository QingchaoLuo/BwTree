#define BLOCK(){std::string c;std::cout << "...";std::cin >> c;}

enum class BwTreeCommandType : std::int8_t {
    insert,
    search
};

template<typename Key, typename Data>
struct BwTreeCommand {
    const BwTreeCommandType type;
    const Key key;
    const Data *data;

    BwTreeCommand(BwTreeCommandType const &type, Key const key, Data const *data) : type(type), key(key), data(data) {
    }
};

std::chrono::milliseconds createBwTreeCommands(const std::size_t numberOfThreads, const std::vector<unsigned long long> &values, const std::vector<unsigned long long> &initial_values, const std::size_t operations, const unsigned percentRead, BwTree::Tree<unsigned long long, unsigned long long> &tree, bool block);

void executeBwTreeCommands(const std::vector<std::vector<BwTreeCommand<unsigned long long, unsigned long long>>> &commands, BwTree::Tree<unsigned long long, unsigned long long> &tree);
