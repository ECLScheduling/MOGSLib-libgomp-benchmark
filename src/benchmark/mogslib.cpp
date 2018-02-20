#include <rts/rts_includes.h>

#ifdef RTS_IS_OPENMP

#include <mogslib.h>

/**
 * TODO: The following flags are a remedy for the problem of setting the adaptor and strategy.
 * As it is currently implemented, there are still changes to be made in this file and possibly inside OpenMP before full support. 
 * A possible and elegant way to proper configure this file's include and pre-processor directives is to work on the pre-processing script,
 * currently configure.sh, to better address the problem of selecting the strategy, the target system and which information to use from within.
 * For now this is cumbersome but can already be used as a proof of concept that portability is do-able, yet not simple.
 */
#define USE_OMP_CHUNK_SIZE

struct OMP_Data {
  unsigned omp_chunk_size;
};
OMP_Data omp_data;

void call_pe_count(void *obj, unsigned npe) {
  static_cast<MOGSLib::Adaptor*>(obj)->setPECount(npe);
}

void call_set_structure(void *obj, unsigned chunksize) {
  omp_data.omp_chunk_size = chunksize;

  //TODO: This definition is problematic as is. For now it works, but a pre-compiler must properly set it.
  #ifdef USE_OMP_CHUNK_SIZE
  static_cast<MOGSLib::Adaptor*>(obj)->setStructure(chunksize);
  #endif
}

unsigned *call_strategy_map(void *obj, void *arg) {
  return static_cast<MOGSLib::Strategy*>(obj)->mapTasks(static_cast<MOGSLib::Adaptor*>(arg));
}

extern "C" {

void input_set_PE_count(void* input, unsigned npe) {
  call_pe_count(input, npe);
}

void input_set_chunksize(void* input, unsigned chunksize) {
  call_set_structure(input, chunksize);
}

unsigned *strategy_map_tasks(void* strategy, void* input) {
  return call_strategy_map(strategy, input);
}

}

#endif // RTS_IS_OPENMP