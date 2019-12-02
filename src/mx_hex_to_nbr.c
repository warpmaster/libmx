#include "libmx.h"

static char mx_tolower(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c + 32;
	}
	return c;
}

unsigned long mx_hex_to_nbr(const char *hex) {
	int hex_len = mx_strlen(hex);
	char hex_digits[] = {'0', '1', '2', '3', '4', '5', '6'
							, '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned long dec_num = 0;

	for (int i = 0, power = hex_len - 1; i < hex_len; i++, power--) {
		for (int j = 0; j < 16; j++) {
			if (mx_tolower(hex[i]) == hex_digits[j])
				dec_num += j * mx_pow(16, power);
		}
	}
	return dec_num;
}
