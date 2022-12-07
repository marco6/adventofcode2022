#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <memory>
#include <utility>

struct dir;

struct dir {
    size_t size{0};
    std::unordered_map<std::string, std::unique_ptr<dir>> dirs;
    dir *parent{nullptr};

    auto& subdir(const std::string& f) {
        auto& res = dirs[f];
        if (!res) {
            res.reset(new dir{});
            res->parent = this;
        }
        return *res;
    }

    void add_file(size_t s) {
        size += s;
        if (this != this->parent) {
            this->parent->add_file(s);
        }
    }
};

dir* cd(dir& root, dir& wd, const std::string& folder) {
    if (folder == "..") {
        return wd.parent;
    } else if (folder == ".") {
        return &wd;
    } else if (folder == "/") {
        return &root;
    } else {
        return &wd.subdir(folder);
    }
}

template <typename F>
void visit(dir& d, F&& f) {
    f(d);
    for (auto& dir : d.dirs) {
        visit(*dir.second, std::forward<F&&>(f));
    }
}

int main() {
    dir root;
    root.parent = &root;

    dir* wd = &root;

    std::string command;

    while (std::cin >> command) {
        if (command == "$") {
            std::cin >> command;
            if (command == "cd") {
                std::cin >> command;
                wd = cd(root, *wd, command);
            }
        } else if (command == "dir") {
            std::cin >> command;
            wd->subdir(command);
        } else {
            auto size = stoul(command);
            std::cin >> command;
            wd->add_file(size);
        }
    }

    // Now visit them all
    size_t smallest = root.size;
    size_t available = 70000000 - root.size;
    size_t target = 30000000 - available;
    visit(root, [&](dir& d) { if (d.size >= target) { smallest = std::min(smallest, d.size); } });
    
    std::cout << smallest << std::endl;
}
