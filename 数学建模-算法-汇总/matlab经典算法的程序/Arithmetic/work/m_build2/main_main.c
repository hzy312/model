/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 22:04:33 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-m" "-W" "main" "-L"
 * "C" "-t" "-T" "link:exe" "-h" "libmmfile.mlib" "main.m" "my_rank.m"
 * "mrank.m" 
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#include "libmatlb.h"
#include "main.h"
#include "my_rank.h"
#include "mrank.h"
#include "libmmfile.h"

extern _mex_information _main_info;

static mexFunctionTableEntry function_table[3]
  = { { "main", mlxMain, 0, 0, &_local_function_table_main },
      { "my_rank", mlxMy_rank, 2, 1, &_local_function_table_my_rank },
      { "mrank", mlxMrank, 1, 1, &_local_function_table_mrank } };

static _mexInitTermTableEntry init_term_table[4]
  = { { libmmfileInitialize, libmmfileTerminate },
      { InitializeModule_main, TerminateModule_main },
      { InitializeModule_my_rank, TerminateModule_my_rank },
      { InitializeModule_mrank, TerminateModule_mrank } };

_mex_information _main_info
  = { 1, 3, function_table, 0, NULL, 0, NULL, 4, init_term_table };

/*
 * The function "main" is a Compiler-generated main wrapper, suitable for
 * building a stand-alone application.  It calls a library function to perform
 * initialization, call the main function, and perform library termination.
 */
int main(int argc, const char * * argv) {
    return mclMain(argc, argv, mlxMain, 0, &_main_info);
}
