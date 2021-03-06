/*---[Streamer.h]----------------------------------------------m(._.)m-------*\
|
|  KnoRBA Common / Streamer
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
 * Defines the interface of `org::knorba::common::Streamer` class
 *
 */

#ifndef ORG_KNORBA_COMMON_STRINGSTREAMER
#define ORG_KNORBA_COMMON_STRINGSTREAMER

#include <sstream>
#include <string>

using namespace std;

namespace org {
namespace knorba {
namespace common {

/**
 * Base class for all classes that can print information about themeselves
 * to a `std::ostream`. Subclasses should implement `printToStream(ostream&)`
 * pure virtual function. This class defines and implements `toString()` 
 * function which internally invokes `printToStream(ostream&)` feeding it with
 * `std::stringstream`.
 *
 * @see operator<<(ostream&, Streamer&)
 */

class Streamer {
public:
 /**
  * Prints information related to the implementing class into the given
  * output stream.
  */
  virtual void printToStream(ostream& stream) = 0;

 /**
  * Converts the result of invocation of `printToStream(ostream&)` to a
  * `std::string` object. 
  */
  string toString();
};

/**
 * Overloads `<<` operator so that any `Streamer` object can be directly
 * used within standard `ostream` object like `cout`.
 */
ostream& operator<<(ostream& os, Streamer& streamer);

} // common
} // knorba
} // org

#endif
