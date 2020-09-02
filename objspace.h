#include <stdlib.h>
#include "stddef.h"

typedef struct rb_objspace
{
    struct
    {
        size_t limit;
        size_t increase;
    } malloc_params;

    struct
    {
        unsigned int mode : 2;
        unsigned int immediate_sweep : 1;
        unsigned int dont_gc : 1;
        unsigned int dont_incremental : 1;
        unsigned int during_gc : 1;
        unsigned int during_compacting : 1;
        unsigned int gc_stressful : 1;
        unsigned int has_hook : 1;
        unsigned int during_minor_gc : 1;
    } flags;

    //rb_event_flag_t hook_events;
    //size_t total_allocated_objects;
    //VALUE next_object_id;

    //rb_heap_t eden_heap;
    //rb_heap_t tomb_heap;

    /*
    struct
    {
        rb_atomic_t finalizing;
    } atomic_flags;

    struct mark_func_data_struct
    {
        void *data;
        void (*mark_func)(VALUE v, void *data);
    } * mark_func_data;

    mark_stack_t mark_stack;
    size_t marked_slots;

    size_t garbage_slots;

    struct
    {
        struct heap_page **sorted;
        size_t allocated_pages;
        size_t allocatable_pages;
        size_t sorted_length;
        RVALUE *range[2];
        size_t freeable_pages;

        size_t final_objects;
        VALUE deferred_final;
    } heap_pages;

    st_table *finalizer_table;


    struct
    {
        int run;
        int latest_gc_info;
        gc_profile_record *records;
        gc_profile_record *current_record;
        size_t next_index;
        size_t size;

        double invoke_time;

        size_t minor_gc_count;
        size_t major_gc_count;
        size_t compact_count;

        double gc_sweep_start_time;
        size_t total_allocated_objects_at_gc_start;
        size_t heap_used_at_gc_start;

        size_t count;
        size_t total_freed_objects;
        size_t total_allocated_pages;
        size_t total_freed_pages;
    } profile;
    struct gc_list *global_list;
    */

    VALUE gc_stress_mode;

    struct
    {
        VALUE parent_object;
        int need_major_gc;
        size_t last_major_gc;
        size_t uncollectible_wb_unprotected_objects;
        size_t uncollectible_wb_unprotected_objects_limit;
        size_t old_objects;
        size_t old_objects_limit;
    } rgengc;
} rb_objspace_t;

rb_objspace_t rb_objspace;

rb_objspace_t * rb_objspace_alloc(void);
