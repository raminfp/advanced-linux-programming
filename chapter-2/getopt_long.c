#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

// name of this program
const char* program_name;

// prints usage information for this program to STREAM (typically stdout
// or stderr), and exit the program with EXIT_CODE.  Does not return.

void print_usage(FILE* stream, int exit_code)
{
	fprintf(stream, "Usage: %s options [ inputfile ...]\n", program_name);
	fprintf(stream,
			"  -h  --help             Display this usage information.\n"
			"  -o  --output filename  Write output to file.\n"
			"  -v  --verbose          Print verbose messages.\n"
		);
	exit(exit_code);
}

// main program entry point.  ARGC contains number of argument list elements.
// ARGV is an array of pointers to them.

int main (int argc, char* argv[])
{
	int next_option;

	// a string listing valid short options letters
	const char* const short_options = "ho:v";

	// an array describing valid long options
	const struct option long_options[] = {
		{ "help", 0, NULL, 'h' },
		{ "output", 1, NULL, 'o' },
		{ "verbose", 0, NULL, 'v' },
		{ NULL, 0, NULL, 0 }  // required at end of array
	};

	// the name of the file to receive program output, or NULL for standard output
	const  char* output_filename = NULL;

	// whether to display verbose messages
	int verbose = 0;

	// remember the name of the program, to incorporate into messages
	// the name is stored in argv[0]
	program_name = argv[0];

	do
	{
		next_option = getopt_long (argc, argv, short_options, long_options, NULL);

		switch (next_option)
		{
			case 'h':  // -h or --help
				// user has requested usage information
				print_usage(stdout, 0);
				break;

			case 'o':  // -o or --output
				// this option takes an argument, the name of the output file
				output_filename = optarg;
				break;

			case 'v':  // -v or --verbose
				verbose = 1;
				break;

			case '?':  // user specified an invalid option
				// print usage information to standard error
				print_usage(stderr, 1);
				break;

			case -1:  // done with options
				break;

			default:  // something unexpected
				abort();
		}
	}
	while (next_option != -1);

	// done with options.  OPTIND points to first nonoption argument.
	// For demonstration purposes, print them if the verbose option was specified

	if (verbose)
	{
		int i;
		for (i = optind; i < argc; ++i)
			printf("Argument: %s\n", argv[i]);

		// the main program goes here

		return 0;
	}
}