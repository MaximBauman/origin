#include "my_list.h"
#include "catch_amalgamated.hpp"

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
        REQUIRE_THROWS_WITH(new_list.PopBack(), "list is empty");
        REQUIRE_THROWS_WITH(new_list.PopFront(), "list is empty");

        //try {
        //    new_list.PopBack();
        //    new_list.PopFront();
        //}
        //catch (const std::runtime_error& ex) {
        //    CHECK(std::string(ex.what()) == "list is empty");
        //}
    }

}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
    return 0;
}