#ifndef LANGPROC_COMPILER_CLI_H
#define LANGPROC_COMPILER_CLI_H

#include <unistd.h>

#include <iostream>

struct CommandLineArguments
{
    std::string compile_source_path;
    std::string compile_output_path;
};

CommandLineArguments ParseCommandLineArgs(int argc, char **argv);

#endif
