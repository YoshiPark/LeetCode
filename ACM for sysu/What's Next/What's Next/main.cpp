#include <stdio.h>
int main() {
	long long a, b, c;
	while (scanf("%lld %lld %lld", &a, &b, &c) != EOF) {
		if (a == 0 && b == 0 && c == 0) break;
		long long arithmetic1 = b - a;
		long long arithmetic2 = c - b;
		if (arithmetic1 == arithmetic2) {
			printf("AP %lld\n", c + arithmetic1);
		}
		else
		{
			double  geometric1 = b / a;
			double  geometric2 = c / b;

			printf("GP %lld\n", c * int(geometric1));
		}
		
	}
	return 0;
}