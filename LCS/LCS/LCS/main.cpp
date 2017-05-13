#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int top_down(char* x, char* y, int x_len, int y_len){	// a top-down memorized algorithm
	if (x_len == 0 || y_len == 0)
		return 0;
	if (x[x_len - 1] == y[y_len - 1])						// x = y
		return 1 + top_down(x, y, x_len - 1, y_len - 1);
	else{
		if (top_down(x, y, x_len - 1, y_len) > top_down(x, y, x_len, y_len - 1)) // find max
			return top_down(x, y, x_len - 1, y_len);
		else
			return top_down(x, y, x_len, y_len - 1);
	}
}
int** bottom_up(char* x, char* y, int** c, int** b, int x_len, int y_len){	// a bottom-up dynamic programming algorithm
	int i, j;		// index

	// initialize c and b
	for (i = 0; i < x_len; i++){
		for (j = 0; j < y_len; j++){
			c[i][j] = 0;
			b[i][j] = 0;
		}
	}

	// compute the length of the LCS by using a bottom-up dynamic programming
	// ¢Ø:1, ¡è:2, ¡ç:3 
	for (i = 1; i < x_len; i++){
		for (j = 1; j < y_len; j++){
			if (x[i - 1] == y[j - 1]){			// ¢Ø
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else{
				if (c[i - 1][j]>c[i][j - 1]){	// ¡è
					c[i][j] = c[i - 1][j];
					b[i][j] = 2;
				}
				else{							// ¡ç
					c[i][j] = c[i][j - 1];
					b[i][j] = 3;
				}
			}
		}
	}

	return b;
}
void print_LCS(char* x, int** b, int x_len, int y_len){							// an algorithm to print an LCS
	if (x_len == 0 || y_len == 0)	// end the function
		return;

	if (b[x_len][y_len] == 1){					// ¢Ø
		print_LCS(x, b, x_len - 1, y_len - 1);	// go to print_LCS function
		cout << x[x_len - 1];					// print x[x_len-1]
	}
	else if (b[x_len][y_len] == 2)				// ¡è
		print_LCS(x, b, x_len - 1, y_len);		// go to print_LCS function
	else if (b[x_len][y_len] == 3)				// ¡ç
		print_LCS(x, b, x_len, y_len - 1);		// go to print_LCS function

}
int main(void){
	char x[20], y[20]; 	// x, y
	int **c, **b;		// c, b
	int x_len, y_len;	// length
	// enter the x and y
	cout << "x : ";
	cin >> x;
	cout << "y : ";
	cin >> y;

	// calculate x' length and y's length
	x_len = strlen(x) + 1;
	y_len = strlen(y) + 1;

	// dynamic allocation
	c = (int**)malloc(sizeof(int*)*x_len);
	for (int i = 0; i < x_len; i++)
		c[i] = (int*)malloc(sizeof(int)*y_len);
	b = (int**)malloc(sizeof(int*)*x_len);
	for (int i = 0; i < x_len; i++)
		b[i] = (int*)malloc(sizeof(int)*y_len);

	/////////////// Longest Common Subsequence (LCS) /////////////////////////
	cout << "<top-down>" << endl;				// print result of top-down
	cout << "length of LCS by using top_down : " << top_down(x, y, x_len - 1, y_len - 1) << endl;
	cout << "<bottom-up>" << endl;				// print result of bottom-up
	bottom_up(x, y, c, b, x_len, y_len);		// bottom-up
	cout << "length of LCS by using bottom-up : " << c[x_len - 1][y_len - 1] << endl;
	cout << "LCS : ";							// print result of LCS
	print_LCS(x, b, x_len - 1, y_len - 1);
	cout << endl;

	// free dynamic allocation
	for (int i = 0; i < x_len; i++){
		free(b[i]);
		free(c[i]);
	}
	free(b);
	free(c);
	return 0;
}