#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */
unsigned hash1 (char* s)
{
   unsigned h = FIRSTH;
   while (*s) {
     h = (h * A) ^ (s[0] * B);
     s++;
   }
   return h % SIZE; 
}

int hash2 (string word)   
// POST: the index of entry is returned
{       int sum = 0;
        for (int k = 0; k < word.length(); k++)
            sum = sum + int(word[k]);
        return  sum % SIZE; 
}

int hash3 (string word)
{
   int seed = 131; 
   unsigned long hash = 0;
   for(int i = 0; i < word.length(); i++)
   {
      hash = (hash * seed) + word[i];
   }
   return hash % SIZE;
}
