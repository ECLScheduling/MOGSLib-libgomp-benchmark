#pragma once

#include <mogslib.h>
#include <rts/rts_includes.h>
#include <omp.h>

class MOGSLibConnect {
public:
  MOGSLib::Adaptor adaptor;
  MOGSLib::Strategy strategy;

  MOGSLibConnect() {}
  ~MOGSLibConnect() {}

  void setOMP(MOGSLib::Load *loads, MOGSLib::UInt n) {
    adaptor.setTasks(loads, n);
    omp_mogslib_set_strategy(&strategy);
    omp_mogslib_set_input(&adaptor);
  }
};

MOGSLibConnect mogslib;