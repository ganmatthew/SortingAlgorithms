// Random Number Generator
// Based on https://www.geeksforgeeks.org/generating-random-number-range-c/
int Random (int floor, int ceiling, int cycles) { 
	int i, num;
	for (i = 0; i < cycles; i++) {
		//num = (rand() % ceiling) + floor;
      num = rand();
	}

	return num;
}

// Generates an array of numbers given the defined limits
void GenerateData (int A[], int N) {
   int i;
   for (i = 0; i < N; i++) {
      A[i] = Random(LIST_MIN, LIST_MAX, 1);
   }
}