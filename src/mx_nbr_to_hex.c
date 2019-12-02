#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	int hex_num_len = 0;
	char hex_digits[] = {'0', '1', '2', '3', '4', '5', '6'
							, '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	char buffer[16];

	if (nbr == 0) return "0";

	for (unsigned long i = nbr; i > 0; i /= 16, hex_num_len++)
		buffer[hex_num_len] = hex_digits[i%16];

	for (int i = 0, j = hex_num_len - 1; i < j; i++, j--)
		mx_swap_char(&buffer[i], &buffer[j]);

	return mx_strncpy(mx_strnew(hex_num_len), buffer, hex_num_len);
}
