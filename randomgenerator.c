// Random Number Generator
// Based on https://www.geeksforgeeks.org/generating-random-number-range-c/

#define USE_LIMIT 0     // set to true to use below limits, otherwise set to false
#define LIST_MIN 1      // lowest possible generated number 
#define LIST_MAX 10     // highest possible generated number

// Generates a random number either with or without limits
int Random (int floor, int ceiling, int cycles) { 
	int i, num;
	for (i = 0; i < cycles; i++) {
      #if USE_LIMIT
		   num = (rand() % ceiling) + floor; // comment out this line for limitless random generation
      #else
         num = rand();
      #endif
	}

	return num;
}

// Generates an array of random numbers given the defined limits
void GenerateData (int A[], int N) {
   int i;
   for (i = 0; i < N; i++) {
      A[i] = Random(LIST_MIN, LIST_MAX, 1);
   }
}