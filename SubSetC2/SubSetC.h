


struct symbol
{
	int type;
	char name[20];
	float val;
};

#define NHASH 9997


struct symbol symbol_table[NHASH];

struct ID_List
{
	int type;
	struct symbol* s;
	struct ID_List* next;
};

int Hash(char* s);
struct symbol* search(char* s);
struct symbol* insert(char* s);
