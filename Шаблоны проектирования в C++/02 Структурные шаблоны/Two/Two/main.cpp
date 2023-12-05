#include <iostream>
#include <algorithm>

class VeryHeavyDatabase {
public:
    virtual std::string GetData(const std::string& key) const {
        return "value";
    }
};

class OneShotDB : public VeryHeavyDatabase {
private:
    VeryHeavyDatabase* real_object;
    size_t sLeft;

public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1)
        : real_object(real_object), sLeft(shots) {}

    std::string GetData(const std::string& key) {
        if (sLeft > 0) {
            --sLeft;
            return real_object->GetData(key);
        } else {
            return "ERROR";
        }
    }
};

class Cont {
public:
    virtual void render(const std::string& str) const {
        std::cout << str;
    }
};

class Paragraph : public Cont {
public:
    void render(const std::string& content) const override {
        std::cout << "<p>" << content << "</p>";
    }
};

class Reversed : public Cont {
public:
    void render(const std::string& content) const override {
        std::string reversedContent = content;
        std::reverse(reversedContent.begin(), reversedContent.end());
        std::cout << reversedContent;
    }
};

class Link : public Cont {
public:
    void render(const std::string& link, const std::string& content) const {
        std::cout << "<a href=" << link << ">" << content << "</a>";
    }
};

int main() {
    VeryHeavyDatabase real_db;
    OneShotDB limit_db(&real_db, 2);

    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;

    auto text_block = new Paragraph();
    text_block->render("Hello world");

    auto reversed_block = new Reversed();
    reversed_block->render("Hello world");

    auto link_block = new Link();
    link_block->render("site", "Hello world");

    delete text_block;
    delete reversed_block;
    delete link_block;

    return 0;
}

