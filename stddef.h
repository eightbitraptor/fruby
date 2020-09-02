#include <stddef.h>

// Create a type VALUE, that is an unsigned long. Ruby uses VALUE as a pointer
// to refer to any kind of Ruby object (like RObject, RBasic etc)
typedef unsigned long VALUE;
