#include <stdio.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BT_BUF_SIZE 100

void std_backtrace(void)
{
	int nptrs;
	void *buffer[BT_BUF_SIZE];
	char **strings;

	nptrs = backtrace(buffer, BT_BUF_SIZE);
	printf("backtrace() returned %d addresses\n", nptrs);

	/* The call backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO)
	   would produce similar output to the following: */

	strings = backtrace_symbols(buffer, nptrs);
	if (strings == NULL)
	{
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
	}

	for (int j = 1; j < nptrs; j++)
		printf("%s\n", strings[j]);

	free(strings);
}


void my_backtrace()
{
	void **fp = __builtin_frame_address(0);
	void *ra = __builtin_return_address(0);
	void **next_fp = 0;

	for (int i = 0;; ++i)
	{
		//printf("[%d] fp: %p\n", i, fp);
		printf("[%d] ra: %p\n", i, ra);

		next_fp = *fp;

		if (next_fp <= fp)
			break;

		fp = next_fp;
		ra = *(fp + 1);
	}
}

void f2()
{
        printf("my_backtrace:\n");
	my_backtrace();

        printf("\nstd_backtrace:\n");
        std_backtrace();
}

void f1()
{
	f2();
}

int main()
{
	f1();
}