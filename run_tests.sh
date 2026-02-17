#i/bin/bash

echo "Testing BUFFER_SIZE=1"
cc -Wall -Werror -Wextra -I. -fsanitize=address get_next_line.c get_next_line_utils.c gnl_tester.c -D BUFFER_SIZE=1 && ./a.out


echo "Testing BUFFER_SIZE=10"
cc -Wall -Werror -Wextra -I. -fsanitize=address get_next_line.c get_next_line_utils.c gnl_tester.c -D BUFFER_SIZE=10 && ./a.out | cat -e


echo "Testing BUFFER_SIZE=42"
cc -Wall -Werror -Wextra -I. -fsanitize=address get_next_line.c get_next_line_utils.c gnl_tester.c -D BUFFER_SIZE=42 && ./a.out | cat -e


echo "Testing BUFFER_SIZE=1000"
cc -Wall -Werror -Wextra -I. -fsanitize=address get_next_line.c get_next_line_utils.c gnl_tester.c -D BUFFER_SIZE=1000 && ./a.out | cat -e
