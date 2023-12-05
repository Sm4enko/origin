#include <iostream>
#include <algorithm>

class Cont {
public:
    virtual void render(const std::string& str) const {
        std::cout << str;
    }
};

class Text : public Cont {
public:

    Text() {}
};

class Paragraph : public Cont {
public:
    void render(const std::string& str) const override {
        std::cout << "<p>" << str << "</p>";
    }
};

class Reversed : public Cont {
public:
    void render(const std::string& str) const override {
        std::string reversedContent = str;
        std::reverse(reversedContent.begin(), reversedContent.end());
        std::cout << reversedContent;
    }
};

class Link : public Cont {
private:
    std::string link;
public:
   
    Link(const std::string& link) : link(link) {}

    void render(const std::string& str) const {
        std::cout << "<a href=" << link << ">" << str << "</a>";
    }
};

int main() {
    auto text_block = new Paragraph();
    text_block->render("Hello world");

    auto reversed_block = new Reversed();
    reversed_block->render("Hello world");

    auto link_block = new Link("netology.ru");
    link_block->render("Hello world");

    delete text_block;
    delete reversed_block;
    delete link_block;

    return 0;
}

