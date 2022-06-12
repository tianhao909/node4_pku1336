#define _GNU_SOURCE
#include<dlfcn.h>

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



//#if 1
#if 0
int global = 0;
void *_malloc(size_t size, const char *file, int line){
	void *p = malloc(size);

	char buff[128] = {0};
	sprintf(buff, "./mem/%p.mem",p);

	FILE *fp = fopen(buff, "w");
	fprintf(fp, "[+%s:%d] --> addr: %p, size: %ld,", file, line, p, size);
	fflush(fp);
	fclose(fp);

	//printf("_malloc[+]--> %p, %s:%d\n",p, file, line);
	//global++;
	return p;

}


void _free(void *p, const char *file, int line){
	char buff[128] = {0};
	sprintf(buff, "./mem/%p.mem",p); 	
	
	if (unlink(buff) < 0) { //no exist
		printf("double free: %p\n",p);
		return ; 
	}	

	free(p);
	//global--;
	//printf("_free[-]--> %p, %s:%d\n",p, file, line);
}

#define malloc(size)	 _malloc(size, __FILE__, __LINE__)
#define free(p)			_free(p, __FILE__, __LINE__)

#else

typedef void *(*malloc_t)(size_t size);
malloc_t malloc_f = NULL;

//typedef void *(*free_t)(void *p);
typedef void (*free_t)(void *p);
free_t free_f = NULL;

//func --> malloc();
//main --> func --> malloc();

int enable_malloc_hook = 1;
int enable_free_hook = 1;

void *malloc(size_t size){

	if(enable_malloc_hook) {
		enable_malloc_hook = 0;
		void *p = malloc_f(size);

		void *caller = __builtin_return_address(0);

		char buff[128] = {0};
		sprintf(buff, "./mem/%p.mem",p);

		FILE *fp = fopen(buff, "w");
		// fprintf(fp, "[+%s:%d] --> addr: %p, size: %ld,", file, line, p, size);
		fprintf(fp, "[+caller %p] --> addr: %p, size: %ld,", caller, p, size);
		fflush(fp);
		fclose(fp);

		//printf("_malloc[+]--> %p, %s:%d\n",p, file, line);
		//global++;
		enable_malloc_hook = 1;
		return p;
	} else {
		return malloc_f(size);
	}
	

}


void free(void *p){

	if(enable_free_hook) {
		enable_free_hook = 0;
		char buff[128] = {0};
		sprintf(buff, "./mem/%p.mem",p); 	
		
		if (unlink(buff) < 0) { //no exist
			printf("double free: %p\n",p);
			return ; 
		}	

		free_f(p);
		enable_free_hook = 1;
	} else {
		free_f(p);	

	}

}


static void init_hook(void) {
	if (malloc_f == NULL) {
		malloc_f = dlsym(RTLD_NEXT, "malloc");
	}

	if (free_f == NULL) {
		free_f = dlsym(RTLD_NEXT, "malloc");
	}
}





//malloc --> hook
#define DEBUG_MEM_LEAK init_hook();

#endif


void func(void) {
	
	void *p1 = malloc(10);
	printf("p1:%p\n",p1);
	void *p2 = malloc(20);
	printf("p2:%p\n",p2);

	free(p1);

	void *p3 = malloc(30);
	printf("p3:%p\n",p3);
	free(p3);
	
	return ;

}
int main() {

	// init_hook();
	DEBUG_MEM_LEAK;
	func();
	//printf("%d\n", global);
	return 0;
}
