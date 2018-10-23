#include <mogslib/mogslib.h>

/**
 * @brief Set the amount of chunks in the OpenMP RTS datastructure.
 * @details A C++ proxy function to set the chunksize data in OpenMP.
 * @param chunksize The amount of chunks generated in OpenMP.
 */
inline void mogslib_call_set_chunksize(unsigned chunksize) {
  MOGSLib::RTS::set_chunk_size(chunksize);
}

/**
 * @brief Set the amount of chunks in the OpenMP RTS datastructure.
 * @details A C++ proxy function to set the chunksize data in OpenMP.
 * @param chunksize The amount of chunks generated in OpenMP.
 */
inline void mogslib_call_set_nPEs(unsigned nPEs) {
  MOGSLib::RTS::set_nPEs(nPEs);
}

/**
 * @brief Set the amount of tasks in the OpenMP RTS datastructure.
 * @details A C++ proxy function to set the ntasks data in OpenMP.
 * @param ntasks The amount of tasks generated in OpenMP.
 */
inline void mogslib_call_set_ntasks(unsigned ntasks) {
  MOGSLib::RTS::set_ntasks(ntasks);
}

/**
 * @brief Call the scheduler within MOGSLib to obtain a task map.
 * @details A C++ proxy function to call the selected MOGSLib scheduler.
 * @return The task map represented as an array to where the task should execute.
 */
inline unsigned *mogslib_call_strategy_map() {
  return MOGSLib::SchedulerCollection::schedule();
}

extern "C" {

/**
 * @brief A function to interface with MOGSLib to register the amount of chunks in OpenMP.
 * @details A C function to interface with OpenMP and direct the execution flow back to C++.
 */
void mogslib_set_chunksize(unsigned chunksize) {
  mogslib_call_set_chunksize(chunksize);
}

/**
 * @brief A function to interface with MOGSLib to register the amount of PEs in OpenMP.
 * @details A C function to interface with OpenMP and direct the execution flow back to C++.
 */
void mogslib_set_nPEs(unsigned nPEs) {
  mogslib_call_set_nPEs(nPEs);
}

/**
 * @brief A function to interface with MOGSLib to register the amount of tasks in OpenMP.
 * @details A C function to interface with OpenMP and direct the execution flow back to C++.
 */
void mogslib_set_ntasks(unsigned ntasks) {
  mogslib_call_set_ntasks(ntasks);
}

/**
 * @brief A function to interface with MOGSLib to call the scheduler task mapping.
 * @details A C function to interface with OpenMP and direct the execution flow back to C++.
 */
unsigned *mogslib_strategy_map() {
  return mogslib_call_strategy_map();
}

}