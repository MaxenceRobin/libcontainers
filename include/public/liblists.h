/**
 * @author Maxence ROBIN
 * @brief Provides simple doubly-linked list manipulation
 */

#ifndef LIB_LISTS_H
#define LIB_LISTS_H

/* Includes ------------------------------------------------------------------*/

#include "libiterators.h"
#include "libtypes.h"

#include <sys/types.h>

/* Definitions ---------------------------------------------------------------*/

struct list;

/* API -----------------------------------------------------------------------*/

/**
 * @brief Creates an empty list of 'type'.
 *
 * @return Pointer to the created list on success.
 * @return NULL if 'type' is invalid.
 * @return NULL if for 'type', 'size' is 0, 'copy' or 'destroy' are invalid.
 */
struct list *list_create(const struct type_info *type);

/**
 * @brief Destroys 'list'.
 */
void list_destroy(const struct list *list);

/**
 * @brief Adds 'value' at the beginning of 'list'.
 *
 * @return 0 on success.
 * @return -EINVAL if 'list' or 'value' are invalid.
 * @return -ENOMEM if on failure.
 */
int list_push_front(struct list *list, const void *value);

/**
 * @brief Adds 'value' at the end of 'list'.
 *
 * @return 0 on success.
 * @return -EINVAL if 'list' or 'value' are invalid.
 * @return -ENOMEM on failure.
 */
int list_push_back(struct list *list, const void *value);

/**
 * @brief Inserts 'value' inside 'list' at the position pointed by 'it'.
 * 'it' points to the newly inserted value after the call.
 *
 * @return 0 on success.
 * @return -EINVAL if 'list', 'it' or 'value' are invalid.
 * @return -ENOMEM on failure.
 */
int list_insert(struct list *list, struct iterator *it, const void *value);

/**
 * @brief Removes the first element of 'list'.
 *
 * @return 0 on success.
 * @return -EINVAL if 'list' is invalid.
 */
int list_pop_front(struct list *list);

/**
 * @brief Removes the last element of 'list'.
 *
 * @return 0 on success.
 * @return -EINVAL if 'list' is invalid.
 */
int list_pop_back(struct list *list);

/**
 * @brief Returns the number of elements inside 'list'.
 *
 * @return The number of elements inside 'list' on success.
 * @return -EINVAL if 'list' is invalid.
 */
ssize_t list_len(const struct list *list);

/* Iterator API --------------------------------------------------------------*/

/**
 * @brief Creates an iterator over the first element of 'list'.
 *
 * @return Pointer to the iterator on success.
 * @return NULL if 'list' is invalid or on failure.
 */
struct iterator *list_begin(const struct list *list);

/**
 * @brief Creates an iterator over the last element of 'list'.
 *
 * @return Pointer to the iterator on success.
 * @return NULL if 'list' is invalid or on failure.
 */
struct iterator *list_end(const struct list *list);

/**
 * @brief Creates a reverse iterator over the last element of 'list'.
 *
 * @return Pointer to the iterator on success.
 * @return NULL if 'list' is invalid or on failure.
 */
struct iterator *list_rbegin(const struct list *list);

/**
 * @brief Creates a reverse iterator over the first element of 'list'.
 *
 * @return Pointer to the iterator on success.
 * @return NULL if 'list' is invalid or on failure.
 */
struct iterator *list_rend(const struct list *list);

#endif /* LIB_LISTS_H */
