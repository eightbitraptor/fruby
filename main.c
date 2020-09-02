/* This project contains a heavily commented version of the memory management
code from Ruby (circa v2.7/3.0). */

/* This just contains standard defs that other parts of Ruby uses */
#include "stddef.h"

/* In the main CRuby implementation, pretty much all of this code lives in gc.c -
we've extracted it here to make it a bit easier to read.
*/
#include "objspace.h"

/* Init_heap This is the main heap initialisation code. Ruby runs this as part
of the main interpreter startup routines. This is basically the third thing
that's done. First we initialise the stack, then we setup the bare vm, then we
initialise the heap, and then we go on to initialise the GC, and then all the
other parts of the VM like True, False, Null, Hash, Array etc
*/
void Init_heap()
{
    // Claim a pointer to our main Object space. This is a struct that holds
    // pointers to all the various heaps, and keeps track of information about
    // how and when GC has been run and what objects are live in the system
    rb_objspace_t *objspace = rb_objspace_alloc();
}

int main()
{
    Init_heap();
}