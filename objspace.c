#include "objspace.h"

/* rb_objspace_alloc: Allocate and create the main objspace struct. In the main
CRuby code Ruby first creates a thread, and then a VM object attached to the
thread, and then creates a VM attached to the thread, then assigns objspace to
the VM. For simplicity here, we're just going to make objspace a global */
rb_objspace_t * rb_objspace_alloc(void)
{
    // First we need to malloc enough space to hold the entire objspace struct
    rb_objspace_t *objspace = calloc(1, sizeof(rb_objspace_t));

    // Now we set a malloc limit. This is used when we allocate new heap pages.
    // In the main interpreter
    objspace->malloc_params.limit = (16 * 1024 * 1024 /* 16MB */);

    // give back our objspace pointer
    return objspace;
}