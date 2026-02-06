#include <fstream>
#include <string>
#include <iostream>


class Printable {
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;
};


class TextData : public Printable {
public:
    explicit TextData(std::string data) : data_(std::move(data)) {};
    std::string print() const override { 
        return data_; 
    }
private:
    std::string data_;
};

class HTMLData : public Printable {
public:
    explicit HTMLData(std::string data) : data_(std::move(data)) {};
    std::string print() const override { 
        return "<html>" + data_ + "</html>"; 
    }
private:
    std::string data_;
};

class JSONData : public Printable {
public:
    explicit JSONData(std::string data) : data_(std::move(data)) {};
    std::string print() const override { 
        return "{ \"data\": \"" + data_ + "\"}"; 
    }
private:
    std::string data_;
};


void saveTo(std::ostream& file, const Printable& printable) {
    file << printable.print();
}

void saveToAsHTML(std::ostream& file, const HTMLData& printable) {
    saveTo(file, printable);
}

void saveToAsJSON(std::ostream& file, const JSONData& printable) {
    saveTo(file, printable);
}

void saveToAsText(std::ostream& file, const TextData& printable) {
    saveTo(file, printable);
}

int main() {
    HTMLData html("Hello world!");
    JSONData json("Hello world!");
    TextData text("Hello world!");

    std::ofstream outPutFile("test.txt");

    if (outPutFile.is_open()) {
        saveToAsHTML(outPutFile, html);
        saveToAsJSON(outPutFile, json);
        saveToAsText(outPutFile, text);
    }
    else {
        std::cout << "Can't open file!";
    }

    std::cout << "File created!" << std::endl;

    return 0;
}