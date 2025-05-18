CC = gcc
CFLAGS = -Wall -Wextra -pedantic -ansi

TARGETS = count_zero_bits palindrome

all: $(TARGETS)

count_zero_bits: count_zero_bits.c
	$(CC) $(CFLAGS) -o count_zero_bits count_zero_bits.c

palindrome: palindrome.c
	$(CC) $(CFLAGS) -o palindrome palindrome.c

clean:
	rm -f $(TARGETS)

