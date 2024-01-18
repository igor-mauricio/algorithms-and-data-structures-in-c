#include "unity.h"
#include "../doubly_linked_list.h"

void setUp(void) {
}

void tearDown(void) {
}

void dummy_test(void){
    return;
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(dummy_test);

    return UNITY_END();
}
