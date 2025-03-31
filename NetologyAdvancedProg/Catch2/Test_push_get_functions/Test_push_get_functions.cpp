#include <iostream>
#include "catch_amalgamated.hpp"

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("test function's", "[Callback's ]") {
    List new_list;


    SECTION("Back functions test's") {
        new_list.PushBack(0);
        new_list.PushBack(230);
        INFO("PUSHBACK TEST");
        CHECK(new_list.Size() == 2);
        INFO("POPBACK TEST");
        CHECK(new_list.PopBack() == 230);
        CHECK(new_list.PopBack() == 0);

    }
    SECTION("Front functions test's") {
        new_list.PushFront(323);
        new_list.PushFront(21);
        INFO("PUSHFRONT TEST");
        CHECK(new_list.Size() == 2);
        INFO("POPFRONT TEST");
        CHECK(new_list.PopFront() == 21);
        CHECK(new_list.PopFront() == 323);
    }
    SECTION("Pop functions, clear list") {
        try {
            new_list.PopBack();
            new_list.PopFront();
        }
        catch (const std::runtime_error& ex) {
            CHECK(std::string(ex.what()) == "list is empty");
        }
    }

}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}