#ifndef __MOGSLIB_H__
#define __MOGSLIB_H__

#ifdef __cplusplus
extern "C" {
#endif

extern void mogslib_set_nPEs(unsigned nPEs);
extern void mogslib_set_chunksize(unsigned nchunks);

extern unsigned *mogslib_strategy_map();

#ifdef __cplusplus
}
#endif

#endif