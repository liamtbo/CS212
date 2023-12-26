/*
 * Liam Bouffard
 * CS212
 * 2D
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
	if (op[1]) { // checks if op has more then one letter
		IssueBadOperationError();
	} else if (*op == '+') {
		return ADD;
	} else if (*op == 'x') {
		return MULT;
	} else if (*op == '-') {
		return SUBTRACT;
	} else if (*op == '/') {
		return DIV;
	} else {
		return UNSUPPORTED;
	}
}


double StringToDouble(char *str) {
	int i = 0;
	double sign = 1.;
	double result_left = 0.; // the left side of the decimal
	double result_right = 0.; // the right side of the decimal

	// check if signed
	if (str[i] == '-') {
		sign = -1.;
		i++;
	}
	while (str[i] != '\0')  {

		if (str[i] == '.') {

			i++;
			int dec_place_c = 0;
			// while str[i] isn't on end character \0
			while (str[i] != '\0') {

				if (str[i] == '.') { // should only be one decimal total
					IssueBadNumberError();
				}

				if (str[i] < '0' || str[i] > '9') {
					IssueBadNumberError();
				}

				// make shift power function
				dec_place_c += 1;
				double  multiplier = .10;
				for (int j = 1; j < dec_place_c; j++) {
					multiplier *= .10;
				}
				// adds the next number one place to the right of previous
				result_right +=  multiplier * (str[i] - '0');
				i++;
			}
		break;
		}

		// check if number
		if (str[i] < '0' || str[i] > '9') {
			IssueBadNumberError();
		}

		// multiple old digit by 10 and then add new digit to it
		result_left = result_left * 10.0 + (str[i] - '0');	
		i++;
	}
	// printf("%lf\n%lf\n", result_right, result_left);
	return (result_right + result_left) * sign;
}



int main(int argc, char *argv[])
{
    printf("%s\n", argv[2]);
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
       case ADD:
         result = v+v2;
         break;
       case MULT:
	 result = v*v2;
	 break;
       case SUBTRACT:
	 result = v-v2;
	 break;
       case DIV:
	 result = v/v2;
	 break;
       case UNSUPPORTED:
	 IssueBadOperationError();
	
    }
    printf("%d\n", (int) result);
 
    return 0;
}
