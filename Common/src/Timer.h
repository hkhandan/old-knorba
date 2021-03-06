/*---[Logger.h]------------------------------------------------m(._.)m-------*\
|
|  KnoRBA Common
|
|  Copyright (c) 2013, RIKEN (The Institute of Physical and Chemial Research)
|  All rights reserved.
|
|  Author: Hamed KHANDAN (hkhandan@ieee.org)
|
|  This file is distributed under the KnoRBA Free Public License. See
|  LICENSE.TXT for details.
|
*//////////////////////////////////////////////////////////////////////////////

/** 
 *
 * @file
 * This file defines interface for `org::knorba::common::Timer` class.
 *
 */

#ifndef ORG_KNORBA_COMMON_TIMER_H
#define ORG_KNORBA_COMMON_TIMER_H

#include "common.h"
#include "Streamer.h"
#include <ctime>
#include <cmath>
#ifdef K_UNIX
#  include <sys/time.h>
#else
#  error "Only UNIX/Linux is supported"
#endif

using namespace std;

namespace org {
namespace knorba {
namespace common {

/**
 * Utility class to measure program execution time. It keeps elapsed time and
 * the CPU time consumed by the process. This class implements `Streamer` so
 * it can be used directly with `Logger` in KnoRBA Common, and standard
 * `ostream`. 
 *
 *     Timer t;
 *     t.start();
 *     ... do whatever you want to measure here ...
 *     LOG << t << EL;
 */

class Timer : public Streamer {
private:
  clock_t        _clockBase;
  struct timeval _timeBase;
  string         _name;

public:
  /** Constructs a `Timer` object with no name. */
  Timer();

  /** 
   * Constructs a `Timer` object with the given name.
   *
   * @param name The name to be given to the timer.
   */
  Timer(string name);

  /** 
   * Starts the timer 
   */
  void start();

  /** 
   * Determines wheather timer is started or not.
   *
   * @return `true` if the timer is started. 
   */ 
  bool isStarted();

  /** 
   * Returns the elapsed time since `start()` is called in seconds with
   * microseconds precision.
   *
   * @return Elapsed time
   */
  double get();

  /**
   * Returnes the amount of CPU time spent for this process since `start()` is
   * called in seconds with miliseconds precision.
   *
   * @return Consumed CPU time.
   */
  double getCpuTime();

  /**
   * Prints a string representation of this object to the given output stream.
   */
  virtual void printToStream(ostream& os);
};

} // namespace common
} // namespace knorba
} // namespace org

#endif
