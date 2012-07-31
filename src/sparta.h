/* ----------------------------------------------------------------------
   SPARTA - Stochastic PArallel Rarefied-gas Time-accurate Analyzer
   http://sparta.sandia.gov
   Steve Plimpton, sjplimp@sandia.gov, Michael Gallis, magalli@sandia.gov
   Sandia National Laboratories

   Copyright (2012) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level SPARTA directory.
------------------------------------------------------------------------- */

#ifndef SPARTA_SPARTA_H
#define SPARTA_SPARTA_H

#include "stdio.h"

namespace SPARTA_NS {

class SPARTA {
 public:

  // fundamental SPARTA classes

  class Memory *memory;          // memory allocation functions
  class Error *error;            // error handling
  class Universe *universe;      // universe of processors
  class Input *input;            // input script processing
                                 // ptrs to top-level SPARTA-specific classes
  class Particle *particle;      // particles
  class Update *update;          // timestepper
  class Comm *comm;              // inter-processor communication
  class Domain *domain;          // simulation box
  class Modify *modify;          // fixes and computes
  class Grid *grid;              // volumetric grid cells
  class Surf *surf;              // surface elements
  class Collide *collide;        // collisions and chemistry
  class Output *output;          // stats/dump/restart
  class Timer *timer;            // CPU timing info

  MPI_Comm world;                // MPI communicator
  FILE *infile;                  // infile
  FILE *screen;                  // screen output
  FILE *logfile;                 // logfile

  char *suffix;                  // suffix to add to input script style names
  int suffix_enable;             // 1 if suffix enabled, 0 if disabled
  class Cuda *cuda;              // CUDA accelerator class

  // other top-level SPARTA classes and variables

  //class RanMars *ranmaster;      // master RN generator

  SPARTA(int, char **, MPI_Comm);
  ~SPARTA();
  void create();
  void init();
  void destroy();

  void print_styles();
};

}

#endif

/* ERROR/WARNING messages:

E: Invalid command-line argument

One or more command-line arguments is invalid.  Check the syntax of
the command you are using to launch SPARTA.

E: Cannot use -reorder after -partition

UNDOCUMENTED

E: Processor partitions are inconsistent

The total number of processors in all partitions must match the number
of processors SPARTA is running on.

E: Must use -in switch with multiple partitions

A multi-partition simulation cannot read the input script from stdin.
The -in command-line option must be used to specify a file.

E: Can only use -pscreen with multiple partitions

UNDOCUMENTED

E: Can only use -plog with multiple partitions

UNDOCUMENTED

E: Cannot open universe screen file

For a multi-partition run, the master screen file cannot be opened.
Check that the directory you are running in allows for files to be
created.

E: Cannot open log.sparta

UNDOCUMENTED

E: Cannot open universe log file

For a multi-partition run, the master log file cannot be opened.
Check that the directory you are running in allows for files to be
created.

E: Cannot open input script %s

Self-explanatory.

E: Cannot open screen file

The screen file specified as a command-line argument cannot be
opened.  Check that the directory you are running in allows for files
to be created.

E: Cannot open logfile

The SPARTA log file named in a command-line argument cannot be opened.
Check that the path and name are correct.

E: Smallint setting in sptype.h is invalid

UNDOCUMENTED

E: Bigint setting in sptype.h is invalid

UNDOCUMENTED

E: MPI_SPARTA_BIGINT and bigint in sptype.h are not compatible

UNDOCUMENTED

E: Small,big integers are not sized correctly

UNDOCUMENTED

*/