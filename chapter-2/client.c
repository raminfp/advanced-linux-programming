#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* server_name = getenv("SERVER_NAME");

	if (server_name == NULL)
		// the SERVER_NAME environment variable was not set. use the default.
		server_name = "server.my-company.com";

	printf("accessing server %s\n", server_name);
	// access erver here...

	return 0;
}