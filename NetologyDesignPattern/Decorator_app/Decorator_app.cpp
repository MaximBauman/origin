#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public: 
    explicit Paragraph(Text* text) : DecoratedText(text) {};
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public: 
    explicit Reversed(Text* text) : DecoratedText(text) {};
    void render(const std::string& data) const {
        std::string r_text = data;
        std::cout << "Reversed text: ";
        std::reverse(r_text.begin(), r_text.end());
        text_->render(r_text);
    }
};
class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {};
    void render(const std::string& url, const std::string& data) const {
        std::cout << "<a href='" << url << "'>";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    std::cout << std::endl;

    auto reverced_text = new Reversed(new Text());
    reverced_text->render("How are you?");
    std::cout << std::endl;

    auto linked_text = new Link(new Text());
    linked_text->render("https://lenta.ru/", "lenta.ru");
}