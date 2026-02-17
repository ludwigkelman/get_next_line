#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*get_next_line(int fd);

void	test_file(char *filename)
{
	int	fd;
	char	*line;
	int	i;

	i = 1;
	printf("===== TESTING: %s ======\n", filename);
	
	fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		printf("Error opening file\n");
		return ;
	}

	while((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", i++, line);
		free(line);
	}
	
	close(fd);
	printf("\n");
}

int main(void)
{
	test_file("tests/empty.txt");
	test_file("tests/one_line.txt");
	test_file("tests/multiple_lines.txt");
	test_file("tests/only_newlines.txt");
	test_file("tests/long_line.txt");
	test_file("tests/only_onenewline.txt");

	return 0;
}
