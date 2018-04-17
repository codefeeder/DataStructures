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

#include <stdlib.h>
#include <stdbool.h>
#include <types.h>
#include <malloc.h>

#ifdef __cplusplus
extern "C" {
#endif

void *init(void *type) {
    return (typeof(type) *) malloc(sizeof(typeof(type)));
}

node *new_node(void *data, node *pointer) {
    node *element = init(element);
    element->data = data;
    element->pointer = pointer;

    return element;
}

bool node_compare(node *first, node *second, bool (*function)(node *, node *)) {

    if (function != NULL) {
        return (bool) function(first, second);
    }

    // Fallback to size
    return sizeof(first->data) > sizeof(second->data);
}

void *node_data(node *ptr) {
    return (typeof(ptr->data) *) ptr->data;
}

bool destroy(void *ptr) {
    free(ptr);
    realloc(ptr, 0);
    ptr = NULL;

    size_t res = malloc_usable_size(ptr);
    return true;
}

bool node_destroy(node *elem) {
    return destroy(elem->data) &&
           destroy(elem->pointer) && destroy(elem);
}

#ifdef __cplusplus
};
#endif