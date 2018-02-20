#ifndef __MOGSLIB_H__
#define __MOGSLIB_H__

#ifdef __cplusplus
extern "C" {
#endif

extern void input_set_PE_count(void*, unsigned);
extern void input_set_chunksize(void* input, unsigned chunksize);
extern unsigned *strategy_map_tasks(void*, void*);

#ifdef __cplusplus
}
#endif

#endif