#ifndef __MOGSLIB_H__
#define __MOGSLIB_H__

#ifdef __cplusplus
extern "C" {
#endif

void input_set_PE_count(void*, unsigned);
void input_set_chunksize(void* input, unsigned chunksize);
unsigned *strategy_map_tasks(void*, void*);

#ifdef __cplusplus
}
#endif

#endif