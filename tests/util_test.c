/*
 * Copyright (C) 2018  Lucas S. Vieira
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * util.h UNIT TESTS
 */

#include <stdlib.h>

#include <util.h>
#include <types.h>
#include <acutest.h>

typedef struct test_struct_ {
    double key;
    long int value;
} test_struct_;

bool test_compare_(node *first, node *second) {
    test_struct_ *first_data = (test_struct_ *) first->data;
    test_struct_ *second_data = (test_struct_ *) second->data;

    return first_data->value > second_data->value;
}


void test_init(void) {
    test_struct_ *ptr = init(ptr);
    TEST_CHECK(ptr != NULL);

    ptr->key = 4.5;
    ptr->value = 10;

    TEST_CHECK((bool) ptr->key);
    TEST_CHECK((bool) ptr->value);
}

void test_new_node(void) {
    test_struct_ *ptr = init(ptr);
    ptr->key = 5.2;
    ptr->value = 10;

    node *node_ptr = new_node(ptr, NULL);

    TEST_CHECK(node_ptr != NULL);

    // Check values
    test_struct_ *node_data = (test_struct_ *) node_ptr->data;

    double node_key = node_data->key;
    long int node_value = node_data->value;

    TEST_CHECK(ptr->key == node_key);
    TEST_CHECK(ptr->value == node_value);

    // Pointer
    TEST_CHECK(node_ptr->pointer == NULL);
}

void test_node_compare(void) {
    test_struct_ *first_data_ptr = init(first_data_ptr);
    first_data_ptr->key = 5.2;
    first_data_ptr->value = 10;

    node *first_ptr = new_node(first_data_ptr, NULL);

    test_struct_ *second_data_ptr = init(second_data_ptr);
    second_data_ptr->key = 5.2;
    second_data_ptr->value = 15;

    node *second_ptr = new_node(second_data_ptr, NULL);

    // Must return false
    TEST_CHECK(!node_compare(first_ptr, second_ptr, test_compare_));

    // Must return true
    TEST_CHECK(node_compare(second_ptr, first_ptr, test_compare_));
}

/*
 * Tests list
 */
TEST_LIST = {
        {"test_init",         test_init},
        {"test_new_node",     test_new_node},
        {"test_node_compare", test_node_compare},
        {0}
};