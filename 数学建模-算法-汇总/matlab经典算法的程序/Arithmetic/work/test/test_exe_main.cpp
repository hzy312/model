//
// MATLAB Compiler: 3.0
// Date: Thu Sep 02 20:52:11 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-p" "-W" "main" "-L"
// "Cpp" "-t" "-T" "link:exe" "-h" "libmmfile.mlib" "test_exe.m" 
//
#include "libmatlb.hpp"
#include "test_exe.hpp"

extern _mexcpp_information _main_info;

static mexFunctionTableEntry function_table[1]
  = { { "test_exe", mlxTest_exe, 0, 1, &_local_function_table_test_exe } };

static _mexcppInitTermTableEntry init_term_table[1]
  = { { InitializeModule_test_exe, TerminateModule_test_exe } };

_mexcpp_information _main_info
  = { 1, 1, function_table, 0, NULL, 0, NULL, 1, init_term_table };

//
// The function "main" is a Compiler-generated main wrapper, suitable for
// building a stand-alone application.  It calls a library function to perform
// initialization, call the main function, and perform library termination.
//
int main(int argc, const char * * argv) {
    return mwMain(argc, argv, mlxTest_exe, 1, &_main_info);
}
