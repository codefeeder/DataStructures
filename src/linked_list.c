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

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <util.h>
#include <types.h>
#include <linked_list.h>

#ifdef __cplusplus
extern "C" {
#endif

list *create_linked_list() {
    list *ptr = init(ptr);

    ptr->list = NULL;
    ptr->last = NULL;
    ptr->nodes = 0;

    return ptr;
}

bool is_empty_linked_list(list *ptr) {
    if (ptr->last != NULL && ptr->list == NULL) {
        return true;
    }

    return false;
}

#ifdef __cplusplus
};
#endif

#endif // LINKED_LIST_H
