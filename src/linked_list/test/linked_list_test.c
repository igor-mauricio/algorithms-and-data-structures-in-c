#include "unity.h"
#include "../linked_list.h"

void setUp(void) {
}

void tearDown(void) {
}

void prepend_should_work(void) {
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        prepend(linkedList, &values[i]);
    }
    TEST_ASSERT_EQUAL_PTR(&values[3], linkedList->head->value);
    TEST_ASSERT_EQUAL_PTR(&values[2], linkedList->head->next->value);
    TEST_ASSERT_EQUAL_PTR(&values[1], linkedList->head->next->next->value);
    TEST_ASSERT_EQUAL_PTR(&values[0], linkedList->head->next->next->next->value);
    TEST_ASSERT_EQUAL_PTR(&values[0], linkedList->tail->value);

    TEST_ASSERT_EQUAL_INT(4, linkedList->size);
}

void append_should_work(void) {
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }
    TEST_ASSERT_EQUAL_PTR(&values[0], linkedList->head->value);
    TEST_ASSERT_EQUAL_PTR(&values[1], linkedList->head->next->value);
    TEST_ASSERT_EQUAL_PTR(&values[2], linkedList->head->next->next->value);
    TEST_ASSERT_EQUAL_PTR(&values[3], linkedList->head->next->next->next->value);
    TEST_ASSERT_EQUAL_PTR(&values[3], linkedList->tail->value);

    TEST_ASSERT_EQUAL_INT(4, linkedList->size);
}

void should_retrieve_head_and_tail(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }


    TEST_ASSERT_EQUAL_INT(values[0], *(int*)get_head(linkedList));
    TEST_ASSERT_EQUAL_INT(values[3], *(int*)get_tail(linkedList));
}

void should_get_a_specific_node_position_value(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    TEST_ASSERT_EQUAL_INT(values[2], *(int*)get(linkedList,2));
}

void pop_should_free_the_node(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    void *value = pop(linkedList);

    TEST_ASSERT_EQUAL_INT(3, linkedList->size);
    TEST_ASSERT_EQUAL_PTR(&values[2], linkedList->tail->value);
    TEST_ASSERT_EQUAL_PTR(&values[3], value);

}

void unshift_should_free_the_node(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    void *value = unshift(linkedList);

    TEST_ASSERT_EQUAL_INT(3, linkedList->size);
    TEST_ASSERT_EQUAL_PTR(&values[1], linkedList->head->value);
    TEST_ASSERT_EQUAL_PTR(&values[0], value);
}

void insert_into_should_create_node(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }
    int inserted_value = 10;

    insert_into(linkedList, &inserted_value, 2);

    TEST_ASSERT_EQUAL_INT(5, linkedList->size);
    TEST_ASSERT_EQUAL_PTR(&values[1], linkedList->head->next->value);
    TEST_ASSERT_EQUAL_PTR(&inserted_value, linkedList->head->next->next->value);
    TEST_ASSERT_EQUAL_PTR(&values[2], linkedList->head->next->next->next->value);
}


void remove_from_should_remove_node(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }
    void *returned_value = remove_from(linkedList, 2);

    TEST_ASSERT_EQUAL_INT(3, linkedList
    ->size);
    TEST_ASSERT_EQUAL_PTR(&values[1], linkedList->head->next->value);
    TEST_ASSERT_EQUAL_PTR(&values[2], returned_value);
    TEST_ASSERT_EQUAL_PTR(&values[3], linkedList->head->next->next->value);
}

void remove_from_initial_node(void) {
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for (int i = 0; i < 4; i++) {
        append(linkedList, &values[i]);
    }
    void *returned_value = remove_from(linkedList, 0);

    TEST_ASSERT_EQUAL_INT(3, linkedList->size);
    TEST_ASSERT_EQUAL_PTR(&values[1], linkedList->head->value);
    TEST_ASSERT_EQUAL_PTR(&values[0], returned_value);
    TEST_ASSERT_EQUAL_PTR(&values[2], linkedList->head->next->value);
}

void remove_from_last_node(void) {
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for (int i = 0; i < 4; i++) {
        append(linkedList, &values[i]);
    }

    void *returned_value = remove_from(linkedList, 3);

    TEST_ASSERT_EQUAL_INT(3, linkedList->size);
    TEST_ASSERT_EQUAL_PTR(&values[3], returned_value);
    TEST_ASSERT_EQUAL_PTR(&values[2], linkedList->tail->value);
}

void remove_from_should_return_null_if_index_is_out_of_bounds(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    void *returned_value = remove_from(linkedList, 4);
    TEST_ASSERT_EQUAL_PTR(NULL, returned_value);
}

void insert_into_should_return_null_if_index_is_out_of_bounds(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};
    int inserted_value = 10;

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    void *returned_value = insert_into(linkedList, &inserted_value, 4);
    TEST_ASSERT_EQUAL_PTR(NULL, returned_value);
}

void get_should_return_null_if_index_is_out_of_bounds(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    void *returned_value = get(linkedList, 4);
    TEST_ASSERT_EQUAL_PTR(NULL, returned_value);
}

void get_should_return_value_at_index(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};

    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    void *returned_value = get(linkedList, 2);
    TEST_ASSERT_EQUAL_PTR(&values[2], returned_value);
}

void get_head_should_get_head_value(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};
    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    void *returned_value = get_head(linkedList);
    TEST_ASSERT_EQUAL_PTR(&values[0], returned_value);
}

void get_tail_should_get_tail_value(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};
    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    void *returned_value = get_tail(linkedList);
    TEST_ASSERT_EQUAL_PTR(&values[3], returned_value);
}

void values_are_preserved_in_linked_list(void){
    LinkedList *linkedList = new_linked_list();
    int values[4] = {1, 2, 3, 5};
    for(int i=0; i < 4; i++){
        append(linkedList, &values[i]);
    }

    for(int i=0; i < 4; i++){
        TEST_ASSERT_EQUAL_INT(values[i], *(int*)get(linkedList, i));
    }
}



int main(void) {
    UNITY_BEGIN();
    RUN_TEST(prepend_should_work);
    RUN_TEST(append_should_work);
    RUN_TEST(should_retrieve_head_and_tail);
    RUN_TEST(should_get_a_specific_node_position_value);
    RUN_TEST(pop_should_free_the_node);
    RUN_TEST(unshift_should_free_the_node);
    RUN_TEST(remove_from_should_remove_node);
    RUN_TEST(remove_from_should_return_null_if_index_is_out_of_bounds);
    RUN_TEST(remove_from_initial_node);
    RUN_TEST(remove_from_last_node);
    RUN_TEST(insert_into_should_return_null_if_index_is_out_of_bounds);
    RUN_TEST(insert_into_should_create_node);
    RUN_TEST(get_should_return_null_if_index_is_out_of_bounds);
    RUN_TEST(get_should_return_value_at_index);
    RUN_TEST(get_head_should_get_head_value);
    RUN_TEST(get_tail_should_get_tail_value);
    RUN_TEST(values_are_preserved_in_linked_list);

    return UNITY_END();
}
