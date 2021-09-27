#ifndef add_h
#define add_h

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdint.h>

typedef struct String String;

typedef struct UUID4 {
  struct String *value;
} UUID4;

/**
 * Returns the current seconds since the UNIX epoch.
 */
double unix_timestamp(void);

/**
 * Returns the current milliseconds since the UNIX epoch.
 */
int64_t unix_timestamp_ms(void);

/**
 * Returns the current microseconds since the UNIX epoch.
 */
int64_t unix_timestamp_us(void);

/**
 * Returns the current nanoseconds since the UNIX epoch.
 */
int64_t unix_timestamp_ns(void);

struct UUID4 uuid4_new(void);

struct UUID4 uuid4_from_raw(const char *ptr);

const char *uuid4_to_raw(const struct UUID4 *self);

void uuid4_free_raw(char *ptr);

void uuid4_free(struct UUID4 uuid);

#endif /* add_h */
